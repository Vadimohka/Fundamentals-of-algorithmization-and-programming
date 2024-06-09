#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   timer = new QTimer(this);
   connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
   //ui->pushButton->setFocus();
   //startTimer();
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   //QTextCodec *russiancodec = QTextCodec::codecForName("Cp1251");//указана кодировка для корректного отображения букв
   //QTextCodec::setCodecForCStrings(russiancodec);
   QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

   if (event->key() == Qt::Key_Escape) {

       if (timer->isActive()) {
           stopTimer();
       } else {
           startTimer();
       }

       enteredText.remove(enteredText.length() - 1, 1);
   }

   if (event->key() == Qt::Key_Backspace) {
       enteredText.remove(enteredText.length() - 1, 1); //
   }
   else {
       enteredText += event->text(); // Добавляем введенный текст к тексту
   }
   QTimer timer;
   timer.setInterval(1000);

   ui->label->setText(enteredText);
   if(enteredText.length() == fileContent.length()){
       stopTimer();
   ComparisonText(enteredText, fileContent);

       }
   else if(enteredText.length() > fileContent.length()){
   messageFunction();

   }
  /*
    *позволит автоматически определить кодировку ввода на основе локали.
    *Таким образом, если пользователь вводит русский или китайский язык, кодировка будет корректно обработана.
    *Это удобно, так как не требует явного указания кодировки для каждой строки текста.
    *Хотя установка кодировки по умолчанию удобна,
лучше всего всегда явно указывать кодировку для строк в своем коде.
Это поможет избежать потенциальных проблем с символами и
обеспечит более надежное поведение вашего приложения.*/

}

void MainWindow::on_pushButton_clicked()
{
   QString str = QFileDialog::getOpenFileName(nullptr, "Choose file",  "", "Текстовые файлы (*.txt)" );
   //ui->text_Language->setText(str);
   QFile file(str);
   if (file.open(QIODevice::ReadOnly)) {
       fileContent = QString::fromUtf8(file.readAll());

       //QVector<char> (str.begin(), str.end());
       //QTextStream in(&file);

       //QString fileContent = in.readAll();
       ui->text_Language->setText(fileContent);
       file.close();
   } else {
       // Обработка ошибки открытия файла
       qDebug() << "Ошибка при открытии файла: " << file.errorString();
   }

/*
сравнение написанного и с файла
точность
таймер
*/
}

void MainWindow::ComparisonText(QString text, QString input)
{
   int len = text.size();
   for(int i = 0; i < len - 1; ++i ){
       if (text[i] != input[i])
           wrong++;
   }

   double accuracy = (100 * (len - wrong))/ len;
   ui->correctly->setText(QString::number(accuracy) + " % ");

}

void MainWindow::messageFunction()
{

   QMessageBox msgBox(this);
   msgBox.setWindowTitle("Предупреждение");
   msgBox.setText("Текст написан");
   msgBox.setIcon(QMessageBox::Information);
   msgBox.exec();
}

void MainWindow::startTimer()
{
   timer->start(1000);  // Таймер с интервалом 1 секунда
   ui->Qtimer->setText("Timer started");
}

void MainWindow::stopTimer()
{
   timer->stop();
   ui->Qtimer->setText("Timer stopped");
   ui->time->setText(QString::number(counter) + "seconds");
   counter = 0;
}

void MainWindow::updateTimer()
{
   ++counter;
   ui->Qtimer->setText("Elapsed time: " + QString::number(counter) + " seconds");
}


