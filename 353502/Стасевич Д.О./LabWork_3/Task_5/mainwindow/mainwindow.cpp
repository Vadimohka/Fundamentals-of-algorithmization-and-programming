#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

#include <QDebug>

mainwindow::mainwindow(): ui(new Ui::mainwindow) {

    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(open_dir_clicked()));

}

void mainwindow::open_dir_clicked() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    qDebug() << dir;
    auto answer = Calculate::CountDirectories(dir);
    ui->lineEdit->setText(QString::number(answer));
    answer = Calculate::CountFiles(dir);
    ui->lineEdit_2->setText(QString::number(answer));
}

