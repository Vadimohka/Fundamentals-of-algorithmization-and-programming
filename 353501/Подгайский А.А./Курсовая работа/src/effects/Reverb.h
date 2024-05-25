#ifndef D827DEA6_68A6_4BD2_AAA5_1A8C9E362EE8
#define D827DEA6_68A6_4BD2_AAA5_1A8C9E362EE8

#include "BaseEffect.h"
class Reverb : public BaseEffect{

    static const int COMB_AMOUNT = 4;

    float combGains[COMB_AMOUNT] = {0.742f, 0.590f, 0.678f, 0.711f};
    int combDelays[COMB_AMOUNT] = {4799, 4540, 3120, 5100};

    float allPassGain[2] = {0.634, 0.767};
    float allPassDelay [2]= {670, 900};

protected:
    virtual void _process(Sample* buf, int size, int max_in, short) override;
    virtual void updateProperties() override;
 
public:
    void setUpUi(QWidget*) override;
    Reverb();
};

#endif /* D827DEA6_68A6_4BD2_AAA5_1A8C9E362EE8 */
