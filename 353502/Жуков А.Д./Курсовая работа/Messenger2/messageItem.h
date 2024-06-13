#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H

#include <QApplication>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QString>
#include <QWidget>
#include <QDebug>

class ChatMessageWidget : public QWidget {

    Q_OBJECT

protected:
    QString fileName = "";
    QString type = "";

public:
    QString messageType() { return type; }
    QString getFileName() { return fileName; }

    // Конструктор для сообщения с именем автора и текстом
    ChatMessageWidget(const QString &author, const QString &text, QWidget *parent = nullptr)
        : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *authorLabel = new QLabel(author, this);
        QLabel *textLabel = new QLabel(text, this);

        layout->addWidget(authorLabel);
        layout->addWidget(textLabel);

        setLayout(layout);
        type = "text";
    }

    // Конструктор для сообщения с именем автора и картинкой
    ChatMessageWidget(const QString &author, const QPixmap &image, QWidget *parent = nullptr)
        : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *authorLabel = new QLabel(author, this);
        QLabel *Lmao = new QLabel(this);
        Lmao->setVisible(false);
        QLabel *imageLabel = new QLabel(this);
        this->setCursor(Qt::PointingHandCursor);

        if (!image.isNull()) {
            imageLabel->setPixmap(image.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        layout->addWidget(authorLabel);
        layout->addWidget(imageLabel);
        layout->addWidget(Lmao);

        setLayout(layout);
        type = "file";
        fileName = author.split(u':').last();
        fileName.removeAt(0);
    }

    // Конструктор для сообщения с картинкой, именем автора и описанием
    ChatMessageWidget(const QString &author, const QString &description, const QPixmap &image, QWidget *parent = nullptr)
        : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *authorLabel = new QLabel(author, this);
        QLabel *descriptionLabel = new QLabel(description, this);
        QLabel *imageLabel = new QLabel(this);

        if (!image.isNull()) {
            imageLabel->setPixmap(image.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        layout->addWidget(authorLabel);
        layout->addWidget(descriptionLabel);
        layout->addWidget(imageLabel);

        setLayout(layout);
        type = "picture";
    }
};

#endif // MESSAGEITEM_H
