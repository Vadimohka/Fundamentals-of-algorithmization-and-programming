#pragma once

#include "FolderCounter.h"
#include <QFuture>
#include <QMainWindow>
#include <qfuturewatcher.h>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void onOpen();
    void onFinished();

protected:
    Ui::MainWindow *ui;
    QFutureWatcher<CountResults> waiter;
};
