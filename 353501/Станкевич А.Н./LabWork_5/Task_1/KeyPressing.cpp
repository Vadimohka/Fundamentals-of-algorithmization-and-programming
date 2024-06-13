#include "mainwindow.h"

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    int code = event->nativeScanCode();
    QVector<QPushButton*> currButtons = getButtons();
    if (code < 67 && currButtons[code - 1] != nullptr && currButtons[code - 1]) {
        if (code != 66) {
            if (code == 50 || code == 62) {
                QString styleSheet = "QPushButton:disabled {border: 2px solid #094065; background-color: #f0f0f0; color: #000000;}";
                currButtons[49]->setStyleSheet(styleSheet);
                currButtons[61]->setStyleSheet(styleSheet);
                currShift = false;
                setNewKeyBoard();
            } else {
                QString styleSheet = "QPushButton:disabled {border: 2px solid #094065; background-color: #f0f0f0; color: #000000;}";
                currButtons[code - 1]->setStyleSheet(styleSheet);
            }
        }
    }
    if (isActiveTrain && (currIndOfText >= currString.size() - 1)) on_bnt_end_clicked();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Tab)
    {
        return;
    }
    int code = event->nativeScanCode();
    QVector<QPushButton*> currButtons = getButtons();

    if (code == -1) return;

    if (code == 66)
    {
        currCaps = !currCaps;
        QString backgroundColor = currCaps ? "yellow" : "#f0f0f0";
        QString textColor = "#000000";
        QString styleSheet = QString("QPushButton:disabled {border: 2px solid #094065; background-color: %1; color: %2;}").arg(backgroundColor, textColor);
        currButtons[code - 1]->setStyleSheet(styleSheet);
        setNewKeyBoard();
    }
    else if (code == 50 || code == 62)
    {
        QString backgroundColor = "blue";
        QString textColor = "#000000";
        QString styleSheet = QString("QPushButton:disabled {border: 2px solid #094065; background-color: %1; color: %2;}").arg(backgroundColor, textColor);
        currButtons[49]->setStyleSheet(styleSheet);
        currButtons[61]->setStyleSheet(styleSheet);
        currShift = true;
        setNewKeyBoard();
    }
    else if (code >= 1 && code <= 66)
    {
        QPushButton* button = currButtons[code - 1];
        if (button != nullptr)
        {
            QString backgroundColor = "red";
            QString textColor = "#000004";
            QString styleSheet = QString("QPushButton:disabled {border: 2px solid #094065; background-color: %1; color: %2;}").arg(backgroundColor, textColor);
            button->setStyleSheet(styleSheet);
            if (isActiveTrain && (currIndOfText < currString.size() - 1)) checkIsCorrectSymbol(event->text());
        }
    }
}

