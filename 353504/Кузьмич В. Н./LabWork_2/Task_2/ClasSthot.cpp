#include "ClasSthot.h"

ClasSthot::ClasSthot() = default;

ClasSthot::ClasSthot(QString nas, int order_number, int table_number, int col, int price){
    ClasSthot::nas = nas;
    ClasSthot::order_number = order_number;
    ClasSthot::table_number = table_number;
    ClasSthot::col = col;
    ClasSthot::price = price;
    ClasSthot::ful_price = col * price;
}
