//
// Created by artemious on 27.02.24.
//

#include "CoreInfo.h"
#include "CoreAudio.h"
#include <qdatetime.h>

namespace ae {
/*Unsafe function, does not check ranges due to fast response necessary
* Octave is indexed from 1
*/
    double CoreInfo::getFreq(Note note, short octave) {
        short ind = 2 + (octave-1)*12 + static_cast<short>(note);
        return freqTable[ind];
    }
    
} 


QString ae::CoreInfo::getTimeString(size_t ind) {
    int msecs_dur = std::round ( 1000 * (qreal)ind / CoreAudio::SamplingFrequency );    
    return QTime(0,0,0,0).addMSecs(msecs_dur).toString("hh:mm:ss.zzz");
}

QString ae::CoreInfo::getCurrentTimeString() {
    return getTimeString(CoreAudio::getBuffer().current);    
}
