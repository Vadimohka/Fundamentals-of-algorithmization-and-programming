#include "mainwindow.h"
#include "ui_mainwindow.h"

class C
{
private:
    int f;

public:
    //C() = default;
    C(int n)
    {
        qDebug() << "Ok";
        f = n;
    }
    void print() { qDebug() << f; }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myvector<C> vect();
    std::vector<C> st(10, 10);
    st[0].print();
    for (int i = 0; i < 10; i++) {
        c = {i, 10 - i};
        a.push_back(c);
        b.push_back(c);
    }
    auto it1 = a.end();
    it1--;
    auto it2 = b.end();
    it2--;
    a.erase(a.begin(), it1);
    b.erase(b.begin(), it2);
    qDebug() << a.size() << b.size();
    for (int i = 0; i < b.size(); i++) {
        qDebug() << a[i].first << a[i].second << b[i].first << b[i].second;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
