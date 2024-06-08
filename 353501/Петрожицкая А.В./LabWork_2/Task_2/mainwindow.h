#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QMessageBox>
#include <QTextStream>
#include "menu.h"
#include "order.h"
#include <QFileDialog>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    std::vector <Menu> menu;
    std::vector <Order> orders;
    bool wasInMenuCheck(const QString DishName);
    int findOrderInMenu(const QString calcDishName);
    void drawMenu();
    QString path;
public:
    MainWindow();

private slots:
    void addOrder();
    void addDish();
    void sortMenu();
    void calculateCheck();
    void popular();
    void change();
    void openFile();
    void deleteOrder();
    void saveFile();
protected:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
