#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <city.h>
#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVector<int> _vec;

    void inputText(QString fileName);
    void outputText(QString fileName);
    void saveArrayToFile(QString fileName);
    void writeCityToTextFile(const QString& fileName);
    void writeCityToBinaryFile(const QString& fileName);
    void showCitiesFromBinaryFile(const QString& fileName);
    void appendSentenceToFile(const QString &fileName);
    void readSentencesFromFile(const QString &fileName);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_parargraphBtn_clicked();
    void on_arrayBtn_clicked();
    void on_sizeBox_valueChanged(int arg1);
    void on_valueBox_valueChanged(int arg1);
    void on_posBox_valueChanged(int arg1);
    void on_appendBtn_clicked();
    void on_structBtn_clicked();
    void on_sentenceBtn_clicked();
    void on_finishBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
