#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arraytable.h"
#include <QHBoxLayout>
#include "medianfunc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    ArrayTable* _originalVector;
    ArrayTable* _medianVector;
    QHBoxLayout* _mainLayout;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void slotUpdateVector();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
