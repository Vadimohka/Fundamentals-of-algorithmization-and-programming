#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H
#include <QtWidgets>

class SearchDialog : public QDialog {
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);

    QString getType() const;
    QString getManufacturer() const;
    QString getModel() const;

private:
    QLineEdit *typeEdit;
    QLineEdit *manufacturerEdit;
    QLineEdit *modelLineEdit;
};
#endif // SEARCHDIALOG_H
