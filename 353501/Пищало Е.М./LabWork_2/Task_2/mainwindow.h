#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QString>
#include <QDir>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include "player.h"
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
    void on_openfilebut_clicked();

    void on_pushButton_clicked();

    void on_hidetopscorrers_clicked();

    void on_biggestpenalty_clicked();

    void on_hidetoppenalty_clicked();

    void on_worstscorersbut_clicked();

    void on_hideworstscorers_clicked();

    void on_addbut_clicked();

    void on_confirmbut_clicked();

    void on_editbut_clicked();

    void on_confirmbut_2_clicked();

private:
    int selectedRow;
    QVector<Player> players;
    Ui::MainWindow *ui;
    QFile file;
    QString pathToFile;
    void FromFiletoVector();
};
#endif // MAINWINDOW_H
