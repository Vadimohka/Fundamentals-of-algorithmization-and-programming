## Визуальный редактор 3D графиков

## Функциональная cхема программы

![Algorithm scheme](schemes/Функциональная%20схема.png)

## Блок-схема алгоритма, реализующего обработку выражений

Применяется в: parser.cpp в методе infixToPostfix(std::string infix)

![Algorithm scheme](schemes/Блок-схема1.png)

## Блок-схема алгоритма, реализующего вычисление точек фунции

Применяется в: parser.cpp в методе Сalc(float x, float y,std::string& infix)

![Algorithm scheme](schemes/Блок-схема2.png)

## Блок-схема алгоритма, реализующего вращение и масштабирование

Применяется в: mainwidget.cpp в методах mouseReleaseEvent(QMouseEvent *e), wheelEvent(QWheelEvent *e), timerEvent
(QTimerEvent *timer)

![Algorithm scheme](schemes/Блок-схема3.png)

## Блок-схема алгоритма, реализующего сохранение текущих функций

Применяется в: surface.cpp в методе saveToFile()

![Algorithm scheme](schemes/Блок-схема4.png)

## Блок-схема алгоритма, реализующего нахождение пересечений

Применяется в: surface.cpp в методе drawSection(std::vector<int> sections)

![Algorithm scheme](schemes/Блок-схема5.png)
