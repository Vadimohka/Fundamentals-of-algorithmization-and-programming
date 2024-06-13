#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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
private:
    QString m_path;
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;

    long long countSubfolders(const QString& path);
    long long countFiles(const QString& path);
private slots:
    void open();
};
#endif // MAINWINDOW_H
