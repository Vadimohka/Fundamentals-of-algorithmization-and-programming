#ifndef GEOMETRYSHAPE_H
#define GEOMETRYSHAPE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QCheckBox>
#include <QTimer>
#include <QLocale>
#include <QPainter>
#include <QDialog>
#include "clickablelabel.h"
#include <QValidator>
#include <QMessageBox>
#include <cmath>
#include <QtMath>

class GeometryShape : public QWidget
{
    Q_OBJECT
public:
    explicit GeometryShape(QWidget *parent = nullptr);
    ~GeometryShape();
    virtual void closeAllWindows();
protected:
    virtual void draw(QPainter&);
    virtual void deltaRotation(qreal);
    virtual void deltaScale(qreal, qreal);
    virtual void deltaShift(QPointF);

    void animateRotation(qreal, qreal);
    void animateScaleChange(qreal, qreal);

    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    QPointF mouseOldPos;
    qreal actualRotation;
    qreal actualScale;

    virtual void updateArea();
    virtual void updatePerimetr();
    virtual void updateMassCenter();

    virtual void PrintInfo();

    qreal area;
    qreal perimetr;
    QPointF massCenter;

    void paintEvent(QPaintEvent*) override;

    qreal PI = acos(-1);

    bool isMoveble;

    QLabel* Info;

    bool isRotating;
    bool isScaling;
    QCheckBox* EnableMoving;
    QWidget* windowMassCenterChange;
    QWidget* RotateSettings;
    QWidget* ScaleSettings;

    virtual void hideWindows();
    QPushButton* SetRotation;
    QPushButton* showMassCenterChange;
    QPushButton* SetScale;
private slots:
    void on_SetRotation_clicked();
    void on_ConfirmRotationSettings_clicked();
    void on_SetScale_clicked();
    void on_ConfirmScaleSettings_clicked();
    void on_EnableMoving_Clicked();
    void on_showMassCenterChange_clicked();
    void on_confirmMassCenterChange_clicked();
private:

    QGridLayout* changemasscenterlayout;

    QLineEdit* newMassCenterX;
    QLineEdit* newMassCenterY;
    ClickableLabel* wronginput;
    QPushButton* confirmMassCenterChange;

    QGridLayout* SetRotationLayout;


    QLineEdit* RotationDuration;
    QLineEdit* RotationAngle;
    QPushButton* ConfirmRotationSettings;
    ClickableLabel* WrongInputRotation;

    QGridLayout* SetScaleLayout;


    QLineEdit* ScaleDuration;
    QLineEdit* ScaleFactor;
    QPushButton* ConfirmScaleSettings;
    QMessageBox* WrongInputScale;

    QTimer* updateTimer;


};

#endif // GEOMETRYSHAPE_H
