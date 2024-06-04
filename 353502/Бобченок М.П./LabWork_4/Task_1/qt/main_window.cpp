//
// Created by u on 09.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"

#include <random>
#include "ui_main_window.h"

void main_window::qs()
{
    if (solving)
        return;
    solving = true;
    time = clock();
    quicksort(0, columns.size() - 1);
    time = clock() - time;

    ui->time->setText(QString::number(time));

    solving = false;
}

void main_window::hs()
{
    if (solving)
        return;
    solving = true;
    time = clock();
    heapSort(columns.size());
    time = clock() - time;

    ui->time->setText(QString::number(time));

    solving = false;
}

void main_window::ms()
{
    if (solving)
        return;
    solving = true;
    time = clock();
    mergeSort(0, columns.size() - 1);
    time = clock() - time;

    ui->time->setText(QString::number(time));

    solving = false;
}

void main_window::is()
{
    if (solving)
        return;
    solving = true;
    time = clock();
    interpolationSort();
    time = clock() - time;

    ui->time->setText(QString::number(time));

    solving = false;
}

void main_window::restart()
{
    if (solving)
        return;
    columns.clear();
}

void main_window::updateWindow()
{
    if (!solving)
    {
        if (columns.size() != ui->columnsNum->value())
        {
            columns.clear();
            for (int i = 1; i <= ui->columnsNum->value(); i++)
            {
                columns.push_back(moving_rect(-680 + 1000 / ui->columnsNum->value() * (i - 1), 97, 1000 / ui->columnsNum->value(), -i * 5, 2));
            }

            shuffle(columns);
        }

        for (auto &u : columns)
            this->scene->addItem(&u);
    }
    else
    {
        for (auto &u : columns)
            this->scene->addItem(&u);
    }
}

void main_window::shuffle(std::vector<moving_rect> &v)
{
    int t = 1000;
    while (t--)
    {
        int i1 = rnd() % columns.size();
        int i2 = rnd() % columns.size();
        v[i1].swap(v[i2]);
    }
}

void main_window::quicksort(int L, int R)
{
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = columns[mid].getH();

    while (i < R || j > L)
    {
        while (columns[i].getH() > piv)
            i++;
        while (columns[j].getH() < piv)
            j--;

        if (i <= j)
        {
            columns[i].swap(columns[j]);
            columns[j].setColor(0);
            QCoreApplication::processEvents();
            updateWindow();
            usleep(1000000 - ui->speed->value());
            columns[j].setColor(2);
            QCoreApplication::processEvents();
            updateWindow();

            i++;
            j--;
        }
        else
        {
            if (i < R)
                quicksort(i, R);
            if (j > L)
                quicksort(L, j);
            return;
        }
    }
}

void main_window::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && columns[l].getH() < columns[largest].getH())
        largest = l;

    if (r < n && columns[r].getH() < columns[largest].getH())
        largest = r;

    if (largest != i)
    {
        columns[i].swap(columns[largest]);

        columns[largest].setColor(0);
        QCoreApplication::processEvents();
        updateWindow();
        usleep(1000000 - ui->speed->value());
        columns[largest].setColor(2);
        QCoreApplication::processEvents();
        updateWindow();

        heapify(n, largest);
    }
}

void main_window::heapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        columns[0].swap(columns[i]);

        columns[i].setColor(0);
        QCoreApplication::processEvents();
        updateWindow();
        usleep(1000000 - ui->speed->value());
        columns[i].setColor(2);
        QCoreApplication::processEvents();
        updateWindow();

        heapify(i, 0);
    }
}

void main_window::mergeSort(int left, int right)
{
    if(left < right)
    {
        int middle = (right + left) / 2;

        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
    }
}

void main_window::merge(int left, int mid, int right)
{
    std::vector<moving_rect> tmp;
    int i1 = left;
    int i2 = mid + 1;

    while (i1 <= mid || i2 <= right)
    {
        if (i1 <= mid && (i2 > right || columns[i1].getH() > columns[i2].getH()))
        {
            tmp.push_back(moving_rect(columns[i1].getX(), columns[i1].getY(), columns[i1].getW(), columns[i1].getH(), columns[i1].getColor()));
            i1++;
        }
        else
        {
            tmp.push_back(moving_rect(columns[i2].getX(), columns[i2].getY(), columns[i2].getW(), columns[i2].getH(), columns[i2].getColor()));
            i2++;
        }
    }

    for (int i = left; i <= right; i++)
    {
        columns[i].swap(tmp[i - left]);

        if (right != left)
        {
            columns[i].setColor(0);
            QCoreApplication::processEvents();
            updateWindow();
            usleep(1000000 - ui->speed->value());
            columns[i].setColor(2);
            QCoreApplication::processEvents();
            updateWindow();
        }
    }
    tmp.clear();
}

void main_window::interpolationSort()
{
    std::map<std::pair<int, int>, int> mp;
    std::vector<moving_rect> tmp;
    for (int i = 0; i < columns.size(); i++)
    {
        tmp.push_back(moving_rect(columns[i].getX(), columns[i].getY(), columns[i].getW(), columns[i].getH(), columns[i].getColor()));
        mp[{-columns[i].getH(), i}]++;
    }

    int i = 0;
    for (auto &u : mp)
    {
        std::cout << u.first.first << " " << u.first.second << "\n";

        columns[i].swap(tmp[u.first.second]);

        columns[i].setColor(0);
        QCoreApplication::processEvents();
        updateWindow();
        usleep(1000000 - ui->speed->value());
        columns[i].setColor(2);
        QCoreApplication::processEvents();
        updateWindow();

        i++;
    }

}

main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window)
{
    this->scene = new QGraphicsScene(this);
    ui->setupUi(this);
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    connect(ui->restart, SIGNAL(pressed()), this, SLOT(restart()));

    connect(ui->quickSort, SIGNAL(clicked(bool)), this, SLOT(qs()));
    connect(ui->heapSort, SIGNAL(clicked(bool)), this, SLOT(hs()));
    connect(ui->mergeSort, SIGNAL(clicked(bool)), this, SLOT(ms()));
    connect(ui->interpolationSort, SIGNAL(clicked(bool)), this, SLOT(is()));

    auto *timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    timer->start();
}

main_window::~main_window() {
    delete ui;
}
