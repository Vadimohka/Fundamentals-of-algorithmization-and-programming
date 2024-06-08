## Разработка игры аналога GALAGA

# Блок-схема алгоритма, реализующего генерации объектов

Применяется в: `gamescene.h` в функции T *GameScene::SpawnObject()

![Algorithm scheme](schemes/Схема 1.jpg)

# Блок-схема алгоритма, реализующего обработку столкновений игровых объектов

Применяется в: `gameobj.cpp`  в функции void GameObj::PreUpdate()

![Algorithm scheme](schemes/Схема 2.jpg)

# Блок-схема алгоритма, реализующего общее движение врагов

Применяется в: `enemy.cpp`  в функции void Enemy::moveByPath(float dt)

![Algorithm scheme](schemes/Схема 3.jpg)

# Блок-схема алгоритма, реализующего спиральную атаку врага

Применяется в: `enemyspiral.cpp`  в функции void EnemySpiral::Update(float dt)

![Algorithm scheme](schemes/Схема 4.jpg)

# Блок-схема алгоритма, реализующего обработку игровых объектов

Применяется в: `gamescene.cpp`  в функции void GameScene::Update(float dt)

![Algorithm scheme](schemes/Схема 5.jpg)

# Функциональная схема программы

![Algorithm scheme](schemes/Схема 6.jpg)