#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QLabel>
class SaveDialog: public QDialog
{
    Q_OBJECT
public:
    SaveDialog(int x, int y);
    QPushButton* YesButton;
    QPushButton* NoButton;
    QPushButton* CanelButton;
    QLabel* textLabel;
    int ans = 0;


public slots:
    void on_YesButton_clicked();
    void on_NoButton_clicked();
    void on_CanelButton_clicked();


};

#endif // SAVEDIALOG_H
