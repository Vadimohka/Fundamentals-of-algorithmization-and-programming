#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent)
{

}

void MyTextEdit::keyPressEvent(QKeyEvent* event){

    if(event -> key() == 16777220){
        QString text = this -> toPlainText();

        emit(Put_text_to_MainWindow(text));
    }
    else{
        QTextEdit::keyPressEvent(event);
    }
}
