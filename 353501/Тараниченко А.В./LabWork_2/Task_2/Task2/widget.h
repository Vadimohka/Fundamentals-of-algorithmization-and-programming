#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QLabel>
#include <QTimer>
#include <student.h>
#include <QVector>
#include <QFile>
#include <QInputDialog>
#include <dialog.h>

class widget : public QWidget
{
public:
    widget(QWidget *parent = nullptr);

    void setFileName(QString name);
    void parce();
    void addComboBox(QString fio);
    void studTable();

    QVector<student> stud;

private:
    QLabel *name;
    QLabel *mat;
    QLabel *phys;
    QLabel *rus;
    QLabel *atestat;
    QComboBox *nameBox;
    QLabel *matText;
    QLabel *physText;
    QLabel *rusText;
    QLabel *atestatText;
    QTableWidget *table;
    QPushButton *deleteButton;
    QPushButton *resizeButton;
    QPushButton *addButton;
    QPushButton *sortButton;
    QPushButton *searchButton;

    QTimer *timer;

    QString filename;

private:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void resizeTimer();
    void showInputDialog();
    void delet();
    void resize();
    void sort(int* a, int*b, int left, int right);
    void butsort();
    void search();
};


#endif // WIDGET_H
