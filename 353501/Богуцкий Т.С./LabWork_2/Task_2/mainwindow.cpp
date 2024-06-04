#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sortGroup->setText("Сортировка по\n убыванию ср.балла\n (по группе)");
    ui->sort->setText("Сортировка по\n убыванию ср.балла\n (все студенты)");

    connect(ui->search, &QPushButton::clicked, this, &MainWindow::openFinder);
    connect(ui->sortGroup, &QPushButton::clicked, this, &MainWindow::openGroup);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addStudent_clicked()
{
    List helper;
    int check = list_for_students.size();
    if (ui->comboBox->currentText()=="(Режим Добавления)")
    {try
    {
        helper.setName(ui->lineNAME->text());
        helper.setSurname(ui->lineSUR->text());
        helper.setDadsname(ui->lineDAD->text());
        helper.setspeciality(ui->lineSPEC->text());
        helper.setgroup(ui->lineGROUP->text());
        helper.setmarkMATH(ui->lineMATH->text());
        helper.setmarkEnglish(ui->lineENG->text());
        helper.setmarkProgramming(ui->linePROG->text());
        list_for_students.append(helper);
        if (check < list_for_students.size())
        {

            QString str = ui->lineNAME->text() + " "+ ui->lineSUR->text() +" " + ui->lineDAD->text() +" "+ ui->lineSPEC->text() +" "+ ui->lineGROUP->text() +" "+ ui->lineMATH->text() +" "+ ui->linePROG->text()  +" "+ ui->lineENG->text()+" ";

            QFile file (reserv);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                QTextStream out(&file);
                out << str << Qt::endl;
                file.close();
            }

            ui->lineNAME->clear();
            ui->lineSUR->clear();
            ui->lineDAD->clear();
            ui->lineSPEC->clear();
            ui->lineGROUP->clear();
            ui->lineMATH->clear();
            ui->lineENG->clear();
            ui->linePROG->clear();
            QMessageBox::information(this, "Успех", "Новый студент успешно добавлен в ведомость");
        }

        QString help_string = nullptr;
        List helper;
        ui->comboBox->clear();
        ui->comboBox->addItem("");
        ui->comboBox->addItem("(Режим Добавления)");
        ui->textBrowser->clear();
        ALLOW = false;
        list_for_students.clear();
    }
    catch (...)
    {
        QMessageBox::critical(this, "Ошибка", "Что-то пошло не так");
    }
    }
    else QMessageBox::critical(this, "Ошибка", "Что-то пошло не так");
}

void MainWindow::on_chooseFile_clicked()
{
    QString help_string = nullptr;
    List helper;
    ui->comboBox->clear();
    ui->comboBox->addItem("");
    ui->comboBox->addItem("(Режим Добавления)");
    ALLOW = false;
    list_for_students.clear();

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
    if (!fileName.isEmpty()) {
        reserv = fileName;
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                bool h1 = true, h2 = true, h3 = true, h4 = true, h5 = true, h6 = true, h7 = true;
                int counter_spaces = 0;
                QString line = in.readLine();
                for (int i = 0; i < line.size(); i++)
                {
                    help_string += line[i];
                    if (line[i]==" ")
                    {
                        help_string.remove(' ');
                        counter_spaces++;
                    }
                    if (counter_spaces == 1 && h1)
                    {
                        helper.Name = help_string;
                        help_string = nullptr;
                        h1 = false;
                    }

                    else if (counter_spaces == 2 && h2)
                    {
                        helper.Surname = help_string;
                        help_string = nullptr;
                        h2 = false;

                    }
                    else if (counter_spaces == 3 && h3)
                    {
                        helper.Dadsname = help_string;
                        help_string = nullptr;
                        h3 = false;
                    }
                    else if (counter_spaces == 4 && h4)
                    {
                        helper.speciality = help_string;
                        help_string = nullptr;
                        h4 = false;
                    }
                    else if (counter_spaces == 5 && h5)
                    {
                        helper.group = help_string.toInt();
                        help_string = nullptr;
                        h5 = false;
                    }
                    else if (counter_spaces == 6 && h6)
                    {
                        helper.markMATH = help_string.toInt();
                        help_string = nullptr;
                        h6 = false;
                    }
                    else if (counter_spaces == 7 && h7)
                    {
                        helper.markProgramming = help_string.toInt();
                        help_string = nullptr;
                        h7 = false;
                    }
                    else if (counter_spaces == 8)
                    {
                        helper.markEnglish = help_string.toInt();
                        help_string = nullptr;
                        list_for_students.append(helper);
                    }

                }
                ALLOW = true;
                qDebug() << "Прочитано из файла:" << line;
            }
            file.close();
        }
    }
    for (int i = 0; i < list_for_students.size(); i++)
    {
        ui->comboBox->addItem(list_for_students[i].Surname + "." + list_for_students[i].Name[0] + "." + list_for_students[i].Dadsname[0]);
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QString str = arg1, help_string = nullptr;

    if (str == "")
    {
        ui->lineNAME->clear(); ui->lineNAME->setReadOnly(true);
        ui->lineSUR->clear(); ui->lineSUR->setReadOnly(true);
        ui->lineDAD->clear(); ui->lineDAD->setReadOnly(true);
        ui->lineSPEC->clear(); ui->lineSPEC->setReadOnly(true);
        ui->lineGROUP->clear(); ui->lineGROUP->setReadOnly(true);
        ui->lineMATH->clear(); ui->lineMATH->setReadOnly(true);
        ui->lineENG->clear(); ui->lineENG->setReadOnly(true);
        ui->linePROG->clear(); ui->linePROG->setReadOnly(true);
        ui->lineEVG->clear(); ui->lineEVG->setReadOnly(true);
    }
    else if (str == "(Режим Добавления)")
    {
        ui->lineNAME->clear(); ui->lineNAME->setReadOnly(false);
        ui->lineSUR->clear(); ui->lineSUR->setReadOnly(false);
        ui->lineDAD->clear(); ui->lineDAD->setReadOnly(false);
        ui->lineSPEC->clear(); ui->lineSPEC->setReadOnly(false);
        ui->lineGROUP->clear(); ui->lineGROUP->setReadOnly(false);
        ui->lineMATH->clear(); ui->lineMATH->setReadOnly(false);
        ui->lineENG->clear(); ui->lineENG->setReadOnly(false);
        ui->linePROG->clear(); ui->linePROG->setReadOnly(false);
        ui->lineEVG->clear(); ui->lineEVG->setReadOnly(true);
    }
    else
    {
        // получаем фамилию из формата combobox Фамилия.Имя.Отчество.
        for (QString i : str)
        {
            help_string += i;
            if (i == '.')
            {
                help_string.remove('.');
                break;
            }
        }

        for(int i = 0 ; i < list_for_students.size(); i++)
        {
            if (list_for_students[i].Surname == help_string)
            {
                ui->lineNAME->setText(list_for_students[i].Name); ui->lineNAME->setReadOnly(true);
                ui->lineSUR->setText(list_for_students[i].Surname); ui->lineSUR->setReadOnly(true);
                ui->lineDAD->setText(list_for_students[i].Dadsname); ui->lineDAD->setReadOnly(true);
                ui->lineSPEC->setText(list_for_students[i].speciality); ui->lineSPEC->setReadOnly(true);
                ui->lineGROUP->setText(QString::number(list_for_students[i].group)); ui->lineGROUP->setReadOnly(true);
                ui->lineMATH->setText(QString::number(list_for_students[i].markMATH)); ui->lineMATH->setReadOnly(true);
                ui->lineENG->setText(QString::number(list_for_students[i].markEnglish)); ui->lineENG->setReadOnly(true);
                ui->linePROG->setText(QString::number(list_for_students[i].markProgramming)); ui->linePROG->setReadOnly(true);
                ui->lineEVG->setText(QString::number(list_for_students[i].averageScore())); ui->lineEVG->setReadOnly(true);
                help_string = nullptr;
                break;
            }
        }
    }
}

void MainWindow::openFinder()
{
    if (ALLOW){
    FindStudent dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        name_find = dialog.get_name();
        surname_find = dialog.get_surname();
        dadsname_find = dialog.get_dadsname();
        for (int i = 0; i<list_for_students.size(); i++)
        {
            if (list_for_students[i].Name == name_find && list_for_students[i].Surname == surname_find && list_for_students[i].Dadsname == dadsname_find)
            {
               QString str = nullptr;
               str = "Найден студент: \n\n" + list_for_students[i].Name + "\n" + list_for_students[i].Surname +
               "\n" + list_for_students[i].Dadsname + "\n" + "Специальность: " + list_for_students[i].speciality +
               "\n" + "Группа: "+ QString::number(list_for_students[i].group) + "\n" + "Математика: " +
               QString::number(list_for_students[i].markMATH) + "\n" + "Анлийский: " +
               QString::number(list_for_students[i].markEnglish) + "\n" + "Программирование: " +
               QString::number(list_for_students[i].markProgramming) +"\n" +
               "Средняя оценка: " + QString::number(list_for_students[i].averageScore());
               ui->textBrowser->setText(str);
               break;
            }
            else if (i == list_for_students.size()-1)
            {
                ui->textBrowser->setText("Студент под таким Ф.И.О. не найден");
            }
        }
    }
    }
    else QMessageBox::critical(this, "Ошибка", "Файл не выбран");
}

void MainWindow::openGroup()
{
    if (ALLOW){
    GroupSort dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        groupname = dialog.get_name();
        QVector <List> helper;
        for (int i = 0; i<list_for_students.size(); i++)
        {
            if (QString::number(list_for_students[i].group) == groupname) helper.append(list_for_students[i]);
        }

        int n = helper.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (helper[j].averageScore() < helper[j + 1].averageScore()) {
                    std::swap(helper[j], helper[j + 1]);
                }
            }
        }

        int num = 0;
        QString str = "Отсортированный список студентов по группам (по убыванию ср.балла): ";

        for (int i = 0; i < helper.size(); i++)
        {
            num++;
            str += "\n" + QString::number(num) + ") " + helper[i].Name +" "+ helper[i].Surname +
            + " " + helper[i].Dadsname + "\n"+ "Специальность: " + helper[i].speciality +
            "   Группа: " + QString::number(helper[i].group) + "\n" + "Мат: " +
            QString::number(helper[i].markMATH) + "  Англ: " +
            QString::number(helper[i].markEnglish) + "   Прог: " +
            QString::number(helper[i].markProgramming) +
            "   Сред: " + QString::number(helper[i].averageScore()) + "\n";
        }
        ui->textBrowser->setText(str);
    }
    }
    else QMessageBox::critical(this, "Ошибка", "Файл не выбран");
}

void MainWindow::on_listStudents_clicked()
{
    if (ALLOW)
    {
    QString str = nullptr;
    int num = 0;
    bool flag = true;
    str = "Список студентов БЕЗ неудовлетворительных оценок за сессию:";
    for (int i = 0; i < list_for_students.size(); i++)
    {
        if (list_for_students[i].markMATH >=4 && list_for_students[i].markEnglish >=4 && list_for_students[i].markProgramming >=4)
        {
            num++;
            flag = false;
            str += "\n" + QString::number(num) + ") " + list_for_students[i].Name +" "+ list_for_students[i].Surname +
            + " " + list_for_students[i].Dadsname + "\n"+ "Специальность: " + list_for_students[i].speciality +
            "   Группа: " + QString::number(list_for_students[i].group) + "\n" + "Мат: " +
            QString::number(list_for_students[i].markMATH) + "  Англ: " +
            QString::number(list_for_students[i].markEnglish) + "   Прог: " +
            QString::number(list_for_students[i].markProgramming) +
            "   Сред: " + QString::number(list_for_students[i].averageScore()) + "\n";
        }
    }
    if (flag)
    {
        str += "\nИх нет.";
    }
    ui->textBrowser->setText(str);
    }
    else QMessageBox::critical(this, "Ошибка", "Файл не выбран");
}

void MainWindow::on_sort_clicked()
{
    if (ALLOW)
    {
    int n = list_for_students.size();
    QVector <List> helper = list_for_students;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (helper[j].averageScore() < helper[j + 1].averageScore()) {
                std::swap(helper[j], helper[j + 1]);
            }
        }
    }

    int num = 0;
    QString str = "Отсортированный список студентов по убыванию ср.балла: ";

    for (int i = 0; i < list_for_students.size(); i++)
    {
        num++;
        str += "\n" + QString::number(num) + ") " + helper[i].Name +" "+ helper[i].Surname +
        + " " + helper[i].Dadsname + "\n"+ "Специальность: " + helper[i].speciality +
        "   Группа: " + QString::number(helper[i].group) + "\n" + "Мат: " +
        QString::number(helper[i].markMATH) + "  Англ: " +
        QString::number(helper[i].markEnglish) + "   Прог: " +
        QString::number(helper[i].markProgramming) +
        "   Сред: " + QString::number(helper[i].averageScore()) + "\n";
    }
    ui->textBrowser->setText(str);
    }
    else QMessageBox::critical(this, "Ошибка", "Файл не выбран");
}

