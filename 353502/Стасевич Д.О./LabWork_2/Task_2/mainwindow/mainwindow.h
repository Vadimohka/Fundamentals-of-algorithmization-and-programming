//
// Created by darina on 4/2/24.
//

#ifndef TASK2_MAINWINDOW_H
#define TASK2_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <qgraphicsscene.h>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>

#include "../objects/Candidate.h"
#include "../objects/Firm.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

private:
    bool open = false;
    QString fileRem;
    QFile file;
    void CantOpen();
    void ShowLists();
    void ShowResult(QVector<Firm> f, QVector<QVector<Candidate> > c);
    void ShowResult(const QVector<Firm>& f);
    void ShowResult(const QVector<Candidate>& f);
    static void ErrorLine(const QString& s);
    int posForChange;

protected:
    Ui::mainwindow *ui;
    QGraphicsScene *scene;

    QVector<Candidate> candidates;
    QVector<Firm> firms;

private slots:
    void openfile_clicked();
    void savefile_clicked();
    void match_clicked();
    void emptyvacancy_clicked();
    void emptycandidate_clicked();
    void sort_clicked();
    void add_clicked(int type);
    void change_clicked(int type);
    void delete_clicked(int type);

    void close_firm_clicked();
    void add_firm_clicked();
    void change_firm_clicked();
    void delete_firm_clicked();
    void show_firm_clicked(int i);

    void close_candidate_clicked();
    void add_candidate_clicked();
    void change_candidate_clicked();
    void delete_candidate_clicked();
    void show_candidate_clicked(int i);


};



#endif //TASK2_MAINWINDOW_H
