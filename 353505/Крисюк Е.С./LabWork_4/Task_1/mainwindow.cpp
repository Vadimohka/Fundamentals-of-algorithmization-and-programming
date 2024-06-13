#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui -> graphicsView -> setScene(scene);

    all_radio_buttons = new QButtonGroup();
    all_radio_buttons -> addButton(ui -> Heap_sort_button);
    all_radio_buttons -> addButton(ui -> Merge_sort_button);
    all_radio_buttons -> addButton(ui -> Quick_sort_button);

    val = new QIntValidator(0,99);

    ui -> Array_size_line -> setValidator(val);
    ui -> Bin_search_number_input_line -> setValidator(val);

    scene -> setBackgroundBrush(Qt::black);

    time = 40;

    is_sorted = false;

    index = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Array_size_line_textChanged(const QString &arg1)
{
    ui -> Time_label -> setText("0");
    QString text = ui -> Array_size_line -> text();

    scene -> clear();
    Rect_list.clear();

    if(text != "") {

        if(text.toInt() > 99){
            ui -> Array_size_line -> setText(QString::number(99));
        }

        else if(text.toInt() == 0){
            ui -> Array_size_line -> setText(QString::number(1));
        }

        ui -> Sort_button -> setEnabled(true);
        ui -> Create_new_columns_button -> setEnabled(true);

        current_array_length = ui -> Array_size_line -> text().toInt();
        current_array = new int[current_array_length];

        scene -> clear();
        Array_input(current_array_length);


        Array_to_scene(current_array_length);

    }

    else{

        ui -> Sort_button -> setEnabled(false);
    }
}


void MainWindow::Array_input(int current_array_length){

    for(int i = 0; i < current_array_length; ++i){
        current_array[i] = QRandomGenerator::global() -> bounded(1,100);
    }
}
void MainWindow::Array_to_scene(int current_array_length){

    Rectangle* rect;

    Rect_list.clear();

    qreal min_pos = 0;
    qreal max_pos = 500;
    qreal d;

    if(current_array_length == 1){
        d = 10;
    }
    else{
        d = (max_pos - min_pos) / (current_array_length - 1);
    }
    if(d > 10){
        d = 10;
    }
    qreal current_pos = 0;

    QBrush brush(QColor(255, 255, 255));

    for(int i = 0; i < current_array_length; ++i){
        qreal height = current_array[i] * 3;

        rect = new Rectangle(current_pos, -height, d, height, nullptr);

        rect -> setBrush(brush);

        current_pos += d;

        Rect_list.append(rect);

        scene -> addItem(rect);

    }
}

void MainWindow::on_Sort_button_clicked()
{

    ui -> Time_label -> setText("");

    Set_buttons_enabled(false);

    if(ui -> Heap_sort_button -> isChecked() || ui -> Merge_sort_button -> isChecked() || ui -> Quick_sort_button -> isChecked()){
        QElapsedTimer timer;
        timer.start();

        if(ui -> Heap_sort_button -> isChecked()){

            HeapSort(current_array, current_array_length);

        }
        else if(ui -> Merge_sort_button -> isChecked()){

            MergeSort(current_array, 0, current_array_length - 1);

        }
        else if(ui -> Quick_sort_button -> isChecked()){

            QuickSort(current_array, 0 , current_array_length - 1);
        }
        qint64 time = timer.elapsed();

        ui -> Time_label -> setText(QString::number(time));

        Set_buttons_enabled(true);

        is_sorted = true;
    }
    else{
        QMessageBox* box = new QMessageBox();
        box -> setText("Выберите сортировку");

        Set_buttons_enabled(true);

        box -> exec();
    }

    if(is_sorted){
        QMessageBox* box = new QMessageBox();
        box -> setText("Массив отсортирован!");

        box -> exec();
    }
}

void MainWindow::QuickSort(int* &array, int min_index, int max_index){
    int left_index = min_index;
    int right_index = max_index;

    int pivot = array[(min_index + max_index) / 2];

    int pivot_index = (left_index + right_index) / 2;


    while(left_index <= right_index){

        while(array[left_index] < pivot){
            left_index++;

        }

        while(array[right_index] > pivot){
            right_index--;
        }

        if(left_index <= right_index){

            if(left_index != right_index){

                Swap_array_elements(array[left_index], array[right_index]);

                Swap_rectangles(left_index, right_index);


            }

            left_index++;
            right_index--;

        }


    }
    if(min_index < right_index){
        QuickSort(array, min_index, right_index);
    }

    if(max_index > left_index){
        QuickSort(array, left_index, max_index);
    }

}

void MainWindow::MergeSort(int* &array, int left, int right) {

    if (left < right) {
        int middle = (right + left) / 2;

        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);

        Merge(array, left, middle, right);
    }

}

void MainWindow::Merge(int* &array, int left, int middle, int right) {

    int left_array_size = middle - left + 1;
    int right_array_size = right - middle;

    int* left_array = new int[left_array_size];
    int* right_array = new int[right_array_size];


    for (int i = 0; i < left_array_size; i++){
        left_array[i] = array[left + i];

    }

    for (int i = 0; i < right_array_size; i++){
        right_array[i] = array[middle + 1 + i];

    }

    int left_array_index = 0;
    int right_array_index = 0;

    int array_current_index = left;

    while (left_array_index < left_array_size && right_array_index < right_array_size) {

        if (left_array[left_array_index] <= right_array[right_array_index]) {

            if(array[array_current_index] != left_array[left_array_index]){

                array[array_current_index] = left_array[left_array_index];

                Set_rectangle(array_current_index, left_array[left_array_index]);

            }

            left_array_index++;
        }
        else {

            if(array[array_current_index] != right_array[right_array_index]){

                array[array_current_index] = right_array[right_array_index];

                Set_rectangle(array_current_index, right_array[right_array_index]);

            }

            right_array_index++;
        }
        array_current_index++;
    }


    while (left_array_index < left_array_size) {

        if(array[array_current_index] != left_array[left_array_index]){

            array[array_current_index] = left_array[left_array_index];

            Set_rectangle(array_current_index, left_array[left_array_index]);
        }

        left_array_index++;
        array_current_index++;
    }

    while (right_array_index < right_array_size) {

        if(array[array_current_index] != right_array[right_array_index]){

            array[array_current_index] = right_array[right_array_index];
            Set_rectangle(array_current_index, right_array[right_array_index]);

        }

        right_array_index++;
        array_current_index++;
    }

    delete[] left_array;
    delete[] right_array;

}

void MainWindow::HeapSort(int* &array, int size){

    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        Swap_array_elements(array[0], array[i]);
        Swap_rectangles(0,i);

        Heapify(array, i, 0);
    }
}
void MainWindow::Heapify(int* & array, int size, int root_index){

    int largest_index = root_index;
    int left_child_index = 2 * root_index + 1;
    int right_child_index = 2 * root_index + 2;


    if (left_child_index < size && array[left_child_index] > array[largest_index]) {
        largest_index = left_child_index;
    }

    if (right_child_index < size && array[right_child_index] > array[largest_index]) {
        largest_index = right_child_index;
    }

    if (largest_index != root_index) {

        Swap_array_elements(array[root_index], array[largest_index]);
        Swap_rectangles(root_index,largest_index);

        Heapify(array, size, largest_index);
    }
}
void MainWindow::Swap_array_elements(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void MainWindow::Swap_rectangles(int first_index, int second_index) {
    qreal first_x = Rect_list[first_index] -> GetX();
    qreal second_x = Rect_list[second_index] -> GetX();

    Rectangle* first_rect = new Rectangle(second_x, Rect_list[first_index]->GetY(), Rect_list[first_index]->GetWidth(), Rect_list[first_index]->GetHeight(), nullptr);
    Rectangle* second_rect = new Rectangle(first_x, Rect_list[second_index]->GetY(), Rect_list[second_index]->GetWidth(), Rect_list[second_index]->GetHeight(), nullptr);

    Rect_list[first_index] -> SetColor(QColor(5, 219, 247));
    Rect_list[second_index] -> SetColor(QColor(5, 219, 247));

    QTime pauseTime = QTime::currentTime().addMSecs(time);

    while (QTime::currentTime() < pauseTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, time);
    }

    scene -> removeItem(Rect_list[first_index]);
    scene -> removeItem(Rect_list[second_index]);

    Rect_list[first_index] = second_rect;
    Rect_list[second_index] = first_rect;

    scene -> addItem(Rect_list[first_index]);
    scene -> addItem(Rect_list[second_index]);

    Rect_list[first_index] -> SetColor(QColor(255, 255, 255));
    Rect_list[second_index] -> SetColor(QColor(255, 255, 255));

}
void MainWindow::Set_rectangle(int current_index, qreal height){

    qreal x = Rect_list[current_index] -> GetX();

    Rectangle* rect = new Rectangle(x,-3 * height,Rect_list[current_index] -> GetWidth(), 3 * height);

    rect -> SetColor(QColor(5, 219, 247));

    QTime pauseTime = QTime::currentTime().addMSecs(time);

    while (QTime::currentTime() < pauseTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, time);
    }

    scene -> removeItem(Rect_list[current_index]);

    Rect_list[current_index] = rect;
    Rect_list[current_index] -> SetColor(QColor(255, 255, 255));

    scene -> addItem(Rect_list[current_index]);
}

void MainWindow::Set_rectangle(int current_index, qreal height, QColor color){

    qreal x = Rect_list[current_index] -> GetX();

    Rectangle* rect = new Rectangle(x,-3 * height,Rect_list[current_index] -> GetWidth(), 3 * height);

    rect -> SetColor(color);

    QTime pauseTime = QTime::currentTime().addMSecs(time);

    while (QTime::currentTime() < pauseTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, time);
    }

    scene -> removeItem(Rect_list[current_index]);

    Rect_list[current_index] = rect;

    scene -> addItem(Rect_list[current_index]);
}

void MainWindow::Debug_array(){
    qDebug() << "===========================";
    for(int i = 0; i < current_array_length; ++i){
        qDebug() << current_array[i];
    }
    qDebug() << "===========================";
}

void MainWindow::Set_buttons_enabled(bool mode){
    if(mode){
        ui -> Sort_button -> setEnabled(true);
        ui -> Create_new_columns_button -> setEnabled(true);
        ui -> Array_size_line -> setReadOnly(false);
    }
    else{
        ui -> Sort_button -> setEnabled(false);
        ui -> Create_new_columns_button -> setEnabled(false);
        ui -> Array_size_line -> setReadOnly(true);
    }
}

void MainWindow::on_Create_new_columns_button_clicked()
{
    Array_input(current_array_length);
    scene -> clear();
    Array_to_scene(current_array_length);

    is_sorted = false;
    ui -> Time_label -> setText("0");

    ui -> Bin_search_button -> setEnabled(false);
    ui -> Bin_search_number_input_line -> setText("");
    ui -> Index_output_line -> setText("");
}

void MainWindow::on_Bin_search_number_input_line_textChanged(const QString &text1)
{

    ui -> Index_output_line -> setText("");

    if(text1 == "0"){
        ui -> Bin_search_number_input_line -> setText("1");
    }

    QString text = ui -> Bin_search_number_input_line -> text();

    if(text != ""){
        if(is_sorted){

            ui -> Bin_search_button -> setEnabled(true);
        }

        else{
            QMessageBox* box = new QMessageBox();
            box -> setText("Отсортируйте массив");
            ui -> Bin_search_number_input_line -> setText("");

            box -> exec();
        }
    }

    else{
        ui -> Bin_search_button -> setEnabled(false);
    }

}

void MainWindow::on_Bin_search_button_clicked()
{
    if(index != -1){
        Set_rectangle(index, current_array[index], QColor(255, 255, 255));
    }

    int digit = ui -> Bin_search_number_input_line -> text().toInt();
    index = binarySearch(current_array, digit, 0, current_array_length - 1);

    if(index != -1){
        Set_rectangle(index, current_array[index], QColor(18, 224, 138));
        ui -> Index_output_line -> setText(QString::number(index));
    }
    else{
        ui -> Index_output_line -> setText(QString::number(index));
        QMessageBox* box = new QMessageBox();
        box -> setText("Такого элемента нет");
        box -> exec();
    }
}

int MainWindow::binarySearch(int* &array, int digit, int left, int right){

    if(left > right){
        return -1;
    }

    int mid = (right+ left) / 2;

    Set_rectangle(mid, current_array[mid], QColor(228, 190, 42));
    Set_rectangle(left, current_array[left], QColor(255, 10, 10));
    Set_rectangle(right, current_array[right], QColor(255, 10, 10));

    QTime pause_time = QTime::currentTime().addMSecs(240);

    while (QTime::currentTime() < pause_time) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 240);
    }

    Set_rectangle(mid, current_array[mid], QColor(255, 255, 255));
    Set_rectangle(left, current_array[left], QColor(255, 255, 255));
    Set_rectangle(right, current_array[right], QColor(255, 255, 255));

    if(array[mid] == digit){
        return mid;
    }

    else if(array[mid] < digit){
        return binarySearch(array, digit, mid + 1, right);
    }
    else{
        return binarySearch(array, digit, left, mid - 1);
    }
}
