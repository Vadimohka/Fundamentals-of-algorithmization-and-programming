#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGridLayout"
#include "QDebug"
#include "QTextStream"
#include "QFile"
#include "QDir"
#include "QStandardItemModel"
#include "QLineEdit"
#include "QLabel"
#include "QPushButton"
#include "QFileDialog"
#include "QMessageBox"
#include "QRegularExpression"
#include "QRegularExpressionValidator"
#include "QIntValidator"
#include "QDoubleValidator"
#include "QListWidget"
#include "QTextEdit"
#include "statement.h"
#include "QtAlgorithms"
#include "TemplateSort.h"
#include "QDialog"
#include "dialogedit.h"
#include "checkstr.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QGridLayout *layout;
    QListWidget *list;
    QVector<Statement *> goods;
    DialogEdit *edit_dialog;


    //Лейблы
    QLabel *group_label;
    QLabel *code_label;
    QLabel *name_label;
    QLabel *model_label;
    QLabel *price_label;
    QLabel *count_label;

    //Поля ввода
    QLineEdit *search_line;
    QLineEdit *group_line;
    QLineEdit *code_line;
    QLineEdit *name_line;
    QLineEdit *model_line;
    QLineEdit *price_line;
    QLineEdit *count_line;
    QLineEdit *min_price_line;
    QLineEdit *max_price_line;
    QTextEdit *memo;

    //Кнопки
    QPushButton *add_button;
    QPushButton *exit_button;
    QPushButton *sort_button;
    QPushButton *save_button;
    QPushButton *save_file_button;
    QPushButton *open_file_button;
    QPushButton *search_button;
    QPushButton *delete_button;
    QPushButton *edit_button;

    void UpdateList();

    void AddButtonClick();

    void DisplayInformation();

    void SortByName();

    void FilterByName();

    void FilterByPrice();

    void ClearAddLines();

    bool CheckAddLinesCorrect();

    void DeleteButtonClick();

    void EditButtonClick();

    void SaveFileButtonClick();

    void OpenFileButtonClick();

    void HandleEdit(int count, int price, QString model, QString name, int code, QString group, int number);

};
#endif // MAINWINDOW_H
