#ifndef HELPMENU_H
#define HELPMENU_H

#include <QDialog>
#include <QTextEdit>
#include <QKeyEvent>


class HelpMenu: public QDialog
{
public:
    HelpMenu();
    QTextEdit* textEdit;

private slots:
    void keyPressEvent(QKeyEvent* event);

};

#endif // HELPMENU_H
