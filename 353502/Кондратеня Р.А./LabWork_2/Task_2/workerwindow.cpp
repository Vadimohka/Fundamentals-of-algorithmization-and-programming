#include "workerwindow.h"
#include "ui_workerwindow.h"


WorkerWindow::WorkerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerWindow)
{
    ui->setupUi(this);
    ui->surnameEdit->setText("Иванов");
    ui->nameEdit->setText("Иван");
    ui->lastnameEdit->setText("Иванович");
    ui->isEducatedEdit->setText("true");
    ui->salaryEdit->setText("99999999");
    ui->experienceOfWorkEdit->setText("100_years");
    ui->vacancyEdit->setText("God");
    ui->lastPlaceEdit->setText("GoogleTeamLeed");
    ui->numberOfChanging->setMinimum(1);
    getDataFromFile();
    strings.append(ui->surnameEdit->text());
    strings.append(ui->nameEdit->text());
    strings.append(ui->lastnameEdit->text());
    strings.append(ui->birthDateEdit->text());
    strings.append(ui->isEducatedEdit->text());
    strings.append(ui->vacancyEdit->text());
    strings.append(ui->salaryEdit->text());
    strings.append(ui->lastPlaceEdit->text());
    strings.append(ui->experienceOfWorkEdit->text());
}

void WorkerWindow::getDataFromFile()
{
    QFile file("/home/kbadpat/OAiP/Lab2/task2/workers.txt");
    qDebug() <<"Its ok";

        // Открытие файла в режиме чтения
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

            // Создание модели данных
        QStandardItemModel* model = new QStandardItemModel();

            // Установка количества столбцов
        model->setColumnCount(9);

            // Чтение строк файла
        int i = 0;
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            line += "false";
            i++;
            qDebug() << "i = " << i;

                // Разделение строки на числа по пробелу
            QStringList string = line.trimmed().split(" ");

                // Проверка корректности количества чисел в строке
            workersList.append(string);
            qDebug() << "norm";
                    // Создание строки модели
            QList<QStandardItem*> rowItems;

                    // Заполнение столбцов модели данными
            for (int column = 0; column < 9; ++column) {
                QString number = string[column];
                QStandardItem* item = new QStandardItem(number);
                rowItems.append(item);
            }

                    // Добавление строки в модель
            model->appendRow(rowItems);
            qDebug() << numberOfRow;

        }

            // Установка модели данных для TableView
        ui->tableView->setModel(model);
        qDebug() << " i ravno " << i;
        numberOfRow = i + 1;
        ui->numberOfChanging->setMaximum(numberOfRow);

            // Закрытие файла
        file.close();
    }
}

WorkerWindow::~WorkerWindow()
{
    delete ui;
}

void WorkerWindow::on_addWorkerButton_clicked()
{
    QFile file("/home/kbadpat/OAiP/Lab2/task2/workers.txt");
    strings.clear();
    strings.append(ui->surnameEdit->text());
    strings.append(ui->nameEdit->text());
    strings.append(ui->lastnameEdit->text());
    strings.append(ui->birthDateEdit->text());
    strings.append(ui->isEducatedEdit->text());
    strings.append(ui->vacancyEdit->text());
    strings.append(ui->salaryEdit->text());
    strings.append(ui->lastPlaceEdit->text());
    strings.append(ui->experienceOfWorkEdit->text());
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        for(int i = 0; i < 9; ++i)
        {
            stream << strings[i] << " " ;
        }
        stream << Qt::endl;
        file.close();
        getDataFromFile();
    }
}


void WorkerWindow::on_changeWorkerButton_clicked()
{
    int index = ui->numberOfChanging->value() - 1;
    strings.clear();
    strings.append(ui->surnameEdit->text());
    strings.append(ui->nameEdit->text());
    strings.append(ui->lastnameEdit->text());
    strings.append(ui->birthDateEdit->text());
    strings.append(ui->isEducatedEdit->text());
    strings.append(ui->vacancyEdit->text());
    strings.append(ui->salaryEdit->text());
    strings.append(ui->lastPlaceEdit->text());
    strings.append(ui->experienceOfWorkEdit->text());
    QFile file("/home/kbadpat/OAiP/Lab2/task2/workers.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            // Чтение всех строк из файла
        QTextStream stream(&file);
        QStringList lines;
        while (!stream.atEnd()) {
            lines.append(stream.readLine());
        }

            // Проверка корректности индекса строки
        lines[index] = strings.join(" ");

            // Устанавливаем позицию файла в начало и очищаем его содержимое
        file.resize(0);

            // Запись измененных строк обратно в файл
        QTextStream writeStream(&file);
        foreach (const QString& line, lines) {
            writeStream << line << " " << Qt::endl;
        }

            // Закрытие файла
        file.close();
    }
    getDataFromFile();
}

QVector<QStringList> WorkerWindow::getWorkersList()
{
    return workersList;
}

int WorkerWindow::getAge(int numberOfWorker)
{
    QDate birthDate = QDate::fromString(workersList[numberOfWorker][3]);

        // Получение текущей даты
    QDate currentDate = QDate::currentDate();

        // Вычисление разницы в годах
    int age = birthDate.daysTo(currentDate) / 365;
    return age;
}


