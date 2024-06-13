#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Date d = Date(0,0,0);
public:
    std::vector<Date> date_list;
    std::vector<Date> current_date_list;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int LAST_INDEX = 0;

    Date parse_date_from_str(std::string s) {
        int d, m, y;

        std::vector<std::string> segments;
        int pos = 0;
        while(pos < s.size()){
            pos = s.find(".");
            segments.push_back(s.substr(0,pos));
            s.erase(0,pos+1);
        }

        d = stoi(segments[0]);
        m = stoi(segments[1]);
        y = stoi(segments[2]);

        return Date(d, m, y);
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_set_date_clicked();

    // void on_groupBox_clicked();

    void on_on_buttonCreateSave_clicked_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_on_buttonCreateAdd_clicked_clicked();

    void show_vector_in_table(std::vector<Date>);

    void on_pushButton_Save_to_File_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
