# Создание простейшего аудиоредактора / среды DAW

Примечание: загруженный проект носит ознакомительный характер и не содержит необходимого подмодуля -- библиотеки PortAudio. Для сборки проекта см. [основной репозиторий](https://github.com/artemious3/aedit).

## Блок-схема алгоритма, реализующего быстрое преобразование Фурье

Применяется в `src/effects/Utils.h` в функции `Utils::ef_fft`.

![ДПФ](https://github.com/artemious3/Fundamentals-of-algorithmization-and-programming/blob/coursework/353501/%D0%9F%D0%BE%D0%B4%D0%B3%D0%B0%D0%B9%D1%81%D0%BA%D0%B8%D0%B9%20%D0%90.%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/schemes/scheme_dft.png)

## Блок-схема алгоритма, реализующего оконное преобразование Фурье

Применяется в `src/effects/FFTProcessor.cpp` в функции `FFTProcessor::_process`.

![ОПФ](https://github.com/artemious3/Fundamentals-of-algorithmization-and-programming/blob/coursework/353501/%D0%9F%D0%BE%D0%B4%D0%B3%D0%B0%D0%B9%D1%81%D0%BA%D0%B8%D0%B9%20%D0%90.%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/schemes/schemes_stft.png)

## Блок-схема алгоритма, реализующего реверберацию

Применяется в `src/effects/Reverb.cpp` в функции `Reverb::_process`.

![Реверберация](https://github.com/artemious3/Fundamentals-of-algorithmization-and-programming/blob/coursework/353501/%D0%9F%D0%BE%D0%B4%D0%B3%D0%B0%D0%B9%D1%81%D0%BA%D0%B8%D0%B9%20%D0%90.%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/schemes/scheme_rev.png)

## Блок-схема алгоритма, реализующего ратяжение звука по времени

Применяется в `src/effects/TimePitch.cpp` в функции `TimePitch::_process`.

![Растяжение по времени](https://github.com/artemious3/Fundamentals-of-algorithmization-and-programming/blob/coursework/353501/%D0%9F%D0%BE%D0%B4%D0%B3%D0%B0%D0%B9%D1%81%D0%BA%D0%B8%D0%B9%20%D0%90.%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/schemes/scheme_tp.png)

## Блок-схема алгоритма, реализующего фазовый вокодер

Применяется в `src/effects/Pitch.cpp` в функции `Pitch::processFftChunk`.

![Фазовый вокодер](https://github.com/artemious3/Fundamentals-of-algorithmization-and-programming/blob/coursework/353501/%D0%9F%D0%BE%D0%B4%D0%B3%D0%B0%D0%B9%D1%81%D0%BA%D0%B8%D0%B9%20%D0%90.%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/schemes/scheme_pv.png)
