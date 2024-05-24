#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <set>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("QLineEdit:disabled, QSpinBox:disabled, QPushButton:disabled,"
                  " QComboBox:disabled, QListWidget:disabled { background-color: #D3D3D3; }");

    comboFilterUpdate();

    connect(ui->listWidget, &QListWidget::itemSelectionChanged, [=](){
        if(ui->listWidget->selectedItems().size() == 0)
        {
            ui->editButton->setEnabled(false);
            ui->deleteButton->setEnabled(false);
        }
        else
        {
            ui->editButton->setEnabled(true);
            ui->deleteButton->setEnabled(true);
        }
    } );

    connect(ui->comboGroups, &QComboBox::currentTextChanged, [=](){

        ui->listWidget->clear();

        if(ui->comboGroups->currentText() == "Все группы")
        {
            printStudentsInListWidget();
        }

        else if(ui->comboGroups->currentText() == "С уд. оценками")
        {
            for(int i = 0; i < studentsList.size(); i++)
            {
                if(studentsList[i].getAgila() >= 4 && studentsList[i].getMatan() >= 4
                && studentsList[i].getDm() >= 4 && studentsList[i].getHist() >= 4 && studentsList[i].getOaip() >= 4)
                {
                    Student st = studentsList[i];

                    ui->listWidget->addItem("(" + studentsList[i].getGroup() + ") "
                                            + studentsList[i].getFIO()
                                            + " — " + QString::number(studentsList[i].getAvgMark()));
                }
            }
        }

        else
        {
            for(int i = 0; i < studentsList.size(); i++)
            {
                if(ui->comboGroups->currentText() == studentsList[i].getGroup())
                {
                    Student st = studentsList[i];

                    ui->listWidget->addItem("(" + studentsList[i].getGroup() + ") "
                                            + studentsList[i].getFIO()
                                            + " — " + QString::number(studentsList[i].getAvgMark()));
                }

            }
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    if(openedFile && openedFile->isOpen()) openedFile->close();
    close();
}

void MainWindow::on_openButton_clicked()
{
    openedFileName = QFileDialog::getOpenFileName(this, "Выберите файл", "/home/deviyan/QTprojects/LabWork2/", "Текстовые файлы (*.txt)");
    openedFile = new QFile(openedFileName);

    if(openedFile->open(QIODevice::ReadWrite))
    {
        ui->addButton->setEnabled(true);
        ui->findButton->setEnabled(true);
        ui->saveButton->setEnabled(true);
        ui->sortButton->setEnabled(true);

        ui->listWidget->setEnabled(true);

        QTextStream in(openedFile);
        studentsList.clear();

        while(!in.atEnd())
        {
            QString name = in.readLine();

            QString fac, spec, gr;
            double matan, oaip, agila, hist, dm;

            in >> fac >> spec >> gr;
            in >> matan >> oaip >> agila >> hist >> dm;

            studentsList.push_back(Student(name, fac, spec, gr, matan, oaip, agila, hist, dm));

            in.readLine();
        }

        ui->listWidget->clear();
        printStudentsInListWidget();

        comboFilterUpdate();

        ui->sortButton->setEnabled(true);
    }
}

void MainWindow::on_saveButton_clicked()
{
    QString savedFileName = QFileDialog::getSaveFileName(this, "Куда сохранить файл", "", "Текстовый файл .txt (*.txt)");

    if(!savedFileName.endsWith(".txt")) savedFileName += ".txt";

    if(!savedFileName.isEmpty())
    {
        QFile savedFile(savedFileName);
        savedFile.open(QIODevice::WriteOnly);

        QTextStream out(&savedFile);
        savedFile.seek(0);

        for(int i = 0; i < studentsList.size(); i++)
        {
            Student student = studentsList[i];
            out << student.getFIO() << '\n' << student.getFaculty() << ' ' << student.getSpeciality() << ' ' << student.getGroup()
                << '\n' << student.getMatan() << ' ' << student.getOaip() << ' '
                << student.getAgila() << ' ' << student.getHist() << ' ' << student.getDm() << '\n';
        }

        savedFile.close();

        ui->statusbar->showMessage("Файл сохранен.", 5000);
    }
}

void MainWindow::on_addButton_clicked()
{
    DialogInputStudent* dialog = new DialogInputStudent(this);
    connect(dialog, &DialogInputStudent::accepted, [=](){

        studentsList.push_back(dialog->getStudentInfo());
        ui->listWidget->clear();
        printStudentsInListWidget();

    });

    dialog->setModal(true);
    dialog->exec();

    comboFilterUpdate();
    ui->sortButton->setEnabled(true);
}

void MainWindow::on_editButton_clicked()
{
    DialogInputStudent* dialog = new DialogInputStudent(this);

    connect(dialog, &DialogInputStudent::accepted, [=](){

        for(int i = 0; i < studentsList.size(); i++)
        {
            if("(" + studentsList[i].getGroup() + ") " + studentsList[i].getFIO() + " — " +QString::number(studentsList[i].getAvgMark()) ==
                ui->listWidget->currentItem()->text())
            {
                studentsList[i] = dialog->getStudentInfo();
                break;
            }
        }

        ui->listWidget->clear();
        printStudentsInListWidget();

        // studentsList[ui->listWidget->currentRow()] = dialog->getStudentInfo();

        // ui->listWidget->clear();
        // printStudentsInListWidget();

        comboFilterUpdate();
        ui->sortButton->setEnabled(true);

    });

    for(int i = 0; i < studentsList.size(); i++)
    {
        if("(" + studentsList[i].getGroup() + ") " + studentsList[i].getFIO() + " — " +QString::number(studentsList[i].getAvgMark()) ==
            ui->listWidget->currentItem()->text())
        {
            dialog->setStudentInfo(studentsList[i]);
            break;
        }
    }

    // dialog->setStudentInfo(studentsList[ui->listWidget->currentRow()]);

    dialog->setModal(true);
    dialog->exec();


}

void MainWindow::printStudentsInListWidget()
{
    for(int i = 0; i < studentsList.size(); i++)
    {
        ui->listWidget->addItem("(" + studentsList[i].getGroup() + ") "
                                + studentsList[i].getFIO()
                                + " — " + QString::number(studentsList[i].getAvgMark()));
    }
}

void MainWindow::on_deleteButton_clicked()
{

    for(int i = 0; i < studentsList.size(); i++)
    {
        if("(" + studentsList[i].getGroup() + ") " + studentsList[i].getFIO() + " — " +QString::number(studentsList[i].getAvgMark()) ==
            ui->listWidget->currentItem()->text())
        {
            studentsList.remove(i);
            break;
        }
    }

    ui->listWidget->clear();
    printStudentsInListWidget();
    // studentsList.remove(ui->listWidget->currentRow());

    // ui->listWidget->clear();
    // printStudentsInListWidget();

    comboFilterUpdate();
}

void MainWindow::on_findButton_clicked()
{
    DialogFindStudent* dialog = new DialogFindStudent(this);

    connect(dialog, &DialogFindStudent::accepted, [=](){

        QString name = dialog->getStudentsName();
        bool isFinded = false;

        for(int i = 0; i < studentsList.size(); i++)
        {
            if(studentsList[i].getFIO() == name)
            {
                ui->listWidget->setCurrentItem(ui->listWidget->item(i));
                isFinded = true;
                break;
            }
        }

        if(!isFinded)
            QMessageBox::warning(this, "Студент не найден", "Студент с таким ФИО не найден.\nПроверьте, правильность написания");

    });

    dialog->setModal(true);
    dialog->exec();
}

void MainWindow::comboFilterUpdate()
{
    QString current = ui->comboGroups->currentText();
    std::set<QString> setGroups;

    GROUPS.clear();
    ui->comboGroups->clear();

    for(int i = 0; i < studentsList.size(); i++)
    {
        qDebug() << ui->comboGroups->findText(studentsList[i].getGroup());
        if(setGroups.find(studentsList[i].getGroup()) == setGroups.end())
        {
            setGroups.insert(studentsList[i].getGroup());
            GROUPS.append(studentsList[i].getGroup());
        }
    }

    GROUPS.sort();

    if(!GROUPS.isEmpty())
    {
        GROUPS.push_front("С уд. оценками");
        GROUPS.push_front("Все группы");
    }

    ui->comboGroups->addItems(GROUPS);

    ui->comboGroups->setCurrentText(current);
}


void MainWindow::on_sortButton_clicked()
{
    std::sort(studentsList.begin(), studentsList.end(), [](const Student &a, const Student &b) {
        return a.getAvgMark() > b.getAvgMark();
    });

    comboFilterUpdate();

    ui->sortButton->setEnabled(false);
}

