#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include "bel.h"
#include "german.h"
#include "french.h"
#include "ch.h"
#include "arab.h"
#include "hebrew.h"
#include <QFont>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QInputMethodEvent>
#include <QDialog>
#include <QMessageBox>
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

    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void check(QString);

 private slots:
     void on_lineEdit_textChanged(const QString &arg1);


     void on_comboBox_currentIndexChanged(int index);

     void on_pushButton_65_clicked();



     void on_pushButton_66_clicked();

 public slots:
      void change();
 private:
    Ui::MainWindow *ui;
    QTimer timer;
    QPushButton **b=new QPushButton*[70];
    QPushButton **bb=new QPushButton*[70];
    QString bel;
    QString ivr;
    QString chi;
    QString deu;
    QString ar;
    QString fr;
    Bel blr;
    QString spec="'.";
    bool flag1,flag2,flag3,flag4,flag5,flag6=0;
    std::vector <QString> bl,get,fer;
    int tp=0;
    int k=0;
    German ger;
    french f;
    ch chin;
    arab ara;
    hebrew h;
    int ttt=0;
    QTimer timerr;
    double aaa=1;
    double corr=1;
};
#endif // MAINWINDOW_H
