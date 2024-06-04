#include "Gain.h"
#include "BaseEffect.h"
#include <qnamespace.h>
#include <qslider.h>
#include <qgridlayout.h>
#include <qspinbox.h>
#include <qwidget.h>
#include <qlabel.h>
#include <QGridLayout>


void Gain::_process(Sample* buf, int size, int max_out, short){
    for(int i = 0; i < size; ++i){
        buf[i] *= _koef;
    }
}

void Gain::setUpUi(QWidget* widget){
    BaseEffect::setUpUi(widget);
    _dbBox = new QDoubleSpinBox;
    _dbBox->setRange(0.0, 4.0);
    _dbBox->setSingleStep(0.5);
    layout->addRow("Gain (ratio)", _dbBox);
}

void Gain::updateProperties(){
    _koef = _dbBox->value();
}