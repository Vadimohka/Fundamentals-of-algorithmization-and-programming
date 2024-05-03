#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "addcompany.h"
#include "addperson.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void companySlot();
    void personSlot();
    void addCompanySlot();
    void addPersonSlot();

    void on_actionAddCompany_triggered();

    void on_actionAddPerson_triggered();

    void on_actionDeleteCompany_triggered();

    void on_actionDeletePerson_triggered();

    void on_actionReset_triggered();

    void on_actionSortPerson_triggered();

    void on_actionSortCompany_triggered();

    void on_actionDefCompany_triggered();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    AddCompany* addCompany;
    AddPerson* addPerson;
    QVector<QVector<QString>> companies;
    QVector<QVector<QString>> people;

    void companyFromFile();
    void personFromFile();
    static bool compare(const QVector<QString>& a, const QVector<QString>& b);
};
#endif // MAINWINDOW_H
