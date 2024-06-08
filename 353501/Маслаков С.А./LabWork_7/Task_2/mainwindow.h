#pragma once
#include "BSTui.h"
#include <QMainWindow>
#include <qgraphicsscene.h>
#include "BST.h"
#include <QTreeWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<QString> fioList = {
            "Иванов Иван Иванович",
            "Петров Петр Петрович",
            "Сидоров Сидор Сидорович",
            "Смирнова Анна Сергеевна",
            "Кузнецов Дмитрий Александрович",
            "Павлова Екатерина Николаевна",
            "Орлов Максим Сергеевич",
            "Волкова Ольга Викторовна",
            "Соколов Александр Михайлович",
            "Лебедева Мария Андреевна",
            "Романов Евгений Витальевич",
            "Ильина Наталья Сергеевна",
            "Васильев Николай Владимирович",
            "Козлова Юлия Игоревна",
            "Морозов Андрей Дмитриевич",
            "Панова Татьяна Александровна",
            "Шестаков Алексей Сергеевич",
            "Виноградова Виктория Сергеевна",
            "Медведев Михаил Иванович",
            "Крылова Елена Владимировна"
    };
    BSTui tree = BSTui(fioList);

public:
  MainWindow();

private slots:
    void isertButSlot();
    void removeButSlot();
    void findMinButSlot();
    void findMaxButSlot();
    void balanceButSlot();
    void findButSlot();
    void findAverageButSlot();
    void printPreOrder();
    void printPostOrder();
    void printInOrder();
    void clearButSlot();
protected:
  Ui::MainWindow *ui;
};