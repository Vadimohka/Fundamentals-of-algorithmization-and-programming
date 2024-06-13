#ifndef MESSENGERWINDOW_H
#define MESSENGERWINDOW_H

#include <QWidget>
#include <QListWidgetItem>
#include <QPixmap>
#include <QDir>
#include <QScrollBar>
#include <QFileDialog>
#include <QMessageBox>

#include "datasender.h"
#include "messageItem.h"
#include "messageStorage.h"
#include "CreateChatDialogWindow.h"

namespace Ui {
class MessengerWindow;
}

class MessengerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MessengerWindow(QWidget *parent = nullptr);
    ~MessengerWindow() override = default;
private:
    Ui::MessengerWindow *ui;

    QString id, userName;
    QStringList users;
    DataSender* datasender;
    MessageStorage* storage;
    QListWidget * currentChat;

    enum MessageType { Text, Picture, File };

    void closeEvent(QCloseEvent *event) override;
    QString fileName(QString path);

public slots:
    void setupUser(QString id, QString login);
    void showChat(QString chatName);
    //void incommingMessage(QString fromUser, QString text, QString date, QString time);
    void addMessageWidget(QListWidget *widget, ChatMessageWidget *messageWidget);

    void loadMessageText(QString text, QString author, QString to, QString time);
    void loadMessageFile(const QString &name, const QString &author, const QString &to, const QString &time);
    void downloadFile(QListWidgetItem *item);
    void incommingFile(const QByteArray &, const QString&);

private slots:
    void on_usersSearch_textEdited(const QString &arg1);
    void on_users_comboBox_textActivated(const QString &arg1);
    void on_chatsList_itemClicked(QListWidgetItem *item);
    void on_send_button_clicked();
    void on_chatsList_itemEntered(QListWidgetItem *item);
    void on_createCharButton_clicked();
    void on_chooseFile_button_clicked();
};

#endif // MESSENGERWINDOW_H
