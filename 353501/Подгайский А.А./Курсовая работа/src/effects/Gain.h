#ifndef B3F47FD0_696B_4651_B239_0E26D650F163
#define B3F47FD0_696B_4651_B239_0E26D650F163
#include "BaseEffect.h"
#include "qslider.h"
#include <qspinbox.h>


class Gain : public BaseEffect
{

private:
    float _koef = 1.0f;

private:
    QDoubleSpinBox* _dbBox;

protected:
    virtual void _process(Sample* buf, int size, int max_in, short) override;
    virtual void updateProperties() override;
 
public:
    void setUpUi(QWidget*) override;


};

#endif /* B3F47FD0_696B_4651_B239_0E26D650F163 */
