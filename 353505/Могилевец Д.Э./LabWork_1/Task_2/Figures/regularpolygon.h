#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "polygon.h"

class RegularPolygon : public Polygon
{
public:
    RegularPolygon();
    RegularPolygon(int);
    ~RegularPolygon();
private:
    QPushButton* showVertexAmountChange;
    QWidget* changeWidget;
    QGridLayout* changingLayout;
    QLineEdit* entervertexesAmount;
    QPushButton* confirmNewAmount;
    QMessageBox* wronginput;
    void hideWindows() override;
private slots:
    void on_showVertexAmountChange_clicked();
    void on_confirmNewAmount_clicked();
};

#endif // REGULARPOLYGON_H
