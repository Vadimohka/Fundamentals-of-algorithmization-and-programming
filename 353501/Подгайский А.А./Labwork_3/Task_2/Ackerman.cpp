#include "Ackerman.h"
#include <cstdint>
#include <qdebug.h>
#include <qlogging.h>
#include <qtypes.h>
#include <QDebug>
#include <stdexcept>

int Ackerman::call = 0;
bool Ackerman::ok = true;

uint32_t Ackerman::p_value(uint8_t m, uint32_t n) {
  ++call;
  if (call > c_maxCalls) {
    ok = false;
  }
  if (!ok) {
    
    return 0;
  }
  
    if(m  == 0){
        return n+1;
    } else if(m > 0 && n == 0){
        return p_value(m-1, 1);
    } else if(m > 0 && n > 0){
        return p_value(m-1, p_value(m, n-1));
    } else {
        return 0;
    }
}

std::optional<uint32_t> Ackerman::Value(uint32_t m, uint32_t n) {
    //qDebug() << "_ENTER_";
    call = 0;
    ok = true;

    if (m > 3 || n > c_limits[m]) {
        return {};
    }
    
    auto val = p_value(m, n);
    
    if (!ok) {
        qDebug() << "spent " << c_maxCalls << " stopping";
        return {};
    } else {
        return {val};
    }
        
}