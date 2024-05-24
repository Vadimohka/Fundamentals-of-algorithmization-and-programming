

#include "Constructor.h"
#include "BaseEffect.h"
#include "Chorus.h"
#include "Gain.h"
#include "PassEQ.h"
#include "Pitch.h"
#include "Reverb.h"
#include "Robotiser.h"
#include "TimePitch.h"
#include "Reverb.h"

BaseEffect* Constructor::getEffect(const std::string& name){
    BaseEffect * effect = nullptr;
    
    if(name == "Gain"){
        effect = new Gain{};
        effect->setObjectName("Gain");
    } else if(name == "Low/High-pass"){
        effect = new PassEQ{};
        effect->setObjectName("Low/High-pass");
    } else if(name == "Robotiser"){
        effect = new Robotiser{};
        effect->setObjectName("Robotiser");
    }
    // } else if(name == "Chorus"){
    //     effect = new Chorus{};
    //     effect->setObjectName("Chorus"); }
     else if(name == "Pitch") {
        effect = new Pitch{};
        effect->setObjectName("Pitch");
    } else if (name == "TimePitch"){
        effect = new TimePitch{};
        effect->setObjectName("TimePitch");
    } else if (name == "Reverb"){
        effect = new Reverb{};
        effect->setObjectName("Reverb");
    }

    return effect;
}