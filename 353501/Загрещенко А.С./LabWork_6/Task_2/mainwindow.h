#pragma once

#include "IOService.h"
#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString actions = "1 - Абзац\n2 - Массив\n3 - Cтруктура(текст)\n4 - Структура (бинарник)\n5 - Предложение";
    IOService* service = nullptr;
  
public:
  MainWindow();
  ~MainWindow();


private slots:
  void on_chooseBtn_clicked();

protected:
  Ui::MainWindow *ui;
};