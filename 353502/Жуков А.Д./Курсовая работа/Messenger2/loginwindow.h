#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

#include "datasender.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow() override;

private:
    Ui::LoginWindow *ui;

    DataSender *dataSender;

signals:
    void userLoggedIn(QString, QString);
    void openWindow();

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();

public slots:
    void loginSucceedSlot(QString uid);
};

#endif // LOGINWINDOW_H
