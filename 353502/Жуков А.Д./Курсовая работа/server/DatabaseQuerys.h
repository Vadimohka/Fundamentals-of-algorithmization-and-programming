#ifndef DATABASEQUERYS_H
#define DATABASEQUERYS_H
#include <QString>

const QString DATABASE_CREATION_ERROR_DBMANAGER {"TABLE HASNT BEEN CREATED (dbm.cpp)"};
const QString DATABASE_OPEN_ERROR_DBMANAGER {"ERROR: Database hasn't been opened (dbm.cpp)"};
const QString CREATE_USERS_TABLE {R"(
                                     CREATE TABLE IF NOT EXISTS usersList (
                                     user_id INTEGER PRIMARY KEY AUTOINCREMENT,
                                     login TEXT NOT NULL UNIQUE,
                                     password TEXT NOT NULL
                                     );)"};
const QString CREATE_CHATS_TABLE {R"(
                                     CREATE TABLE IF NOT EXISTS chatsList (
                                     chat_id INTEGER PRIMARY KEY AUTOINCREMENT,
                                     chat_name TEXT UNIQUE,
                                     is_group BOOLEAN NOT NULL
                                     );)"};
const QString CREATE_MEMBERS_TABLE {R"(
                                     CREATE TABLE IF NOT EXISTS chat_members (
                                     chat_id INTEGER,
                                     user_id INTEGER,
                                     FOREIGN KEY (chat_id) REFERENCES chatsList(chat_id),
                                     FOREIGN KEY (user_id) REFERENCES usersList(user_id),
                                     PRIMARY KEY (chat_id, user_id)
                                     );)"};
const QString CREATE_MESSAGES_TABLE {R"(
                                     CREATE TABLE IF NOT EXISTS messages (
                                     message_id INTEGER PRIMARY KEY AUTOINCREMENT,
                                     chat_id INTEGER,
                                     user_id INTEGER,
                                     content TEXT,
                                     file BLOB,
                                     created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
                                     type TEXT NOT NULL,
                                     FOREIGN KEY (chat_id) REFERENCES chatsList(chat_id),
                                     FOREIGN KEY (user_id) REFERENCES usersList(user_id)
                                     );)"};

#endif // DATABASEQUERYS_H
