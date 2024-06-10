#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDate>
#include <QMessageBox>
#include <QFlags>
#include <QInputDialog>
#include <QMessageBox>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создание таблицы
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4); // Четыре столбца для отображения дат, следующего дня, разницы и кнопок
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Запрет редактирования ячеек
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // Выделение целой строки

    // Создание кнопки выбора файла
    fileButton = new QPushButton("Выбрать файл", this);
    connect(fileButton, &QPushButton::clicked, this, &MainWindow::openFileDialog);

    // Создание кнопки вывода следующей даты
    nextDayButton = new QPushButton("Вывести следующую дату", this);
    connect(nextDayButton, &QPushButton::clicked, this, &MainWindow::showNextDay);

    // Создание кнопки вычисления разницы
    diffButton = new QPushButton("Вычислить разницу", this);
    connect(diffButton, &QPushButton::clicked, this, &MainWindow::showDiff);

    // Создание поля для ввода даты рождения
    birthdateEdit = new QDateEdit(QDate::currentDate(), this);
    birthdateEdit->setDisplayFormat("dd.MM.yyyy"); // Установка формата отображения даты

    // Создание кнопки добавления даты рождения в таблицу
    QPushButton *addBirthdayButton = new QPushButton("Добавить дату рождения", this);
    connect(addBirthdayButton, &QPushButton::clicked, this, &MainWindow::addBirthday);

    // Создание кнопки изменения даты в таблице
    QPushButton *modifyDateButton = new QPushButton("Изменить дату", this);
    connect(modifyDateButton, &QPushButton::clicked, this, &MainWindow::modifyDate);

    // Создание главного виджета и установка таблицы, кнопок и полей в него
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(tableWidget);
    layout->addWidget(fileButton);
    layout->addWidget(nextDayButton);
    layout->addWidget(diffButton);
    layout->addWidget(birthdateEdit);
    layout->addWidget(addBirthdayButton);
    layout->addWidget(modifyDateButton);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", QString(), "Текстовые файлы (*.txt)");

    if (!fileName.isEmpty())
    {
        loadDatesFromFile(fileName);
    }
}

void MainWindow::loadDatesFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QStringList collection;
        QDate birthdate = birthdateEdit->date(); // Получение выбранной даты рождения

        // Чтение данных из файла и добавление в коллекцию
        while (!in.atEnd())
        {
            QString line = in.readLine();
            collection.append(line);
        }

        file.close();

        // Установка размеров таблицы
        tableWidget->setRowCount(collection.size() + 1); // +1 для даты рождения

        // Заполнение таблицы данными
        for (int i = 0; i < collection.size(); ++i)
        {
            const QString& currentDateStr = collection.at(i);
            QDate currentDate = QDate::fromString(currentDateStr, "dd.MM.yyyy");

            QTableWidgetItem *currentDateItem = new QTableWidgetItem(currentDateStr);
            tableWidget->setItem(i, 0, currentDateItem);
        }

        // Добавление даты рождения в таблицу
        QTableWidgetItem *birthdateItem = new QTableWidgetItem(birthdate.toString("dd.MM.yyyy"));
        tableWidget->setItem(collection.size(), 0, birthdateItem);
    }
}

void MainWindow::showNextDay()
{
    // Получение выбранной строки
    int selectedRow = tableWidget->currentRow();
    if (selectedRow < 0) {
        QMessageBox::information(this, "Ошибка", "Не выбрана строка с датой.");
        return;
    }

    // Получение текущей даты из таблицы
    QTableWidgetItem *currentDateItem = tableWidget->item(selectedRow, 0);
    QString currentDateStr = currentDateItem->text();
    QDate currentDate = QDate::fromString(currentDateStr, "dd.MM.yyyy");

    // Вычисление следующей даты
    QDate nextDate = currentDate.addDays(1);

    // Вывод следующей даты в таблицу
    QTableWidgetItem *nextDateItem = new QTableWidgetItem(nextDate.toString("dd.MM.yyyy"));
    tableWidget->setItem(selectedRow, 1, nextDateItem);
}

void MainWindow::showDiff()
{
    // Получение выбранной строки
    int selectedRow = tableWidget->currentRow();
    if (selectedRow < 0) {
        QMessageBox::information(this, "Ошибка", "Не выбрана строка с датой.");
        return;
    }

    // Получение текущей даты из таблицы
    QTableWidgetItem *currentDateItem = tableWidget->item(selectedRow, 0);
    QString currentDateStr = currentDateItem->text();
    QDate currentDate = QDate::fromString(currentDateStr, "dd.MM.yyyy");

    // Вычисление разницы между текущей датой и датой рождения
    QDate birthdate = birthdateEdit->date();
    int diff = birthdate.daysTo(currentDate);

    // Вывод разницы в таблицу
    QTableWidgetItem *diffItem = new QTableWidgetItem(QString::number(diff));
    tableWidget->setItem(selectedRow, 2, diffItem);
}

void MainWindow::addBirthday()
{
    // Получение выбранной строки или добавление новой строки, если ни одна не выбрана
    int selectedRow = tableWidget->currentRow();
    if (selectedRow < 0) {
        selectedRow = tableWidget->rowCount();
        tableWidget->insertRow(selectedRow);
    }

    // Убедитесь, что таблица имеет достаточное количество столбцов
    int columnCount = tableWidget->columnCount();
    if (columnCount < 1) {
        tableWidget->setColumnCount(1);
    }

    // Получение даты из поля ввода даты рождения
    QDate date = birthdateEdit->date();

    // Вставка даты рождения в таблицу
    QTableWidgetItem *birthdateItem = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
    tableWidget->setItem(selectedRow, 0, birthdateItem);
}

void MainWindow::modifyDate()
{
    // Получение выбранной строки
    int selectedRow = tableWidget->currentRow();
    if (selectedRow < 0) {
        QMessageBox::information(this, "Ошибка", "Не выбрана строка для изменения даты.");
        return;
    }

    // Получение текущей даты из таблицы
    QTableWidgetItem *currentDateItem = tableWidget->item(selectedRow, 0);
    QString currentDateStr = currentDateItem->text();
    QDate currentDate = QDate::fromString(currentDateStr, "dd.MM.yyyy");

    // Создание диалогового окна для изменения даты
    QDialog dialog(this);
    dialog.setWindowTitle("Изменение даты");

    // Создание виджета для выбора даты
    QDateEdit dateEdit(&dialog);
    dateEdit.setDate(currentDate);
    dateEdit.setCalendarPopup(true);

    // Создание кнопок "ОК" и "Отмена"
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);

    // Создание компоновщика
    QVBoxLayout layout(&dialog);
    layout.addWidget(&dateEdit);
    layout.addWidget(&buttonBox);

    // Обработка нажатия кнопки "ОК"
    connect(&buttonBox, &QDialogButtonBox::accepted, [&]() {
        // Получение выбранной даты
        QDate newDate = dateEdit.date();

        // Проверка правильности ввода даты
        if (!newDate.isValid()) {
            QMessageBox::warning(this, "Ошибка", "Неправильный формат даты.");
            return;
        }

        // Обновление даты в таблице
        QTableWidgetItem *newDateItem = new QTableWidgetItem(newDate.toString("dd.MM.yyyy"));
        tableWidget->setItem(selectedRow, 0, newDateItem);

        // Закрытие диалогового окна
        dialog.accept();
    });

    // Обработка нажатия кнопки "Отмена"
    connect(&buttonBox, &QDialogButtonBox::rejected, [&]() {
        // Закрытие диалогового окна
        dialog.reject();
    });

    // Отображение диалогового окна
    dialog.exec();
}
