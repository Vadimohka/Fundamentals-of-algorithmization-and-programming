#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDir>
#include <QFile>
#include <QKeyEvent>

#include "mytextedit.h"
#include "airport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_comboBox_currentIndexChanged(int index);

    void on_Text_page_input_line_textChanged(const QString &arg1);

    void on_Array_page_text_edit_textChanged();

    void on_Create_button_clicked();

private:
    Ui::MainWindow *ui;

    void SetTextToFile_20(QString &text);
    void Set_text_to_file_name_0(int length);

    QString Labname_path;
    QString Lab_name_0_path;
    QString Txt_path;
    QString Bin_path;

    MyTextEdit* edit;

    int index = 0;

    int* array;
    int array_length = 0;

    void Switch_menu();

    void Start();
    void Add_text_to_mainwindow_choose_2();
    void Add_text_to_mainwindow_from_array();

    void Add_structs_txt_to_window();
    void Add_structs_bin_to_window();

    void Add_struct_to_txt_file(Airport &);
    void Add_struct_to_bin_file(Airport &);

};
#endif // MAINWINDOW_H
