#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <product.h>
#include <QMessageBox>
#include <QFileDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

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
    void ReadProducts();

    void on_AddButton_clicked();

    void on_ChangeButton_clicked();

    // void on_OpenFileButton_clicked();

    void on_DeleteButton_clicked();

    void on_SeeButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_OpenButton_clicked();

    void on_SortButton_clicked();

private:
    QString filePath;
    int amount;

    Product* productsfromfile;

    void FillName();
    Product FillProductLine();
    void RewriteFile(int rowIndex, const QString &newdate);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
