#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <qregularexpression.h>
#include <QRegularExpressionValidator>
#include <qalgorithms.h>
#include <QtCore>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
  
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[1-9]{0,19}"), this);
    ui->a_Edit->setValidator(validator);
    connect(ui->a_Edit, &QLineEdit::textChanged, this,&MainWindow::output);
}

void MainWindow::output(){
    QString input = ui->a_Edit->text();
    QString output;
    QString tmp;

    int size = input.size();
    if ( (size / 2) == 0)
        return;

    int ind = (size / 3) * 3;
    for (int i = 0 ; i < ind; i+= 3) {
        tmp = input.mid(i, 3);
        std::sort(tmp.begin(), tmp.end());
        output.append(tmp[1]);
    }

    tmp = input.mid(ind, (size - ind));
    int res = 0;
    for (QChar &c : tmp) {
        res += c.digitValue();
    }

    if (tmp.size() > 0)
        output.append(QString::number(res / tmp.size()));

    ui->b_Edit->setText(output);
}