#ifndef E9A35319_4F4D_4BAD_9620_684BEF0F12F9
#define E9A35319_4F4D_4BAD_9620_684BEF0F12F9

#include "BaseEffect.h"
#include "QSpinBox"

class TimePitch : public BaseEffect
{

private:
    float koef = 0.6f;
    QDoubleSpinBox* koefBox;

protected:
    virtual void _process(Sample* buf, int size, int max_in, short) override;
    virtual void apply() override;
    virtual void updateProperties() override;
 
public:
    void setUpUi(QWidget*) override;
    TimePitch();


};

#endif /* E9A35319_4F4D_4BAD_9620_684BEF0F12F9 */
