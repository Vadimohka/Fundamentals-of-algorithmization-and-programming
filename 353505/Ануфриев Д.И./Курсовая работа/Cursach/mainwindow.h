#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "gamefield.h"
#include "figures/ltypefigure.h"
#include "figures/ttypefigure.h"
#include "figures/square2typefigure.h"
#include "figures/miniltypefigure.h"
#include "figures/inverseltypefigure.h"
#include "figures/stypefigure.h"
#include "figures/inversestypefigure.h"
#include "figures/stick4typefigure.h"
#include "figures/bigltypefigure.h"
#include "figures/diagonalstick2figure.h"

#include "backtrackinggenerator.h"

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

    void clearGame();
    void updateRecord();
    void loadRecord();

    void startNewGame();

    void loadGameFromFile();
    void loadGameIntoFile();

    void generateFigureWithType(GameField* field, int numberOfType, int rotation, int posX);

private:
    Ui::MainWindow *ui;
    GameField* field;
    QGraphicsScene* scene;

    QVector<FigureItem*> figures;
    int valueOfFiguresOnTheScene;

    qreal qUnit;

    BacktrackingGenerator* generator;

signals:
    void exit();

private slots:
    void on_exitButton_clicked();

public slots:
    void oneOfFiguresWasPlaced();
};
#endif // MAINWINDOW_H
