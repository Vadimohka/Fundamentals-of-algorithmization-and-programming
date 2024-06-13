#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyString str("abcdefg");

    std::cout << str << std::endl;
    str = str + 'a';
    std::cout << str << std::endl;
    std::cout << str.front() << std::endl;
    str = str + str;
    std::cout << str << std::endl;
    str.erase(1, 3);
    std::cout << str << std::endl;
    std::cout << str.find("gaab") << std::endl;
    std::cout << (str.find("gab") == NO_SUCH_POSITION) << std::endl;
    str.push_back('s');
    std::cout << str << std::endl;

    MyBitset<8> a("10010011"), b("00111011");
    a = a & b;
    std::cout << a << std::endl;
    std::cout << a.count() << std::endl;
    a ^= b;
    std::cout << a.all() << std::endl;
    std::cout << a.any() << std::endl;
    std::cout << a.none() << std::endl;

    a = MyBitset<8>("10101010");
    std::cout << a.flip() << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

