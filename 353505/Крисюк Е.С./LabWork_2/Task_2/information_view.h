#ifndef INFORMATION_VIEW_H
#define INFORMATION_VIEW_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Information_View;
}

class Information_View : public QDialog
{
    Q_OBJECT

signals:
    void Send_check(const QString&);
public:
    explicit Information_View(QWidget *parent = nullptr);
    ~Information_View();

private slots:
    void on_Cancel_button_clicked();

private:
    Ui::Information_View *ui;

public slots:
    void Reseive_data(const QString &file_path, const QString &menu_path);
};

#endif // INFORMATION_VIEW_H
