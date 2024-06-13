#include "language.h"

Language::Language()
{
    /***********************ENGLISH*****************/

    english[0] = " ";
    english[49] = "`";
    english[10] = "1";
    english[11] = "2";
    english[12] = "3";
    english[13] = "4";
    english[14] = "5";
    english[15] = "6";
    english[16] = "7";
    english[17] = "8";
    english[18] = "9";
    english[19] = "0";
    english[20] = "-";
    english[21] = "=";
    //english[22] = "";
    english[24] = "q";
    english[25] = "w";
    english[26] = "e";
    english[27] = "r";
    english[28] = "t";
    english[29] = "y";
    english[30] = "u";
    english[31] = "i";
    english[32] = "o";
    english[33] = "p";
    english[34] = "[";
    english[35] = "]";
    english[38] = "a";
    english[39] = "s";
    english[40] = "d";
    english[41] = "f";
    english[42] = "g";
    english[43] = "h";
    english[44] = "j";
    english[45] = "k";
    english[46] = "l";
    english[47] = ";";
    english[48] = "'";
    //english[50] = "";
    english[52] = "z";
    english[53] = "x";
    english[54] = "c";
    english[55] = "v";
    english[56] = "b";
    english[57] = "n";
    english[58] = "m";
    english[59] = ",";
    english[60] = ".";
    english[61] = "/";
    //english[62] = "";

    /*********************RUSSIAN****************/

    russian[0] = " ";
    russian[49] = "ё";
    russian[10] = "1";
    russian[11] = "2";
    russian[12] = "3";
    russian[13] = "4";
    russian[14] = "5";
    russian[15] = "6";
    russian[16] = "7";
    russian[17] = "8";
    russian[18] = "9";
    russian[19] = "0";
    russian[20] = "-";
    russian[21] = "=";
    //russian[22] = "";
    russian[24] = "й";
    russian[25] = "ц";
    russian[26] = "у";
    russian[27] = "к";
    russian[28] = "е";
    russian[29] = "н";
    russian[30] = "г";
    russian[31] = "ш";
    russian[32] = "щ";
    russian[33] = "з";
    russian[34] = "х";
    russian[35] = "ъ";
    russian[38] = "ф";
    russian[39] = "ы";
    russian[40] = "в";
    russian[41] = "а";
    russian[42] = "п";
    russian[43] = "р";
    russian[44] = "о";
    russian[45] = "л";
    russian[46] = "д";
    russian[47] = "ж";
    russian[48] = "э";
    //russian[50] = "";
    russian[52] = "я";
    russian[53] = "ч";
    russian[54] = "с";
    russian[55] = "м";
    russian[56] = "и";
    russian[57] = "т";
    russian[58] = "ь";
    russian[59] = "б";
    russian[60] = "ю";
    russian[61] = ".";
    //russian[62] = "";

    /******************GERMAN*********************/

    german[0] = " ";
    german[49] = "^";
    german[10] = "1";
    german[11] = "2";
    german[12] = "3";
    german[13] = "4";
    german[14] = "5";
    german[15] = "6";
    german[16] = "7";
    german[17] = "8";
    german[18] = "9";
    german[19] = "0";
    german[20] = "ß";
    german[21] = "´";
    //german[22] = "";
    german[24] = "q";
    german[25] = "w";
    german[26] = "e";
    german[27] = "r";
    german[28] = "t";
    german[29] = "z";
    german[30] = "u";
    german[31] = "i";
    german[32] = "o";
    german[33] = "p";
    german[34] = "ü";
    german[35] = "+";
    german[38] = "a";
    german[39] = "s";
    german[40] = "d";
    german[41] = "f";
    german[42] = "g";
    german[43] = "h";
    german[44] = "j";
    german[45] = "k";
    german[46] = "l";
    german[47] = "ö";
    german[48] = "ä";
    //german[50] = "";
    german[52] = "y";
    german[53] = "x";
    german[54] = "c";
    german[55] = "v";
    german[56] = "b";
    german[57] = "n";
    german[58] = "m";
    german[59] = ",";
    german[60] = ".";
    german[61] = "-";
    //german[62] = "";

    /**********************FRENCH********************/

    french[0] = " ";
    french[49] = "²";
    french[10] = "&";
    french[11] = "é";
    french[12] = "\"";
    french[13] = "'";
    french[14] = "(";
    french[15] = "-";
    french[16] = "è";
    french[17] = "_";
    french[18] = "ç";
    french[19] = "à";
    french[20] = ")";
    french[21] = "=";
    //frenchan[22] = "";
    french[24] = "a";
    french[25] = "z";
    french[26] = "e";
    french[27] = "r";
    french[28] = "t";
    french[29] = "y";
    french[30] = "u";
    french[31] = "i";
    french[32] = "o";
    french[33] = "p";
    french[34] = "^";
    french[35] = "$";
    french[38] = "q";
    french[39] = "s";
    french[40] = "d";
    french[41] = "f";
    french[42] = "g";
    french[43] = "h";
    french[44] = "j";
    french[45] = "k";
    french[46] = "l";
    french[47] = "m";
    french[48] = "ù";
    //frenchan[50] = "";
    french[52] = "w";
    french[53] = "x";
    french[54] = "c";
    french[55] = "v";
    french[56] = "b";
    french[57] = "n";
    french[58] = ",";
    french[59] = ";";
    french[60] = ":";
    french[61] = "!";
    //frenchan[62] = "";

    /*********************ARABIAN****************/

    arabian[0] = " ";
    arabian[49] = "ذ";
    arabian[10] = "1";
    arabian[11] = "2";
    arabian[12] = "3";
    arabian[13] = "4";
    arabian[14] = "5";
    arabian[15] = "6";
    arabian[16] = "7";
    arabian[17] = "8";
    arabian[18] = "9";
    arabian[19] = "0";
    arabian[20] = "-";
    arabian[21] = "=";
    //arabian[22] = "";
    arabian[24] = "ض";
    arabian[25] = "ص";
    arabian[26] = "ث";
    arabian[27] = "ق";
    arabian[28] = "ف";
    arabian[29] = "غ";
    arabian[30] = "ع";
    arabian[31] = "ه";
    arabian[32] = "خ";
    arabian[33] = "ح";
    arabian[34] = "ج";
    arabian[35] = "د";
    arabian[38] = "ش";
    arabian[39] = "س";
    arabian[40] = "ي";
    arabian[41] = "ب";
    arabian[42] = "ل";
    arabian[43] = "ا";
    arabian[44] = "ت";
    arabian[45] = "ن";
    arabian[46] = "م";
    arabian[47] = "ك";
    arabian[48] = "ط";
    //arabian[50] = "";
    arabian[52] = "ئ";
    arabian[53] = "ء";
    arabian[54] = "ؤ";
    arabian[55] = "ر";
    arabian[56] = "لا";
    arabian[57] = "ى";
    arabian[58] = "ة";
    arabian[59] = "و";
    arabian[60] = "ز";
    arabian[61] = "ظ";
    //arabian[62] = "";

    /*******************CHINEESE*********************/

    chineese[0] = " ";
    chineese[49] = "`";
    chineese[10] = "1";
    chineese[11] = "2";
    chineese[12] = "3";
    chineese[13] = "4";
    chineese[14] = "5";
    chineese[15] = "6";
    chineese[16] = "7";
    chineese[17] = "8";
    chineese[18] = "9";
    chineese[19] = "0";
    chineese[20] = "-";
    chineese[21] = "=";
    //chineese[22] = "";
    chineese[24] = "q";
    chineese[25] = "w";
    chineese[26] = "e";
    chineese[27] = "r";
    chineese[28] = "t";
    chineese[29] = "y";
    chineese[30] = "u";
    chineese[31] = "i";
    chineese[32] = "o";
    chineese[33] = "p";
    chineese[34] = "[";
    chineese[35] = "]";
    chineese[38] = "a";
    chineese[39] = "s";
    chineese[40] = "d";
    chineese[41] = "f";
    chineese[42] = "g";
    chineese[43] = "h";
    chineese[44] = "j";
    chineese[45] = "k";
    chineese[46] = "l";
    chineese[47] = ";";
    chineese[48] = "'";
    //chineese[50] = "";
    chineese[52] = "z";
    chineese[53] = "x";
    chineese[54] = "c";
    chineese[55] = "v";
    chineese[56] = "b";
    chineese[57] = "n";
    chineese[58] = "m";
    chineese[59] = ",";
    chineese[60] = ".";
    chineese[61] = "/";
    //chineese[62] = "";

    /*********************BELORUSIAN********************/

    belorussian[0] = " ";
    belorussian[49] = "ё";
    belorussian[10] = "1";
    belorussian[11] = "2";
    belorussian[12] = "3";
    belorussian[13] = "4";
    belorussian[14] = "5";
    belorussian[15] = "6";
    belorussian[16] = "7";
    belorussian[17] = "8";
    belorussian[18] = "9";
    belorussian[19] = "0";
    belorussian[20] = "-";
    belorussian[21] = "=";
    //belorussian[22] = "";
    belorussian[24] = "й";
    belorussian[25] = "ц";
    belorussian[26] = "у";
    belorussian[27] = "к";
    belorussian[28] = "е";
    belorussian[29] = "н";
    belorussian[30] = "г";
    belorussian[31] = "ш";
    belorussian[32] = "ў";
    belorussian[33] = "з";
    belorussian[34] = "х";
    belorussian[35] = "'";
    belorussian[38] = "ф";
    belorussian[39] = "ы";
    belorussian[40] = "в";
    belorussian[41] = "а";
    belorussian[42] = "п";
    belorussian[43] = "р";
    belorussian[44] = "о";
    belorussian[45] = "л";
    belorussian[46] = "д";
    belorussian[47] = "ж";
    belorussian[48] = "э";
    //belorussian[50] = "";
    belorussian[52] = "я";
    belorussian[53] = "ч";
    belorussian[54] = "с";
    belorussian[55] = "м";
    belorussian[56] = "і";
    belorussian[57] = "т";
    belorussian[58] = "ь";
    belorussian[59] = "б";
    belorussian[60] = "ю";
    belorussian[61] = ".";
    //belorussian[62] = "";

    /***********************IVRIT********************/

    ivrit[0] = " ";
    ivrit[49] = ";";
    ivrit[10] = "1";
    ivrit[11] = "2";
    ivrit[12] = "3";
    ivrit[13] = "4";
    ivrit[14] = "5";
    ivrit[15] = "6";
    ivrit[16] = "7";
    ivrit[17] = "8";
    ivrit[18] = "9";
    ivrit[19] = "0";
    ivrit[20] = "-";
    ivrit[21] = "=";
    //ivrit[22] = "";
    ivrit[24] = "/";
    ivrit[25] = "'";
    ivrit[26] = "ק";
    ivrit[27] = "ר";
    ivrit[28] = "א";
    ivrit[29] = "ט";
    ivrit[30] = "ו";
    ivrit[31] = "ן";
    ivrit[32] = "ם";
    ivrit[33] = "פ";
    ivrit[34] = "]";
    ivrit[35] = "[";
    ivrit[38] = "ש";
    ivrit[39] = "ד";
    ivrit[40] = "ג";
    ivrit[41] = "כ";
    ivrit[42] = "ע";
    ivrit[43] = "י";
    ivrit[44] = "ח";
    ivrit[45] = "ל";
    ivrit[46] = "ך";
    ivrit[47] = "ף";
    ivrit[48] = ",";
    //ivrit[50] = "";
    ivrit[52] = "ז";
    ivrit[53] = "ס";
    ivrit[54] = "ב";
    ivrit[55] = "ה";
    ivrit[56] = "נ";
    ivrit[57] = "מ";
    ivrit[58] = "צ";
    ivrit[59] = "ת";
    ivrit[60] = "ץ";
    ivrit[61] = ".";
    //ivrit[62] = "";
}

QMap<int, QString> Language::getMap(int index)
{
    switch (index) {
    case 0:
        return english;
        break;
    case 1:
        return russian;
        break;
    case 2:
        return german;
        break;
    case 3:
        return french;
        break;
    case 4:
        return arabian;
        break;
    case 5:
        return chineese;
        break;
    case 6:
        return belorussian;
        break;
    case 7:
        return ivrit;
        break;
    default:
        throw 1;
        break;
    }
}

QVector<QString> Language::getKeys(int index)
{
    QVector<QString> ans;
    ans.resize(4);

    switch (index) {
    case 0:
        ans[0] = english1;
        ans[1] = english2;
        ans[2] = english3;
        ans[3] = english4;
        return ans;
        break;
    case 1:
        ans[0] = russian1;
        ans[1] = russian2;
        ans[2] = russian3;
        ans[3] = russian4;
        return ans;
        break;
    case 2:
        ans[0] = german1;
        ans[1] = german2;
        ans[2] = german3;
        ans[3] = german4;
        return ans;
        break;
    case 3:
        ans[0] = french1;
        ans[1] = french2;
        ans[2] = french3;
        ans[3] = french4;
        return ans;
        break;
    case 4:
        ans[0] = arabian1;
        ans[1] = arabian2;
        ans[2] = arabian3;
        ans[3] = arabian4;
        return ans;
        break;
    case 5:
        ans[0] = chineese1;
        ans[1] = chineese2;
        ans[2] = chineese3;
        ans[3] = chineese4;
        return ans;
        break;
    case 6:
        ans[0] = belorussian1;
        ans[1] = belorussian2;
        ans[2] = belorussian3;
        ans[3] = belorussian4;
        return ans;
        break;
    case 7:
        ans[0] = ivrit1;
        ans[1] = ivrit2;
        ans[2] = ivrit3;
        ans[3] = ivrit4;
        return ans;
        break;
    default:
        throw 1;
        break;
    }
}
