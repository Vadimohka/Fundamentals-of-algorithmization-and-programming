#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "table.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

    void openFile();
    void putDataFromFileToTable();

private slots:
    void on_btnSelectFile_clicked();

    void on_line_author_returnPressed();

    void on_lineEdit_title_returnPressed();

    void on_lineEdit_publisher_returnPressed();

    void on_lineEdit_year_returnPressed();

    void on_lineEdit_pages_returnPressed();

    void on_btn_AddBook_clicked();

    void on_lineEdit_NumToEdit_returnPressed();

    void on_lineEdit_EditedRow_returnPressed();

    void on_btn_SortYear_clicked();

    void on_btn_SortPublisher_clicked();

    void on_lineInput_returnPressed();

    void on_btn_delete_clicked(bool checked);

    void on_btn_find_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QFile file;
    QString pathToFile;
    Table *table;
    QVector <Book*> books;
    QRegularExpression re;

    QString author;
    QString title;
    QString publisher;

    int year{};
    int pages{};
    int n{};

    bool WasOpen = false;
    bool WasAuthor = false;
    bool WasTitle = false;
    bool WasPubl = false;
    bool WasYear = false;
    bool WasPages = false;
    bool WasNum = false;
};
#endif // MAINWINDOW_H
