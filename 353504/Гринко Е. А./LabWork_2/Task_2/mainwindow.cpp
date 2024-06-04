#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression re("[0-9]{1}");

    ui->mathW->setValidator(new QRegularExpressionValidator(re, ui->mathW));
    ui->progW->setValidator(new QRegularExpressionValidator(re, ui->progW));
    ui->histW->setValidator(new QRegularExpressionValidator(re, ui->histW));
    ui->mathS->setValidator(new QRegularExpressionValidator(re, ui->mathS));
    ui->progS->setValidator(new QRegularExpressionValidator(re, ui->progS));
    ui->histS->setValidator(new QRegularExpressionValidator(re, ui->histS));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    ui->Output->clear();
    path = QFileDialog::getOpenFileName();
    file.setFileName(path);
    if (file.exists())
    {
        file.open(QIODevice::ReadWrite);
        s = file.readAll();
        ui->Output->setText("File open");
    }
    else
    {
        ui->Output->setText("File not open");
    }
    int i = 0;
    while (i < s.length())
    {
        int group = s.mid(i, 6).toInt();
        i += 7;
        QString fio = "";
        for (int j = 0; j != 3; ++i)
        {
            if (s[i] == ' ')
            {
                ++j;
            }
            fio += s[i];
        }
        while (!s[i].isDigit())
        {
            ++i;
        }
        int math1 = s.mid(i, 1).toInt();
        ++i;
        while (!s[i].isDigit())
        {
            ++i;
        }
        int prog1 = s.mid(i, 1).toInt();
        ++i;
        while (!s[i].isDigit())
        {
            ++i;
        }
        int hist1 = s.mid(i, 1).toInt();
        ++i;
        while (!s[i].isDigit())
        {
            ++i;
        }
        int math2 = s.mid(i, 1).toInt();
        ++i;
        while (!s[i].isDigit())
        {
            ++i;
        }
        int prog2 = s.mid(i, 1).toInt();
        ++i;
        while (!s[i].isDigit())
        {
            ++i;
        }
        int hist2 = s.mid(i, 1).toInt();
        i += 2;
        students.append(Student(group, fio, math1, prog1, hist1, math2, prog2, hist2));
    }
    ui->debtors->setRowCount(students.length());
    ui->Dismiss->setRowCount(students.length());
    ui->students->setRowCount(students.length());

}


void MainWindow::on_DebtorsList_clicked()
{
    ui->Output->clear();
    if (file.isOpen())
    {
        for (int i = 0, j = 0; i < students.size(); ++i)
        {
            if (students[i].w_math < 4 || students[i].w_prog < 4 || students[i].w_history < 4)
            {
                ui->debtors->setItem(j, 0, new QTableWidgetItem(students[i].printFio()));
                ++j;
            }
        }
    }
    else
    {
        ui->Output->setText("File not open");
    }
}


void MainWindow::on_DismissList_clicked()
{
    ui->Output->clear();
    if(file.isOpen())
    {
        for (int i = 0, j = 0; i < students.size(); ++i)
        {
            if ((students[i].w_math < 4 || students[i].w_prog < 4 || students[i].w_history < 4) &&
                ((students[i].s_math < 4 && students[i].s_prog < 4) ||
                 (students[i].s_history < 4 && students[i].s_prog < 4) ||
                 (students[i].s_history < 4 && students[i].s_math < 4)))
            {
                ui->Dismiss->setItem(j, 0, new QTableWidgetItem(students[i].printFio()));
                ++j;
            }
        }
    }
    else
    {
        ui->Output->setText("File not open");
    }
}


void MainWindow::on_StudentsList_clicked()
{
    ui->Output->clear();
    if (file.isOpen())
    {
        for (int i = 0; i < students.size(); ++i)
        {
            ui->students->setItem(i, 0, new QTableWidgetItem(QString::number(students[i].numOfGroup_)));
            ui->students->setItem(i, 1, new QTableWidgetItem(students[i].printFio()));
            ui->stud->addItem(students[i].printFio());
        }
    }
    else
    {
        ui->Output->setText("File not open");
    }
}


void MainWindow::on_sort_clicked()
{
    ui->Output->clear();
    if (file.isOpen())
    {
        QVector<Student> st0;
        QVector<Student> st1;
        QVector<Student> st2;
        QStringList fio0;
        QStringList fio1;
        QStringList fio2;
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].numOfGroup_ % 10 == 0)
            {
                st0.append(students[i]);
            }
            else if (students[i].numOfGroup_ % 10 == 1)
            {
                st1.append(students[i]);
            }
            else if (students[i].numOfGroup_ % 10 == 2)
            {
                st2.append(students[i]);
            }
        }
        students.clear();
        for (int i = 0; i < st0.size(); ++i)
        {
            fio0.append(st0[i].printFio());
        }
        std::sort(fio0.begin(), fio0.end());
        for (int i = 0; i < st1.size(); ++i)
        {
            fio1.append(st1[i].printFio());
        }
        std::sort(fio1.begin(), fio1.end());
        for (int i = 0; i < st2.size(); ++i)
        {
            fio2.append(st2[i].printFio());
        }
        std::sort(fio2.begin(), fio2.end());
        for (int i = 0; i < st0.size(); ++i)
        {
            for (int j = 0; j < st0.size(); ++j)
            {
                if (st0[j].fio_ == fio0[i])
                {
                    students.append(st0[j]);
                }
            }
        }
        for (int i = 0; i < st1.size(); ++i)
        {
            for (int j = 0; j < st1.size(); ++j)
            {
                if (st1[j].fio_ == fio1[i])
                {
                    students.append(st1[j]);
                }
            }
        }
        for (int i = 0; i < st2.size(); ++i)
        {
            for (int j = 0; j < st2.size(); ++j)
            {
                if (st2[j].fio_ == fio2[i])
                {
                    students.append(st2[j]);
                }
            }
        }
        ui->stud->clear();
    }
    else
    {
        ui->Output->setText("File not open");
    }
}

void MainWindow::on_stud_activated(int index)
{
    ui->Output->clear();
    if (file.isOpen())
    {
        ui->name->setText(students[index].printFio());
        ui->group->setText(QString::number(students[index].numOfGroup_));
        double wintMark = (students[index].w_history + students[index].w_math + students[index].w_prog) / 3.0;
        double sumMark = (students[index].s_history + students[index].s_math + students[index].s_prog) / 3.0;
        ui->summer->setText("summer session: " + QString::number(sumMark));
        ui->winter->setText("winter session: " + QString::number(wintMark));
    }
    else
    {
        ui->Output->setText("File not open");
    }
}


void MainWindow::on_add_clicked()
{
    Student s;
    if (file.isOpen())
    {
        QTextStream stream(&file);
        newStudent = ui->newStud->text();
        QString group = newStudent.mid(0, 6);
        if (group[5].isDigit())
        {
            s.numOfGroup_ = group.toInt();
        }
        QString fio = newStudent.mid(7, newStudent.length() - 7);
        s.fio_ = fio;
        students.append(Student(s));

        s.w_math = ui->mathW->text().toInt();
        s.w_prog = ui->progW->text().toInt();
        s.w_history = ui->histW->text().toInt();
        s.s_math = ui->mathS->text().toInt();
        s.s_prog = ui->progS->text().toInt();
        s.s_history = ui->histS->text().toInt();
        if (s.s_history != 0 && s.s_prog != 0 && s.s_math != 0 && s.w_history != 0 && s.w_prog != 0 && s.w_math != 0)
        {
            stream << QString::number(s.numOfGroup_) + ' ' + s.fio_ << ' ' << "mathw: " << s.w_math << " progw: " <<
                s.w_prog << " historyw: " << s.w_history << " maths: " << s.s_math << " progs: " << s.s_prog << " historys: " << s.s_history;
            ui->newStud->clear();
            ui->mathS->clear();
            ui->progS->clear();
            ui->histS->clear();
            ui->mathW->clear();
            ui->progW->clear();
            ui->histW->clear();
        }
    }
    else
    {
        ui->Output->setText("File not open");
    }
}
