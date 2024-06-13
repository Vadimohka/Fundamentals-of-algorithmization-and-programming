#include <QApplication>
#include "QMainWindow"
#include "QDebug"
#include <QPushButton>
#include <QLocale>
#include "QInputDialog"
#include <QFile>
#include "QTextEdit"
#include "QTextStream"
#include "QMainWindow"
#include "map"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow *Main = new QMainWindow;
    QTextEdit *TextPrinter = new QTextEdit;
    QFile stylesFile("/home/shosh/CourseProject/Course project/Styles/styles.qss");
    stylesFile.open(QIODevice::ReadWrite);
    QString style(stylesFile.readAll());
    a.setStyleSheet(style);
    while (true) {
        int num = QInputDialog::getInt(Main, QObject::tr("Enter the params"), QObject::tr("1 mean exiting, other numbers mean printing text"));
        QString text;
        switch (num) {
            case 1:
                return 0;
            default:
                text = QInputDialog::getText(Main, QObject::tr("Enter the text"), QObject::tr("Anything you like"));
                TextPrinter->show();
                TextPrinter->append(text);
                int size = QInputDialog::getInt(Main, QObject::tr("Enter the size of array"), QObject::tr("Size of array"));
                for (int i = 0; i < size; i++) {
                    double input = QInputDialog::getDouble(Main, QObject::tr("Enter double"), QObject::tr("Value"));
                }
        }
    }
    return QApplication::exec();
}
