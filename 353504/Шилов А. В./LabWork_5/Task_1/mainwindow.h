#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QShortcut>
#include <QTimer>
#include <QTime>
#include <QFileDialog>>

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
    QStringList rowsRus;
    QStringList rowsBel;
    QStringList rowsEng;
    QStringList rowsFr;
    QStringList rowsGer;
    QStringList rowsIvr;
    QStringList rowsAra;
    QVector<QPushButton*> buttons;
    QString ger = "dies ist ein Beispiel für einen Text auf Deutsch es enthält genau zweihundert Zeichen deutsch ist eine wunderschöne Sprache";
    QString fra = "ceci est un exemple de texte en français il contient exactement deux cents caractères le français est une belle langue";
    QString ara = "هذا مثال على نص باللغة العربية يحتوي بالضبط على مائتي حرف. اللغة العربية لغة جميلة";
    QString bel = "гэта прыклад тэксту на беларускай мове ён змяшчае роўна двесце сімвалаў Беларуская мова прыгожая мова";
    QString ivr = "זהו דוגמה לטקסט בעברית זה מכיל בדיוק מאתיים תווים העברית היא שפה יפה";
    QString output;
    QString outtext;
    QString input = "";
    QTimer *timer;
    QTime time;

private slots:
    void addSec();
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
