#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QRandomGenerator>
#include "clickablelabel.h"
#include "circularbutton.h"
#include "citybuttons.h"
#include "picturelabel.h"
#include "searchline.h"

const int WFIRST = 782;
const int HFIRST = 531;
const int RAND_DIAPOSON = 50;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *randomButton;
    QVBoxLayout *layout;
    SearchLine *searchLine;
    ClickableLabel *pictureLabel;
    CityButtons buttons;
    QHash<int, int> hashMap;
    QVector<CityInfoWidget> *infoWidgets;
    int canResize, randInd;

    void showRandomCity();
    int getRandom();
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MAINWINDOW_H
