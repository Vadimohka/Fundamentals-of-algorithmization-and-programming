#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "candidate.h"
#include <QFile>
#include <QMainWindow>
#include <vector>
#include <QTableWidget>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    bool checkInputDistrict();
    bool checkInputName();
    bool checkInputParty();
    bool checkInputProfession();
    bool checkInputAge();
    bool checkInputIncome();

    Candidate candidate;

    std::vector<Candidate> _candidates;
    QStringList _parties;
    QStringList _jobs;
    std::vector<double> _income;
    std::vector<int> _amount;
    std::vector<double> _age;
    QFile file;
    QString _path_to_file;
    void openFile();
    void writeToFile();
    void readFromFile();
    void deleteCandidate();
    void getInfo();
    void addCandidateToTable();
    void search(QString name);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
