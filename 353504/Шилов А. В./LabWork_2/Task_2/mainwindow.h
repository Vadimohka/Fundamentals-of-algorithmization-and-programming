#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "candidate.h"
#include "firm.h"

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

    void GetCandidatesFromFile();
    void GetFirmsFromFile();
    void OpenFile(int flag);
    void SaveFile(int flag);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

private:
    void fillFieldsCandidates();
    void fillFieldsFirms();
    void setVisibleAddCandidateMenu(bool flag);
    void setVisibleAddFirmMenu(bool flag);
    void setEditModeCandidates(bool flag, bool flag2);
    void setEditModeFirms(bool flag, bool flag2);

    bool isCandidateAvailable(Firm firm, Candidate candidate);


    QString getTextToSave(int flag);

    Candidate getNewCandidate();
    Firm getNewFirm();

    Ui::MainWindow *ui;
    QVector<Candidate> m_candidates;
    QVector<Firm> m_firms;
    QString m_candidatesFilePath;
    QString m_firmsFilePath;
    QVector<QVector<Candidate>> m_candidatesForFirm;
};
#endif // MAINWINDOW_H
