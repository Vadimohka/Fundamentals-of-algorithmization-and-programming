#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTreeWidgetItem>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

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

private slots:
    void on_pushButtonOpenFolder_clicked();

private:
    Ui::MainWindow *ui;

private:
    void count( const QString& Path , long long& folder , long long& file );
    QPair< long long , long long > setTree( const QString &Path , QTreeWidgetItem *parentItem );


};
#endif // MAINWINDOW_H
