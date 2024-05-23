#pragma once

#include "address.h"
#include <QMainWindow>
#include <QGraphicsScene> // Вместо <qgraphicsscene.h> используйте <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

protected:
    Ui::MainWindow *ui;
    Address *homeAddress = nullptr; // Заменим 'fw' на 'homeAddress'

    void initializeDefaultAddress(); // Изменим initDefaultFootwear на initializeDefaultAddress
    void resetAddress(Address*);

private slots:
    void on_initializeButton_clicked(); // Приведем имена слотов к нижнемуCamelCase
    void on_initializeValuesButton_clicked(); // Приведем имена слотов к нижнемуCamelCase
    void on_printButton_clicked(); // Приведем имена слотов к нижнемуCamelCase

};
