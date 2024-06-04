#ifndef DIALOGLOSE_H
#define DIALOGLOSE_H

#include <QDialog>

namespace Ui {
class DialogLOSE;
}

class DialogLOSE : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLOSE(QWidget *parent = nullptr);
    ~DialogLOSE();

private:
    Ui::DialogLOSE *ui;
signals:
    void openMainMenu();
public slots:
    void open();
private slots:
    void on_buttonBox_accepted();

};

#endif // DIALOGLOSE_H
