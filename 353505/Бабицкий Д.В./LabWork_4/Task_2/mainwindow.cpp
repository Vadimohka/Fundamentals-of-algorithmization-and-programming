#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(980, 600);
    setFixedSize(980, 600);
    scene->setSceneRect(0, 0, 900, 300);
    ui->graphicsView->setScene(scene);
    uptimer = new QTimer;
    QObject::connect(uptimer, &QTimer::timeout, [=](){
        update();
        buttonsSetup();
    });
    uptimer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uptimer;
}

void MainWindow::fillVectorWithRandom(QVector<long long> &vec, int count)
{
    isSorted = false;
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
    if (ind_of_last_paint != -1) vec_of_item[ind_of_last_paint]->setBrush(QBrush(Qt::white));
    if (isSearched) vec_of_item[ind]->setBrush(QBrush(Qt::green));
    else vec_of_item[ind]->setBrush(QBrush(Qt::red));
    ind_of_last_paint = ind;
}

void MainWindow::buttonsSetup()
{
    if (vec_of_item.size() == 0) {
        ui->bnt_search->setEnabled(false);
        ui->bnt_search->setStyleSheet("background-color: red;");
        ui->bnt_sort->setEnabled(false);
        ui->bnt_sort->setStyleSheet("background-color: red;");
    }
    else if (sortIsActive) {
        ui->bnt_search->setEnabled(false);
        ui->bnt_search->setStyleSheet("background-color: red;");
        ui->bnt_sort->setEnabled(false);
        ui->bnt_sort->setStyleSheet("background-color: red;");
        ui->bnt_random_filling->setEnabled(false);
        ui->bnt_random_filling->setStyleSheet("background-color: red;");
    }
    else {
        ui->bnt_search->setEnabled(true);
        ui->bnt_search->setStyleSheet("background-color: white;");
        ui->bnt_sort->setEnabled(true);
        ui->bnt_sort->setStyleSheet("background-color: white;");
        ui->bnt_random_filling->setEnabled(true);
        ui->bnt_random_filling->setStyleSheet("background-color: white;");
    }
    if (!isSorted) {
        ui->bnt_search->setEnabled(false);
        ui->bnt_search->setStyleSheet("background-color: red;");
    }
    else {
        ui->bnt_search->setEnabled(true);
        ui->bnt_search->setStyleSheet("background-color: white;");
    }
}

void MainWindow::on_bnt_random_filling_clicked()
{
    int count = ui->spb_kolvo_elementov->value();
    fillVectorWithRandom(start_vector, count);
    createRectArray(start_vector);
}


void MainWindow::on_bnt_sort_clicked()
{
    short temp = ui->comboBox->currentIndex();
    if (start_vector.isEmpty()) QMessageBox::information(this, tr("Информация"), tr("Массив уже остсортирован или сортируется, введите другой!"));
    else if (temp == 0) {
        sortIsActive = true;
        heap_sort *hs = new heap_sort();
        sort_result = hs->get_result(start_vector);
        copy_start_vector = start_vector;
        qint64 time = hs->get_time_of_sort();
        const QString message = "Время сортировки составило: " + QString::number(time) + " сантимиллисекунд!!!";
        start_vector.clear();
        copy_start_vector = sort_result[sort_result.size() - 1];
        createRectArray(sort_result[0]);
        int i = 1;
        QTimer *timer = new QTimer(this);
        QObject::connect(timer, &QTimer::timeout, [=]() mutable {
            if (i == sort_result.size()) {
                timer->stop();
                sortIsActive = false;
                isSorted = true;
                QMessageBox::information(this, tr("Информация"), tr(message.toStdString().c_str()));
                delete timer;
            } else {
                createRectArray(sort_result[i]);
                ++i;
            }
        });
        timer->start(200);
    }
    else if (temp == 1) {
        sortIsActive = true;
        quick_sort *qs = new quick_sort();
        sort_result = qs->get_result(start_vector);
        copy_start_vector = start_vector;
        qint64 time = qs->get_time_of_sort();
        const QString message = "Время сортировки составило: " + QString::number(time) + " сантимиллисекунд!!!";
        start_vector.clear();
        copy_start_vector = sort_result[sort_result.size() - 1];
        createRectArray(sort_result[0]);
        int i = 1;
        QTimer *timer = new QTimer(this);
        QObject::connect(timer, &QTimer::timeout, [=]() mutable {
            if (i == sort_result.size()) {
                timer->stop();
                sortIsActive = false;
                isSorted = true;
                QMessageBox::information(this, tr("Информация"), tr(message.toStdString().c_str()));
                delete timer;
            }
            else {
                createRectArray(sort_result[i]);
                ++i;
            }
        });
        timer->start(200);
    }
    else if (temp == 2) {
        sortIsActive = true;
        merge_sort *ms = new merge_sort();
        sort_result = ms->get_result(start_vector);
        copy_start_vector = start_vector;
        qint64 time = ms->get_time_of_sort();
        const QString message = "Время сортировки составило: " + QString::number(time) + " сантимиллисекунд!!!";
        start_vector.clear();
        copy_start_vector = sort_result[sort_result.size() - 1];
        createRectArray(sort_result[0]);
        int i = 1;
        QTimer *timer = new QTimer(this);
        QObject::connect(timer, &QTimer::timeout, [=]() mutable {
            if (i == sort_result.size()) {
                timer->stop();
                sortIsActive = false;
                isSorted = true;
                QMessageBox::information(this, tr("Информация"), tr(message.toStdString().c_str()));
                delete timer;
            }
            else {
                createRectArray(sort_result[i]);
                ++i;
            }
        });
        timer->start(200);
    }
    else {
        sortIsActive = true;
        interpolation_sort *is = new interpolation_sort();
        sort_result = is->get_result(start_vector);
        copy_start_vector = start_vector;
        qint64 time = is->get_time_of_sort();
        const QString message = "Время сортировки составило: " + QString::number(time) + " сантимиллисекунд!!!";
        start_vector.clear();
        copy_start_vector = sort_result[sort_result.size() - 1];
        createRectArray(sort_result[0]);
        int i = 1;
        QTimer *timer = new QTimer(this);
        QObject::connect(timer, &QTimer::timeout, [=]() mutable {
            if (i == sort_result.size()) {
                timer->stop();
                sortIsActive = false;
                isSorted = true;
                QMessageBox::information(this, tr("Информация"), tr(message.toStdString().c_str()));
                delete timer;
            }
            else {
                createRectArray(sort_result[i]);
                ++i;
            }
        });
        timer->start(200);
    }
}


void MainWindow::on_bnt_search_clicked()
{
    binary_search *bs = new binary_search();
    binary_power *bp = new binary_power();
    long long target = ui->spb_target->value();
    search_result = bs->get_result(copy_start_vector, target);
    createRectArray(copy_start_vector);
    int i = 0;
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, [=]() mutable {
        if (i == search_result.size() - 1) {
            if (copy_start_vector[search_result[search_result.size() - 1]] == target) {
                paintSearchTarget(search_result[i], 1);
                QString message = "<html><head></head><body>";
                message += "Элемент успешно найден<br>";
                long long index = search_result[search_result.size() - 1] + 1;
                message += "Его индекс в массиве: " + QString::number(index) + "<br>";
                message += "Реузультат выражения посчитанный при помощи binpow: " + QString::number(bp->get_result(index, copy_start_vector.size(), target));
                message += "</body></html>";
                QMessageBox::information(this, tr("Информация"), tr(message.toStdString().c_str()));
            }
            else {
                paintSearchTarget(search_result[i], 0);
                QMessageBox::information(this, tr("Информация"), tr("Такой элемент не найден!!!"));
            }
            timer->stop();
            delete timer;
        }
        else {
            paintSearchTarget(search_result[i], 0);
            ++i;
        }
    });
    timer->start(200);
}
