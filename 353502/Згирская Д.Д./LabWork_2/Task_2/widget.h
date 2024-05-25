#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include "Worker.h"
#include <QFileDialog>
#include <QDebug>
#include <fstream>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_open_file_clicked();

    void on_add_to_file_clicked();

    void on_edit_file_clicked();

    void on_delete_from_file_clicked();

    void on_show_file_clicked();

    void on_comboBox_activated(int index);

    void clearErrorWorkerFIO();
    void clearErrorMentorFIO();
    void clearErrorDateGave();
    void clearErrorDeadline();
    void clearErrorDateComplete();

private:
    QString _path = nullptr;
    QString _newPath = nullptr;
    std::ifstream input;
    std::ofstream output; //write
    QVector<Worker> _workersVector;
    void fromFileToVector();
    bool checkDateInput(QString text);
    bool checkFIOInput(QString text);
    bool checkFileInput(QString text);
    bool checkLineNumberInput();
    bool fileIsEmpty(QString path);
    void addToFile(Worker added, QString path);
    void clearFile(QString path);
    void fillProjectsOnMentorFile(QString text);
    void fillTaskOnWorkerFile(QString text);
    void fillWorkersOnProjectFile(QString text);
    void fillWorkersFailedDeadline();
    void showTable();

    Ui::Widget *ui;
};
#endif // WIDGET_H
