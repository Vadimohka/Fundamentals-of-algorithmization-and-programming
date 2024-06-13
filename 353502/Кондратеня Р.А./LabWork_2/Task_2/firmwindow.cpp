#include "firmwindow.h"
#include "ui_firmwindow.h"

FirmWindow::FirmWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirmWindow)
{
    ui->setupUi(this);
    ui->nameEdit->setText("MMMPyramid");
    ui->vacancyEdit->setText("TeamLeed");
    ui->salaryEdit->setText("99999999");
    ui->isEducatedEdit->setText("true");
    ui->vacationEdit->setText("100_years");
    ui->minimalAgeEdit->setText("20");
    ui->maximumAgeEdit->setText("40");
    ui->minimalExperienceEdit->setText("10");
    strings.append(ui->nameEdit->text());
    strings.append(ui->vacancyEdit->text());
    strings.append(ui->salaryEdit->text());
    strings.append(ui->isEducatedEdit->text());
    strings.append(ui->vacationEdit->text());
    strings.append(ui->minimalAgeEdit->text());
    strings.append(ui->maximumAgeEdit->text());
    strings.append(ui->minimalExperienceEdit->text());
    getDataFromFile();
}

FirmWindow::~FirmWindow()
{
    delete ui;
}

void FirmWindow::getDataFromFile()
{
    QFile file("/home/kbadpat/OAiP/Lab2/task2/firms.txt");
    qDebug() <<"Its ok1";

        // Открытие файла в режиме чтения
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

            // Создание модели данных
        QStandardItemModel* model = new QStandardItemModel();

            // Установка количества столбцов
        model->setColumnCount(8);
        vacancyList.clear();

            // Чтение строк файла
        int i = 0;
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            line += "false";
            i++;


                // Разделение строки на числа по пробелу
            QStringList numbers = line.trimmed().split(" ");


                // Проверка корректности количества чисел в строке

            vacancyList.append(numbers);
            qDebug() << "norm";
                    // Создание строки модели
            QList<QStandardItem*> rowItems;

                    // Заполнение столбцов модели данными
            for (int column = 0; column < 8; ++column) {
                QString number = numbers[column];
                QStandardItem* item = new QStandardItem(number);
                rowItems.append(item);
            }

                    // Добавление строки в модель
            model->appendRow(rowItems);
            qDebug() << numberOfRow;
            ui->numberOfChanging->setMaximum(numberOfRow);
        }

            // Установка модели данных для TableView
        ui->tableView->setModel(model);
        numberOfRow = i + 1;

            // Закрытие файла
        file.close();
    }
}

void FirmWindow::on_changeWorkerButton_clicked()
{
    int index = ui->numberOfChanging->value() - 1;
    strings.clear();
    strings.append(ui->nameEdit->text());
    strings.append(ui->vacancyEdit->text());
    strings.append(ui->salaryEdit->text());
    strings.append(ui->isEducatedEdit->text());
    strings.append(ui->vacationEdit->text());
    strings.append(ui->minimalAgeEdit->text());
    strings.append(ui->maximumAgeEdit->text());
    strings.append(ui->minimalExperienceEdit->text());
    QFile file("/home/kbadpat/OAiP/Lab2/task2/firms.txt");
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


void FirmWindow::on_addWorkerButton_clicked()
{
    QFile file("/home/kbadpat/OAiP/Lab2/task2/firms.txt");
    strings.clear();
    strings.append(ui->nameEdit->text());
    strings.append(ui->vacancyEdit->text());
    strings.append(ui->salaryEdit->text());
    strings.append(ui->isEducatedEdit->text());
    strings.append(ui->vacationEdit->text());
    strings.append(ui->minimalAgeEdit->text());
    strings.append(ui->maximumAgeEdit->text());
    strings.append(ui->minimalExperienceEdit->text());
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        QList<QStandardItem*> rowItems;

        for(int i = 0; i < 8; ++i)
        {
            stream << strings[i] << " " ;
        }
        stream << Qt::endl;
        file.close();
        getDataFromFile();
    }
}

QVector<QStringList> FirmWindow::getVacancyList()
{
    return vacancyList;
}

