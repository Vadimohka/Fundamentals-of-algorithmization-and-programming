#include "mainwindow.h"

void MainWindow::setKeyboard(int index)
{
    for (int  i = 0; i < 66; ++i)
    {
        if(keys[i] != nullptr && keys[i])
        {
            keys[i]->setText(keyboard[index][i + 1]);
        }
    }
}

void MainWindow::initKeyboard()
{
    keys = {
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            ui->pushButton_10,
            ui->pushButton_11,
            ui->pushButton_12,
            ui->pushButton_13,
            ui->pushButton_14,
            ui->pushButton_15,
            ui->pushButton_16,
            ui->pushButton_17,
            ui->pushButton_18,
            ui->pushButton_19,
            ui->pushButton_20,
            ui->pushButton_21,
            nullptr,
            nullptr,
            ui->pushButton_24,
            ui->pushButton_25,
            ui->pushButton_26,
            ui->pushButton_27,
            ui->pushButton_28,
            ui->pushButton_29,
            ui->pushButton_30,
            ui->pushButton_31,
            ui->pushButton_32,
            ui->pushButton_33,
            ui->pushButton_34,
            ui->pushButton_35,
            nullptr,
            nullptr,
            ui->pushButton_38,
            ui->pushButton_39,
            ui->pushButton_40,
            ui->pushButton_41,
            ui->pushButton_42,
            ui->pushButton_43,
            ui->pushButton_44,
            ui->pushButton_45,
            ui->pushButton_46,
            ui->pushButton_47,
            ui->pushButton_48,
            ui->pushButton_49,
            ui->pushButton_50,
            ui->pushButton_51,
            ui->pushButton_52,
            ui->pushButton_53,
            ui->pushButton_54,
            ui->pushButton_55,
            ui->pushButton_56,
            ui->pushButton_57,
            ui->pushButton_58,
            ui->pushButton_59,
            ui->pushButton_60,
            ui->pushButton_61,
            ui->pushButton_62,
            nullptr,
            nullptr,
            ui->pushButton_65,
            ui->pushButton_66
    };

    keyboard.resize(7);

    QString str = R"TOKEN(1 2 3 4 5 6 7 8 9 0 - = ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ذ \ ئ ء ؤ ر لا ى ة و ز ظ
1 2 3 4 5 6 7 8 9 0 - = й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э ё \ я ч с м і т ь б ю .
1 2 3 4 5 6 7 8 9 0 - = q w e r t y u i o p [ ] a s d f g h j k l ; ' ` \ z x c v b n m , . /
1 2 3 4 5 6 7 8 9 0 - = q w e r t y u i o p [ ] a s d f g h j k l ; ' ` \ z x c v b n m , . /
! é " ' ( - è _ ç à ) = a z e r t y u i o p ^ $ q s d f g h j k l m ù ² * w x c v b n , ; : !
1 2 3 4 5 6 7 8 9 0 ß ´ q w e r t z u i o p ü + a s d f g h j k l ö ä ^ # y x c v b n m , . -
1 2 3 4 5 6 7 8 9 0 - = / ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ; \ ז ס ב ה נ מ צ ת ץ .)TOKEN";

    QStringList langs = str.split("\n");
    for(int i = 0; i < langs.count(); ++i)
    {
        if (langs[i].isEmpty())
        {
            break;
        }
        QStringList keys = langs[i].split(" ");

        int k = 10;
        int n = 0;
        while(k < 62)
        {
            if (k == 22 || k == 36)
            {
                k += 2;
                continue;
            }
            if (k == 50)
            {
                ++k;
                continue;
            }
            keyboard[i][k] = keys[n];
            ++k;
            ++n;
        }
        keyboard[i][66] = "caps";
        keyboard[i][65] = "space";
        keyboard[i][50] = "shift";
        keyboard[i][62] = "shift";
    }
}
