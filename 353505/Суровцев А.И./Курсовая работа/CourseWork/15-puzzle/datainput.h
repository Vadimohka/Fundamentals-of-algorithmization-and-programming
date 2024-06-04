#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <QWidget>
#include <QStyle>
#include <QHostAddress>
#include <QRegularExpressionMatch>

namespace Ui {
class DataInput;
}

class DataInput : public QWidget
{
    Q_OBJECT

public:
    explicit DataInput(QWidget *parent = nullptr);
    ~DataInput();
    QString getPort();
    QString getIP();
    QString getName();

private slots:
    void on_lnl_ip_textChanged(const QString &arg1);

    void on_bnt_connect_clicked();

    void on_lnl_port_textChanged(const QString &arg1);
    void checkInputs();

signals:
    void formClosed(const QString& name, const QString& IP, const QString& port);

private:
    Ui::DataInput *ui;
    QString port;
    QString IP;
    QString name;
};

#endif // DATAINPUT_H
