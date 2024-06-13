#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsItemGroup>
#include <QLabel>
#include <QLayout>
#include <QVector>

#include <QWidget>

#include <ellips.h>
#include <shar.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Shar *shar;
    QLabel *text;
    QVector<int> itemsId;
    static constexpr QPoint startPos = {-30, -30};

private slots:

    void on_pushButton_clicked();

    void on_deletebutton_clicked();
};
#endif // MAINWINDOW_H
