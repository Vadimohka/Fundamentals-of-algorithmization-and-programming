#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTimer>
#include <QMessageBox>
#include <QTextCursor>
#include <QCursor>

#include "keyboard.h"
#include "customtextedit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event) override;

private slots:

    void on_beginButton_clicked();

public slots:
    void updateTime();
    void oneWordPlus();
    void endOfInput();

    void addCorrectCharsCount();
    void addIncorrectCharsCount();
    void generateRandomWords(int count);

    void initializeDictionaries();

    void openNewFile();


private:
    Ui::MainWindow *ui;
    Keyboard* keyboard;
    QTimer* timer;
    CustomTextEdit* textEdit;

    long long elapsedTime;
    long long inputedWords;
    long long incorrectCharsCount, correctCharsCount;

    QMap<int, QVector<QString>> DictionariesVector;
    QString openedFileName;
};
#endif // MAINWINDOW_H
