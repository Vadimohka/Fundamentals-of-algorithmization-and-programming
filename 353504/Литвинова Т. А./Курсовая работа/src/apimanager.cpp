#include "apimanager.h"
#include "ThreadManager.cpp"


#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/asio/ssl.hpp>

static QStringList daysOfWeek = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};


ApiManager::ApiManager(const std::string& server, const std::string& path) :
    server_(server), path_(path), io_service_(), context_(boost::asio::ssl::context::sslv23), socket_(io_service_, context_){}

void ApiManager::connect_groups() {//ПОЛУЧЕНИЕ ВСЕХ ГРУПП В УНИВЕРЕ

    //emit progressUpdated(20); // Обновление прогресса на 20%

    request.setUrl(QUrl("https://iis.bsuir.by/api/v1/student-groups"));

    // отправляем GET-запрос и получаем ответ
    reply = manager.get(request);

    // ожидаем завершения запроса
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    responseData = reply->readAll();
    //qDebug() << responseData;

    QString strReply = QString::fromUtf8(responseData);
    strReplyEditGroup = strReply;
    processJsonGroup(strReplyEditGroup);
}

void ApiManager::processJsonGroup(const QString& jsonStr) {// ПОЛУЧЕНИЕ ПОЛЯ НОМЕР ГРУППЫ И СОХРАНЕНИЕ В МАССИВ
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
    QJsonArray array = doc.array();

    for (int i = 0; i < array.size(); ++i) {
        QJsonObject object = array[i].toObject();
        QJsonValue needed_field = object.value("name");
        QString groupNumber = needed_field.toString();
        // Проверка, что номер группы не начинается с нуля
        if (!groupNumber.startsWith('0')) {
            string_array_group.append(groupNumber);
        }
    }
    qDebug()<<"Группа сохранена в массив";

    //string_array_group.append("353504");
}

void ApiManager::connect_group_schedule() {//ПОЛУЧЕНИЕ РАСПИСАНИЯ КАЖДОЙ ГРУППЫ           (РАБОЧАЯ ВЕРСИЯ)
    QThreadPool *threadPool = QThreadPool::globalInstance();
    threadPool->setMaxThreadCount(8);
    qDebug() << "!Начало для потоков:" << QDateTime::currentDateTime().toMSecsSinceEpoch();

    for (const QString& groupNumber : string_array_group) {
        ThreadManager *task = new ThreadManager(groupNumber, apimanager);
        threadPool->start(task);
    }
    threadPool->waitForDone();
    qDebug() << "!Конец для потоков:" << QDateTime::currentDateTime().toMSecsSinceEpoch();
    qDebug()<<"Запросы расписания групп выполнены";
}

QString ApiManager::getResponse(QString groupNumber) {
    QString url = QString("https://iis.bsuir.by/api/v1/schedule?studentGroup=%1").arg(groupNumber);
    request.setUrl(QUrl(url));

    qDebug() << "Начало:" << QDateTime::currentDateTime().toMSecsSinceEpoch();

    // Создаем QNetworkAccessManager
    QNetworkAccessManager manager;

    // Отправляем GET-запрос и получаем ответ
    QNetworkReply* reply = manager.get(request);

    // Создаем цикл событий для ожидания завершения запроса
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // Проверяем, была ли ошибка в запросе
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Ошибка: " << reply->errorString();
        return "";
    }

    // Получаем данные ответа
    QByteArray responseData = reply->readAll();

    qDebug() << "Конец_:" << QDateTime::currentDateTime().toMSecsSinceEpoch();

    qDebug() << "Получено расписание группы";
    return QString::fromUtf8(responseData);
}

// Синхронизированный метод processResult
void ApiManager::processResult(QString requestResult) {
    QMutexLocker locker(&mutex); // Блокировка для потокобезопасного доступа
    // ... ваш код для обработки результатов ...
    if(requestResult==""){
        return;
    }
    //qDebug() << "Processing result: " << requestResult;
    processGroupSchedule(requestResult);
}

void ApiManager::processGroupSchedule(const QString& jsonStr) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
    QJsonObject object = doc.object();
    QJsonValue schedules_field = object.value("schedules");

    if (schedules_field.isObject()) {
        QJsonObject schedules_object = schedules_field.toObject();
        QSet<QString> uniqueSchedules; // Добавлено для проверки уникальности

        for (const QString& day : daysOfWeek) {
            QJsonValue day_field = schedules_object.value(day);
            if (day_field.isArray()) {
                QJsonArray day_array = day_field.toArray();

                for (const QJsonValue& dayValue : day_array) {
                    if (dayValue.isObject()) {
                        QJsonObject dayObject = dayValue.toObject();
                        processDayObject(dayObject, day);
                    }
                }

            }
        }
    }
}

void ApiManager::processDayObject(const QJsonObject& dayObject, const QString& day) {
    QString auditorium = dayObject.value("auditories").toArray().first().toString();
    QString startLessonTime = QTime::fromString(dayObject.value("startLessonTime").toString(), "HH:mm").toString("HH:mm");
    QString endLessonTime = QTime::fromString(dayObject.value("endLessonTime").toString(), "HH:mm").toString("HH:mm");
    QJsonArray weekNumberArray = dayObject.value("weekNumber").toArray();
    QStringList weekNumbers;
    for (const QJsonValue& value : weekNumberArray) {
        weekNumbers.append(QString::number(value.toInt()));
    }
    QString weekNumbersString = weekNumbers.join(", ");

    QString scheduleString = auditorium + "+" + startLessonTime + "+" + endLessonTime + "+" + weekNumbersString;
    // Проверка на уникальность перед добавлением
    if (!uniqueSchedules.contains(scheduleString)) {
        uniqueSchedules.insert(scheduleString);
        daySchedules[day].append(scheduleString);
    }
}



void ApiManager::createFinalSchedule() {  //                    (РАБОТАЕТ)

    finalSchedule.clear();

    for (const QString& day : daysOfWeek) {
        for (const QString& schedule : daySchedules[day]) {
            QStringList scheduleDetails = schedule.split("+");
            QString auditorium = scheduleDetails.at(0);
            QString startLessonTime = scheduleDetails.at(1);
            QString endLessonTime = scheduleDetails.at(2);
            QString timeSlot = startLessonTime + "+" + endLessonTime;
            QString key = auditorium + "+" + day;

            // Проверка на уникальность временного слота перед добавлением
            if (!finalSchedule[key].contains(timeSlot)) {
                finalSchedule[key].insert(timeSlot);
            }
        }
    }

    // Вывод итогового расписания
    qDebug() << "Аудитория\\День | " + daysOfWeek.join(" | ");
    for (const QString& key : finalSchedule.keys()) {
        QString line = key + " | ";
        for (const QString& day : daysOfWeek) {
                QString dayKey = key.split("+").at(0) + "+" + day;
            if (finalSchedule.contains(dayKey)) {
                line += QStringList(finalSchedule[dayKey].begin(), finalSchedule[dayKey].end()).join(", ") + " | ";
            } else {
                line += " - | ";
            }
        }
        qDebug() << line;
    }
    qDebug()<<"Создана финальная карта";
    //Semit finished(); // Сигнал о завершении процесса

}

QString ApiManager::getDayOfWeekString(const QDate& date) {
    QMap<int, QString> daysOfWeek = {
        {1, "Понедельник"},
        {2, "Вторник"},
        {3, "Среда"},
        {4, "Четверг"},
        {5, "Пятница"},
        {6, "Суббота"},
        {7, "Воскресенье"}
    };
    return daysOfWeek[date.dayOfWeek()];
}

QString ApiManager::checkDate(const QDate& date) {
    QDate currentDate = QDate::currentDate();
    QDate endDate(2024, 6, 7); // 7 июня 2024 года

    if (date < currentDate) {
        return "Эта дата уже прошла";
    } else if (date > endDate) {
        return "Занятия заканчиваются 7 июня 2024 года";
    } else {
        return ""; // Дата в допустимом диапазоне
    }
}


QString ApiManager::findScheduleTime(const QMap<QString, QSet<QString>>& finalSchedule, const QString& auditorium, const QDate& date) {
    QString dayOfWeek = getDayOfWeekString(date);

    // Проверка, является ли день воскресеньем
    if (dayOfWeek == "Воскресенье") {
        qDebug() << "Университет не работает в воскресенье";
        return ""; // Возвращаем пустую строку, чтобы не использовать это значение в дальнейшем коде
    }

    QString key = auditorium + "+" + dayOfWeek;
    if (finalSchedule.contains(key)) {
        return QStringList(finalSchedule[key].begin(), finalSchedule[key].end()).join(", ");
    }
    return "Расписание не найдено";
}

QStringList ApiManager::findFreeTimeSlots(const QMap<QString, QSet<QString>>& finalSchedule, const QString& auditorium, const QDate& date) {
    QStringList freeTimeSlots;
    QTime startTime(9, 0); // Начало рабочего дня
    QTime endTime(22, 0); // Конец рабочего дня
    QString dayOfWeek = getDayOfWeekString(date);

    // Проверка, является ли день воскресеньем
    if (dayOfWeek == "Воскресенье") {
        qDebug() << "Университет не работает в воскресенье";
        return freeTimeSlots; // Возвращаем пустой список
    }

    if (dayOfWeek == "Суббота") {
        endTime = QTime(18, 0);
    }

    QString key = auditorium + "+" + dayOfWeek;
    QSet<QString> busySet = finalSchedule.value(key);

    //QStringList busyList = QStringList(QList<QString>::fromSet(busySet));
    // Преобразуем QSet в QStringList
    QStringList busyList;
    for (const QString &entry : busySet) {
        busyList << entry;
    }


    // Функция сравнения для сортировки
    struct TimeSlotCompare {
        bool operator()(const QString &a, const QString &b) const {
            QTime timeA = QTime::fromString(a.split("+").first(), "HH:mm");
            QTime timeB = QTime::fromString(b.split("+").first(), "HH:mm");
            return timeA < timeB;
        }
    };

    // Сортируем список временных интервалов
    std::sort(busyList.begin(), busyList.end(), TimeSlotCompare());

    // Находим свободные интервалы
    QTime lastEndTime = startTime;
    for (const QString& timeSlot : busyList) {
        QStringList times = timeSlot.split("+");
        QTime busyStartTime = QTime::fromString(times.first(), "HH:mm");
        QTime busyEndTime = QTime::fromString(times.last(), "HH:mm");

        if (lastEndTime < busyStartTime) {
            // Добавляем свободный интервал
            freeTimeSlots.append(lastEndTime.toString("HH:mm") + "+" + busyStartTime.toString("HH:mm"));
        }
        lastEndTime = busyEndTime; // Обновляем время окончания последнего занятого интервала
    }

    // Проверяем, осталось ли свободное время в конце дня
    if (lastEndTime < endTime) {
        freeTimeSlots.append(lastEndTime.toString("HH:mm") + "+" + endTime.toString("HH:mm"));
    }

    return freeTimeSlots;
}

// Функция сравнения для сортировки
bool ApiManager::timeCompare(const QPair<QTime, QTime>& a, const QPair<QTime, QTime>& b) {
    return a.first < b.first;
}
