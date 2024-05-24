#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString Task = "1 Записать абзац в файл\n"
                   "2 Считать абзац с файла и распечатать\n"
                   "3 Записать массив в файл\n"
                   "4 Считать массив с файла и распечатать\n"
                   "5 Записать структуру в файл\n"
                   "6 Считать структуры с файла и распечатать\n"
                   "7 Записать предложение в файл\n"
                   "8 Считать предложение с файла и распечатать\n"
                   "9 Записать структуру в бинарный файл\n"
                   "10 Считать структуру с бинарного файла и распечатать\n";

    QFont font = ui->label->font();
    font.setPixelSize(20);
    ui->label->setFont(font);
    ui->label->setText(Task);
    ui->textEdit->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MainFunc()
{
    QStringList List;
    QDataStream in(&File);
    QString s;
    NumbOfCommand = NowStr.toInt();
    switch (NumbOfCommand) {
    case 1:
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите абзац. Для завершения ввода нажмите Enter\n");
        break;
    case 2:
        File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/Abzaz.txt");
        File.open(QIODevice::ReadOnly);
        s = File.readAll();
        File.close();
        ui->textEdit->setText(ui->textEdit->toPlainText() + s + '\n');
        NumbOfCommand = 0;
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
        break;
    case 3:
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите элементы масива. Для разделения используйте }\n");
        break;
    case 4:
        File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/arr.txt");
        File.open(QIODevice::ReadOnly);
        s = File.readAll();
        List = s.split("}");
        for (int i = 0; i < List.size(); ++i){
            ui->textEdit->setText(ui->textEdit->toPlainText() + List[i] + ' ');
        }
        File.close();
        ui->textEdit->setText(ui->textEdit->toPlainText() + '\n');
        NumbOfCommand = 0;
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
        break;
    case 5:
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите поля струтуры через |\n");
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Структура содержит следующие поля: Наличие батареи(true/false), Класс защиты(1-5), Количество стрелок(3-8), Радиус(дробное число 5 - 10), Название фирмы, Зависимость цены от количества драг. камней (5 элементов в формате {1,2,3,4,5} от 1 до 1000)\n");
        break;
    case 6:
        File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/Struct.txt");
        File.open(QIODevice::ReadOnly);
        s = File.readAll();
        List = s.split("\n");
        for (int i = 0; i < List.size(); ++i){
            ui->textEdit->setText(ui->textEdit->toPlainText() + List[i]);
            if (i != List.size() -1){
                ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
            }
        }
        File.close();
        NumbOfCommand = 0;
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
        break;
    case 7:
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите предложение. Для завершения ввода нажмите Enter\n");
        break;
        break;
    case 8:
        File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/Offer.txt");
        File.open(QIODevice::ReadOnly);
        s = File.readAll();
        File.close();
        ui->textEdit->setText(ui->textEdit->toPlainText() + s);
        NumbOfCommand = 0;
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
        break;
    case 9:
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите поля струтуры через |\n");
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Структура содержит следующие поля: Наличие батареи(true/false), Класс защиты(1-5), Количество стрелок(3-8), Радиус(дробное число 5 - 10), Название фирмы, Зависимость цены от количества драг. камней (5 элементов в формате {1,2,3,4,5} от 1 до 1000)\n");
        break;
    case 10:
        File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/bin.txt");
        File.open(QIODevice::ReadOnly);
        in >> s;
        ui->textEdit->setText(ui->textEdit->toPlainText() + s + "\n");
        File.close();
        NumbOfCommand = 0;
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
        break;
    default:
        ui->textEdit->setText(ui->textEdit->toPlainText() + "Неизвестная команда\n");
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == 16777219){
        if (ui->textEdit->toPlainText().size() > 0){
            QString str = ui->textEdit->toPlainText();
            str.erase(str.end()- 1);
            NowStr.erase(NowStr.end() - 1);
            ui->textEdit->setText(str);
        }
    }
    else if (event->key() == 16777220){
        if (NumbOfCommand == 0){
            ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
            MainFunc();
        }
        else{
            QStringList List;
            QStringList List2;
            QTextStream out(&File);
            QDataStream out2(&File);

            switch (NumbOfCommand) {
            case 1:
                File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/Abzaz.txt");
                File.open(QIODevice::WriteOnly);
                out << NowStr;
                File.close();
                ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Записано\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                NowStr.clear();
                break;
            case 3:
                List = NowStr.split("}");
                File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/arr.txt");
                foreach (QString i, List) {
                    bool a;
                    i.toDouble(&a);
                    if (!a){
                        ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                        NumbOfCommand = 0;
                        NowStr.clear();
                        return;
                    }
                }
                File.open(QIODevice::WriteOnly);
                out << NowStr;
                File.close();
                ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Записано\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                NowStr.clear();
                break;
            case 5:
                File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/Struct.txt");
                List = NowStr.split("|");
                if (List.size() != 6){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[0] != "true" && List[0]!= "false"){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[1].toInt() < 1 || List[1].toInt() > 5){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[2].toInt() < 3 || List[2].toInt() > 8){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[3].toDouble() < 5 || List[3].toDouble() > 10){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                List[5].erase(List[5].begin(), List[5].begin()+ 1);
                List[5].erase(List[5].end() - 1);
                List2 = List[5].split(",");
                for (int i = 0; i < List2.size(); ++i){
                    if (List2[i].toInt() < 1 || List2[i].toInt() > 1000){
                        ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                        NumbOfCommand = 0;
                        NowStr.clear();
                        return;
                    }
                }
                File.open(QIODevice::Append);
                NowStr.push_front("\n");
                out << NowStr;
                File.close();
                ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Записано\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                NowStr.clear();
                break;
            case 7:
                File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/Offer.txt");
                File.open(QIODevice::Append);
                out << NowStr + "\n";
                File.close();
                ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Записано\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                NowStr.clear();
                break;
            case 9:
                File.setFileName("/home/stepan/Labs OAIP/6/2/Lab6Task2/bin.txt");
                File.open(QIODevice::Append);
                List = NowStr.split("|");
                if (List.size() != 6){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[0] != "true" && List[0]!= "false"){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[1].toInt() < 1 || List[1].toInt() > 5){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[2].toInt() < 3 || List[2].toInt() > 8){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                if (List[3].toDouble() < 5 || List[3].toDouble() > 10){
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                    ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                    NumbOfCommand = 0;
                    NowStr.clear();
                    return;
                }
                List[5].erase(List[5].begin(), List[5].begin()+ 1);
                List[5].erase(List[5].end() - 1);
                List2 = List[5].split(",");
                for (int i = 0; i < List2.size(); ++i){
                    if (List2[i].toInt() < 1 || List2[i].toInt() > 1000){
                        ui->textEdit->setText(ui->textEdit->toPlainText() + "\nВведены неверные данные\n");
                        ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                        NumbOfCommand = 0;
                        NowStr.clear();
                        return;
                    }
                }
                File.open(QIODevice::Append);
                NowStr.push_front("\n");
                out2 << NowStr;
                File.close();
                ui->textEdit->setText(ui->textEdit->toPlainText() + "\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Записано\n");
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Введите комманду\n");
                NowStr.clear();
                break;
            default:
                ui->textEdit->setText(ui->textEdit->toPlainText() + "Неизвестная команда\n");
                break;
            }
            NumbOfCommand = 0;
        }
        NowStr.clear();
    }
    else{
        ui->textEdit->setText(ui->textEdit->toPlainText() + event->text());
        NowStr += event->text();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    File.close();
    event->accept();
}


