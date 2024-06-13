#ifndef DIALOGRECTANGLE_H
#define DIALOGRECTANGLE_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>

namespace Ui {
class DialogRectangle;
}

class DialogRectangle : public QDialog
{
    Q_OBJECT
public:
    explicit DialogRectangle(QWidget *parent = nullptr);
    ~DialogRectangle();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
private:
    Ui::DialogRectangle *ui;
signals:
    void sendData(int x, int y, int width, int height, QColor BruahColor, QColor PenColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGRECTANGLE_H


