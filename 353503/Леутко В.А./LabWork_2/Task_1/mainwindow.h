#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "date.h"

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

    QString projectDirectory;
private:
    Ui::MainWindow *ui;

    QFile file;
    QString filePath;
    Date tempPointer=*new Date;


protected slots:
    void openFile();
    void closeFile();
    void dateAddButton_clicked();
    void dateEditButton_clicked();
    void updateBirthdayDays(const QDate &date);
};
#endif // MAINWINDOW_H
