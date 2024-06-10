#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>

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
    void openFileDialog();
    void loadDatesFromFile(const QString& fileName);
    void showNextDay();
    void showDiff();
    void addBirthday();
    void modifyDate();

private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QPushButton *fileButton;
    QPushButton *nextDayButton;
    QPushButton *diffButton;
    QDateEdit *birthdateEdit;
};

#endif // MAINWINDOW_H
