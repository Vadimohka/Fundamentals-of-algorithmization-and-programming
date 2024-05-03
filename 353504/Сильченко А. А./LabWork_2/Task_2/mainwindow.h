#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deputy.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int bimage=0;
    std::vector<Deputy> book_list;
    std::vector<Deputy> current_book_list;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int LAST_INDEX = 0;


    Deputy parse_book_from_str(std::string s) {
        std::string author, book_nm, comp_book;
        int year, quant, num;

        std::vector<std::string> segments;
        int pos = 0;
        while (s.size() != 0) {
            pos = s.find(";");
            segments.push_back(s.substr(0,pos));
            s.erase(0,pos+1);
        }
        author = segments[0];
        book_nm = segments[1];
        comp_book = segments[2];
        year = stoi(segments[3]);
        quant = stoi(segments[4]);
        num = stoi(segments[5]);

        return Deputy(author, book_nm, comp_book, year, quant, num);
    }

private slots:
    void on_pushButton_2_clicked();

    void on_search_button_clicked();

    void show_vector_in_table(std::vector<Deputy>);

    void on_sort_year_clicked();

    void on_comboBox_Company_currentIndexChanged(int index);

    void on_pushButton_Save_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_buttonCreateSave_clicked();

    void on_buttonCreateAdd_clicked();

    void on_pushAlarm_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
