#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Ship {
    int shipId;
    double shipLength;
    char shipType;
    bool isDocked;
    static const int maxNameLength = 20;
    char shipName[maxNameLength];
    static const int maxCrewSize = 100;
    int crewSize;
};

void writeParagraphToFile(const string& filename) {
    wofstream file(filename, ios::out);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }
    getchar();
    cout << "Введите параграф (нажмите Enter для завершения):" << endl;
    wchar_t ch;
    while ((ch = getchar()) != L'\n') {
        file.put(ch);
    }

    file.close();
}

void readAndPrintParagraphFromFile(const string& filename) {
    wifstream file(filename, ios::in);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения!" << endl;
        return;
    }

    cout << "Параграф из файла " << filename << ":" << endl;
    wchar_t ch;
    while (file.get(ch)) {
        cout.put(ch);
    }

    file.close();
}

void writeArrayToFile(const string& filename, char delimiter) {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    ofstream file(filename, ios::out);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }

    cout << "Введите элементы массива, разделенные '" << delimiter << "': ";
    for (int i = 0; i < size; ++i) {
        char value;
        cin >> value;
        file << value;
        if (i != size - 1) {
            file << delimiter;
        }
    }

    file.close();
}

void readAndPrintArrayFromFile(const string& filename, char delimiter) {
    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения!" << endl;
        return;
    }

    cout << "Массив из файла " << filename << ":" << endl;
    char value;
    while (file.get(value)) {
        if (value != delimiter) {
            cout << value << " ";
        }
    }

    file.close();
}

void writeStructToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }

    Ship obj;
    cout << "Введите идентификатор корабля: ";
    cin >> obj.shipId;
    cout << "Введите длину корабля: ";
    cin >> obj.shipLength;
    cout << "Введите тип корабля: ";
    cin >> obj.shipType;
    cout << "Находится ли корабль пришвартованным (1 - да, 0 - нет): ";
    cin >> obj.isDocked;
    cout << "Введите имя корабля (не более " << Ship::maxNameLength << " символов): ";
    cin >> obj.shipName;
    cout << "Введите размер экипажа: ";
    cin >> obj.crewSize;

    file << obj.shipId << "|" << obj.shipLength << "|" << obj.shipType << "|" << obj.isDocked << "|" << obj.shipName << "|" << obj.crewSize << endl;

    file.close();
}

void readAndPrintStructsFromFile(const string& filename) {
    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения!" << endl;
        return;
    }

    cout << "Структуры из файла " << filename << ":" << endl;
    Ship obj;
    char delimiter;
    while (file >> obj.shipId >> delimiter && delimiter == '|' &&
           file >> obj.shipLength >> delimiter && delimiter == '|' &&
           file >> obj.shipType >> delimiter && delimiter == '|' &&
           file >> obj.isDocked >> delimiter && delimiter == '|' &&
           file >> obj.shipName >> delimiter && delimiter == '|' &&
           file >> obj.crewSize) {
        cout << obj.shipId << "|" << obj.shipLength << "|" << obj.shipType << "|" << obj.isDocked << "|" << obj.shipName << "|" << obj.crewSize << " ; ";
    }

    file.close();
}

void writeSentenceToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }

    cin.ignore();
    string sentence;
    cout << "Введите предложение: ";
    getline(cin, sentence);

    file << sentence << endl;

    file.close();
}

void readAndPrintSentencesFromFile(const string& filename) {
    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения!" << endl;
        return;
    }

    cout << "Предложения из файла " << filename << ":" << endl;
    string sentence;
    while (getline(file, sentence)) {
        cout << sentence << endl;
    }

    file.close();
}

int main() {
    int choice;
    const string surname = "ФамилияЛаб20";
    const string paragraphFile = surname + ".txt";
    const string arrayFile = surname + "_0.txt";
    const string structFile = surname + "_1.txt";
    const string binaryFile = surname + "_2.bin";
    const string sentenceFile = surname + "_3.txt";

    do {
        cout << "\nМеню:\n"
             << "1. Записать параграф в файл\n"
             << "2. Прочитать и распечатать параграф из файла\n"
             << "3. Записать массив в файл\n"
             << "4. Прочитать и распечатать массив из файла\n"
             << "5. Записать структуру в файл\n"
             << "6. Прочитать и распечатать структуры из файла\n"
             << "7. Записать предложение в файл\n"
             << "8. Прочитать и распечатать предложения из файла\n"
             << "9. Выход\n"
             << "Введите ваш выбор: ";

        cin >> choice;

        switch (choice) {
            case 1:
                writeParagraphToFile(paragraphFile);
                break;
            case 2:
                readAndPrintParagraphFromFile(paragraphFile);
                break;
            case 3:
                writeArrayToFile(arrayFile, '-');
                break;
            case 4:
                readAndPrintArrayFromFile(arrayFile, '-');
                break;
            case 5:
                writeStructToFile(structFile);
                break;
            case 6:
                readAndPrintStructsFromFile(structFile);
                break;
            case 7:
                writeSentenceToFile(sentenceFile);
                break;
            case 8:
                readAndPrintSentencesFromFile(sentenceFile);
                break;
            case 9:
                cout << "Завершение программы...\n";
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, введите число от 1 до 9.\n";
        }
    } while (choice != 9);

    return 0;
}
