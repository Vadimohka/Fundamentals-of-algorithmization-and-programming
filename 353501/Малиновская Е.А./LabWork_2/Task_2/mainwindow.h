#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "task.h"
#include <QMainWindow>
#include <QFile>
#include <QVector>
#include <QTableWidgetItem>

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

private slots:
    void openFile();
    void on_openFileButton_clicked();
    void on_searchButton_clicked();
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onEditButtonClicked();
    void sortButtonClicked();
    void showTasksButtonClicked();

private:
    Ui::MainWindow *ui;
    QFile *file;
    QVector<Task*> tasks;

    void addTableRow(const Task& task);
    void removeSelectedTableRow();
    void sortTableByProjectName();
    void editSelectedTableRow(const Task& task);
    void loadTasksFromFile(const QString& filePath);

};

#endif // MAINWINDOW_H
