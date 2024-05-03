#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QGroupBox>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QStackedLayout>
#include <QVBoxLayout>
#include "datefile.h"
#include "datetable.h"
#include "durationtable.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DateFile* dateFile;
    DateTable* fileDateTable;
    QPushButton* setFilebtn;

    DateTable* resultDateTable;
    DurationTable* resultDurationTable;
    QStackedLayout* resultTable;
    QPushButton* changeResultBtn;

    QFormLayout* editLayout;
    QSpinBox* daySpinBox;
    QSpinBox* monthSpinBox;
    QSpinBox* yearSpinBox;
    QLabel* birthdayLbl;
    Date birthday;
    QLabel* tillYourBithday;

    unsigned selectedDate;
    QPushButton* changeActionBtn;
    QLabel* modeLbl;
    QPushButton* applyBtn;
    QSpinBox* numberSpinBox;
    unsigned addMode; //0 - 2

    QFormLayout* editFileLayout;
    QSpinBox* dayFileSpinBox;
    QSpinBox* monthFileSpinBox;
    QSpinBox* yearFileSpinBox;

    const QString exampleFileName = "/home/mikalai/gitlabs/Task1/exampledate.txt";
    QString currentFileName;
    QVector<Date> dateVector;

    QGroupBox* topBox, *botBox;
    QGridLayout* mainLayout;

    QVector<Date> getResultDateVector();
    QVector<int> getResultDurationVector();

private slots:
    void slotInvalidFile();
    void slotChangeResultBtn();
    void slotChangeActionBtn();
    void slotUpdateBD();
    void slotUpdateDate();
    void slotSelectDate();
    void slotChangeFile();
    void slotApply();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
