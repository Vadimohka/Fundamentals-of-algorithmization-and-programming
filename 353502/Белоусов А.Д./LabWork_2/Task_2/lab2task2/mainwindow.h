#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fileservice.h"
#include "groupcontainer.h"
#include "productcontainer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum currentMode
{
    editMode,
    addMode
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void updateTable();

    void updateGroups();

private slots:
    void on_add_button_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_endEdit_button_clicked();

    void on_find_with_button_clicked();

    void on_less_then_button_clicked();

    void on_sort_button_clicked();

    void on_addGroup_textEdit_clicked();

    void on_save_button_clicked();

    void on_open_button_clicked();

private:
    Ui::MainWindow *ui;
    GroupContainer* groupContainer{new GroupContainer};
    ProductContainer* productContainer{new ProductContainer};
    FileService* fileService{new FileService};
    std::vector<Product*>* productsToShow{new std::vector<Product*>};

    currentMode mode{addMode};
    int64_t positionToEdit{0};
};
#endif // MAINWINDOW_H
