# МЕССЕНДЖЕР — ФАЙЛООБМЕННИК С ПЕРЕДАЧЕЙ СООБЩЕНИЙ И МЕДИА ЧЕРЕЗ ЛОКАЛЬНУЮ СЕТЬ

## Блок-схема алгоритма, реализующего загрузку чатов для пользователя

Применяется в `Messenger/databasemanager.cpp` в функции `DatabaseManager::getUserChatNames`.

![Схема 1](https://github.com/Tyrpirator/readme_test/assets/155314539/60c2838f-eda1-4f4a-885a-b3f8f2d13bcf)

## Блок-схема алгоритма, реализующего подгрузку сообщений из чата

Применяется в `Messenger/databasemanager.cpp` в функции `DatabaseManager::loadMessages`.

![Схема 2](https://github.com/Tyrpirator/readme_test/assets/155314539/2d8cf943-f491-4fa4-915b-1a51bb7038d2)


## Блок-схема алгоритма, реализующего создание чата

Применяется в `Messenger/databasemanager.cpp` в функции `DatabaseManager::createChat`.

![Схема 3](https://github.com/Tyrpirator/readme_test/assets/155314539/5798dac1-f59e-49a1-b709-f23f51c393f6)


## Блок-схема алгоритма, реализующего поиск id чата

Применяется в `Messenger/server.cpp` в функции `DatabaseManager::getChatId`.

![Схема 4](https://github.com/Tyrpirator/readme_test/assets/155314539/6dfe3497-b655-4c9e-8cae-7ad37445a78e)


## Блок-схема алгоритма, реализующего рассылку сообщений в чате

Применяется в `Messenger/server.cpp` в функции `Server::sendOut`.

![Схема 5](https://github.com/Tyrpirator/readme_test/assets/155314539/5ee36893-7504-409e-8e4c-e3f277803979)

