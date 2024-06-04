#ifndef VIRTKEYBOARDCONSTS_H
#define VIRTKEYBOARDCONSTS_H

const int KEY_SIZE = 60;
const int KEY_SPOT = 10;
const int MAX_H_KEY_AMNT = 15;
const int MAX_V_KEY_AMNT = 5;

const double KEY_SPOT_HALF = KEY_SPOT * 0.5;
const double KEY_SPOT_1_5 = KEY_SPOT * 1.5;
const double KEY_SIZE_1_5 = KEY_SIZE * 1.5;
const double KEY_SIZE_2 = KEY_SIZE * 2.0;
const double KEY_SPOT_2_5 = KEY_SPOT * 2.5;
const double KEY_SIZE_2_5 = KEY_SIZE * 2.5;
const double KEY_SIZE_3 = KEY_SIZE * 3.0;
const double KEY_SPOT_3_5 = KEY_SPOT * 3.5;
const double KEY_SIZE_4 = KEY_SIZE * 4.0;
const double KEY_SPOT_4_5 = KEY_SPOT * 4.5;
const double KEY_SIZE_4_5 = KEY_SIZE * 4.5;
const double KEY_SIZE_7 = KEY_SIZE * 7.0;
const double KEY_SIZE_11_5 = KEY_SIZE * 11.5;
const double KEY_SIZE_13_5 = KEY_SIZE * 13.5;

const double ROW_1_Y = KEY_SPOT_HALF;
const double ROW_2_Y = KEY_SPOT_1_5 + KEY_SIZE;
const double ROW_3_Y = KEY_SPOT * 2.5 + KEY_SIZE_2;
const double ROW_4_Y = KEY_SPOT * 3.5 + KEY_SIZE_3;
const double ROW_5_Y = KEY_SPOT * 4.5 + KEY_SIZE_4;

#endif // VIRTKEYBOARDCONSTS_H
