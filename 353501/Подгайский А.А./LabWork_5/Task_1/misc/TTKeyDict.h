#ifndef B3C67EF2_3AD6_44BC_B6C0_5B1B9DA0F8A8
#define B3C67EF2_3AD6_44BC_B6C0_5B1B9DA0F8A8
#include <Qt>
#include <QString>
#include <QMap>
#include <qcontainerfwd.h>
#include "Common.h"

class TTKeyDict{
public:
 
private:
// QMap<QChar, int> map;   const QStringList src {
// "q w e r t y u i o p [ ] a s d f g h j k l ; ' z x c v b n m , . /"
// "Q W E R T Y U I O P { } A S D F G H J K L : " Z X C V B N M < > ?"
// "q w e r t z u i o p ü + a s d f g h j k l ö ä z x c v b n m , . /
// "Q W E R T Z U I O P Ü * A S D F G H J K L Ö Ä Y X C V B N M ; : _
// "ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ئ ء ؤ ر لا ى ة و ز ظ
// َ" ً ُ ٌ لإ إ ` ÷ × ؛ < > ِ ٍ ] [ لأ أ ـ ، / : " ~ ْ } { لآ آ ' , . ؟"
// "й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э я ч с м і т ь б ю .", 
// "Й Ц У К Е Н Г Ш Ў З Х ' Ф Ы В А П Р О Л Д Ж Э Я Ч С М І Т Ь Б Ю ,", 
// "/ ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ז ס ב ה נ מ צ ת ץ .", 
// "Q W E R T Y U I O P { } A S D F G H J K L : " Z X V B N M < > ?)~~";

// const QString  azerty_src = 
// R"~~(a z e r t y u i o p ^ $ q s d f g h j k l m ù w x c v b n , ; : !
// A Z E R T Y U I O P ¨ £ Q S D F G H J K L M % W X C V B N ? . / §)~~";


   const QStringList src = {
    "Q W E R T Y U I O P { } A S D F G H J K L : \" Z X V C     B N M < > , . ?",
"Q W E R T Z U I O P Ü * A S D F G H J K L Ö Ä Y X C V B N M ; : _",
R"~~(ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ئ ء ؤ ر لا ى ة و ز ظ)~~", 
R"~~(Й Ц У К Е Н Г Ш Ў З Х ' Ф Ы В А П Р О Л Д Ж Э Я Ч С М І Т Ь Б Ю ,)~~", 
R"~~(/ ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ז ס ב ה נ מ צ ת ץ .)~~", 
R"~~(Q W E R T Y U I O P { } A S D F G H J K L : " Z X V C B N M < > ?)~~",
};

const QStringList azerty_src = {
R"~~(a z e r t y u i o p ^ $ q s d f g h j k l m ù w x c v b n , ; : !)~~",
R"~~(A Z E R T Y U I O P ¨ £ Q S D F G H J K L M % W X C V B N ? . / §)~~" };

const QString parse_src = R"~~(q w e r t y u i o p [ ] a s d f g h j k l ; ' z x c v b n m , . /
Q W E R T Y U I O P { } A S D F G H J K L : " Z X C V B N M < > ?
q w e r t z u i o p ü + a s d f g h j k l ö ä z x c v b n m , . /
Q W E R T Z U I O P Ü * A S D F G H J K L Ö Ä Y X C V B N M ; : _
ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ئ ء ؤ ر لا ى ة و ز ظ
َ ً ُ ٌ لإ إ ` ÷ × ؛ < > ِ  ٍ ] [ لأ أ ـ ، / : " ~ ْ } { لآ آ ' , . ؟
/ ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ז ס ב ה נ מ צ ת ץ .
й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э я ч с м і т ь б ю .
Й Ц У К Е Н Г Ш Ў З Х ' Ф Ы В А П Р О Л Д Ж Э Я Ч С М І Т Ь Б Ю ,
a z e r t y u i o p ^ $ q s d f g h j k l m ù w x c v b n , ; : !
A Z E R T Y U I O P ¨ £ Q S D F G H J K L M % W X C V B N ? . / §
)~~";

QMap<QString, int> universal_map;
QMap<QString, int> azerty_map;
QMap<QString,int> locale_maps[6];

private:
    void registerKeys(QStringList chars, Common::Locale loc);
public:
    TTKeyDict();
    int getKey(QChar c, Common::Locale loc);
    QString getLocString(Common::Locale loc);
};


#endif /* B3C67EF2_3AD6_44BC_B6C0_5B1B9DA0F8A8 */
