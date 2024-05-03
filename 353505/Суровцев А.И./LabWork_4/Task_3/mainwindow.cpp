#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(970, 600);
    setFixedSize(970, 600);
    scene->setSceneRect(0, 0, 900, 300);
    ui->graphicsView->setScene(scene);
    uptimer = new QTimer;
    QObject::connect(uptimer, &QTimer::timeout, [=](){
        update();
        if (start_vector.size() == 0) {
            ui->bnt_get_new_array->setEnabled(false);
            ui->bnt_get_new_array->setStyleSheet("background-color: red;");
        }
        else if (animationIsTrue) {
            ui->bnt_random->setEnabled(false);
            ui->bnt_random->setStyleSheet("background-color: red;");
        }
        else {
            ui->bnt_get_new_array->setEnabled(true);
            ui->bnt_get_new_array->setStyleSheet("background-color: white;");
            ui->bnt_random->setEnabled(true);
            ui->bnt_random->setStyleSheet("background-color: white;");
        }
    });
    uptimer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillVectorWithRandom(QVector<long long> &vec, int count)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 200);

    vec.clear();
    vec.reserve(count);

    for (int i = 0; i < count; ++i) {
        vec.push_back(dis(gen));
    }
}

void MainWindow::createRectArray(const QVector<long long> &data)
{
    QVector<QGraphicsRectItem *> rectArray;
    scene->clear();
    vec_of_item.clear();

    qreal sceneWidth = scene->width();
    qreal sceneHeight = scene->height();

    qreal columnWidth = sceneWidth / data.size();
    qreal maxHeight = sceneHeight - 100;
    qreal startX = columnWidth / 2;
    qreal startY = sceneHeight - 50;

    for (int i = 0; i < data.size(); ++i) {
        qreal height = (qreal)data[i] / 200.0 * maxHeight;
        qreal x = startX + i * columnWidth - columnWidth / 2;
        qreal y = startY - height;

        QGraphicsRectItem *rect = scene->addRect(x, y, columnWidth, height);
        rectArray.append(rect);
    }

    vec_of_item = rectArray;
}

void MainWindow::paintSearchTarget(long long ind, bool isSearched)
{
    if (isSearched) vec_of_item[ind]->setBrush(QBrush(Qt::green));
    else vec_of_item[ind]->setBrush(QBrush(Qt::yellow));
}

void MainWindow::on_bnt_random_clicked()
{
    int count = ui->spb_count_of_elements->value();
    fillVectorWithRandom(start_vector, count);
    createRectArray(start_vector);
}


void MainWindow::on_bnt_get_new_array_clicked()
{
    MedianTriples *mt = new MedianTriples();
    QVector<long long> result = mt->get_median_triples(start_vector);
    QVector<long long> arr_of_index = mt->get_arr_of_index();
    QVector<long long> arr_of_double_index = mt->get_arr_of_double_index();
    QTimer *timer = new QTimer(this);
    int i = 0;
    animationIsTrue = true;
    QObject::connect(timer, &QTimer::timeout, [=]() mutable {
        if (i == arr_of_index.size() + 1) {
            createRectArray(result);
            animationIsTrue = false;
            QMessageBox::information(this, tr("Информация"), tr("На экране полученный медианный массив!!!"));
            timer->stop();
            delete timer;
        }
        else if (i == arr_of_index.size()) {
            if (arr_of_double_index.size() == 1) {
                paintSearchTarget(arr_of_double_index[0], 1);
                ++i;
            }
            else if (arr_of_double_index.size() == 2) {
                paintSearchTarget(arr_of_double_index[0], 0);
                paintSearchTarget(arr_of_double_index[1], 0);
                ++i;
            }
            else {
                ++i;
            }
        }
        else {
            paintSearchTarget(arr_of_index[i], 1);
            ++i;
        }
    });
    timer->start(75);
}

