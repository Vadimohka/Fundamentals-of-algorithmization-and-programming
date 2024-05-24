//
// Created by dmitry on 10.2.24.
//

#ifndef FIRST_MAINWINDOW_H
#define FIRST_MAINWINDOW_H

#include <QGraphicsItem>

#include <Button.h>

class MainWindow :
        public Button
{
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  };


#endif //FIRST_MAINWINDOW_H
