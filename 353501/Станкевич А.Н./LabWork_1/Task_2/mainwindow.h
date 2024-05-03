#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QPushButton>
#include <QPainter>
#include <QGraphicsRotation>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handleCircleAction();
    void handleSquareAction();
    void handleTriangleAction();
    void handleRhombusAction();
    void handleRectangleAction();
    void handleHexagonAction();
    void handleStar5xAction();
        void handleStar6xAction();
        void handleStar8xAction();
    void handleCrossAction();
    int shouldDrawCircle = 0;
    void on_doubleSpinBox_valueChanged();
    int xCoordinate = 0;
    int yCoordinate = 0;
    int rotationAngle = 0;
    int CentralX  = 0;
    int CentralY = 0;
    int funcCent1 = 0;
    int funcCent2 = 0;
    QString func1 = QString::number(CentralX);
    QString func2 = QString::number(CentralY);
    double perimetr = 0;
    QString p = QString::number(perimetr);
    double Area = 0;
    QString s = QString::number(Area);
        QGraphicsRotation* rotation = new QGraphicsRotation;

    QGraphicsRectItem* rectItem();
        QGraphicsItem* item();

    void updateLabel();




private slots:

    void on_menuButton_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QMenu *m_menu;
    QGraphicsScene* scene;

protected:
    void paintEvent(QPaintEvent* event) override;

};
#endif // MAINWINDOW_H
