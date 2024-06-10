#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include "man.h"
#include "women.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QList<Women> womenList;
    QList<Man> menList;
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QPushButton* openButton;
    QPushButton* addButton;
    QPushButton* deleteButton;
    void addField();
    void deleteField();
    void openFile();
    bool readParametersFromFile(const QString& filePath, QList<Women>& womenList, QList<Man>& menList);
    void fillRow(QTableWidget* tableWidget, int row, const Women& woman, const QString& gender);
    void fillRow(QTableWidget* tableWidget, int row, const Man& man, const QString& gender);
    QTableWidget* getTableWidget();

    QList<QPair<Women, Man>> findMatchingPairs(const QList<Women>& womenList, const QList<Man>& menList);
    bool meetPartnerRequirements(const Man& man, const Women& woman);
    bool meetPartnerRequirements(const Women& woman, const Man& man);


private slots:
    void openTableWindow();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
};

#endif // MAINWINDOW_H
