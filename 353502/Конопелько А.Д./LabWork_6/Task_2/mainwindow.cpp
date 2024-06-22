#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTextStream>
#include <QFile>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stream_in(&text_in)
    , stream_out(&text_out)
{

    ui->setupUi(this);
    // ui->textEdit_2->setText("wgeb");
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::func);
    timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly())
        text_in += ui->lineEdit->text();
}

void MainWindow::func()
{
    auto& out = *ui->textEdit;
    auto& in = *ui->lineEdit;

    while (true) {
        QCoreApplication::processEvents();

        stream_out << "Select a menu option: \n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        in.setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int choice;
        stream_in >> choice;
        if (stream_in.status() != QTextStream::Ok) {
            text_in.clear();
            stream_in.resetStatus();
        } else {
            text_in.remove(0, stream_in.pos());
            stream_out << choice << '\n';
        }
        stream_in.seek(0);
        in.setText(text_in);
        processMenuChoice(choice);
    }
}

void MainWindow::processMenuChoice(int choice) {
    auto& out = *ui->textEdit;
    auto& in = *ui->lineEdit;
    switch (choice) {
    case 1:
    {
        QString fileName = "KonopelkoLab20.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "You selected option 1\nEnter a paragraph of text\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        text_in.clear();
        in.setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for writing\n";
        } else {
            for (int i = 0; i < text_in.length(); ++i) {
                file_stream << text_in.at(i);
            }
            file.close();
            text_in.clear();
            in.setText(text_in);
            stream_in.readAll();
            stream_out << "Text successfully written to the file\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            while (!file_stream.atEnd()) {
                QChar character;
                file_stream >> character;
                stream_out << character;
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 2:
    {
        QString fileName = "KonopelkoLab20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "You selected option 2\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for writing\n";
        } else {
            stream_out << "Enter the size of the array\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int n;
            stream_in >> n;
            if (stream_in.status() != QTextStream::Ok || n < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << n << '\n';
            }
            in.setText(text_in);

            char c;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                stream_out << "Enter character (" << i+1 << "/" << n << ")\n";
                out.setText(text_out);
                out.moveCursor(QTextCursor::End);
                while (text_in.isEmpty()){
                    QCoreApplication::processEvents();
                }
                stream_in >> c;
                if (stream_in.status() != QTextStream::Ok) {
                    stream_out << "Invalid input\n";
                    stream_in.seek(0);
                    stream_in.resetStatus();
                    text_in.clear();
                    ok = false;
                    break;
                } else {
                    text_in.remove(0, stream_in.pos());
                    stream_in.seek(0);
                    stream_out << c << '\n';
                }
                in.setText(text_in);
                file_stream << c << ':';
            }

            file.close();
            if (ok) stream_out << "Text successfully written to the file\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 3:
    {
        stream_out << "You selected option 3\nFile contents:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "KonopelkoLab20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            while (!file_stream.atEnd()) {
                QChar character;
                file_stream >> character;
                if (character != ':')
                    stream_out << character << ' ';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 4:
    {
        stream_out << "You selected option 4\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "KonopelkoLab20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for writing\n";
        } else {
            stream_out << "Enter AutoRepair address\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            QString addr = text_in;
            text_in.clear();
            stream_out << "Enter number of instruments\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int instruments;
            stream_in >> instruments;
            if (stream_in.status() != QTextStream::Ok || instruments < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);
            stream_out << "Enter number of floors\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int floors;
            stream_in >> floors;
            if (stream_in.status() != QTextStream::Ok || floors < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);
            stream_out << "Enter number of workers\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int workers;
            stream_in >> workers;
            if (stream_in.status() != QTextStream::Ok || workers < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);
            stream_out << "Enter AutoRepair area\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int area;
            stream_in >> area;
            if (stream_in.status() != QTextStream::Ok || area < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);

            file_stream << addr << ' ' << instruments << ' ' << floors << ' ' << workers << ' ' << area << '\n';
            file.close();
            stream_out << "Data of autoRepair was successfully written to the file\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 5:
    {
        stream_out << "You selected option 5\nFile contents:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "KonopelkoLab20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            while (!file_stream.atEnd()) {
                QString addr;
                int instruments, floors, workers, area;
                file_stream >> addr >> instruments >> floors >> workers >> area;
                if (file_stream.status() != QTextStream::Ok) {
                    break;
                }
                stream_out << addr << '|' << instruments << '|' << floors << '|' << workers << '|' << area << '\n';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 6:
    {
        stream_out << "You selected option 6\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "KonopelkoLab20_2.bin";
        QFile file(fileName);
        QDataStream file_stream(&file);
        if (!file.open(QIODevice::Append)) {
            stream_out << "Failed to open file " << fileName << " for writing\n";
        } else {
            stream_out << "Enter AutoRepair address\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            QString addr = text_in;
            text_in.clear();
            stream_out << "Enter number of instruments\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int instruments;
            stream_in >> instruments;
            if (stream_in.status() != QTextStream::Ok || instruments < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);
            stream_out << "Enter number of floors\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int floors;
            stream_in >> floors;
            if (stream_in.status() != QTextStream::Ok || floors < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);
            stream_out << "Enter number of workers\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int workers;
            stream_in >> workers;
            if (stream_in.status() != QTextStream::Ok || workers < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);
            stream_out << "Enter AutoRepair area\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int area;
            stream_in >> area;
            if (stream_in.status() != QTextStream::Ok || area < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            }
            text_in.clear();
            stream_in.seek(0);

            file_stream << addr << instruments << floors << workers << area;
            file.close();
            stream_out << "Data of AutoRepair was successfully written to the file\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 7:
    {
        stream_out << "You selected option 7\nFile contents:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "KonopelkoLab20_2.bin";
        QFile file(fileName);
        QDataStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            while (!file_stream.atEnd()) {
                QString addr;
                int instruments, floors, workers, area;
                file_stream >> addr >> instruments >> floors >> workers >> area;
                if (file_stream.status() != QDataStream::Ok) {
                    break;
                }
                stream_out << addr << " ; " << instruments << " ; " << floors << " ; " << workers << " ; " << area << '\n';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 8:
    {
        QString fileName = "KonopelkoLab20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "You selected option 8\nEnter a sentence\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        in.setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for writing\n";
        } else {
            file_stream << text_in << '\n';
            file.close();
            text_in.clear();
            in.setText(text_in);
            stream_in.readAll();
            stream_out << "Sentence successfully written to the file\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 9:
    {
        QString fileName = "KonopelkoLab20_3.txt";
        QFile file(fileName);
        stream_out << "You selected option 9\n";
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            QTextStream file_stream(&file);
            QMap<QChar, int> letter_count;
            while (!file_stream.atEnd()) {
                QString line = file_stream.readLine();
                for (QChar letter : line) {
                    if (letter.isLetter()) {
                        letter = letter.toLower();
                        letter_count[letter]++;
                    }
                }
            }
            file.close();
            stream_out << "Letter counts:\n";
            for (auto it = letter_count.begin(); it != letter_count.end(); ++it) {
                stream_out << it.key() << ": " << it.value() << "\n";
            }
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 10:
    {
        QApplication::exit();
        stream_out << "You selected option 10\n";
        stream_out << "Goodbye!";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QTimer::singleShot(300, this, [=](){

        });
        break;
    }
    default:
        stream_out << "Invalid option\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    stream_out << "\n";
    // Reset the line editor
    in.setReadOnly(false);
    in.clear();
    // Update the text output and scroll to the end
    out.setText(text_out);
    out.moveCursor(QTextCursor::End);
}
