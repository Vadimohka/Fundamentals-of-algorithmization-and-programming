#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"library.h"
#include <QMainWindow>
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
    void displayBookList();
    void displayReaderList();
    void displayBookLoanList();
    void displayOverdueBooksLoanList();

private slots:
    void on_addBook_clicked();

    void on_removeBook_clicked();

    void on_findBooksByTitle_clicked();

    void on_addReader_clicked();

    void on_findReadersByFullName_clicked();

    void on_addBookLoan_clicked();



    void on_saveData_clicked();

private:
    Ui::MainWindow *ui;
    Library library; // Объект библиотеки для работы с книгами, читателями и книгами взятыми в аренду
    void sortBooksByCode(QList<Book>& books);
    void sortReaderByCode(QList<Reader>& redears);
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
