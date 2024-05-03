#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

class Vis;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void onUpdate(int x);
    void updateSelected();

protected:
    Ui::MainWindow *ui;
    QList<QPair<int, int>> solution;
    Vis *vis;
};
