#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  MainWindow window;
  window.setGeometry(200, 200, 1500, 700);
  window.show();

  return a.exec();
}
