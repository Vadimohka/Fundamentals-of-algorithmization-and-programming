#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QTextCursor>
#include <QTime>
#include <QTimer>
#include <ui_mainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);
    void increment();

    void on_pushButtonBelarusian_clicked();

    void on_pushButtonGermany_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString dictant;
    /*QString dictant = "Вожыкі жывуць ва ўсіх мясцінах Беларусі. Іх можна сустрэць у садзе, парку, непадалёку "
          "ад хлява для свойскай жывёлы. Гэта адзін з самых адважных звяркоў. Ён не спяшаецца "
          "ўцякаць, калі сустрэне каго-небудзь на сцяжынцы. Натапырыць свае вострыя калючкі і "
          "сярдзіта пыхкае. Калі ж крыўдзіцель нападзе, звярок умомант згорнецца ў клубок. Няшмат "
          "знойдзецца ахвотнікаў пагуляць з такім калючым мячыкам. Вожык - смелы паляўнічы. Ён "
          "знішчае шкодных жукоў, слімакоў, бурыць мышыныя і кратовыя гнёзды. Ніколі не абміне "
          "гадзюку. Змяя ўмела бароніцца, але вожыка надзейна засцерагаюць вострыя калючкі. Вожыкі "
          "нараджаюцца з іголкамі. Аднак напачатку яны мяккія і белыя. Замест іх праз два-тры "
          "тыдні вырастаюць цёмныя і калючыя. Малако для вожыка - самы смачны ласунак.";*/
    QTextCursor cursor;
    QString text;
    int yourSpeedu;
    int numbermistakes;
    QTimer timer;
    double second;
    void readFromFile(QString);
};
#endif // MAINWINDOW_H
