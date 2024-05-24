#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QTableWidget>
#include <QTextStream>

#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void changeEvent(QEvent * e) override;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void readFromFile(const QString &filepath);
    void FillRowComboBox();

public slots:
    void ShowInTable(Date date, int rowCount);
    void ChooseFile();
    void EditFile();
    void AddToFile();
    void Delete();

private:
    Ui::MainWindow *ui;
    QVector <Date> dates;
    QRegularExpression regex;
    QString filepath;
};
#endif // MAINWINDOW_H
