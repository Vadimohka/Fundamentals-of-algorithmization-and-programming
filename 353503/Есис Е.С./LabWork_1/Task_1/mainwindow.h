#include <QGraphicsScene>
#include <QMainWindow>

#include "house.h"



class House;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Line test;


public:
    MainWindow();

private slots:
    void onClick();


protected:
    House house;

    QGraphicsScene *scene;
    Ui::MainWindow *ui;
};
