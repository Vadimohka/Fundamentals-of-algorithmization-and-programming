#include "mainwindow.h"
#include "typingtrainer.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QComboBox *languageComboBox = new QComboBox(this);
    languageComboBox->addItem("German");
    languageComboBox->addItem("French");
    languageComboBox->addItem("Arabic");
    // Добавьте остальные языки
    connect(languageComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(updateLanguage(const QString &)));

    layout->addWidget(languageComboBox);

    // Создание метки для времени
    timeLabel = new QLabel("Time: 00:00", this);
    layout->addWidget(timeLabel);

    // Создание метки для точности
    accuracyLabel = new QLabel("Accuracy: 100%", this);
    layout->addWidget(accuracyLabel);

    // Поле ввода текста
    inputField = new QLineEdit(this);
    layout->addWidget(inputField);

    // Кнопки для выбора языка
    languageComboBox = new QComboBox(this);
    languageComboBox->addItem("English");
    languageComboBox->addItem("German");
    languageComboBox->addItem("French");
    languageComboBox->addItem("Arabic");
    languageComboBox->addItem("Chinese");
    languageComboBox->addItem("Belarusian");
    languageComboBox->addItem("Hebrew");
    layout->addWidget(languageComboBox);

    // Создание и запуск таймера
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimeAndAccuracy);
    timer->start(1000);

    // Подключение сигналов к слотам
    connect(inputField, &QLineEdit::textChanged, this, &MainWindow::updateTimeAndAccuracy);
    connect(inputField, &QLineEdit::textChanged, this, &MainWindow::addKeyToInputField);
    connect(languageComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::changeLanguage);
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateTimeAndAccuracy()
{
    // Обновление времени и точности
    // Оставлено для реализации
}

void MainWindow::addKeyToInputField()
{
    // Добавление символа в поле ввода
    // Оставлено для реализации
}

void MainWindow::changeLanguage(int index)
{
    // Изменение языка интерфейса
    // Оставлено для реализации
}
