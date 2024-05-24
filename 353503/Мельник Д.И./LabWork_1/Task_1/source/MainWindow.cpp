//
// Created by dmitry on 10.2.24.
//

#include <MainWindow.h>


MainWindow::MainWindow(QWidget *parent) {
    m_upButton->move(30, 430);
    m_downButton->move(430,430);

    m_upButton->resize(50, 50);
    m_downButton->resize(50,50);
    m_upButton->setParent(this);
    m_downButton->setParent(this);

}

MainWindow::~MainWindow() noexcept {
}

