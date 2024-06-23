#ifndef VIEW_DIALOG_H
#define VIEW_DIALOG_H
#include <QDialog>
#include<QTextEdit>
#include<QVBoxLayout>

class view_Dialog:public QDialog
{
public:
    view_Dialog(QWidget *parent = nullptr):QDialog(parent){
        textEdit = new QTextEdit(this);
        textEdit->setReadOnly(true);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(textEdit);

        setLayout(layout);
    }
    void setText(const QString &text)
    {
        textEdit->setPlainText(text);
    }
private:
    QTextEdit *textEdit;
};

#endif // VIEW_DIALOG_H
