#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arrLineEdit->setParent(this);
    arrLineEdit->setGeometry(400, 0, 300, 30);
    arrLineEdit->setValidator(val);

    ansLineEdit->setParent(this);
    ansLineEdit->setGeometry(400, 40, 300, 30);
    ansLineEdit->setEnabled(false);

    getAnsButton->setParent(this);
    getAnsButton->setText("Вычислить");
    getAnsButton->setGeometry(0, 0, 300, 30);

    QPushButton::connect(getAnsButton, SIGNAL(pressed()), this, SLOT(on_getAnsButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeAns()
{
    if (vec.size() > 0){
        ansVec.clear();
        int ans = 0;
        for (int i = 0; i < vec.size(); i+=3){
            int n1 = vec[i];
            if (i + 1 < vec.size()){
                int n2 = vec[i + 1];
                if (i + 2 < vec.size()){
                    int n3 = vec[i + 2];
                    if ((n1 <= n2 && n1 >= n3) || (n1 >= n2 && n1 <= n3)) ans = n1;
                    else if ((n2 <= n1 && n2 >= n3) || (n2 >= n1 && n2 <= n3)) ans = n2;
                    else ans = n3;
                }
                else{
                    ans = (n1 + n2) / 2;
                }
            }
            else ans = n1;
            ansVec.append(ans);
        }
    }
}

void MainWindow::showAns()
{
    QString str = "";
    for (int i = 0; i < ansVec.size(); ++i){
        str += QString::number(ansVec[i]) + " ";
    }
    ansLineEdit->setText(str);
}

void MainWindow::makeArr()
{
    vec.clear();
    QStringList list = arrLineEdit->text().split(',');
    if (list[list.size() - 1] == "") list.pop_back();

    for (auto &i: list){
        vec.append(i.toInt());
    }
}


void MainWindow::on_getAnsButton_clicked()
{
    makeArr();
    makeAns();
    showAns();
}
