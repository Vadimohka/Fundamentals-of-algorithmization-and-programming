#ifndef DIALOGTRIANGLE_H
#define DIALOGTRIANGLE_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>

namespace Ui {
class DialogTriangle;
}

class DialogTriangle : public QDialog
{
    Q_OBJECT
public:
    explicit DialogTriangle(QWidget *parent = nullptr);
    ~DialogTriangle();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
private:
    Ui::DialogTriangle *ui;
signals:
    void sendData(int x, int y, int base, int side, QColor bColor, QColor pColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGTRIANGLE_H
