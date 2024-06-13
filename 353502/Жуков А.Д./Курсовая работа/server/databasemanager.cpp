 #include "databasemanager.h"

DatabaseManager::DatabaseManager()
    : database_users(QSqlDatabase::addDatabase("QSQLITE", "connection1"))
    , query(new QSqlQuery(database_users))
{
    database_users.setDatabaseName("users.db");

    if (database_users.open())
    {
        if (!query->exec(CREATE_USERS_TABLE))
        {
            qDebug() << DATABASE_CREATION_ERROR_DBMANAGER << "users";
        }
        if (!query->exec(CREATE_CHATS_TABLE))
        {
            qDebug() << DATABASE_CREATION_ERROR_DBMANAGER << "chats";
        }
        if (!query->exec(CREATE_MEMBERS_TABLE))
        {
            qDebug() << DATABASE_CREATION_ERROR_DBMANAGER << "members";
        }
        if (!query->exec(CREATE_MESSAGES_TABLE))
        {
            qDebug() << DATABASE_CREATION_ERROR_DBMANAGER << "messages";
        }
    } else {
        qDebug() << DATABASE_OPEN_ERROR_DBMANAGER;
    }
    database_users.close();
}

bool DatabaseManager::registerUser(const QString &login, const QString &password)
{
    userExist(login);
    if (database_users.open()) {
        query->prepare("SELECT * FROM usersList WHERE login = :login;");
        query->bindValue(":login", login);
        query->exec();

        if (query->next()) {
            //////////////////////
            qDebug() << "NOT REGISTERED (dbm.cpp)";
            //////////////////////
            database_users.close();
            return false;
        }
        //////////////////////
        qDebug() << "REGISTERED";
        //////////////////////
        query->prepare("INSERT INTO usersList (login,password) VALUES (:log,:pass);");
        query->bindValue(":log", login);
        query->bindValue(":pass", password);
        query->exec();
    }
    database_users.close();
    return true;
}

bool DatabaseManager::userExist(const QString &login, const QString &password)
{
    if (database_users.open()) {
        if (password.isEmpty()) {
            query->prepare("SELECT * FROM usersList WHERE login = :login;");
            query->bindValue(":login", login);
            query->exec();
        } else {
            query->prepare("SELECT * FROM usersList WHERE login = :login AND password = :password;");
            query->bindValue(":login", login);
            query->bindValue(":password", password);
            query->exec();
        }
        //////////////////////
        qDebug() << "ISHEM... (dbm.cpp)";
        //////////////////////
        if(query->first()) {
            //////////////////////
            qDebug() << "NASHLI! (dbm.cpp)";
            qDebug() << "user data: " << query->value(0).toString() << query->value(1).toString() << query->value(2).toString();
            //////////////////////
            database_users.close();
            return true;
        }
    }
    //////////////////////
    qDebug() << "NENAHOD... (dbm.cpp)";
    //////////////////////
    database_users.close();
    return false;
}

bool DatabaseManager::createChat(const QString &chatName, bool isGroup, const QList<int> &memberIds) {
    if (memberIds.size() != 2 && !isGroup) {
        qDebug() << "Error: Private chat must have exactly 2 members.";
        return false;
    }

    database_users.open();
    database_users.transaction();  // Начинаем транзакцию

    QString finalChatName = chatName;

    if (!isGroup) {
        QStringList memberNames;
        for (int userId : memberIds) {
            memberNames << getNameById(QString::number(userId));  // Предполагается, что у вас есть метод getUsernameById
        }
        finalChatName = memberNames.join("?");
    }                                           //ТУТ НАДА МЕТОД КОТОРЫЙ В КОММЕНТЕ ДО РЕАЛИЗОВАТЬ И ПОМЕНЯТЬ РАЗДЕЛИТЕЛЬ И СДЕЛАТЬ МЕТОД КОТОРЫЙ ПОДСТРОКУ ИЩЕТ ПО НИКНЕЙМУ

    query->prepare(R"(
        INSERT INTO chatsList (chat_name, is_group)
        VALUES (:chat_name, :is_group)
    )");
    query->bindValue(":chat_name", finalChatName);
    query->bindValue(":is_group", isGroup);

    if (!query->exec()) {
        qDebug() << "Error creating chat:" << query->lastError().text();
        database_users.rollback();  // Откатываем транзакцию в случае ошибки
        return false;
    }

    int chatId = query->lastInsertId().toInt();

    query->prepare(R"(
        INSERT INTO chat_members (chat_id, user_id)
        VALUES (:chat_id, :user_id)
    )");

    for (int userId : memberIds) {
        query->bindValue(":chat_id", chatId);
        query->bindValue(":user_id", userId);

        if (!query->exec()) {
            qDebug() << "Error adding member to chat:" << query->lastError().text();
            database_users.rollback();  // Откатываем транзакцию в случае ошибки
            return false;
        }
    }

    database_users.commit();  // Фиксируем транзакцию
    database_users.close();
    return true;
}

void DatabaseManager::addMessage(const QString &message, const QString &fromUser, const QString &toUser, const QString &isGroup, const QString &type, const QByteArray &file)
{
    QSqlQuery query(database_users);
    database_users.open();
    database_users.transaction();

    // Get user_id
    query.prepare("SELECT user_id FROM usersList WHERE login = :name;");
    query.bindValue(":name", fromUser);
    if (!query.exec() || !query.next()) {
        qDebug() << "User not found:" << query.lastError() << " 157";
        database_users.rollback();
        return;
    }
    int userId = query.value(0).toInt();

    // Get chat_id
    bool isgrp = isGroup.toInt();
    int chatId = getChatId(toUser, fromUser, isgrp);
    if (chatId == -1) {
        qDebug() << "Chat not found";
        database_users.rollback();
        return;
    }

    if (type == "text") {
        // Insert message into messages table
        query.prepare("INSERT INTO messages (chat_id, user_id, content, created_at, type) VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(chatId);
        query.addBindValue(userId);
        query.addBindValue(message);
        query.addBindValue(timeNow());
        query.addBindValue(type);
    } else if (type == "file") {
        query.prepare("INSERT INTO messages (chat_id, user_id, content, file, created_at, type) VALUES (?, ?, ?, ?, ?, ?);");
        query.addBindValue(chatId);
        query.addBindValue(userId);
        query.addBindValue(message);
        query.addBindValue(file);
        query.addBindValue(timeNow());
        query.addBindValue(type);
    }

    if (!query.exec()) {
        qDebug() << "Error inserting message:" << query.lastError();
        database_users.rollback();
        return;
    } else {
        qDebug() << "Message added successfully";
    }

    database_users.commit();
    database_users.close();
}

QStringList DatabaseManager::loadMessages(const QString &author, const QString &to)
{
    QStringList messageList;
    if (!database_users.isOpen()) {
        if (!database_users.open()) {
            qDebug() << "Ошибка при открытии базы данных: " << database_users.lastError();
            return messageList;
        }
    }

    // Определяем идентификатор чата
    QSqlQuery query(database_users);
    int chat_id = -1;
    bool isGroupChat = false;

    // Проверяем, является ли 'to' именем группового чата
    query.prepare("SELECT chat_id FROM chatsList WHERE chat_name = :chat_name");
    query.bindValue(":chat_name", to);
    if (query.exec() && query.next()) {
        chat_id = query.value(0).toInt();
        isGroupChat = true;
    } else {
        // Если это не групповой чат, проверяем комбинацию авторов
        QString privateChatName = QString("%1?%2").arg(author, to);
        QString privateChatNameReversed = QString("%1?%2").arg(to, author);
        query.prepare("SELECT chat_id FROM chatsList WHERE chat_name = :chat_name1 OR chat_name = :chat_name2");
        query.bindValue(":chat_name1", privateChatName);
        query.bindValue(":chat_name2", privateChatNameReversed);
        if (query.exec() && query.next()) {
            chat_id = query.value(0).toInt();
        } else {
            qDebug() << "Чат не найден.";
            return messageList;
        }
    }

    // Извлекаем сообщения из таблицы messages для найденного chat_id
    query.prepare("SELECT content, user_id, created_at, type FROM messages WHERE chat_id = :chat_id");
    query.bindValue(":chat_id", chat_id);

    if (query.exec()) {
        while (query.next()) {
            QString content = query.value(0).toString();
            int user_id = query.value(1).toInt();
            QString created_at = query.value(2).toString();
            QString type = query.value(3).toString();

            // Получаем имя отправителя
            QSqlQuery userQuery(database_users);
            userQuery.prepare("SELECT login FROM usersList WHERE user_id = :user_id");
            userQuery.bindValue(":user_id", user_id);
            QString authorName;
            if (userQuery.exec() && userQuery.next()) {
                authorName = userQuery.value(0).toString();
            } else {
                qDebug() << "Не удалось найти пользователя с id:" << user_id;
                continue;
            }

            // Формируем строку формата text_author_to_time
            QString formattedMessage = QString("%1%2%3%4%5")
                                           .arg(content, authorName, to, created_at, type);

            // Добавляем сообщение в список
            messageList.append(formattedMessage);
        }
    } else {
        qDebug() << "Ошибка при выполнении запроса к таблице messages: " << query.lastError();
    }

    return messageList;
}

QString &DatabaseManager::LoadFile(const QString &author, const QString &to)
{
    QString *LastFile = new QString;
    if (!database_users.isOpen()) {
        if (!database_users.open()) {
            qDebug() << "Ошибка при открытии базы данных: " << database_users.lastError();
            return *LastFile;
        }
    }

    // Определяем идентификатор чата
    QSqlQuery query(database_users);
    int chat_id = -1;
    bool isGroupChat = false;

    query.prepare("SELECT chat_id FROM chatsList WHERE chat_name = :chat_name");
    query.bindValue(":chat_name", to);
    if (query.exec() && query.next()) {
        chat_id = query.value(0).toInt();
        isGroupChat = true;
    } else {
        // Если это не групповой чат, проверяем комбинацию авторов
        QString privateChatName = QString("%1?%2").arg(author, to);
        QString privateChatNameReversed = QString("%1?%2").arg(to, author);
        query.prepare("SELECT chat_id FROM chatsList WHERE chat_name = :chat_name1 OR chat_name = :chat_name2");
        query.bindValue(":chat_name1", privateChatName);
        query.bindValue(":chat_name2", privateChatNameReversed);
        if (query.exec() && query.next()) {
            chat_id = query.value(0).toInt();
        } else {
            qDebug() << "Чат не найден.";
            return *LastFile;
        }
    }

    query.prepare("SELECT content, file, user_id, created_at FROM messages WHERE chat_id = :chat_id");
    query.bindValue(":chat_id", chat_id);

    if (query.exec()) {
        if (query.next()) {
            QString fileName = query.value(0).toString();
            QString file = query.value(1).toString();
            int user_id = query.value(2).toInt();
            QString created_at = query.value(3).toString();

            // Получаем имя отправителя
            QSqlQuery userQuery(database_users);
            userQuery.prepare("SELECT login FROM usersList WHERE user_id = :user_id");
            userQuery.bindValue(":user_id", user_id);
            QString authorName;
            if (userQuery.exec() && userQuery.next()) {
                authorName = userQuery.value(0).toString();
                *LastFile = QString("%1%2%3%4%5").arg(fileName, authorName, to, created_at, file);
            } else {
                qDebug() << "Не удалось найти пользователя с id:" << user_id;
            }
        } else {
            qDebug() << "Ошибка поиска файла: " << query.lastError();
        }
    } else {
        qDebug() << "Ошибка при выполнении запроса к таблице messages: " << query.lastError();
    }

    return *LastFile;
}

QStringList &DatabaseManager::getMemebersIds(const QString &chatName)
{
    //не работает :(
    QStringList Ids;
    return Ids;
}

QString DatabaseManager::getUserChatNames(int userId)
{
    qDebug() << userId;
    QStringList chatNames;
    database_users.open();

    QString uName = getNameById(QString::number(userId));
    query->prepare(R"(
SELECT *
FROM chatsList
JOIN chat_members ON chatsList.chat_id = chat_members.chat_id
WHERE chat_members.user_id = :user_id;
    )");
    query->bindValue(":user_id", QString::number(userId));

    // Выполнение запроса
    if (!query->exec()) {
        qDebug() << "Ошибка при выполнении запроса:" << query->lastError().text();
        return {};
    }

    // Извлечение результатов
    while (query->next()) {
        qDebug() << "FOUND CHAT FOR " << userId << ": " << query->value(1).toString() << " group: " << query->value(2).toBool();
        if (query->value(2).toBool()) {
            chatNames.append(query->value(1).toString());
        } else {
            QString firstName = query->value(1).toString().split(u'?').first();
            QString secomdName = query->value(1).toString().split(u'?').last();
            chatNames.append(firstName == uName ? secomdName : firstName);
        }
    }
    database_users.close();

    qDebug() << "CHATS FOR " << userId << ": " << chatNames.join("");

    if (chatNames.isEmpty())
        return "";
    return chatNames.join("");
}

QString DatabaseManager::getNameById(const QString &id)
{
    query->prepare("SELECT login FROM usersList WHERE user_id = ?");
    query->addBindValue(id);
    query->exec();
    if (!query->first()) {
        qDebug() << "CANT FOUND USER: " << query->lastError();
        return "";
    }
    return query->value(0).toString();
}

QByteArray &DatabaseManager::getFile(const QString &name)
{
    QByteArray *fileData = new QByteArray;
    database_users.open();

    query->prepare("SELECT file FROM messages WHERE content = ?");
    query->addBindValue(name);

    if (query->exec()) {
        if (query->first()) {
            *fileData = query->value(0).toByteArray();
            database_users.close();
            qDebug() << "FILE NAIDEN!!!" << (*fileData).size();
            return *fileData;
        }
    }

    database_users.close();
    return *fileData;
}

int DatabaseManager::getChatId(const QString &chatName, const QString &fromUser, bool &isGroup) {
    QString privateChatName1 = fromUser + "?" + chatName;
    QString privateChatName2 = chatName + "?" + fromUser;

    // Check if the chat is private
    query->prepare(R"(
        SELECT chat_id, is_group
        FROM chatsList
        WHERE (chat_name = :chat_name1 OR chat_name = :chat_name2)
    )");
    query->bindValue(":chat_name1", privateChatName1);
    query->bindValue(":chat_name2", privateChatName2);

    if (query->exec() && query->next()) {
        isGroup = query->value("is_group").toBool();
        return query->value("chat_id").toInt();
    }

    // Check if the chat is a group chat
    query->prepare(R"(
        SELECT chat_id, is_group
        FROM chatsList
        WHERE chat_name = :chat_name
    )");
    query->bindValue(":chat_name", chatName);

    if (query->exec() && query->next()) {
        isGroup = query->value("is_group").toBool();
        return query->value("chat_id").toInt();
    }

    qDebug() << "Error getting chat_id for" << chatName << ":" << query->lastError().text();
    return -1;
}

QString DatabaseManager::getUID(const QString &login)
{
    if (!database_users.isOpen()) {
        database_users.open();
    }
    if (userExist(login)) {
        if (database_users.open()) {
            query->prepare("SELECT user_id FROM usersList WHERE login = :login;");
            query->bindValue(":login", login);
            query->exec();
        }
        if(query->first()) {
            QString uid = query->value(0).toString();
            database_users.close();
            return uid;
        }
    }
    database_users.close();
    return {};
}

QString DatabaseManager::getUsersByKey(const QString &key, const QString &exceptId)
{
    QString users = "";
    if (database_users.open()) {
        query->prepare("SELECT * FROM usersList WHERE login LIKE :key AND user_id != :id;");
        query->bindValue(":key", "%" + key + "%");
        query->bindValue(":id", exceptId);
        query->exec();
        //////////////////////
        qDebug() << key << exceptId;
        //////////////////////
        while (query->next()) {
            users.append(query->value(1).toString() + "");
            //qDebug() << query->value(1).toString();
        }
        users.removeLast();
        //////////////////////
        qDebug() << users;
        //////////////////////
    }
    database_users.close();
    return users;
}

QString DatabaseManager::timeNow()
{
    std::time_t raw_time = std::time(nullptr);
    std::tm* time_info = std::localtime(&raw_time);;
    return {(time_info->tm_hour < 9 ? "0" : "")
            + QString::number(time_info->tm_hour) + ":" + (time_info->tm_min < 9 ? "0" : "")
            + QString::number(time_info->tm_min)};
}

QString DatabaseManager::dateNow()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;
    return {QString::number(day) + "." + QString::number(month) + "." + QString::number(year)};
}
