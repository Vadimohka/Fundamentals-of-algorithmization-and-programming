#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QListView>
#include <QStringListModel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>
#include <unordered_set>
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

    void createSets(int minPrice, int maxPrice);

    void createSetsRec(int i, int currentPrice, int minPrice, int maxPrice, component** &currentSet, int &currentSetSize, std::unordered_set<QString> &currentTypes, int &maxSize, int &setNumber);

    void on_pushButton_6_clicked();

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
