#ifndef STATS_WINDOW_H
#define STATS_WINDOW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Stats_window;
}

class Stats_window : public QDialog
{
    Q_OBJECT

public:
    explicit Stats_window(int, int, int, int, QWidget *parent = nullptr);
    ~Stats_window();

private slots:
    void on_close_button_clicked();

private:
    Ui::Stats_window *ui;
    int correct_count;
    int incorrect_count;
    int wrongs_count;
};

#endif // STATS_WINDOW_H
