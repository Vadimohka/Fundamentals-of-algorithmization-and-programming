#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    console = new ConsoleEdit();

    setlocale(LC_ALL, "ru_RU.UTF-8");

    ui->verticalLayout->addWidget(console);

    loop = new QEventLoop();

    QTimer::singleShot(100, this, &MainWindow::run);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::input()
{
    QString string = "";

    connect(console, &ConsoleEdit::inputFinished, loop, &QEventLoop::quit);
    loop->exec();

    string = console->getCurrentString();

    return string;
}

int MainWindow::inputInt()
{
    bool isIncorrect;

    do {
        isIncorrect = false;

        QString str = input();
        bool ok;
        int number = str.toInt(&ok);

        if (!ok) {
            print("Ввод совершен некорректно, потворите\n");
            isIncorrect = true;
        } else {
            return number;
        }

    } while (isIncorrect);
}

double MainWindow::inputDouble()
{
    bool isIncorrect;

    do {
        isIncorrect = false;

        QString str = input();
        bool ok;
        double number = str.toDouble(&ok);

        if (!ok) {
            print("Ввод совершен некорректно, потворите\n");
            isIncorrect = true;
        } else {
            return number;
        }

    } while (isIncorrect);
}

void MainWindow::print(QString string)
{
    console->print(string);
}

void MainWindow::print(wchar_t ch)
{
    console->print(ch);
}

void MainWindow::run()
{
    bool isNotExit;

    do {
        printMenu();
        isNotExit = true;

        int number = inputInt();

        while (number < 1 || number > 6) {
            print("Нет такого пункта в меню, введите повторно!\n");
            number = inputInt();
        }

        switch (number) {
        case 1: {
            runFirstPunkt();
            break;
        }
        case 2: {
            runSecondPunkt();
            break;
        }
        case 3: {
            runThirdPunkt();
            break;
        }
        case 4: {
            runFourthPunkt();
            break;
        }
        case 5: {
            runFifthPunkt();
            break;
        }
        case 6: {
            isNotExit = false;
            close();
            break;
        }
        default: {
            break;
        }
        }

    } while (isNotExit);
}

void MainWindow::runFirstPunkt()
{
    bool isNotExit;

    do {
        isNotExit = true;

        print("1. Ввести текст до нажатия Enter для перезаписи файла.\n");
        print("2. Вывести текст из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while (num < 1 || num > 3) {
            print("Нет такого пункта в меню, введите повторно!\n");
        }

        switch (num) {
        case 1: {
            print("Введите текст до нажатия Enter.\n");
            QString text = input();

            QFile file("../../КлепацкийЛаб20.txt");
            if (!file.open(QIODevice::WriteOnly)) {
                return;
            }
            QTextStream out(&file);

            for (size_t i = 0; i < text.size(); i++) {
                out << text[i];
            }

            file.close();

            break;
        }
        case 2: {
            QFile file("../../КлепацкийЛаб20.txt");
            if (!file.open(QIODevice::ReadOnly)) {
                return;
            }
            QTextStream in(&file);

            print("Текст в файле: \n");

            file.seek(0);
            while (!in.atEnd()) {
                QString character = in.read(1);
                print(character);
            }

            print('\n');
            file.flush();
            file.close();

            break;
        }
        case 3: {
            isNotExit = false;
            break;
        }
        }

    } while (isNotExit);
}

void MainWindow::runSecondPunkt()
{
    bool isNotExit;

    do {
        print("1. Ввести массив для перезаписи файла.\n");
        print("2. Вывести массив из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while (num < 1 || num > 3) {
            print("Нет такого пункта в меню, введите повторно!\n");
        }

        switch (num) {
        case 1: {
            print("Введите число элементов массива типа long int:\n");

            int size;

            QFile file("../../КлепацкийЛаб20_0.txt");
            if (!file.open(QIODevice::WriteOnly)) {
                return;
            }
            QTextStream out(&file);

            size = inputInt();

            long int *array = new long int[size];

            long int element;

            for (int i = 0; i < size; i++) {
                print("Введите " + QString::number(i + 1) + "-й элемент: \n");

                element = inputInt();

                array[i] = element;
                out << element << "%";
            }

            file.close();

            break;
        }
        case 2: {
            QFile file("../../КлепацкийЛаб20_0.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                return;
            }
            QTextStream in(&file);

            QString elements;

            in >> elements;

            QStringList numbers = elements.split(" ");

            foreach (const QString &number, numbers) {
                print(number + ' ');
            }

            print("\n");

            file.close();

            break;
        }
        case 3: {
            isNotExit = false;
            break;
        }
        }
    } while (isNotExit);
}

void MainWindow::runThirdPunkt()
{
    bool isNotExit;

    do {
        print("1. Ввести поля структуры киносериал для дозаписи в файл.\n");
        print("2. Вывести записанные структуры из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while (num < 1 || num > 3) {
            print("Нет такого пункта в меню, введите повторно!\n");
            num = inputInt();
        }

        isNotExit = true;
        switch (num) {
        case 1: {
            QFile file("../../КлепацкийЛаб20_1.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                return;
            }
            QTextStream out(&file);

            int actors = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double dengi = 1;
            QString glavnu = "m", end = "y", name = "name";

            print("Введите количество актеров: \n");
            do {
                if (actors <= 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                actors = inputInt();
            } while (actors <= 0);

            print("Введите количество потраченных денег: \n");
            do {
                if (dengi <= 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                dengi = inputDouble();
            } while (dengi <= 0);

            print("Введите какого пола является режиссер (m/f): \n");
            do {
                if (glavnu != "f" && glavnu != "m")
                    print("Ввод некорректный! Повторите ввод: \n");
                glavnu = input();
            } while (glavnu != "f" && glavnu != "m");

            print("Введите закончились ли съемки (y/n): \n");
            do {
                if (end != "y" && end != "n")
                    print("Ввод некорректный! Повторите ввод: \n");
                end = input();
            } while (end != "y" && end != "n");

            print("Введите название сериала: \n");
            do {
                if (name.size() == 0 || name.size() > 40)
                    print("Ввод некорректный! Повторите ввод: \n");
                name = input();
            } while (name.size() == 0 || name.size() > 40);

            print("Введите кол-во оскаров: \n");
            do {
                if (goldMedals < 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                goldMedals = inputInt();
            } while (goldMedals < 0);

            print("Введите кол-во золотых глобусов: \n");
            do {
                if (silverMedals < 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                silverMedals = inputInt();
            } while (silverMedals < 0);

            print("Введите кол-во золотой малины: \n");
            do {
                if (bronzeMedals < 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                bronzeMedals = inputInt();
            } while (bronzeMedals < 0);

            out << actors << ' ' << dengi << ' ' << glavnu << ' ' << (end == "y" ? "true" : "false")
                << ' ' << name << ' ' << goldMedals << ' ' << silverMedals << ' ' << bronzeMedals
                << '\n';

            file.close();

            print("Данные сериала успешно дозаписаны в файл.\n");

            break;
        }
        case 2: {
            QFile file("../../КлепацкийЛаб20_1.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                return;
            }
            QTextStream in(&file);

            int actors = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double dengi = 1;
            QString glavnu = "m", end = "y", name = "name";

            print("Данные файла: \n");

            while (!in.atEnd()) {
                in >> actors >> dengi >> glavnu >> end >> name >> goldMedals >> silverMedals
                    >> bronzeMedals;

                if (glavnu != "" && end != "") {
                    print(QString::number(actors) + '|' + QString::number(dengi) + '|' + glavnu
                          + '|' + end + '|' + name + '|' + QString::number(goldMedals) + ','
                          + QString::number(silverMedals) + ',' + QString::number(bronzeMedals)
                          + '\n');
                }
            }

            file.close();

            break;
        }
        case 3: {
            isNotExit = false;
        }
        }
    } while (isNotExit);
}

void MainWindow::runFourthPunkt()
{
    bool isNotExit;

    do {
        isNotExit = true;

        print("1. Ввести поля структуры киносериал для дозаписи в бинарный файл.\n");
        print("2. Вывести записанные структуры из бинарного файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while (num < 1 || num > 3) {
            print("Нет такого пункта в меню, введите повторно!\n");
            num = inputInt();
        }

        switch (num) {
        case 1: {
            QFile file("../../КлепацкийЛаб20_1.bin");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                return;
            }
            QDataStream OUT(&file);
            QTextStream out(&file);

            int actors = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double dengi = 1;
            QString glavnu = "m", end = "y", name = "name";

            print("Введите кол-во актеров: \n");
            do {
                if (actors <= 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                actors = inputInt();
            } while (actors <= 0);

            print("Введите кол-во потраченных денег: \n");
            do {
                if (dengi <= 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                dengi = inputDouble();
            } while (dengi <= 0);

            print("Введите пол режиссера (m/f): \n");
            do {
                if (glavnu != "f" && glavnu != "m")
                    print("Ввод некорректный! Повторите ввод: \n");
                glavnu = input();
            } while (glavnu != "f" && glavnu != "m");

            print("Введите закончены ли съемки (y/n): \n");
            do {
                if (end != "y" && end != "n")
                    print("Ввод некорректный! Повторите ввод: \n");
                end = input();
            } while (end != "y" && end != "n");

            print("Введите название сериала: \n");
            do {
                if (name.size() == 0 || name.size() > 20)
                    print("Ввод некорректный! Повторите ввод: \n");
                name = input();
            } while (name.size() == 0 || name.size() > 20);

            print("Введите кол-во оскаров: \n");
            do {
                if (goldMedals < 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                goldMedals = inputInt();
            } while (goldMedals < 0);

            print("Введите кол-во золотых глобусов: \n");
            do {
                if (silverMedals < 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                silverMedals = inputInt();
            } while (silverMedals < 0);

            print("Введите кол-во золотой малины: \n");
            do {
                if (bronzeMedals < 0)
                    print("Ввод некорректный! Повторите ввод: \n");
                bronzeMedals = inputInt();
            } while (bronzeMedals < 0);

            Kinoserial kinoserial;
            kinoserial.actors = actors;
            kinoserial.dengi = dengi;
            kinoserial.glavnu = glavnu.toStdString()[0];
            kinoserial.end = ((end == "true") ? true : false);

            strcpy(kinoserial.name, name.toStdString().c_str());
            kinoserial.medals[0] = goldMedals;
            kinoserial.medals[1] = silverMedals;
            kinoserial.medals[2] = bronzeMedals;

            OUT.writeRawData(reinterpret_cast<const char *>(&kinoserial), sizeof(Kinoserial));

            file.close();

            print("Данные сериала успешно дозаписаны в файл.\n");

            break;
        }
        case 2: {
            QFile file("../../КлепацкийЛаб20_1.bin");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                return;
            }
            QTextStream in(&file);
            QDataStream IN(&file);

            int actors = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double dengi = 1;
            QString glavnu = "m", end = "y", name = "name";

            print("Данные файла: \n");

            Kinoserial kinoserial;

            while (file.read(reinterpret_cast<char *>(&kinoserial), sizeof(Kinoserial))) {
                actors = kinoserial.actors;
                dengi = kinoserial.dengi;
                glavnu = kinoserial.glavnu;
                end = (kinoserial.end ? "true" : "false");
                name = kinoserial.name;
                goldMedals = kinoserial.medals[0];
                silverMedals = kinoserial.medals[1];
                bronzeMedals = kinoserial.medals[2];

                if (glavnu != "" && end != "") {
                    print(QString::number(actors) + " ; " + QString::number(dengi) + " ; " + glavnu
                          + " ; " + end + " ; " + name + " ; " + QString::number(goldMedals) + ','
                          + QString::number(silverMedals) + ',' + QString::number(bronzeMedals)
                          + '\n');
                }
            }

            file.close();
            break;
        }
        case 3: {
            isNotExit = false;
            break;
        }
        }

    } while (isNotExit);
}

void MainWindow::runFifthPunkt()
{
    bool isNotExit;

    do {
        isNotExit = true;

        print("1. Ввести текст до нажатия Enter для дозаписи в файл.\n");
        print("2. Вывести текст из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while (num < 1 || num > 3) {
            print("Нет такого пункта в меню, введите повторно!\n");
            num = inputInt();
        }

        switch (num) {
        case 1: {
            print("Введите текст до нажатия Enter.\n");
            QString text = input();

            QFile file("../../КлепацкийЛаб20_3.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                return;
            }
            QTextStream out(&file);

            out << text;

            file.close();

            break;
        }
        case 2: {
            QFile file("../../КлепацкийЛаб20_3.txt");
            if (!file.open(QIODevice::ReadOnly)) {
                return;
            }
            QTextStream in(&file);

            print("Текст в файле: \n");

            file.seek(0);
            while (!in.atEnd()) {
                QString character = in.read(1);
                print(character);
            }

            print('\n');
            file.flush();
            file.close();

            break;
        }
        case 3: {
            isNotExit = false;
            break;
        }
        }

    } while (isNotExit);
}

void MainWindow::printMenu()
{
    print("\nМеню\n\n");
    print("1. Работа с перезаписью текста (файл КлепацкийЛаб20.txt)\n");
    print("2. Работа с массивом данных (файл КлепацкийЛаб20_0.txt)\n");
    print("3. Работа со стурктурой Киносериал (файл КлепацкийЛаб20_1.txt)\n");
    print("4. Работа со стурктурой Киносериал в бинарном файле (файл КлепацкийЛаб20_1.bin)\n");
    print("5. Работа с дозаписью текста (файл КлепацкийЛаб20_3.txt)\n");
    print("6. Выйти из программы.\n");
}
