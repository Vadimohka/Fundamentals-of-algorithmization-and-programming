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

    do
    {
        isIncorrect = false;

        QString str = input();
        bool ok;
        int number = str.toInt(&ok);

        if(!ok)
        {
            print("Ввод совершен некорректно, потворите\n");
            isIncorrect = true;
        }
        else
        {
            return number;
        }

    }while(isIncorrect);
}

double MainWindow::inputDouble()
{
    bool isIncorrect;

    do
    {
        isIncorrect = false;

        QString str = input();
        bool ok;
        double number = str.toDouble(&ok);

        if(!ok)
        {
            print("Ввод совершен некорректно, потворите\n");
            isIncorrect = true;
        }
        else
        {
            return number;
        }

    }while(isIncorrect);
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

    do
    {
        printMenu();
        isNotExit = true;

        int number = inputInt();

        while(number < 1 || number > 6)
        {
            print("Нет такого пункта в меню, введите повторно!\n");
            number = inputInt();
        }

        switch(number)
        {
        case 1:
        {
            runFirstPunkt();
            break;
        }
        case 2:
        {
            runSecondPunkt();
            break;
        }
        case 3:
        {
            runThirdPunkt();
            break;
        }
        case 4:
        {
            runFourthPunkt();
            break;
        }
        case 5:
        {
            runFifthPunkt();
            break;
        }
        case 6:
        {
            isNotExit = false;
            close();
            break;
        }
        default:
        {
            break;
        }
        }

    } while(isNotExit);
}

void MainWindow::runFirstPunkt()
{
    bool isNotExit;

    do
    {
        isNotExit = true;


        print("1. Ввести текст до нажатия Enter для перезаписи файла.\n");
        print("2. Вывести текст из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while(num < 1 || num > 3)
        {
            print("Нет такого пункта в меню, введите повторно!\n");
        }

        switch(num)
        {
        case 1:
        {
            print("Введите текст до нажатия Enter.\n");
            QString text = input();

            QFile file("../../АнуфриевЛаб20.txt");
            if (!file.open(QIODevice::WriteOnly)) {
                return;
            }
            QTextStream out(&file);

            for(size_t i = 0; i < text.size(); i++)
            {
                out << text[i];
            }

            file.close();

            break;
        }
        case 2:
        {
            QFile file("../../АнуфриевЛаб20.txt");
            if (!file.open(QIODevice::ReadOnly)) {
                return;
            }
            QTextStream in(&file);

            print("Текст в файле: \n");

            file.seek(0);
            while(!in.atEnd())
            {
                QString character = in.read(1);
                print(character);
            }

            print('\n');
            file.flush();
            file.close();

            break;
        }
        case 3:
        {
            isNotExit = false;
            break;
        }
        }

    } while(isNotExit);

}

void MainWindow::runSecondPunkt()
{

    bool isNotExit;

    do
    {
        print("1. Ввести массив для перезаписи файла.\n");
        print("2. Вывести массив из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while(num < 1 || num > 3)
        {
            print("Нет такого пункта в меню, введите повторно!\n");
        }

        switch(num)
        {
        case 1:
        {
            print("Введите число элементов массива типа int:\n");

            int size;

            QFile file("../../АнуфриевЛаб20_0.txt");
            if (!file.open(QIODevice::WriteOnly)) {
                return;
            }
            QTextStream out(&file);

            size = inputInt();

            int* array = new int[size];

            int element;

            for(int i = 0; i < size; i++)
            {
                print("Введите " + QString::number(i + 1) + "-й элемент: \n");

                element = inputInt();

                array[i] = element;
                out << element << "\\";
            }

            file.close();

            break;
        }
        case 2:
        {
            QFile file("../../АнуфриевЛаб20_0.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                return;
            }
            QTextStream in(&file);

            QString elements;

            in >> elements;

            QStringList numbers = elements.split("\\");

            foreach(const QString &number, numbers) {
                print(number + ' ');
            }

            print("\n");

            file.close();

            break;
        }
        case 3:
        {
            isNotExit = false;
            break;
        }
        }
    } while(isNotExit);

}

void MainWindow::runThirdPunkt()
{

    bool isNotExit;

    do
    {
        print("1. Ввести поля структуры спортсмен для дозаписи в файл.\n");
        print("2. Вывести записанные структуры из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while(num < 1 || num > 3)
        {
            print("Нет такого пункта в меню, введите повторно!\n");
            num = inputInt();
        }

        isNotExit = true;
        switch(num)
        {
        case 1:
        {
            QFile file("../../АнуфриевЛаб20_1.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                return;
            }
            QTextStream out(&file);

            int age = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double weight = 1;
            QString sex = "m", isJock = "y", name = "name";

            print("Введите возраст спортсмена: \n");
            do
            {
                if(age <= 0 || age > 140) print("Ввод некорректный! Повторите ввод: \n");
                age = inputInt();
            } while(age <= 0 || age > 140);

            print("Введите вес спортсмена: \n");
            do
            {
                if(weight <= 0 || weight > 200) print("Ввод некорректный! Повторите ввод: \n");
                weight = inputDouble();
            } while(weight <= 0 || weight > 200);

            print("Введите пол спортсмена (m/f): \n");
            do
            {
                if(sex != "f" && sex != "m") print("Ввод некорректный! Повторите ввод: \n");
                sex = input();
            } while(sex != "f" && sex != "m");

            print("Введите накаченного ли телосложения спортсмен (y/n): \n");
            do
            {
                if(isJock != "y" && isJock != "n") print("Ввод некорректный! Повторите ввод: \n");
                isJock = input();
            } while(isJock != "y" && isJock != "n");

            print("Введите имя спортсмена: \n");
            do
            {
                if(name.size() == 0 || name.size() > 20) print("Ввод некорректный! Повторите ввод: \n");
                name = input();
            } while(name.size() == 0 || name.size() > 20);

            print("Введите кол-во золотых медалей спортсмена: \n");
            do
            {
                if(goldMedals < 0) print("Ввод некорректный! Повторите ввод: \n");
                goldMedals = inputInt();
            } while(goldMedals < 0);

            print("Введите кол-во серебрянных медалей спортсмена: \n");
            do
            {
                if(silverMedals < 0) print("Ввод некорректный! Повторите ввод: \n");
                silverMedals = inputInt();
            } while(silverMedals < 0);

            print("Введите кол-во бронзовых медалей спортсмена: \n");
            do
            {
                if(bronzeMedals < 0) print("Ввод некорректный! Повторите ввод: \n");
                bronzeMedals = inputInt();
            } while(bronzeMedals < 0);


            out << age << ' ' << weight << ' ' << sex << ' ' << (isJock == "y" ? "true" : "false") << ' '
                << name << ' ' << goldMedals << ' ' << silverMedals << ' ' << bronzeMedals << '\n';

            file.close();

            print("Данные спортсмена успешно дозаписаны в файл.\n");

            break;
        }
        case 2:
        {
            QFile file("../../АнуфриевЛаб20_1.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                return;
            }
            QTextStream in(&file);

            int age = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double weight = 1;
            QString sex = "m", isJock = "y", name = "name";

            print("Данные файла: \n");

            while(!in.atEnd())
            {
                in >> age >> weight >> sex >> isJock >> name >> goldMedals >> silverMedals >> bronzeMedals;

                if(sex != "" && isJock != "")
                {
                    print(QString::number(age) + '|' + QString::number(weight) + '|' + sex + '|' + isJock
                          + '|' + name + '|' + QString::number(goldMedals) + ',' + QString::number(silverMedals) + ',' + QString::number(bronzeMedals) + '\n');
                }
            }

            file.close();

            break;
        }
        case 3:
        {
            isNotExit = false;
        }
        }
    }while(isNotExit);


}

void MainWindow::runFourthPunkt()
{
    bool isNotExit;

    do
    {
        isNotExit = true;

        print("1. Ввести поля структуры спортсмен для дозаписи в бинарный файл.\n");
        print("2. Вывести записанные структуры из бинарного файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while(num < 1 || num > 3)
        {
            print("Нет такого пункта в меню, введите повторно!\n");
            num = inputInt();
        }

        switch(num)
        {
        case 1:
        {
            QFile file("../../АнуфриевЛаб20_1.bin");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                return;
            }
            QDataStream OUT(&file);
            QTextStream out(&file);

            int age = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double weight = 1;
            QString sex = "m", isJock = "y", name = "name";

            print("Введите возраст спортсмена: \n");
            do
            {
                if(age <= 0 || age > 140) print("Ввод некорректный! Повторите ввод: \n");
                age = inputInt();
            } while(age <= 0 || age > 140);

            print("Введите вес спортсмена: \n");
            do
            {
                if(weight <= 0 || weight > 200) print("Ввод некорректный! Повторите ввод: \n");
                weight = inputDouble();
            } while(weight <= 0 || weight > 200);

            print("Введите пол спортсмена (m/f): \n");
            do
            {
                if(sex != "f" && sex != "m") print("Ввод некорректный! Повторите ввод: \n");
                sex = input();
            } while(sex != "f" && sex != "m");

            print("Введите накаченного ли телосложения спортсмен (y/n): \n");
            do
            {
                if(isJock != "y" && isJock != "n") print("Ввод некорректный! Повторите ввод: \n");
                isJock = input();
            } while(isJock != "y" && isJock != "n");

            print("Введите имя спортсмена: \n");
            do
            {
                if(name.size() == 0 || name.size() > 20) print("Ввод некорректный! Повторите ввод: \n");
                name = input();
            } while(name.size() == 0 || name.size() > 20);

            print("Введите кол-во золотых медалей спортсмена: \n");
            do
            {
                if(goldMedals < 0) print("Ввод некорректный! Повторите ввод: \n");
                goldMedals = inputInt();
            } while(goldMedals < 0);

            print("Введите кол-во серебрянных медалей спортсмена: \n");
            do
            {
                if(silverMedals < 0) print("Ввод некорректный! Повторите ввод: \n");
                silverMedals = inputInt();
            } while(silverMedals < 0);

            print("Введите кол-во бронзовых медалей спортсмена: \n");
            do
            {
                if(bronzeMedals < 0) print("Ввод некорректный! Повторите ввод: \n");
                bronzeMedals = inputInt();
            } while(bronzeMedals < 0);

            Sportsman sportsman;
            sportsman.age = age;
            sportsman.weight = weight;
            sportsman.sex = sex.toStdString()[0];
            sportsman.isJock = ((isJock == "true") ? true : false);

            strcpy(sportsman.name, name.toStdString().c_str());
            sportsman.medals[0] = goldMedals;
            sportsman.medals[1] = silverMedals;
            sportsman.medals[2] = bronzeMedals;

            OUT.writeRawData(reinterpret_cast<const char*>(&sportsman), sizeof(Sportsman));

            file.close();

            print("Данные спорстмена успешно дозаписаны в файл.\n");

            break;
        }
        case 2:
        {
            QFile file("../../АнуфриевЛаб20_1.bin");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                return;
            }
            QTextStream in(&file);
            QDataStream IN(&file);

            int age = 1, goldMedals = 0, silverMedals = 0, bronzeMedals = 0;
            double weight = 1;
            QString sex = "m", isJock = "y", name = "name";

            print("Данные файла: \n");


            Sportsman sportsman;

            while (file.read(reinterpret_cast<char*>(&sportsman), sizeof(Sportsman))) {
                age = sportsman.age;
                weight = sportsman.weight;
                sex = sportsman.sex;
                isJock = (sportsman.isJock ? "true" : "false");
                name = sportsman.name;
                goldMedals = sportsman.medals[0];
                silverMedals = sportsman.medals[1];
                bronzeMedals = sportsman.medals[2];

                if(sex != "" && isJock != "")
                {
                    print(QString::number(age) + " ; " + QString::number(weight) + " ; " + sex + " ; " + isJock
                          + " ; " + name + " ; " + QString::number(goldMedals) + ',' + QString::number(silverMedals) + ',' + QString::number(bronzeMedals) + '\n');
                }

            }

            file.close();
            break;
        }
        case 3:
        {
            isNotExit = false;
            break;
        }
        }

    } while(isNotExit);
}

void MainWindow::runFifthPunkt()
{
    bool isNotExit;

    do
    {
        isNotExit = true;


        print("1. Ввести текст до нажатия Enter для дозаписи в файл.\n");
        print("2. Вывести текст из файла.\n");
        print("3. Выйти в главное меню.\n");

        int num;

        num = inputInt();

        while(num < 1 || num > 3)
        {
            print("Нет такого пункта в меню, введите повторно!\n");
            num = inputInt();
        }

        switch(num)
        {
        case 1:
        {
            print("Введите текст до нажатия Enter.\n");
            QString text = input();

            QFile file("../../АнуфриевЛаб20_3.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                return;
            }
            QTextStream out(&file);

            out << text;

            file.close();

            break;
        }
        case 2:
        {
            QFile file("../../АнуфриевЛаб20_3.txt");
            if (!file.open(QIODevice::ReadOnly)) {
                return;
            }
            QTextStream in(&file);

            print("Текст в файле: \n");

            file.seek(0);
            while(!in.atEnd())
            {
                QString character = in.read(1);
                print(character);
            }

            print('\n');
            file.flush();
            file.close();

            break;
        }
        case 3:
        {
            isNotExit = false;
            break;
        }
        }

    } while(isNotExit);
}


void MainWindow::printMenu()
{
    print("\nМеню\n\n");
    print("1. Работа с перезаписью текста (файл АнуфриевЛаб20.txt)\n");
    print("2. Работа с массивом данных (файл АнуфриевЛаб20_0.txt)\n");
    print("3. Работа со стурктурой Спортсмен (файл АнуфриевЛаб20_1.txt)\n");
    print("4. Работа со стурктурой Спортсмен в бинарном файле (файл АнуфриевЛаб20_1.bin)\n");
    print("5. Работа с дозаписью текста (файл АнуфриевЛаб20_3.txt)\n");
    print("6. Выйти из программы.\n");
}
