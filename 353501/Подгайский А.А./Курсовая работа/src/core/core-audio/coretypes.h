//
// Created by artemious on 21.02.24.
//

#ifndef AEDIT_CORETYPES_H
#define AEDIT_CORETYPES_H

#include <stdbool.h>

typedef float Sample;

typedef struct {
    Sample * left;
    Sample * right;
    long long current;
    long long size;
    bool isStereo;
} StereoAudioBuffer;


#endif //AEDIT_CORETYPES_H
