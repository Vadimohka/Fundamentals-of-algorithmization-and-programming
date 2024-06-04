#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QVector>
#include <QTreeWidgetItem>
#include <QPair>

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
    void on_Change_path_button_clicked();

private:
    Ui::MainWindow *ui;
    QString current_path;
    void Calculate_number_of_folders_and_files(QString);


    long long count_of_folders;
    long long count_of_files;
    int length_of_array;

    QVector <QFileInfo> vector_of_all_count_of_dirs;

    QFileInfoList list_copy_dir;

    QPair<long, long> setTree(const QString &folderPath, QTreeWidgetItem *parentItem);
};
#endif // MAINWINDOW_H
