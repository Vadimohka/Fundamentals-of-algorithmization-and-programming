#ifndef LAB3_TASK1_MAINWINDOW_H_
#define LAB3_TASK1_MAINWINDOW_H_

#include <QDoubleValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "converter.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    QVBoxLayout* vbox;
    QLabel* label;
    QLineEdit* line_edit;
    QDoubleValidator* validator;
    QPushButton* button;
    Ui::MainWindow* ui;
   private slots:
    void doTask();
};


#endif  //LAB3_TASK1_MAINWINDOW_H_
