#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "DialogCompany.h"
#include "DialogJobOpenings.h"
#include "DialogCondidate.h"

#include "Condidate.h"
#include "Companies.h"
#include "JobOpenings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //friend class DialogCompany;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void UpdateTables();

    void ReadFile();
    void WriteFile();

    void ProcessReading(const QString& allData, std::vector<Company>& companies, std::vector<JobOpener>& jobOpeners, std::vector<Condidate>& condidates);
    void CorrelateCompanies();
    void ClearJobOpener();
    void ClearCondidate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Table_Companies_cellClicked(int row, int column);


    void on_pushButton_3_clicked();

    void closeEvent(QCloseEvent* event);

    void on_Table_JobOpeners_cellClicked(int row, int column);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_activated(int index);

    void on_Table_Condidates_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    DialogCompany* m_pDialogCompany;
    DialogJobOpenings* m_pDialogJobOpenings;
    DialogCondidate* m_pDialogCondidates;

    std::vector<JobOpener*> m_showedOpeners;
    std::vector<Condidate*> m_showedCondidates;

    int selectetCompanyIndex = -1;
    int selectetJobOpenerIndex = -1;
};


#endif // MAINWINDOW_H
