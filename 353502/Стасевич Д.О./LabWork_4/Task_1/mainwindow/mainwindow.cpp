#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

#include <QDebug>
#include <iostream>

mainwindow::mainwindow(): ui(new Ui::mainwindow), scene (new QGraphicsScene(this)) {

    ui->setupUi(this);
    ui->widget->hide();
    ui->graphicsView->setScene(scene);
    ui->pushButton->setEnabled(0);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    auto *timer = new QTimer(this);
    timer->setInterval(1000);

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(do_sort_clicked(int)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(do_binary_search_clicked()));
    connect(ui->sizespinBox, SIGNAL(valueChanged(int)), this, SLOT(set_enable()));
    connect(ui->arraytextEdit, SIGNAL(textChanged()), this, SLOT(set_enable()));
    connect(ui->nextMoveButton, SIGNAL(clicked()), this, SLOT(next_step_clicked()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close_clicked()));
    connect(ui->nextMoveButton, SIGNAL(pressed()), timer, SLOT(start()));
    connect(timer, SIGNAL(timeout()), this, SLOT(next_step_clicked()));
    connect(ui->nextMoveButton, SIGNAL(released()), timer, SLOT(stop()));

}

void mainwindow::do_sort_clicked(int type) {
    int nn = ui->sizespinBox->value();
    auto t = ui->arraytextEdit->toPlainText();
    int *arr = new int[nn];
    try {
        ArrayOperations::StringToArray(t, arr, nn);
    }
    catch (...)
    {
        QMessageBox message;
        message.setText("Введен некоррекный массив");
        message.exec();
        return;
    }
    float time;
    switch (type) {
        case 0:
        {
            qDebug() << "heap";
            a = new int[nn];
            for(int i = 0; i < nn; i ++)
                a[i] = arr[i];
            n = nn;
            steps.clear();
            scene->clear();
            array_draw.clear();
            time = ArrayOperations::HeapSort(arr, nn, steps);
            cur = 0;
            ui->nextMoveButton->setEnabled(1);
            ui->showlabel->hide();
            ui->closeButton->hide();
            ui->widget->show();
            StartArray();
            break;
        }
        case 1:
        {
            qDebug() << "merge";
            a = new int[nn];
            for(int i = 0; i < nn; i ++)
                a[i] = arr[i];
            n = nn;
            steps.clear();
            scene->clear();
            array_draw.clear();
            time = ArrayOperations::MergeSort(arr, nn, steps);
            cur = 0;
            ui->nextMoveButton->setEnabled(1);
            ui->showlabel->hide();
            ui->closeButton->hide();
            ui->widget->show();
            StartArray();

            break;
        }
        case 2:
        {
            qDebug() << "quick";
            a = new int[nn];
            for(int i = 0; i < nn; i ++)
                a[i] = arr[i];
            n = nn;
            steps.clear();
            scene->clear();
            array_draw.clear();
            time = ArrayOperations::QuickSort(arr, nn, steps);
            cur = 0;
            ui->nextMoveButton->setEnabled(1);
            ui->showlabel->hide();
            ui->closeButton->hide();
            ui->widget->show();
            StartArray();
            break;
        }
        default:
        {
            qDebug() << "interpolar";
            a = new int[nn];
            for(int i = 0; i < nn; i ++)
                a[i] = arr[i];
            n = nn;
            steps.clear();
            scene->clear();
            array_draw.clear();
            time = ArrayOperations::InterpolarSort(arr, nn, steps);

            cur = 0;
            ui->nextMoveButton->setEnabled(1);
            ui->showlabel->hide();
            ui->closeButton->hide();
            ui->widget->show();
            StartArray();
        }
    }
    QString answer;
    for(int i = 0; i < nn; i ++)
    {
        answer += QString::number(arr[i]) + ' ';
    }
    ui->sortedArraytextEdit->setText(answer);
    ui->timetextEdit->setText(QString::number(time));
    ui->pushButton->setEnabled(1);
}

void mainwindow::do_binary_search_clicked() {
    int digit = ui->digitspinBox->value();
    int nn = ui->sizespinBox->value();
    auto t = ui->sortedArraytextEdit->toPlainText();
    t.remove(t.size() - 1, 1);
    int *arr = new int[nn];
    ArrayOperations::StringToArray(t, arr, nn);
    int x = ArrayOperations::BinSearch(arr, nn, digit);

    ui->binsearchtextEdit->setText(QString::number(x));
    if(digit)
        ui->binpowtextEdit->setText(QString::number(ArrayOperations::binpow(x, nn, digit)));
    else
        ui->binpowtextEdit->setText("деление на 0");
}

void mainwindow::set_enable() {
    ui->pushButton->setEnabled(0);
}

void mainwindow::next_step_clicked() {
    if(cur >= steps.size())
        return;
    std::cout << "cur = " << cur << '\n';
    scene->clear();
    array_draw.clear();
    for(int i = 0; i < n; i ++)
    {
        auto r = new Rectangle(-360 + i * 15, 190 - (300 * (steps[cur][i] - mn) / d + 15), (300 * (steps[cur][i] - mn) / d + 15));
        array_draw.push_back(r);
        scene->addItem(array_draw[i]);
    }
    QString s;
    for(int i = 0; i < n; i ++)
    {
        s += QString::number(steps[cur][i]) + " ";
    }
    ui->currentArrayplainTextEdit->setPlainText(s);
    cur ++;
    if(cur == steps.size())
    {
        ui->nextMoveButton->setEnabled(0);
        ui->showlabel->show();
        ui->closeButton->show();
    }
}

void mainwindow::close_clicked() {
    ui->widget->hide();
}

void mainwindow::StartArray() {
    // create vector of rectangles
    mn = a[0];
    int mx = a[0];
    for(int i = 1; i < n; i ++)
    {
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    d = mx - mn + 1;
    for(int i = 0; i < n; i ++)
    {
        auto r = new Rectangle(-360 + i * 15, 190 - (300 * (a[i] - mn) / d + 15), (300 * (a[i] - mn) / d + 15));
        array_draw.push_back(r);
        scene->addItem(array_draw[i]);
    }
    QString s;
    for(int i = 0; i < n; i ++)
    {
        s += QString::number(a[i]) + " ";
    }
    ui->currentArrayplainTextEdit->setPlainText(s);
}


