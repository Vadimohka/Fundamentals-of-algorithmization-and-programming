#include "mainwindow.h"
#include "notebook.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTextStream>
#include <QFile>
#include <fstream>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stream_in(&text_in)
    , stream_out(&text_out)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::menu);
    timer->start(100);
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
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

void MainWindow::menu()
{
    QTextEdit& out = *ui->textEdit;
    QLineEdit& in = *ui->lineEdit;

    while (true) {
        QCoreApplication::processEvents();

        stream_out <<"Choose \n" ;
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
        QString fileName = "СтанкевичЛаб20.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Number 1\nWrite text\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        text_in.clear();
        in.setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for save\n";
        } else {
            for (int i = 0; i < text_in.length(); ++i) {
                file_stream << text_in.at(i);
            }
            file.close();
            text_in.clear();
            in.setText(text_in);
            stream_in.readAll();
            stream_out << "Succes saving\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 2:
    {
        QString fileName = "path/to/your/file.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "You selected option 2\nFile content:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        if (!file.exists()) {
            stream_out << "File " << fileName << " does not exist\n";
        } else if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for read\n";
        } else {
            while (!file_stream.atEnd()) {
                QString line;
                file_stream >> line;
                stream_out << line << "\n";
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 3:
    {
        QString fileName = "СтанкевичЛаб20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Number 3\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream_out << "Failed to open file" << fileName << " for save\n";
        } else {
            stream_out << "Enter array size\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int n;
            stream_in >> n;
            if (stream_in.status() != QTextStream::Ok || n < 0) {
                stream_out << "Wrong enter\n";
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

            float c;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                stream_out << "Write symbol (" << i+1 << "/" << n << ")\n";
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
                file_stream << c << '>';
            }

            file.close();
            if (ok) stream_out << "Numbers successfully written to file\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }

    case 4:
    {
        QString fileName = "СтанкевичЛаб20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Number 4\nFile contents:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);

        if (!file.exists()) {
            stream_out << "File " << fileName << " does not exist\n";
        } else if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            while (!file_stream.atEnd()) {
                QChar character;
                file_stream >> character;
                if (character == '>') {
                    stream_out << ' ';
                } else {
                    stream_out << character;
                }
            }
            file.close();
        }

        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 5:
    {
        stream_out << "Number 5\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "СтанкевичЛаб20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            stream_out << "Failed to open file" << fileName << " for save\n";
        } else {
            Notebook notebook;
            stream_out << "Enter year (int)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> notebook.year;
            if (stream_in.status() != QTextStream::Ok || notebook.year < 1900 || notebook.year > 2025) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.year << '\n';
            }
            in.setText(text_in);

            stream_out << "Write cost (double)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> notebook.price;
            if (stream_in.status() != QTextStream::Ok || notebook.price < 0) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                //notebook.price = round(notebook.price * 100.0) / 100.0;
                stream_out << QString::number(notebook.price) << '\n';
            }
            in.setText(text_in);

            stream_out << "Write name of laptop (char)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> notebook.model;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "Invalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.model << '\n';
            }
            in.setText(text_in);

            stream_out << "Enter availability (bool as int)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int t;
            stream_in >> t;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "Ivalid input\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                notebook.isAvailable = t;
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.isAvailable << '\n';
            }
            in.setText(text_in);

            file_stream << notebook.year << '\n' << QString::number(notebook.price, 'g', 100) << '\n' << notebook.model << '\n' << notebook.isAvailable << '\n';

            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }

    case 6:
    {
        stream_out << "Number 6\nFile contents:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "СтанкевичЛаб20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);

        if (!file.exists()) {
            stream_out << "File " << fileName << " does not exist\n";
        } else if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for reading\n";
        } else {
            int i = 0;
            QString line;
            QVector<QString> vec(4);
            while (!file_stream.atEnd()) {
                line = file_stream.readLine();
                vec[i] = line;
                ++i;
                if (i == 4) {
                    for (int j = 0; j < i; ++j) {
                        if (j != 0) stream_out << " | ";
                        stream_out << vec[j];
                    }
                    stream_out << '\n';
                    i = 0;
                }
            }
            for (int j = 0; j < i; ++j) {
                if (j != 0) stream_out << " | ";
                stream_out << vec[j];
            }
            file.close();
        }

        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 7:
    {
        stream_out << "Number 7\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "СтанкевичЛаб20_2.bin";
        std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
        if (!file.is_open()) {
            stream_out << "Invalid " << fileName << " for read\n";
        } else {
            Notebook notebook;
            stream_out << "Year (int)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> notebook.year;
            if (stream_in.status() != QTextStream::Ok || notebook.year < 1900 || notebook.year > 2025) {
                stream_out << "Invalid\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.year << '\n';
            }
            in.setText(text_in);

            stream_out << "Cost (double)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> notebook.price;
            if (stream_in.status() != QTextStream::Ok || notebook.price < 0) {
                stream_out << "Invalid\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.price << '\n';
            }
            in.setText(text_in);

            stream_out << "Model (char)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> notebook.model;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "Invalid\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.model << '\n';
            }
            in.setText(text_in);

            stream_out << "Availability (bool as int)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int t;
            stream_in >> t;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "Invalid\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                notebook.isAvailable = t;
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << notebook.isAvailable << '\n';
            }
            in.setText(text_in);

            file.write(reinterpret_cast<const char*>(&notebook), sizeof(notebook));

            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 8:
    {
        stream_out << "Number 8\nFile Content:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "СтанкевичЛаб20_2.bin";
        std::ifstream file(fileName.toStdString(), std::ios::binary);
        if (!file.is_open()) {
            stream_out << "Invalid " << fileName << " for read\n";
        } else {
            Notebook notebook;
            while (!file.eof()) {
                file.read(reinterpret_cast<char*>(&notebook), sizeof(notebook));
                if (file.eof()) break;
                stream_out << "Year: " << notebook.year << " \n";
                                                               stream_out << "Cost: " << notebook.price << " \n";
                stream_out << "Model: " << notebook.model << " \n";
                    stream_out << "Avalability: " << (notebook.isAvailable ? "Yes" : "No") << '\n';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 9:
    {
        QString fileName = "СтанкевичЛаб20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Number 9\nWrite text\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        text_in.clear();
        in.setReadOnly(false);

        while (text_in.isEmpty()) {
            QCoreApplication::processEvents();
        }

        in.setReadOnly(true);

        if (!file.exists()) {
            if (!file.open(QIODevice::Append | QIODevice::Text)) {
                    stream_out << "Failed to create file " << fileName << " for writing\n";
            } else {
                    file_stream << text_in << '\n';
                    file.close();
                    text_in.clear();
                    in.setText(text_in);
                    stream_in.readAll();
                    stream_out << "Save successful\n";
            }
        } else if (!file.open(QIODevice::Append | QIODevice::Text)) {
            stream_out << "Failed to open file " << fileName << " for writing\n";
        } else {
            file_stream << text_in << '\n';
            file.close();
            text_in.clear();
            in.setText(text_in);
            stream_in.readAll();
            stream_out << "Save successful\n";
        }

        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 10:
    {
        stream_out << "Number 10\n File content:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "Станкевич20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Invalid " << fileName << " for read\n";
        } else {
            QString line;
            while (!file_stream.atEnd()) {
                line = file_stream.readLine();
                stream_out << line << '\n';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 11:
        stream_out << "Exit.\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);

        exit(0);
        break;
    default:
        stream_out << " pls from 1 to 11\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
    }
    stream_out << "\n";
    out.setText(text_out);
    out.moveCursor(QTextCursor::End);
    in.setReadOnly(true);
}
