#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void CountFilesAndFoldersHelper(const QDir &dir, int &fileCount, int &folderCount, int level);
    void CountFilesAndFolders(const QDir &dir);

public slots:
    void ChooseFile();

private:
    Ui::MainWindow *ui;
    QString filepath;
    QDir dir;
    int fileCount{0};
    int folderCount{0};
    int level{0};
};
#endif // MAINWINDOW_H
