#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , deque(new Deque<int>())
{
    ui->setupUi(this);
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 10; i++) {
        deque->push_back(rand() % 200 - 99);
    }
    updateBrowser();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete deque;
    deque = nullptr;
}

void MainWindow::updateBrowser()
{
    QFont font = ui->dequeBrowser->font();
    font.setPointSize(14);
    ui->dequeBrowser->setFont(font);
    QString dequeS;
    for (size_t i = 0; i < deque->get_size(); i++) {
        dequeS += QString::number(deque->at(i)) + "    ";
    }
    ui->dequeBrowser->setText(dequeS.trimmed());
}

bool MainWindow::is_sorted()
{
    Node<int> *current = deque->get_front();
    while (current != nullptr && current->next != nullptr) {
        if (current->value > current->next->value) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void MainWindow::on_pop_back_clicked()
{
    if (!deque->is_empty()) {
        int val = deque->pop_back();
        QMessageBox::information(this,
                                 "Элемент удален",
                                 "Значение " + QString::number(val) + " было удалено с конца дека");
    } else {
        QMessageBox::warning(this, "Дек пуст", "Невозможно удалить элемент: дек пуст.");
    }
    updateBrowser();
}

void MainWindow::on_pop_front_clicked()
{
    if (!deque->is_empty()) {
        int value = deque->pop_front();
        QMessageBox::information(this,
                                 "Элемент удален",
                                 "Значение " + QString::number(value)
                                     + " было удалено с начала дека.");
    } else {
        QMessageBox::warning(this, "Дек пуст", "Невозможно удалить элемент: дек пуст.");
    }
    updateBrowser();
}

void MainWindow::on_push_back_clicked()
{
    bool ok;
    int value
        = QInputDialog::getInt(this, "Введите значение", "Значение: ", 0, INT_MIN, INT_MAX, 1, &ok);
    if (ok) {
        deque->push_back(value);
        updateBrowser();
    }
}

void MainWindow::on_push_front_clicked()
{
    bool ok;
    int value
        = QInputDialog::getInt(this, "Введите значение", "Значение: ", 0, INT_MIN, INT_MAX, 1, &ok);
    if (ok) {
        deque->push_front(value);
        updateBrowser();
    }
}

void MainWindow::on_at_clicked()
{
    bool ok;
    int index = QInputDialog::getInt(this,
                                     "Введите индекс",
                                     "Индекс:",
                                     0,
                                     0,
                                     deque->get_size() - 1,
                                     1,
                                     &ok);
    if (ok) {
        int value = deque->at(index);
        QMessageBox::information(this,
                                 "Значение элемента",
                                 "Значение элемента на позиции " + QString::number(index) + ": "
                                     + QString::number(value));
    }
}

void MainWindow::on_get_size_clicked()
{
    size_t size = deque->get_size();
    QMessageBox::information(this, "Размер дека", "Размер дека: " + QString::number(size));
}

void MainWindow::on_is_empty_clicked()
{
    if (deque->is_empty()) {
        QMessageBox::information(this, "Статус дека", "Дек пуст.");
    } else {
        QMessageBox::information(this, "Статус дека", "В деке есть элементы.");
    }
}

void MainWindow::on_peek_back_clicked()
{
    if (!deque->is_empty()) {
        int value = deque->peek_back();
        QMessageBox::information(this,
                                 "Просмотр заднего элемента",
                                 "Задний элемент: " + QString::number(value));
    } else {
        QMessageBox::warning(this, "Дек пуст", "Невозможно просмотреть элемент: дек пуст.");
    }
}

void MainWindow::on_peek_front_clicked()
{
    if (!deque->is_empty()) {
        int val = deque->peek_front();
        QMessageBox::information(this,
                                 "Просмотр переднего элемента",
                                 "Передний элемент: " + QString::number(val));
    } else {
        QMessageBox::warning(this, "Дек пуст", "Невозможно просмотреть элемент: дек пуст.");
    }
}

void MainWindow::on_sort_clicked()
{
    if (deque != nullptr && !deque->is_empty()) {
        if (is_sorted()) {
            QMessageBox::information(this, "Сортировка", "Элементы дека уже отсортированы.");
        } else {
            deque->sort();
            updateBrowser();
            QMessageBox::information(this, "Сортировка выполнена", "Элементы дека отсортированы.");
        }
    } else {
        QMessageBox::warning(this, "Дек пуст", "Невозможно отсортировать элементы: дек пуст.");
    }
}
