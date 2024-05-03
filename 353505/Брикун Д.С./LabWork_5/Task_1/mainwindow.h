#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qapplication.h"
#include "qinputmethod.h"
#include <QMainWindow>
#include <QTextEdit>
#include <QDebug>
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
    QInputMethod *inputMethod = QApplication::inputMethod();

private:
    Ui::MainWindow *ui;
    QString curLocale;
    int curLocaleNum = 0;
    void setButtonText(int buttonNumber, const QString &text);
    void changedLocale();
    void setSymbols();
    void initSymbols();
    void initDictionaryes();
    void generateText();
    QVector<QVector<QString>> dictionary;
    QVector<QString> testText;
    QVector<QVector<QMap<int, QString>>> textKeys;
    bool caps = false, shift = false;
    void addTextToLineEdit();
    QTimer *timer;
    int seconds = 0;
    int words = 0;
    int symbols = 0, symbolsOk = 0;

public slots:
    void buttonClicked(int, bool proc);
    void buttonReleased(int);

private slots:
    void myslot(){
        // QString newLayout = qApp->inputMethod()->locale().name();
        QMessageBox::information(nullptr, "Information", "Please remember to change your keybord according to combobox.");

    };
    void on_comboBox_currentIndexChanged(int index);
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_clicked();
    void on_pushButton_start_clicked();
    void updateTimer();
    void on_pushButton_stop_clicked();
    void on_pushButton_open_clicked();
};

#endif // MAINWINDOW_H
