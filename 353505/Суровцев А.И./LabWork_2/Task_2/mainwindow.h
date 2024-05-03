#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include <QDesktopServices>
#include <QDateTime>
#include "borrowing.h"
#include "reader.h"
#include "book.h"
#include "library.h"
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
    void displayVectorInList(const QVector<QString> &data);
    void addtofiles(const QString &arg1, const QString path);
    void removeLineFromFile(const QString& filename, int lineNumberToRemove);
    bool isValidDate(const QString &dateString);
    void my_style_button();
    void my_style_button2();
    void setup_buttons1();
    void dis_setup_buttons1();
    void setup_buttons2();
    void dis_setup_buttons2();

private slots:


    void on_bntOpen_Files_clicked();

    void on_ln_vidachi_textChanged(const QString &arg1);

    void on_ln_vernut_textChanged(const QString &arg1);

    void on_ln_vernul_textChanged(const QString &arg1);

    void on_bnt_info_book_clicked();

    void on_bnt_info_reader_clicked();

    void on_bnt_info_get_book_clicked();

    void on_ln_mob_number_textChanged(const QString &arg1);

    void on_ln_coder_textChanged(const QString &arg1);

    void on_ln_codeb_textChanged(const QString &arg1);

    void on_ln_code_of_reader_textChanged(const QString &arg1);

    void on_ln_year_of_edition_textChanged(const QString &arg1);

    void on_ln_code_of_book_textChanged(const QString &arg1);

    void on_bnt_add_to_file_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_bnt_end_clicked();

    void on_bnt_vibor_clicked();

    void on_bnt_rem_vib_clicked();

    void on_bntSort_clicked();

    void on_bnt_dolj_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    const QString path_work = "/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/workfile.txt";
    const QString path_book = "/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/book_file.txt";
    const QString path_reader = "/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/reader_file.txt";
    const QString path_borrowing = "/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/borrowing_file.txt";
    QString res1;
    QString res2;
    QString res3;
    QVector <Book> books;
    QVector <Reader> readers;
    QVector <Borrowing> borrowings;
    Library l;
    int ind_lastSort = -1;
    bool dolj = 0;
};
#endif // MAINWINDOW_H
