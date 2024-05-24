#ifndef FINDSTUDENT_H
#define FINDSTUDENT_H

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class FindStudent : public QDialog {
public:

    QString namE = nullptr;
    QString surnamE = nullptr;
    QString dadsnamE = nullptr;

    QString get_name();
    QString get_surname();
    QString get_dadsname();

    FindStudent(QWidget* parent = nullptr) : QDialog(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);
        lineEdit1 = new QLineEdit(this);
        lineEdit2 = new QLineEdit(this);
        lineEdit3 = new QLineEdit(this);
        labelA = new QLabel("Имя: ");
        labelB = new QLabel("Фамилия: ");
        labelC = new QLabel("Отчество: ");
        labelD = new QLabel("");
        ready = new QPushButton("Готово");

        layout->addWidget(lineEdit1);
        layout->addWidget(lineEdit2);
        layout->addWidget(lineEdit3);
        layout->addWidget(labelA);
        layout->addWidget(labelB);
        layout->addWidget(labelC);
        layout->addWidget(labelD);
        layout->addWidget(ready);

        layout->insertWidget(0, labelA);
        layout->insertWidget(1, lineEdit1);
        layout->insertWidget(2, labelB);
        layout->insertWidget(3,lineEdit2);
        layout->insertWidget(4, labelC);
        layout->insertWidget(5, lineEdit3);
        layout->insertWidget(6, labelD);
        layout->insertWidget(7, ready);

        setWindowTitle("Введите Ф.И.О.");
        connect(ready, &QPushButton::clicked, this, &FindStudent::on_ready_clicked);

    }

private:
    QLineEdit* lineEdit1;
    QLineEdit* lineEdit2;
    QLineEdit* lineEdit3;
    QLabel* labelA;
    QLabel* labelB;
    QLabel* labelC;
    QLabel* labelD;
    QPushButton* ready;

private slots:
    void on_ready_clicked();
};

#endif // FINDSTUDENT_H
