#ifndef DIALOGCIRCLE_H
#define DIALOGCIRCLE_H

#include <QDialog>
#include <QColor>
#include <QColorDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class DialogCircle;
}

class DialogCircle : public QDialog
{
    Q_OBJECT
public:
    explicit DialogCircle(QWidget *parent = nullptr);
    ~DialogCircle();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
private:
    Ui::DialogCircle *ui;

signals:
    void sendData(int x, int y, int r, QColor bColor, QColor pColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGCIRCLE_H

