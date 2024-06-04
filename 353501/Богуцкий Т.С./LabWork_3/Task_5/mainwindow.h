#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDir>
#include <QFileDialog>
#include <QScrollArea>
#include "filemodel.h"
#include <QIcon>
#include "counter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Open_clicked();

private:

    FileModel* model;
    Ui::MainWindow *ui;
    void add(const QString& directory, QTreeWidgetItem* parentItem);
};
#endif // MAINWINDOW_H

