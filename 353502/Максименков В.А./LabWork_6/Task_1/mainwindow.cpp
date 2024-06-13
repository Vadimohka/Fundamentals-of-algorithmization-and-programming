#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->confirmButton, &QPushButton::clicked, this, &MainWindow::confirm);

    /***************DEFAULT*INITIALISATION****************************/

    Foot foot1 = static_cast<QString> ("20 51.22 C false SUMMER 40,41,42,45,12,98,23/");
    demo = "foot1:   " + foot1.toString();
    ui->demonstraitingBrowser->setText(demo);

    ui->askingBrowser->setText("Enter total number:");

    /*******************POINTER*INITIALIZATION***************************/

    Foot foot2 = Foot("20 51.22 C false SUMMER 40,41,42,45,12,98,23/");
    Foot* foot2_ptr = &foot2;

    foot2_ptr->totalNumber = 10;
    foot2_ptr->price = 55.05;
    foot2_ptr->type = 'C';
    foot2_ptr->isUniversal = true;

    foot2_ptr->season[0] = 'A';
    foot2_ptr->season[1] = 'U';
    foot2_ptr->season[2] = 'T';
    foot2_ptr->season[3] = 'U';
    foot2_ptr->season[4] = 'M';
    foot2_ptr->season[5] = 'N';

    foot2_ptr->sz[0] = 35;

    demo += "\n";
    demo += "foot2:    ";
    demo += foot2_ptr->toString();
    ui->demonstraitingBrowser->setText(demo);

    /******************REFERENSE*INITIALIZATION*****************************/

    Foot foot3 = Foot("20 51.22 C false SUMMER 40,41,42,45,12,98,23/");
    Foot& foot3_ref = foot3;

    foot3_ref.totalNumber = 10;
    foot3_ref.price = 55.05;
    foot3_ref.type = 'C';
    foot3_ref.isUniversal = true;

    foot3_ref.season[0] = 'A';
    foot3_ref.season[1] = 'U';
    foot3_ref.season[2] = 'T';
    foot3_ref.season[3] = 'U';
    foot3_ref.season[4] = 'M';
    foot3_ref.season[5] = 'N';

    foot3_ref.sz[0] = 35;

    demo += "\n";
    demo += "foot3:    ";
    demo += foot3_ref.toString();
    ui->demonstraitingBrowser->setText(demo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::confirm()
{
    if (ui->answerEdit->text() == "") return;

    QString ans = ui->answerEdit->text();
    init += ans + " ";
    ++index;
    changeAsk(index);
}

void MainWindow::changeAsk(int index)
{
    switch (index) {
    case 1:
        ui->askingBrowser->setText("Enter price:");
        break;
    case 2:
        ui->askingBrowser->setText("Enter type:");
        break;
    case 3:
        ui->askingBrowser->setText("Enter isUniversal:");
        break;
    case 4:
        ui->askingBrowser->setText("Enter season:");
        break;
    case 5:
        ui->askingBrowser->setText("Enter sizes:");
        break;
    default:
        index = 0;
        init[init.size()-1] = '/';
        ui->askingBrowser->setText("");
        Foot foot = Foot(init);
        init  = "";
        demo += "\n";
        demo += "foot:    ";
        demo += foot.toString();
        ui->demonstraitingBrowser->setText(demo);
        break;
    }

    ui->answerEdit->setText("");
}
