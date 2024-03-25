#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bindectranslator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    const qint64 MAX_DEC = 262143;
    const qint8 MAX_PRE = 15;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void slotShowResult();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
