#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <QKeyEvent>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    MyLineEdit(QWidget *parent = nullptr) : QLineEdit(parent)
    {}

    void setHintText(QString hintText, int i){
        this->hintText.push_back(hintText);
        this->hintText = hintText;
        Buf = hintText;
        setFixedSize(1015,30);
        this->setAlignment(Qt::AlignVCenter);
        setText(hintText);
        this->setAlignment(Qt::AlignVCenter);
        setCursorPosition(0);
        this->i = i;
    }

    void keyPressEvent(QKeyEvent *event) override
    {
        // Если это событие клавиши с символом
        if (event->type() == QEvent::KeyPress && event->text().length() == 1) {
            // Получаем символ события клавиши
            QString hintChar = event->text().at(0);

            int cursorPos = cursorPosition();

            // Получаем первый символ из подсказки
            QChar keyPressed = hintText.at(cursorPos);
            if (event->key() == Qt::Key_Shift)
            {
                hintChar = '@';
            }
            else if (event->key() == Qt::Key_Backspace){
                hintChar = '#';
            }
            pressResult(hintChar);
            if (hintText.size() > 1){
            hintText.remove(0, 1);
            }
            else {
            hintText = Buf;
            }
            switch(i){
            case 0:
                if (hintChar == '0') hintChar = '0';
                if (hintChar == '1') hintChar = '1';
                if (hintChar == '2') hintChar = '2';
                if (hintChar == '3') hintChar = '3';
                if (hintChar == '4') hintChar = '4';
                if (hintChar == '5') hintChar = '5';
                if (hintChar == '6') hintChar = '6';
                if (hintChar == '7') hintChar = '7';
                if (hintChar == '8') hintChar = '8';
                if (hintChar == '9') hintChar = '9';
                if (hintChar == 'q') hintChar = "ض";
                if (hintChar == 'w') hintChar = "ص";
                if (hintChar == 'e') hintChar = "ث";
                if (hintChar == 'r') hintChar = "ق";
                if (hintChar == 't') hintChar = "ف";
                if (hintChar == 'y') hintChar = "غ";
                if (hintChar == 'u') hintChar = "ع";
                if (hintChar == 'i') hintChar = "ه";
                if (hintChar == 'o') hintChar = "خ";
                if (hintChar == 'p') hintChar = "ح";
                if (hintChar == '[') hintChar = "ج";
                if (hintChar == ']') hintChar = "د";
                if (hintChar == '`') hintChar = "ذ";
                if (hintChar == 'a') hintChar = "ش";
                if (hintChar == 's') hintChar = "س";
                if (hintChar == 'd') hintChar = "ي";
                if (hintChar == 'f') hintChar = "ب";
                if (hintChar == 'g') hintChar = "ل";
                if (hintChar == 'h') hintChar = "ا";
                if (hintChar == 'j') hintChar = "ت";
                if (hintChar == 'k') hintChar = "ن";
                if (hintChar == 'l') hintChar = "م";
                if (hintChar == ';') hintChar = "ك";
                if (hintChar == '\'') hintChar = "ط";
                if (hintChar == 'z') hintChar = "ئ";
                if (hintChar == 'x') hintChar = "ء";
                if (hintChar == 'c') hintChar = "ؤ";
                if (hintChar == 'v') hintChar = "ر";
                if (hintChar == 'b') hintChar = "لا";
                if (hintChar == 'n') hintChar = "ى";
                if (hintChar == 'm') hintChar = "ة";
                if (hintChar == ',') hintChar = "و";
                if (hintChar == '.') hintChar = "ز";
                if (hintChar == '/') hintChar = "ظ";
                if (hintChar == '-') hintChar = '-';
                if (hintChar == '=') hintChar = '=';
                if (hintChar == ' ') hintChar = ' ';
                break;
            case 1:
                if (hintChar == '0') hintChar = '0';
                if (hintChar == '1') hintChar = '1';
                if (hintChar == '2') hintChar = '2';
                if (hintChar == '3') hintChar = '3';
                if (hintChar == '4') hintChar = '4';
                if (hintChar == '5') hintChar = '5';
                if (hintChar == '6') hintChar = '6';
                if (hintChar == '7') hintChar = '7';
                if (hintChar == '8') hintChar = '8';
                if (hintChar == '9') hintChar = '9';
                if (hintChar == 'q') hintChar = 'q';
                if (hintChar == 'w') hintChar = 'w';
                if (hintChar == 'e') hintChar = 'e';
                if (hintChar == 'r') hintChar = 'r';
                if (hintChar == 't') hintChar = 't';
                if (hintChar == 'y') hintChar = 'z';
                if (hintChar == 'u') hintChar = 'u';
                if (hintChar == 'i') hintChar = 'i';
                if (hintChar == 'o') hintChar = 'o';
                if (hintChar == 'p') hintChar = 'p';
                if (hintChar == '[') hintChar = "´";
                if (hintChar == ']') hintChar = '+';
                if (hintChar == '`') hintChar = '^';
                if (hintChar == 'a') hintChar = 'a';
                if (hintChar == 's') hintChar = 's';
                if (hintChar == 'd') hintChar = 'd';
                if (hintChar == 'f') hintChar = 'f';
                if (hintChar == 'g') hintChar = 'g';
                if (hintChar == 'h') hintChar = 'h';
                if (hintChar == 'j') hintChar = 'j';
                if (hintChar == 'k') hintChar = 'k';
                if (hintChar == 'l') hintChar = 'l';
                if (hintChar == ';') hintChar = "ö";
                if (hintChar == '\'') hintChar = "ä";
                if (hintChar == 'z') hintChar = 'y';
                if (hintChar == 'x') hintChar = 'x';
                if (hintChar == 'c') hintChar = 'c';
                if (hintChar == 'v') hintChar = 'v';
                if (hintChar == 'b') hintChar = 'b';
                if (hintChar == 'n') hintChar = 'n';
                if (hintChar == 'm') hintChar = 'm';
                if (hintChar == ',') hintChar = ',';
                if (hintChar == '.') hintChar = '.';
                if (hintChar == '/') hintChar = '.';
                if (hintChar == '-') hintChar = "ß";
                if (hintChar == '=') hintChar = "´";
                if (hintChar == ' ') hintChar = ' ';
                break;
            case 2:
                if (hintChar == 'q') hintChar = 'a';
                if (hintChar == 'w') hintChar = 'z';
                if (hintChar == 'e') hintChar = 'e';
                if (hintChar == 'r') hintChar = 'r';
                if (hintChar == 't') hintChar = 't';
                if (hintChar == 'y') hintChar = 'y';
                if (hintChar == 'u') hintChar = 'u';
                if (hintChar == 'i') hintChar = 'i';
                if (hintChar == 'o') hintChar = 'o';
                if (hintChar == 'p') hintChar = 'p';
                if (hintChar == '[') hintChar = '^';
                if (hintChar == ']') hintChar = '$';
                if (hintChar == 'a') hintChar = 'q';
                if (hintChar == 's') hintChar = 's';
                if (hintChar == 'd') hintChar = 'd';
                if (hintChar == 'f') hintChar = 'f';
                if (hintChar == 'g') hintChar = 'g';
                if (hintChar == 'h') hintChar = 'h';
                if (hintChar == 'j') hintChar = 'j';
                if (hintChar == 'k') hintChar = 'k';
                if (hintChar == 'l') hintChar = 'l';
                if (hintChar == ';') hintChar = 'm';
                if (hintChar == '\'') hintChar = "ù";
                if (hintChar == 'z') hintChar = 'w';
                if (hintChar == 'x') hintChar = 'x';
                if (hintChar == 'c') hintChar = 'c';
                if (hintChar == 'v') hintChar = 'v';
                if (hintChar == 'b') hintChar = 'b';
                if (hintChar == 'n') hintChar = 'n';
                if (hintChar == 'm') hintChar = ',';
                if (hintChar == ',') hintChar = ';';
                if (hintChar == '.') hintChar = ':';
                if (hintChar == '/') hintChar = '!';
                if (hintChar == '-') hintChar = ')';
                if (hintChar == '=') hintChar = '=';
                if (hintChar == ' ') hintChar = ' ';
                break;
            case 3:
                break;
            case 4:
                if (hintChar == 'q') hintChar = "й";
                if (hintChar == 'w') hintChar = "ц";
                if (hintChar == 'e') hintChar = "у";
                if (hintChar == 'r') hintChar = "к";
                if (hintChar == 't') hintChar = "е";
                if (hintChar == 'y') hintChar = "н";
                if (hintChar == 'u') hintChar = "г";
                if (hintChar == 'i') hintChar = "ш";
                if (hintChar == 'o') hintChar = "ў";
                if (hintChar == 'p') hintChar = "з";
                if (hintChar == '[') hintChar = "х";
                if (hintChar == ']') hintChar = "'";
                if (hintChar == '`') hintChar = "ё";
                if (hintChar == 'a') hintChar = "ф";
                if (hintChar == 's') hintChar = "ы";
                if (hintChar == 'd') hintChar = "в";
                if (hintChar == 'f') hintChar = "а";
                if (hintChar == 'g') hintChar = "п";
                if (hintChar == 'h') hintChar = "р";
                if (hintChar == 'j') hintChar = "о";
                if (hintChar == 'k') hintChar = "л";
                if (hintChar == 'l') hintChar = "д";
                if (hintChar == ';') hintChar = "ж";
                if (hintChar == '\'') hintChar = "э";
                if (hintChar == 'z') hintChar = "я";
                if (hintChar == 'x') hintChar = "ч";
                if (hintChar == 'c') hintChar = "с";
                if (hintChar == 'v') hintChar = "м";
                if (hintChar == 'b') hintChar = "і";
                if (hintChar == 'n') hintChar = "т";
                if (hintChar == 'm') hintChar = "ь";
                if (hintChar == ',') hintChar = "б";
                if (hintChar == '.') hintChar = "ю";
                if (hintChar == '/') hintChar = ".";
                if (hintChar == '-') hintChar = "-";
                if (hintChar == '=') hintChar = "=";
                if (hintChar == ' ') hintChar = ' ';
                break;
            case 5:
                if (hintChar == 'q') hintChar = "/";
                if (hintChar == 'w') hintChar = "'";
                if (hintChar == 'e') hintChar = "ק";
                if (hintChar == 'r') hintChar = "ר";
                if (hintChar == 't') hintChar = "א";
                if (hintChar == 'y') hintChar = "ט";
                if (hintChar == 'u') hintChar = "ו";
                if (hintChar == 'i') hintChar = "ן";
                if (hintChar == 'o') hintChar = "ם";
                if (hintChar == 'p') hintChar = "פ";
                if (hintChar == '[') hintChar = "]";
                if (hintChar == ']') hintChar = "[";
                if (hintChar == '`') hintChar = "ש";
                if (hintChar == 'a') hintChar = "ד";
                if (hintChar == 's') hintChar = "ג";
                if (hintChar == 'd') hintChar = "כ";
                if (hintChar == 'f') hintChar = "ע";
                if (hintChar == 'g') hintChar = "י";
                if (hintChar == 'h') hintChar = "י";
                if (hintChar == 'j') hintChar = "ח";
                if (hintChar == 'k') hintChar = "ל";
                if (hintChar == 'l') hintChar = "ך";
                if (hintChar == ';') hintChar = "ף";
                if (hintChar == '\'') hintChar = ",";
                if (hintChar == 'z') hintChar = "ז";
                if (hintChar == 'x') hintChar = "ס";
                if (hintChar == 'c') hintChar = "ב";
                if (hintChar == 'v') hintChar = "ה";
                if (hintChar == 'b') hintChar = "נ";
                if (hintChar == 'n') hintChar = "מ";
                if (hintChar == 'm') hintChar = "צ";
                if (hintChar == ',') hintChar = "ת";
                if (hintChar == '.') hintChar = "ץ";
                if (hintChar == '/') hintChar = '.';
                if (hintChar == '-') hintChar = '-';
                if (hintChar == '=') hintChar = '=';
                if (hintChar == ' ') hintChar = ' ';
                break;
            }

            // Проверяем, совпадает ли введенный символ с символом из подсказки

            // Устанавливаем новый текст в поле ввода


            setText(hintText);
            setCursorPosition(cursorPos);
            if (keyPressed == hintChar) {

                keyPressResult(0);
            } else {
                qDebug() << keyPressed << " " << hintChar;
                keyPressResult(1);
            }
        }
    }

void keyPressResult(int res){
    emit resultSignal(res);
 }

signals:
    void resultSignal(int result);
    void pressResult(QString hintChar);

private:
    QString hintText;
    QString Buf;
    int i = 0;
};
