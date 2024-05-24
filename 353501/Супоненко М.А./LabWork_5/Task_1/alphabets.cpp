#include "mainwindow.h"

void MainWindow::initSymbolsOfAlphabet(){
    SIMVOLS.resize(7);
    SIMVOLS[0] = "Q W E R T Y U I O P { } A S D F G H J K L : \" Z X C V B N M < > ?";
    SIMVOLS[1] = "Q W E R T Z U I O P Ü * A S D F G H J K L Ö Ä Y X C V B N M ; : _";
    SIMVOLS[2] = "A Z E R T Y U I O P ¨ £ Q S D F G H J K L M Ù W X C V B N ? . / §";
    SIMVOLS[3] = "Q W E R T Y U I O P } { A S D F G H J K L : \" Z X C V B N M > < ?";
    SIMVOLS[4] = "َ ً ُ ٌ   إ ` ÷ × ؛ < > ِ ٍ ] [   أ ـ ، / : \" ~ ْ } {   آ ' , . ؟";
    SIMVOLS[5] = "Q W E R T Y U I O P { } A S D F G H J K L : \" Z X C V B N M < > ?";
    SIMVOLS[6] = "Й Ц У К Е Н Г Ш Ў З Х ' Ф Ы В А П Р О Л Д Ж Э Я Ч С М І Т Ь Б Ю ,";

    simvols.resize(7);
    simvols[0] = "q w e r t y u i o p [ ] a s d f g h j k l ; ' z x c v b n m , . /";
    simvols[1] = "q w e r t z u i o p ü + a s d f g h j k l ö ä y x c v b n m , . -";
    simvols[2] = "a z e r t y u i o p ^ $ q s d f g h j k l m ù w x c v b n , ; : !";
    simvols[3] = "/ ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ז ס ב ה נ מ צ ת ץ .";
    simvols[4] = "ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ئ ء ؤ ر   ى ة و ز ظ";
    simvols[5] = "q w e r t y u i o p [ ] a s d f g h j k l ; ' z x c v b n m , . /";
    simvols[6] = "й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э я ч с м і т ь б ю .";
}