#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    obgect = new hanoi;
    scene->addItem(obgect);
    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(251, 217, 171));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);
    ui->pushAlarm->setStyleSheet("background-color:red");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Hanoi(int n, int i, int k) {
    if (n == 1) {
        ui->table->insertRow(kol_el_table);
        vect.resize(kol_el_table + 1);
        ui->table->setItem(kol_el_table, 0, new QTableWidgetItem(str.setNum(1)));
        vect[kol_el_table].namber_kol = 1;
        ui->table->setItem(kol_el_table, 1, new QTableWidgetItem(i == 1 ? "A" : (i == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_start = i;
        ui->table->setItem(kol_el_table, 2, new QTableWidgetItem(k == 1 ? "A" : (k == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_finish = k;
        kol_el_table++;
    }
    else {
        int tmp = 6 - i - k;
        Hanoi(n - 1, i, tmp);
        ui->table->insertRow(kol_el_table);
        vect.resize(kol_el_table + 1);
        ui->table->setItem(kol_el_table, 0, new QTableWidgetItem(str.setNum(n)));
        vect[kol_el_table].namber_kol = n;
        ui->table->setItem(kol_el_table, 1, new QTableWidgetItem(i == 1 ? "A" : (i == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_start = i;
        ui->table->setItem(kol_el_table, 2, new QTableWidgetItem(k == 1 ? "A" : (k == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_finish = k;
        kol_el_table++;
        Hanoi(n - 1, tmp, k);
    }
}

void MainWindow::fun(){
    is_finish = obgect -> animate(kol_el_table - 1);
    ui->graphicsView->viewport()->update();
    if (is_finish){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(fun()));
        timer -> stop();
    }
}
void MainWindow::on_pushButton_clicked()
{
    if (n != 0)
    {
        obgect -> namber_vector = 0;
        Hanoi(n, 1, 2);
        obgect -> qvector_table(vect);
        connect(timer, SIGNAL(timeout()), this, SLOT(fun()));
        timer->start(10);
    }
}

void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    QString str;
    n = ui -> spinBox -> value();
    if (n != 0){
        obgect -> otr_col(n);
    }
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    kol_el_table = 0;
    vect.clear();
    ui -> table -> clearContents();
    ui -> table -> setRowCount(0);
    timer -> stop();
    obgect -> inis();
    obgect -> otr_col(n);
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushAlarm_clicked()
{
    if(!bimage)
    {
        ui->pushAlarm->setStyleSheet("background-color:green");
        QPixmap pix("/home/oblachko/Projects/LabWork_3/Task_4/cat.jpg");
        ui->label_2->setPixmap(pix);
        ui->label_3->setText("Ад прадзедаў спакон вякоў\nМне засталася спадчына;\nПаміж сваіх і чужакоў\nЯна мне ласкай матчынай.\n\nАб ёй мне баюць казкі-сны\nВясеннія праталіны,\nІ лесу шэлест верасны,\nІ ў полі дуб апалены.\n\nАб ёй мне будзіць успамін\nНа ліпе бусел клёкатам\nІ той стары амшалы тын,\nШто лёг ля вёсак покатам;\n\nІ тое нуднае ягнят\nБляянне-зоў на пасьбішчы,\nІ крык вароніных грамад\nНа могілкавым кладзьбішчы.\n\nІ ў белы дзень, і ў чорну ноч\nЯ ўсцяж раблю агледзіны,\nЦі гэты скарб не збрыў дзе проч,\nЦі трутнем ён не з’едзены.\n\nНашу яго ў жывой душы,\nЯк вечны светач-полымя,\nШто сярод цемры і глушы\nМне свеціць між вандоламі.\n\nЖыве з ім дум маіх сям’я\nІ сніць з ім сны нязводныя...\nЗавецца ж спадчына мая\nЎсяго Старонкай Роднаю.");
        ui->pushAlarm->setText("Всё хорошо");
    }
    else
    {
        ui->pushAlarm->setStyleSheet("background-color:red");
        ui->label_2->setText(" ");
        ui->label_3->setText("");
        ui->pushAlarm->setText("Нажать, когда всё плохо");
    }

    bimage=!bimage;
}

