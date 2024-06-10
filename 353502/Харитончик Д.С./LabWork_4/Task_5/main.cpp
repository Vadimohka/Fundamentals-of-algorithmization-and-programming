
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>
#include <qapplication.h>

// Класс Pair для представления пары значений
template<typename T1, typename T2>
class Pair {
public:
    Pair() = default;
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    T1 first;
    T2 second;
};

// Класс Vector для представления вектора, содержащего пары
template<typename T1, typename T2>
class Vector {
public:
    void addPair(const T1& value1, const T2& value2) {
        pairs.push_back(Pair<T1, T2>(value1, value2));
    }

    size_t size() const {
        return pairs.size();
    }

    Pair<T1, T2>& operator[](size_t index) {
        return pairs[index];
    }

private:
    std::vector<Pair<T1, T2>> pairs;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем объект класса Vector
    Vector<std::vector<int>, std::vector<Pair<int, double>>> vectorObject;

    // Добавляем данные
    vectorObject.addPair({1, 2, 3}, {{1, 1.1}, {2, 2.2}, {3, 3.3}});
    vectorObject.addPair({4, 5, 6}, {{4, 4.4}, {5, 5.5}, {6, 6.6}});

    // Создаем графический интерфейс
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Выводим содержимое vectorObject
    for (size_t i = 0; i < vectorObject.size(); ++i) {
        QLabel *label = new QLabel(&window);

        // Получаем данные из vectorObject
        auto& pair = vectorObject[i];
        auto& firstVector = pair.first;
        auto& secondVector = pair.second;

        // Формируем строку для вывода
        QString text = "Pair " + QString::number(i + 1) + ":\n";

        // Выводим первый вектор
        text += "First vector: ";
        for (const auto& value : firstVector) {
            text += QString::number(value) + " ";
        }
        text += "\n";

        // Выводим второй вектор
        text += "Second vector:\n";
        for (const auto& pair : secondVector) {
            text += "(" + QString::number(pair.first) + ", " + QString::number(pair.second) + ") ";
        }

        label->setText(text);
        layout->addWidget(label);
    }

    window.setLayout(layout);
    window.setWindowTitle("Vector of Pairs Example");
    window.show();

    return app.exec();
}
