#include <QCoreApplication>
#include <QTextStream>
#include <QStringList>
#include <algorithm>

std::vector<int> calculateMedians(const std::vector<int> &sequence) {
    std::vector<int> medians;
    std::vector<int> triplet;

    for (size_t i = 0; i < sequence.size(); ++i) {
        triplet.push_back(sequence[i]);

        if (triplet.size() == 3 || i == sequence.size() - 1) {
            std::sort(triplet.begin(), triplet.end());
            int medianIndex = triplet.size() / 2;
            if (triplet.size() % 2 == 0) {
                int median = (triplet[medianIndex - 1] + triplet[medianIndex]) / 2;
                medians.push_back(median);
            } else {
                medians.push_back(triplet[medianIndex]);
            }
            triplet.clear();
        }
    }

    return medians;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream in(stdin);
    QTextStream out(stdout);

    out << "Введите последовательность чисел (через пробел): ";
    out.flush();
    QString input = in.readLine();
    QStringList inputList = input.split(" ", Qt::SkipEmptyParts);

    std::vector<int> sequence;
    for (const QString& str : inputList) {
        sequence.push_back(str.toInt());
    }

    std::vector<int> medians = calculateMedians(sequence);

    out << "Исходная последовательность: ";
    for (int num : sequence) {
        out << num << " ";
    }
    out << Qt::endl;

    out << "Медианы подряд идущих троек элементов: ";
    for (int num : medians) {
        out << num << " ";
    }
    out << Qt::endl;

    return a.exec();
}
