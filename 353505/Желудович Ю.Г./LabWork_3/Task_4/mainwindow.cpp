#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui -> graphicsView -> setScene(scene);

    val = new QIntValidator(1,15,this);
    ui -> Count_of_rings_line -> setValidator(val);

    Add_columns_to_scene();

    ui -> Output_tree -> setColumnCount(2);
    ui -> Output_tree -> setColumnWidth(0,90);
    ui -> Output_tree -> setColumnWidth(1,50);

    QStringList list;
    list << "Откуда" << "Куда";
    ui -> Output_tree -> setHeaderLabels(list);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Add_columns_to_scene(){
    QBrush brush(Qt::black);

    First_column = new QGraphicsRectItem(60,55,10,120, nullptr);
    First_column -> setBrush(brush);

    Second_column = new QGraphicsRectItem(220, 55, 10, 120, nullptr);
    Second_column -> setBrush(brush);

    Third_column = new QGraphicsRectItem(380,55,10,120, nullptr);
    Third_column -> setBrush(brush);

    scene -> addItem(Second_column);
    scene -> addItem(First_column);
    scene -> addItem(Third_column);

}

void MainWindow::Rings_add_to_list(int count){


    int size = 140;
    int height = 120;

    if(height / count < 20) {
        height /= count;
    }
    else {
        QPen pen;
        height = 20;
    }

    int d = 0;


    if(count > 1){
        d = -100 / (count - 1);
    }

    for(int i = 0; i < count; ++i){
        int red = QRandomGenerator::global() -> bounded(256);
        int blue = QRandomGenerator::global() -> bounded(256);
        int green = QRandomGenerator::global() -> bounded(256);

        QBrush brush(QColor(red, blue, green));

        Rings* ring = new Rings(65 - size / 2, 180 - height * (i + 1), size, height, nullptr);

        ring -> setBrush(brush);
        ring -> SetHaracteristics(size,height);
        list_A.insert(0,ring);

        scene -> addItem(list_A[0]);

        size += d;
    }
}

void MainWindow::on_Count_of_rings_line_textChanged(const QString &arg1)
{

    int count = 3;
    if(ui -> Count_of_rings_line -> text() != "") {

        if(ui -> Count_of_rings_line -> text().toInt() > 15){
            ui -> Count_of_rings_line -> setText(QString("15"));
        }
        else if(ui -> Count_of_rings_line -> text().toInt() == 0){
            ui -> Count_of_rings_line -> setText(QString("1"));
        }

        scene -> clear();
        list_A.clear();
        list_B.clear();
        list_C.clear();
        ui -> Output_tree -> clear();

        Add_columns_to_scene();
        ui -> Solve_button -> setEnabled(true);

        count = ui -> Count_of_rings_line -> text().toInt();
        Rings_add_to_list(count);
        hanoi(count, QString("A"), QString("C"), QString("B"));

    }
    else{
        ui -> Solve_button -> setEnabled(false);

        scene -> clear();
        Add_columns_to_scene();

        list_A.clear();
        list_B.clear();
        list_C.clear();

        ui -> Output_tree -> clear();
    }
}


void MainWindow::hanoi(int count, QString from , QString to, QString temp){


    if(count == 1){
        QTreeWidgetItem* item = new QTreeWidgetItem(ui -> Output_tree);
        item -> setText(0, from);
        item -> setText(1,to);
        ui -> Output_tree -> addTopLevelItem(item);

        return;
    }

    hanoi(count - 1, from, temp, to);

    QTreeWidgetItem* item = new QTreeWidgetItem(ui -> Output_tree);
    item -> setText(0,from);
    item -> setText(1,to);
    ui -> Output_tree -> addTopLevelItem(item);

    hanoi(count - 1, temp, to, from);
}

void MainWindow::hanoi_to_scene(int number){
    if(number == ui -> Output_tree -> topLevelItemCount()){
        return;
    }

    QTreeWidgetItem* row = ui -> Output_tree -> topLevelItem(number);
    ui -> Output_tree -> setCurrentItem(row);

    QTreeWidgetItem* item = ui -> Output_tree -> topLevelItem(number);

    QString first, second;

    first = item -> text(0);
    second = item -> text(1);
\
    Rings* delete_element;
    int x = 0, y = 0;

    int current_pos = 0;

    if(first == "A"){
        delete_element = list_A.takeAt(0);

        x = delete_element -> x;
        y = delete_element -> y;

        if(second == "B"){
            current_pos = 225 - delete_element -> size / 2;
        }

        else if(second == "C"){
            current_pos = 385 - delete_element -> size / 2;
        }

        hanoi_ring_up(delete_element, 0, "up");

        QTimer* timer = new QTimer(this);

        timer -> setInterval(3 * abs(y));
        timer -> setSingleShot(true);  //first timer

        connect(timer, &QTimer::timeout, this, [=]() mutable{

            if(second == "B"){
                hanoi_ring_right(delete_element, current_pos, "right");
            }

            else if(second == "C"){
                hanoi_ring_right(delete_element, 385 - delete_element -> size / 2, "right");
            }
        });

        timer -> start();

    }
    else if(first == "B"){
        delete_element = list_B.takeAt(0);

        x = delete_element -> x;
        y = delete_element -> y;

        if(second == "A"){
            current_pos = 65 - delete_element -> size / 2;
        }
        else if(second == "C"){
            current_pos = 385 - delete_element -> size / 2;
        }


        hanoi_ring_up(delete_element, 0, "up");

        QTimer* timer = new QTimer(this);

        timer -> setInterval(3 * abs(y));
        timer -> setSingleShot(true);  //first timer

        connect(timer, &QTimer::timeout, this, [=]() mutable{

            if(second == "A"){
                hanoi_ring_right(delete_element, current_pos, "left");
            }

            else if(second == "C"){
                hanoi_ring_right(delete_element, 385 - delete_element -> size / 2, "right");
            }
        });

        timer -> start();

    }
    else if(first == "C"){
        delete_element = list_C.takeAt(0);
        x = delete_element -> x;
        y = delete_element -> y;

        if(second == "A"){
            current_pos = 65 - delete_element -> size / 2;
        }
        if(second == "B"){
            current_pos = 225 - delete_element -> size / 2;
        }

        hanoi_ring_up(delete_element, 0, "up");

        QTimer* timer = new QTimer(this);

        timer -> setInterval(3 * abs(y));
        timer -> setSingleShot(true);  //first timer

        connect(timer, &QTimer::timeout, this, [=]() mutable{

            if(second == "B"){
                hanoi_ring_right(delete_element, current_pos, "left");
            }

            else if(second == "A"){
                hanoi_ring_right(delete_element, current_pos, "left");
            }
        });

        timer -> start();

    }


    QTimer* timer_down = new QTimer(this);

    timer_down -> setInterval(3 * abs(y) + 2 * abs(current_pos - x));
    timer_down -> setSingleShot(true);

    connect(timer_down, &QTimer::timeout, this, [=]() {

        if(second == "A"){
            list_A.insert(0,delete_element);
            hanoi_ring_up(delete_element, 180 - delete_element -> height * list_A.size(), "down");
        }
        else if(second == "B"){
            list_B.insert(0,delete_element);
            hanoi_ring_up(delete_element, 180 - delete_element -> height * list_B.size(), "down");

        }
        else if(second == "C"){
            list_C.insert(0,delete_element);
            hanoi_ring_up(delete_element, 180 - delete_element -> height * list_C.size(), "down");

        }

    });
    timer_down -> start();

    QTimer* timer_all = new QTimer(this);

    timer_all -> setInterval(3 * abs(y) + 2 * abs(current_pos - x) + 3 * abs(y));
    timer_down -> setSingleShot(true);

    connect(timer_down, &QTimer::timeout, this, [=]() {
        hanoi_to_scene(number + 1);
    });

}

void MainWindow::hanoi_ring_up(Rings* item, qreal current_pos, QString symbol){
    QTimer* timer = new QTimer(this);

    timer -> setInterval(3);

    connect(timer, &QTimer::timeout, this, [=]() mutable {

        if(symbol == "up"){
            if(item -> y > current_pos){
                item -> Move_up(-1); //up
            }
            else{

                timer -> stop();
            }
        }
        else if(symbol == "down"){
            if(item -> y < current_pos){ //down
                item -> Move_up(1);
            }
            else{

                timer -> stop();
            }
        }
    }) ;
    timer -> start();
}

void MainWindow::hanoi_ring_right(Rings* item, qreal current_pos, QString symbol){
    QTimer* timer = new QTimer(this);

    timer -> setInterval(2);

    connect(timer, &QTimer::timeout, this, [=]() mutable {

        if(symbol == "right"){
            if(item -> x < current_pos){  //right
                item -> Move_right(1);
            }
            else{
                timer -> stop();
            }
        }
        else if(symbol == "left"){
            if(item -> x > current_pos){ //left
                item -> Move_right(-1);
            }
            else{
                timer -> stop();
            }
        }
    }) ;
    timer -> start();
}
void MainWindow::on_Solve_button_clicked()
{
    ui -> Solve_button -> setEnabled(false);
    ui -> Count_of_rings_line -> setReadOnly(true);
    hanoi_to_scene(0);
}
