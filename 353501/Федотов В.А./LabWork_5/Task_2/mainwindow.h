#pragma once

#include "StringLib/CustomString.h"
#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
    MainWindow();

private slots:
    void updateLabels(QString qstring);

private:
    String s1;
    String s2;

protected:
    Ui::MainWindow *ui;
};
