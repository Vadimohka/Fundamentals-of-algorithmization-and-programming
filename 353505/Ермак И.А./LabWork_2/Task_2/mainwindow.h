#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>>
#include <project.h>
#include <QMessageBox>
#include <QMap>
#include <QFileDialog>>
#include <QFile>
#include <QTextStream>
#include <QSet>

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
protected:
    bool InputValidationNameHuman(QString InputDate);
    bool InputValidationDate(QString InputDate);
    bool InputValidationTerm(QString InputDate);
    void InputOpenedFile(QString InputData);
    void InputValidationEnter(QString InputData);
    void AddListData(QString NameProject, QString TaskProject, QString Executor, QString Supervisor,
                     QString DateIssuing, QString Term, QString DateHanding);
    void AddTextOutput(QString TextOutput);
    void CheckedTable(int CountOld);
private slots:
    void on_ButtonAddProject_clicked();

    void on_ButtonListSupervisor_clicked();

    void on_ButtonTaskExecutor_clicked();

    void on_ButtonExecutorsProject_clicked();

    void on_ButtonOverdue_clicked();

    void on_ButtonSaveFile_clicked();

    void on_ButtonOpenFile_clicked();
private:
    QString TextOutputFile= "";

private:
    Ui::MainWindow *ui;
    Project *project;
    QVector<Project*> projects;
};
#endif // MAINWINDOW_H
