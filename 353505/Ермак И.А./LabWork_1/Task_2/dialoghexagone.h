#ifndef DIALOGHEXAGONE_H
#define DIALOGHEXAGONE_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QMessageBox>

namespace Ui {
class DialogHexagone;
}

class DialogHexagone : public QDialog
{
    Q_OBJECT
public:
    explicit DialogHexagone(QWidget *parent = nullptr);
    ~DialogHexagone();
private slots:
    void on_BrushColor_clicked();
    void on_PenColor_clicked();
    void on_buttonBox_accepted();
private:
    Ui::DialogHexagone *ui;
signals:
    void sendData(int x, int y, int side, QColor BrushColor, QColor PenColor);
protected:
    bool BrushColorChoosed = false;
    bool PenColorChoosed = false;
};

#endif // DIALOGHEXAGONE_H

