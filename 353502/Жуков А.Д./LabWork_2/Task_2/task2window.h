#ifndef TASK2WINDOW_H
#define TASK2WINDOW_H

#include <QWidget>
#include <QFileSystemModel>
#include <QMessageBox>

#include "diskinfo.h"

namespace Ui {
class Task2Window;
}

class Task2Window : public QWidget
{
    Q_OBJECT

public:
    explicit Task2Window(QWidget *parent = nullptr);
    ~Task2Window() override;

private slots:
    void on_button_open_clicked();

    void on_button_delete_clicked();

    void on_button_add_clicked();

    void on_button_save_clicked();

    void on_sortComboBox_currentTextChanged(const QString &arg1);

    void on_button_search_clicked();

private:
    Ui::Task2Window *ui;

    QList<DiskInfo> infoList;
    QStringList allFiles;

    void FileToList(QString filePath);
    void CreateFile(QString type, QString name, QString author, QString price, QString note);

    const QString DEFAULT_PATH = "../build-lab2-Desktop_Qt_6_6_2_shared_MinGW_w64_MINGW64_MSYS2-Debug/debug/task2Data/";
};

#endif // TASK2WINDOW_H
