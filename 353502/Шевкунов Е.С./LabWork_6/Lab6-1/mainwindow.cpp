#include "mainwindow.h"
#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QRegularExpression>
#include "mus.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    lay = new QGridLayout(centralWidget);
    centralWidget->setLayout(lay);

    L1 = new QLabel("Title: ");
    L2 = new QLabel("Listeners: ");
    L3 = new QLabel("Rating: ");
    L4 = new QLabel("Length: ");
    L5 = new QLabel("Category: ");

    E1 = new QLineEdit(this);
    E2 = new QLineEdit(this);
    E3 = new QLineEdit(this);
    E4 = new QLineEdit(this);
    E5 = new QLineEdit(this);

    E3->setPlaceholderText("x.xx");
    E4->setPlaceholderText("xx:xx:xx");
    E5->setPlaceholderText("x");

    butt = new QPushButton("Add");
    check = new QCheckBox("Explicit content");

    text = new QTextEdit();
    text->setReadOnly(1);

    lay->addWidget(L1, 0, 0);
    lay->addWidget(E1, 0, 1);
    lay->addWidget(L2, 0, 2);
    lay->addWidget(E2, 0, 3);
    lay->addWidget(L3, 0, 4);
    lay->addWidget(E3, 0, 5);
    lay->addWidget(L4, 0, 6);
    lay->addWidget(E4, 0, 7);
    lay->addWidget(L5, 0, 8);
    lay->addWidget(E5, 0, 9);
    lay->addWidget(check, 0, 10);
    lay->addWidget(butt, 1, 10);
    lay->addWidget(text, 2, 0, 1, 11);
    lay->setRowStretch(2, 5);

    InicialisateImplicit();

    connect(butt, SIGNAL(clicked()), this, SLOT(create()));

    setFixedSize(1200, 800);
}

void MainWindow::InicialisateImplicit()
{
    int lengthArray[] = {1, 22, 21};
    mus Inic1("Test1", 0, 5.0, lengthArray, 'a', false);

    mus Inic2;
    const char* title = "Test2";
    Inic2.title = new char[strlen(title) + 1];
    strcpy(Inic2.title, title);
    Inic2.listeners = 10;
    Inic2.rating = 4.5;
    Inic2.length[0] = 2;
    Inic2.length[1] = 15;
    Inic2.length[2] = 30;
    Inic2.cat = 'b';
    Inic2.isExplicit = true;

    mus *Inic3 = new mus();
    mus *ptr = Inic3;
    ptr->title = "Test3";
    ptr->listeners = 100;
    ptr->rating = 4.5;
    ptr->length[0] = 1;
    ptr->length[1] = 2;
    ptr->length[2] = 3;
    ptr->cat = 'a';
    ptr->isExplicit = false;

    mus *Inic4 = new mus();
    mus& ref = *Inic4;
    ref.title = "Test4";
    ref.listeners = 100;
    ref.rating = 4.5;
    ref.length[0] = 1;
    ref.length[1] = 2;
    ref.length[2] = 3;
    ref.cat = 'a';
    ref.isExplicit = false;

    text->append(Inic1.ret() + "\n" + Inic2.ret() + "\n" + Inic3->ret() + "\n" + Inic4->ret() + "\n");
}

void MainWindow::create()
{
    QString qstr = E1->text();
    if (qstr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Title cannot be empty");
        return;
    }
    QByteArray byteArray = qstr.toUtf8();
    const char* tit = byteArray.constData();

    QString listenersText = E2->text();
    bool ok;
    int lis = listenersText.toInt(&ok);
    if (!ok || lis < 0) {
        QMessageBox::warning(this, "Input Error", "Listeners must be a non-negative integer");
        return;
    }

    QString ratingText = E3->text();
    double rate = ratingText.toDouble(&ok);
    if (!ok || rate < 0.0 || rate > 5.0) {
        QMessageBox::warning(this, "Input Error", "Rating must be a number between 0 and 5");
        return;
    }

    QString lengthText = E4->text();
    QRegularExpression regex("^\\d{1,2}:\\d{1,2}:\\d{1,2}$");
    QRegularExpressionMatch match = regex.match(lengthText);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Length must be in the format HH:MM:SS");
        return;
    }
    int lArr[3];
    QStringList parts = lengthText.split(":");
    for (int i = 0; i < 3; ++i) {
        lArr[i] = parts[i].toInt();
    }

    QString qch = E5->text();
    if (qch.isEmpty() || qch.length() != 1) {
        QMessageBox::warning(this, "Input Error", "Category must be a single character");
        return;
    }
    char cat = qch.toUtf8().constData()[0];

    bool boo = check->isChecked();

    E1->setText("");
    E2->setText("");
    E3->setText("");
    E4->setText("");
    E5->setText("");

    mus Inic5(tit, lis, rate, lArr, cat, boo);
    text->append("\n" + Inic5.ret());
}


