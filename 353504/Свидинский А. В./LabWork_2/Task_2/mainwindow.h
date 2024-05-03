#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QListView>
#include <QStringListModel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "component.h"
#include "dialogsearch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void receiveData(const QString &searchType, const QString &searchFirm, const QString &searchModel);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void openfile();

    void makeBase();

    void currentComponentsInArray();

    void updateComboBoxFirm();

    void updateComboBoxModel();

    void updateComboBoxPrice();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QListView *listView;
    QStringListModel *model;
    QStandardItemModel *model2;
    QString pathFile;
    QString information;
    component **components;
    int kolvo;

    int skolko;
    component **currentComponent;
    bool current;
    bool open;
};
#endif // MAINWINDOW_H
