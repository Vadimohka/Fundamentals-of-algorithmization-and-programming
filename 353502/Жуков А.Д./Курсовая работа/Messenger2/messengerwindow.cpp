#include "messengerwindow.h"
#include "ui_messengerwindow.h"
#include <QPixmap>

MessengerWindow::MessengerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MessengerWindow)
    , storage(new MessageStorage)
{
    //qDebug() << QDir::currentPath() + "/savedChats.txt";
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);

    ////////////            TESTS
    /*
    QListWidget * messagesList = new QListWidget;
    currentChat = messagesList;
    ui->verticalLayout->addWidget(messagesList);
    messagesList->setIconSize(QSize(300, 300));

    ChatMessageWidget *widget1 = new ChatMessageWidget("Author 1", "This is a text message.");
    addMessageWidget(messagesList, widget1);

    QPixmap image2("C:/Users/zukor/OneDrive/Desktop/СИСЬКИ/unknown-2");
    ChatMessageWidget *widget2 = new ChatMessageWidget("Author 2", image2);
    addMessageWidget(messagesList, widget2);

    QListWidget * messagesList2 = new QListWidget;
    messagesList2->setIconSize(QSize(300, 300));
    messagesList2->addItem(new QListWidgetItem(QIcon(QPixmap("C:/Users/zukor/OneDrive/Desktop/СИСЬКИ/unknown-2")), ""));

    storage->addChat(messagesList, "test_chat");
    storage->addChat(messagesList2, "test_chat2");

    messagesList->hide();
    ui->verticalLayout->addWidget(storage->loadChat("test_chat2"));
    messagesList2->hide();
    messagesList->show();
    ui->verticalLayout->addWidget(storage->loadChat("test_chat"));
*/
    ////////////
}

void MessengerWindow::closeEvent(QCloseEvent *event)
{
    datasender->userDisconnected();
    Q_UNUSED(event)
}

QString MessengerWindow::fileName(QString path)
{
    QFileInfo info(path);
    return info.fileName();
}

void MessengerWindow::setupUser(QString id, QString login)
{
    this->id = id;
    this->userName = login;
    ui->label->setText(id);
    datasender = new DataSender;
    connect(datasender, &DataSender::chatCreated, this, &MessengerWindow::showChat);
    connect(datasender, &DataSender::loadMessageText, this, &MessengerWindow::loadMessageText);
    connect(datasender, &DataSender::loadMessageFile, this, &MessengerWindow::loadMessageFile);
    connect(datasender, &DataSender::incommingFile, this, &MessengerWindow::incommingFile);
    datasender->connectSocket(id);
}

void MessengerWindow::showChat(QString chatName)
{
    if (ui->chatsList->findItems(chatName + "\n", Qt::MatchExactly).isEmpty()) {
        ui->chatName->setText(chatName);
        ui->chatsList->addItem(chatName + "\n");

        if (!storage->chatExists(chatName)) {
            QListWidget * messagesList = new QListWidget;
            ui->verticalLayout->addWidget(messagesList);
            messagesList->setIconSize(QSize(300, 300));
            storage->addChat(messagesList, chatName);
            if (currentChat != nullptr) {
                currentChat->hide();
            }
            currentChat = messagesList;
            currentChat->show();
            qDebug() << "ENTERED: " << chatName;
            ui->send_button->setEnabled(true);
            ui->chooseFile_button->setEnabled(true);
            connect(messagesList, QListWidget::itemClicked, this, MessengerWindow::downloadFile);
        }
        //ui->chatsList->setCurrentItem(ui->chatsList->findItems(chatName, Qt::MatchExactly).first());
    }
}

/*
void MessengerWindow::incommingMessage(QString fromUser, QString text, QString date, QString time)
{
    if (ui->chatsList->findItems(fromUser, Qt::MatchExactly).isEmpty()) {
        ui->chatsList->addItem(fromUser);
    }
    if (ui->chatsList->currentItem()->text() == fromUser) {
        ui->chatsList->addItem(text);
    }
}
*/

void MessengerWindow::addMessageWidget(QListWidget *widget, ChatMessageWidget *messageWidget)
{
    QListWidgetItem *item1 = new QListWidgetItem(widget);
    item1->setSizeHint(messageWidget->sizeHint());
    widget->addItem(item1);
    widget->setItemWidget(item1, messageWidget);
    storage->addChat(widget, ui->chatName->text());
    widget->scrollToBottom();
}

void MessengerWindow::loadMessageText(QString text, QString author, QString to, QString time)
{
    qDebug() << "INCOMMING MESSAGE: " << text << "," << author << "," << to << "," << time;
    if (storage->chatExists(to)) {
        ChatMessageWidget *textMessage = new ChatMessageWidget(author + " " + time + ":", text);
        addMessageWidget(storage->loadChat(to), textMessage);
        //storage->loadChat(to)->scrollToBottom();
    } else {
        qDebug() << "CHAT DONT EXISTS! 105";
    }
}

void MessengerWindow::loadMessageFile(const QString &name, const QString &author, const QString &to, const QString &time)
{
    qDebug() << "INCOMMING MESSAGE: " << name << "," << author << "," << to << "," << time;
    if (storage->chatExists(to)) {
        QPixmap map(QDir::current().filePath("download_icon.png"));
        ChatMessageWidget *textMessage = new ChatMessageWidget(author + " " + time + ": " + name, map);
        addMessageWidget(storage->loadChat(to), textMessage);
    } else {
        qDebug() << "CHAT DONT EXISTS! 105";
    }
}

void MessengerWindow::downloadFile(QListWidgetItem *item)
{
    //if (item->listWidget()->)
    qDebug() << "НАЖАТ???";
    qDebug() << "НАЖАТ???" << currentChat->itemWidget(item)->children().size();
    if (qobject_cast<ChatMessageWidget *>(currentChat->itemWidget(item))->messageType() == "file")
    {
        qDebug() << "НАЖАТ!!!" << qobject_cast<ChatMessageWidget *>(currentChat->itemWidget(item))->getFileName();
        datasender->downloadFile(qobject_cast<ChatMessageWidget *>(currentChat->itemWidget(item))->getFileName());
    }
}

void MessengerWindow::incommingFile(const QByteArray &data, const QString &name)
{
    QFile file(QCoreApplication::applicationDirPath() + "/" + name);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.write(data);
    } else {
        qDebug() << "FILE NOT OPEN";
    }
}

void MessengerWindow::on_usersSearch_textEdited(const QString &arg1)
{
    //ПОЧТИ РАБОТАЕТ
    QStringList users = datasender->getUsersList(id, ui->usersSearch->text());
    ui->users_comboBox->clear();
    if (!users.empty()) {
        ui->users_comboBox->addItems(users);
    }
}

void MessengerWindow::on_users_comboBox_textActivated(const QString &toUser)
{
    datasender->createChat("private", userName, toUser);
    ui->send_button->setEnabled(true);
    qDebug() << toUser;
}


void MessengerWindow::on_chatsList_itemClicked(QListWidgetItem *chatName)
{
    if (currentChat != nullptr) {
        currentChat->hide();
    }

    QString chat = chatName->text().split(u'\n').first();
    qDebug() << chat;
    if (storage->chatExists(chat)) {
        currentChat = storage->loadChat(chat);
        currentChat->show();
        ui->chatName->setText(chat);
        qDebug() << "LOADED " << chat;
        if (storage->loadChat(chat)->count() == 0) {
            datasender->loadChatOnLogin(userName, chat);
        }
    } else {
        qDebug() << "chat dont exist";
    }
}


void MessengerWindow::on_send_button_clicked()
{
    if (!ui->message_edit->text().isEmpty() && !ui->chatsList->selectedItems().isEmpty()) {
        //currentChat->clear();
        datasender->sendMessage(ui->message_edit->text(), userName, ui->chatName->text(), "0");
        ui->message_edit->clear();
    }
}


void MessengerWindow::on_chatsList_itemEntered(QListWidgetItem *item)
{
    qDebug() << item->text();
    //datasender->createChat("private", userName, item->text().split(u'\n').first());
    QListWidget * messagesList = new QListWidget;
    ui->verticalLayout->addWidget(messagesList);
    messagesList->setIconSize(QSize(300, 300));
    storage->addChat(messagesList, item->text().split(u'\n').first());
    if (currentChat != nullptr) {
        currentChat->hide();
    }
    currentChat = messagesList;
    currentChat->show();
    qDebug() << "ENTERED";
}

void MessengerWindow::on_createCharButton_clicked()
{
    //////СНЕСТИ ЕСЛИ НЕ ПАШЕТ
    ChatDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString chatName = dialog.getChatName();
        datasender->createChat("group", chatName, userName);
        qDebug() << "ЧАТ СОЗДАН" << chatName;
    }
    //////СНЕСТИ ЕСЛИ НЕ ПАШЕТ
}


void MessengerWindow::on_chooseFile_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "All Files (*)");

    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        if (fileInfo.size() > (1024 * 1024 * 25)) {
            QMessageBox::warning(this, "File Too Large", "The selected file exceeds the 25 MB size limit.");
            return;
        }

        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray fileData = file.readAll();
            //QString fileContent = QString::fromLatin1(fileData.toBase64());
            qDebug() << this->fileName(fileName) << fileData.size();
            datasender->sendFile(this->fileName(fileName), userName, ui->chatName->text(), "0", fileData);
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Cannot open file for reading.");
        }
    } else {
        QMessageBox::information(this, "No File Selected", "You did not select any file.");
    }
}

