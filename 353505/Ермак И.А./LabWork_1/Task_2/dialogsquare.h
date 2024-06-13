#ifndef DIALOGSQUARE_H
#define DIALOGSQUARE_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QMessageBox>
#include <QString>

namespace Ui {
class DialogSquare;
}
class DialogSquare : public QDialog {
    Q_OBJECT
public:
    explicit DialogSquare(QWidget *parent = nullptr);
    ~DialogSquare();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
private:
    Ui::DialogSquare *ui;
signals:
    void sendData(int x, int y, int side, QColor bColor, QColor pColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGSQUARE_H
