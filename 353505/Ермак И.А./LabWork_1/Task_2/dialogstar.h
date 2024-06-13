#ifndef DIALOGSTAR_H
#define DIALOGSTAR_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>

namespace Ui {
class DialogStar;
}

class DialogStar : public QDialog
{
    Q_OBJECT
public:
    explicit DialogStar(QWidget *parent = nullptr);
    ~DialogStar();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();


private:
    Ui::DialogStar *ui;
signals:
    void sendData(int x, int y, int radius, QColor bColor, QColor pColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGSTAR_H
