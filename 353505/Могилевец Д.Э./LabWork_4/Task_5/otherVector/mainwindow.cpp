#include "mainwindow.h"
#include "vector.cpp"

mainWindow::mainWindow() {
    vBox = new QVBoxLayout;

    gridBox = new QGridLayout;

    gridBox->addWidget(atPB, 0, 0);
    connect(atPB, SIGNAL(clicked(bool)), SLOT(atSlot()));
    gridBox->addWidget(capacityPB, 0, 1);
    connect(capacityPB, SIGNAL(clicked(bool)), SLOT(capacitySlot()));
    gridBox->addWidget(clearPB, 0, 2);
    connect(clearPB, SIGNAL(clicked(bool)), SLOT(clearSlot()));
    gridBox->addWidget(dataPB, 0, 3);
    connect(dataPB, SIGNAL(clicked(bool)), SLOT(dataSlot()));
    gridBox->addWidget(emptyPB, 1, 1);
    connect(emptyPB, SIGNAL(clicked(bool)), SLOT(emptySlot()));
    gridBox->addWidget(erasePB, 1, 2);
    connect(erasePB, SIGNAL(clicked(bool)), SLOT(eraseSlot()));
    gridBox->addWidget(maxSizePB, 1, 4);
    connect(maxSizePB, SIGNAL(clicked(bool)), SLOT(maxSizeSlot()));
    gridBox->addWidget(popBackPB, 2, 0);
    connect(popBackPB, SIGNAL(clicked(bool)), SLOT(popBackSlot()));
    gridBox->addWidget(pushBackPB, 2, 1);
    connect(pushBackPB, SIGNAL(clicked(bool)), SLOT(pushBackSlot()));
    gridBox->addWidget(reservePB, 1, 3);
    connect(reservePB, SIGNAL(clicked(bool)), SLOT(reserveSlot()));
    gridBox->addWidget(resizePB, 1, 0);
    connect(resizePB, SIGNAL(clicked(bool)), SLOT(resizeSlot()));
    gridBox->addWidget(sizePB, 0, 4);
    connect(sizePB, SIGNAL(clicked(bool)), SLOT(sizeSlot()));


    vBox->addLayout(gridBox);

    te = new QSpinBox();
    labelVector = new QLabel("vector<int>");

    vBox->addWidget(te);
    vBox->addWidget(labelVector);

    setLayout(vBox);
    update();

    setWindowTitle("Демонстрация методов");
}


void mainWindow::atSlot() {
    int s = te->text().toInt();
    if (s == 0)
        if (te->text() != "0") {
            QMessageBox::warning(this, "At", "Error");
            return;
        }
    if (s >= 0 && s < a.size())
        QMessageBox::information(this, "At", QString::number(a[s]));
    else
        QMessageBox::warning(this, "At", "Error");
}


void mainWindow::capacitySlot() {
    QMessageBox::information(this, "Capacity", QString::number(a.capacity()));
}


void mainWindow::clearSlot() {
    a.clear();
    update();
}

void mainWindow::dataSlot() {
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(a.data()),
                                         QT_POINTER_SIZE * 2, 16, QChar('0'));
    QMessageBox::information(this, "Data", ptrStr);
}

void mainWindow::emptySlot() {
    QMessageBox::information(this, "EmplaceBack", a.empty() ? "Empty" : "Not");
}

void mainWindow::eraseSlot() {
    QString s = te->text();
    int i1 = te->value();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Erase", "Error");
            return;
        }
    }

    if (i1 >= 0 && i1 < a.size()) {
        qDebug() << i1;
        a.erase(a.begin() + i1);
        QMessageBox::information(this, "Erase", "Ok");
    } else QMessageBox::warning(this, "Erase", "Error");
    update();
}


void mainWindow::maxSizeSlot() {
    QMessageBox::information(this, "Max Size", QString::number(a.max_size()));
}

void mainWindow::popBackSlot() {
    if (a.size() > 0)
        a.pop_back();
    update();
}

void mainWindow::pushBackSlot() {
    QString s = te->text();
    int i1 = te->value();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "PushBeeck", "Error");
            return;
        }
    }

    a.push_back(i1);
    QMessageBox::information(this, "PushBeeck", "Ok");
    update();
}

void mainWindow::reserveSlot() {
    QString s = te->text();
    int i1 = te->value();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Reserve", "Error");
            return;
        }
    }

    a.reserve(i1);
    QMessageBox::information(this, "Reserve", "Ok");
}

void mainWindow::resizeSlot() {
    QString s = te->text();
    int i1 = te->value();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Resize", "Error");
            return;
        }
    }

    if (i1 >= 0) {
        a.resize(i1);
        QMessageBox::information(this, "Resize", "Ok");
    } else QMessageBox::information(this, "Resize", "Ok");
    update();
}

void mainWindow::sizeSlot() {
    QMessageBox::information(this, "Size", QString::number(a.size()));
}

void mainWindow::update() {
    QString s = "";
    for (auto i: a) {
        s += QString::number(i) + ", ";
    }

    labelVector->setText("vector<int> = " + s);
}
