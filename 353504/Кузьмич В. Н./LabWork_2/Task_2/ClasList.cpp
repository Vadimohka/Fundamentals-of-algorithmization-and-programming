#include "ClasList.h"

ClasList::ClasList()  = default;

ClasList::ClasList(int order_number, int table_number, int col, QString nas){
    ClasList::order_number = order_number;
    ClasList::table_number = table_number;
    ClasList::col = col;
    ClasList::nas = nas;
}
