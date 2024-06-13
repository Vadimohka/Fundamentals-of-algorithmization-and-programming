#ifndef CREATECHATDIALOGWINDOW_H
#define CREATECHATDIALOGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>

class ChatDialog : public QDialog {
    Q_OBJECT

    QLineEdit *lineEdit;

public:
    ChatDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Создать чат");
        setFixedSize(300, 150);

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setAlignment(Qt::AlignCenter); // Центрируем основной макет

        QLabel *label = new QLabel("Введите название чата:", this);
        label->setAlignment(Qt::AlignCenter); // Центрируем текст в метке
        mainLayout->addWidget(label);

        QLineEdit *lineEdit = new QLineEdit(this);
        lineEdit->setFixedHeight(30); // Увеличиваем высоту текстового поля
        mainLayout->addWidget(lineEdit);

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        mainLayout->addWidget(buttonBox);

        connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

        this->lineEdit = lineEdit;
    }

    QString getChatName() const {
        return lineEdit->text();
    }
};

#endif // CREATECHATDIALOGWINDOW_H
