#ifndef DIALOGELLIPSE_H
#define DIALOGELLIPSE_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>

namespace Ui {
class DialogEllipse;
}

class DialogEllipse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEllipse(QWidget *parent = nullptr);
    ~DialogEllipse();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
private:
    Ui::DialogEllipse *ui;
signals:
    void sendData(int x, int y, int rH, int rV, QColor bColor, QColor pColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGELLIPSE_H
