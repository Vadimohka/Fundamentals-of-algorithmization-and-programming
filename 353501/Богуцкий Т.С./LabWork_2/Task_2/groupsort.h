#ifndef GROUPSORT_H
#define GROUPSORT_H

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class GroupSort : public QDialog
{
public:
    QString name_for_group = nullptr;
    QString get_name();

    GroupSort(QWidget* parent = nullptr) : QDialog(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);
        lineEdit1 = new QLineEdit(this);
        ready = new QPushButton("Готово");
        label1 = new QLabel("Группа:");

        layout->addWidget(lineEdit1);
        layout->addWidget(label1);
        layout->addWidget(ready);

        layout->insertWidget(0, label1);
        layout->insertWidget(1, lineEdit1);
        layout->insertWidget(2, ready);

        setWindowTitle("Введите номер группы");
        connect(ready, &QPushButton::clicked, this, &GroupSort::on_ready_clicked);
    }

private:
    QLineEdit* lineEdit1;
    QLabel* label1;
    QPushButton* ready;

private slots:
    void on_ready_clicked();
};

#endif // GROUPSORT_H

