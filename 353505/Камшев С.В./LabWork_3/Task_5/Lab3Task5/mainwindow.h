#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QDirIterator>
#include <QTreeWidget>


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
    QPushButton* button = new QPushButton;
    QLabel* numberOfFoldersLabel = new QLabel;
    QLabel* numberOfFilesLabel = new QLabel;
    QTreeWidget* treeWidget = new QTreeWidget;


    int quantityOfFolders = 0;

    int func(QString str, int &quantityOfFolders, QTreeWidgetItem* item);

private slots:
    void on_button_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
