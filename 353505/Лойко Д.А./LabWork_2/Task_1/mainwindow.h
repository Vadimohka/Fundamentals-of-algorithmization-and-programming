#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

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
    void ReadDates();

    void on_BithdayButton_clicked();

    void on_AddDateButton_clicked();

    void on_ChangeDateButton_clicked();

    void on_OpenFileButton_clicked();

private:
    QString filePath;
    Date today = today.Today();

    Date bithday;
    Date* datesfromfile;
    int amount;

    void FillTable();
    Date FillDateLine();
    void RewriteFile(int rowIndex, const QString &newdate);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
