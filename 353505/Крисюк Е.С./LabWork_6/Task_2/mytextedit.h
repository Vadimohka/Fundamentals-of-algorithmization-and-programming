#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include <QString>
#include <QMainWindow>

class MyTextEdit : public QTextEdit
{
    Q_OBJECT

signals:
    void Put_text_to_MainWindow(QString &);
public:
    MyTextEdit(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
};

#endif // MYTEXTEDIT_H
