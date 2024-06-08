#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <QTextStream>
#include <QFile>
#include <QTextEdit>
#include "smartphone.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void ShowMenu();
    void PrintMenu(int choice);
    void SaveTextToFile();
    void GetFileContents();
    void SaveArrayToFile();
    void GetArrayContents();
    void SaveSmartphoneToFile();
    void GetSmartphoneContents();
    void SaveSmartphoneToBinaryFile();
    void GetSmartphoneFromBinaryFileContents();
    void AddTextToFile();
    void GetStringToFile();
private slots:
    void on_lineEdit_returnPressed();

    void on_menu_clicked();

private:
    Ui::MainWindow *ui;
    QString text_in;
    QString text_out;
    QTextStream stream_out;
    QTextStream stream_in;

    const QString menu = "\nМеню:\n1: ввести один абзац текста (до нажатия Enter). Сохранить данный текст в текстовый файл с именем «KaraichevaLab6.txt» посредством посимвольной записи\n"
                         "2: посимвольно считать из текстового файла с именем «KaraichevaLab6.txt» текст и вывести его на экран\n"
                         "3: ввести размер массива и массив типа short int, разделяющий символ '|'. Сохранить эти элементы массива в текстовый файл с именем «KaraichevaLab6_0.txt» посредством потокового ввода\n"
                         "4: cчитать из текстового файла с именем «KaraichevaLab6_0.txt» элементы массива посредством потокового вывода и вывести на экран считанный из файла массив, разделяя печатаемые значения символом «пробел»\n"
                         "5: ввести содержимое полей объекта типа структуры Smartphone. Сохранить содержимое всех полей структуры в текстовый файл с именем «KaraichevaLab6_1.txt»\n"
                         "6: прочитать из текстового файла с именем «KaraichevaLab6_1.txt» все записанные в нем структуры и распечатать содержимое их полей на экран, разделяя содержимое полей знаком '|'\n"
                         "7: запросить у пользователя ввести содержимое полей объекта типа вашей структуры. Сохранить содержимое всех полей структуры в бинарный файл с именем «KaraichevaLab6_2.bin»\n"
                         "8: прочитать из бинарного файла с именем «KaraichevaLab6_2.bin» все записанные в нем структуры и распечатать содержимое их полей на экран, разделяя содержимое полей символами \" ; \"\n"
                         "9: запросить у пользователя ввести предложение (до нажатия Enter) и дописать данное предложение в текстовый файл с именем «KaraichevaLab6_3.txt» в виде отдельной строки\n"
                         "10: построчно считать из текстового файла с именем «KaraichevaLab6_3.txt» все предложения и вывести их на экран\n"
                         "11: Выход\n"
                         "Выберите пункт меню: \n";
};
#endif // MAINWINDOW_H
