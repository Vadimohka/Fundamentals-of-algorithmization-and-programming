#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FilterWindow;
}

class FilterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWindow(QWidget *parent = nullptr);
    ~FilterWindow();

    bool isInputCorrect();

private slots:
    void on_pushButton_clicked();
signals:
    void filterSignal(double minValue, double maxValue);

private:
    Ui::FilterWindow *ui;
};

#endif // FILTERWINDOW_H
