#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    QFile file("../mainwindow.cpp");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(QString("Не удалось открыть файл: %1").arg("../mainwindow.cpp").toStdString());
    }
    QTextStream in(&file);
    QStringList lines;
    int stringCounter = 0;
    while (!in.atEnd()) {
        QString line = QString::number(stringCounter) + " " + in.readLine();
        queue.insertBack(line);
        stringCounter++;
    }
    file.close();


    updateWidget(this->queue);

    QString str = getElementByIndex(queue, 2);

}

void MainWindow::on_insertButton_clicked(){
    int indexToInsert = -1;
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->isSelected()) {
            indexToInsert = i;
        }
    }
    if(indexToInsert != -1){
        insertElementsBefore(queue, indexToInsert, selectedElems);
        updateWidget(queue);
    }
}

void MainWindow::insertElementsBefore(Queue<QString>& deque, int index, QVector<QString>& elementsToInsert) {
    QVector<QString> poppedElems;
    
    int indexCounter = 0;
    while(indexCounter != index){
        poppedElems.push_back(deque.front());
        deque.deleteFront();
        indexCounter++;
    }

    while(!elementsToInsert.isEmpty()){
        deque.insertFront(elementsToInsert.front());
        elementsToInsert.pop_front();
    }

    while(!poppedElems.isEmpty()){
        deque.insertFront(poppedElems.back());
        poppedElems.pop_back();
    }
    
    printDeque(deque);
}

void MainWindow::on_pushButton_clicked(){
    removeSelectedItemsFromQueue(queue);
    makeListOfSelectedElems(queue);
    updateWidget(queue);
}

void MainWindow::updateWidget(Queue<QString>& queue){
    ui->listWidget->clear();
    for (int i = 0; i < queue.size(); ++i) {
        ui->listWidget->addItem(queue.front());
        queue.insertBack(queue.front());
        queue.deleteFront();
    }
}

void MainWindow::makeListOfSelectedElems(Queue<QString>& deque){
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->isSelected()) {
            selectedElems.push_back(item->text());
        }
    }
}

void MainWindow::removeSelectedItemsFromQueue(Queue<QString>& deque){
    QVector<int> indexes;
    int counter = 0;
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->isSelected()) {
            indexes.push_back(i - counter);
            counter++;
        }
    }
    for(size_t i = 0; i < indexes.size(); i++){
        removeElementByIndex(deque, indexes[i]);
    }
}

void MainWindow::removeElementByIndex(Queue<QString>& deque, size_t index) {
    Queue<QString> tempDeque;

    for (size_t i = 0; i < index; i++) {
        if (deque.isEmpty()) {
            throw std::out_of_range("Очередь слишком короткая для заданного индекса");
        }
        tempDeque.insertBack(deque.front());
        deque.deleteFront();
    }

    if (deque.isEmpty()) {
        throw std::out_of_range("Очередь слишком короткая для заданного индекса");
    }
    deque.deleteFront();

    while (!tempDeque.isEmpty()) {
        deque.insertFront(tempDeque.back());
        tempDeque.deleteBack();
    }
    printDeque(deque);
}

void MainWindow::printDeque(Queue<QString>& deque) {
    qDebug() << "Элементы Deque:";
    for (int i = 0; i < deque.size(); ++i) {
        qDebug() << (deque.front()) << " ";
        deque.insertBack(deque.front());
        deque.deleteFront();
    }
    qDebug() << "\n";
}

QString MainWindow::getElementByIndex(Queue<QString>& queue, size_t index) {
    Queue<QString> tempQueue;
    
    for (size_t i = 0; i < index; i++) {
        if (queue.isEmpty()) {
            throw std::out_of_range("Очередь слишком короткая для заданного индекса");
        }
        tempQueue.insertBack(queue.front());
        queue.deleteFront();
    }

    QString result = tempQueue.front();

    while (!tempQueue.isEmpty()) {
        queue.insertFront(tempQueue.back());
        tempQueue.deleteBack();
    }
    
    return result;
}