#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSize currentSize = size();
    setFixedSize(currentSize);
    uptimer = new QTimer;
    QObject::connect(uptimer, &QTimer::timeout, [=](){
        update();
        if (start_vector.size() == 0) {
            ui->bnt_at->setEnabled(false);
            ui->bnt_at->setStyleSheet("background-color: gray;");
            ui->bnt_clear->setEnabled(false);
            ui->bnt_clear->setStyleSheet("background-color: gray;");
            ui->bnt_erase->setEnabled(false);
            ui->bnt_erase->setStyleSheet("background-color: gray;");
            ui->bnt_max_size->setEnabled(false);
            ui->bnt_max_size->setStyleSheet("background-color: gray;");
            ui->bnt_pop_back->setEnabled(false);
            ui->bnt_pop_back->setStyleSheet("background-color: gray;");
            ui->bnt_push_back->setEnabled(false);
            ui->bnt_push_back->setStyleSheet("background-color: gray;");
            ui->bnt_reserve->setEnabled(false);
            ui->bnt_reserve->setStyleSheet("background-color: gray;");
            ui->bnt_capacity->setEnabled(false);
            ui->bnt_capacity->setStyleSheet("background-color: gray;");
            ui->bnt_resize->setEnabled(false);
            ui->bnt_resize->setStyleSheet("background-color: gray;");
            ui->bnt_data->setEnabled(false);
            ui->bnt_data->setStyleSheet("background-color: gray;");
            ui->bnt_empty->setEnabled(false);
            ui->bnt_empty->setStyleSheet("background-color: gray;");
            ui->bnt_size->setEnabled(false);
            ui->bnt_size->setStyleSheet("background-color: gray;");
        }
        else {
            ui->bnt_at->setEnabled(true);
            ui->bnt_at->setStyleSheet("background-color: white;");
            ui->bnt_clear->setEnabled(true);
            ui->bnt_clear->setStyleSheet("background-color: white;");
            ui->bnt_erase->setEnabled(true);
            ui->bnt_erase->setStyleSheet("background-color: white;");
            ui->bnt_max_size->setEnabled(true);
            ui->bnt_max_size->setStyleSheet("background-color: white;");
            ui->bnt_pop_back->setEnabled(true);
            ui->bnt_pop_back->setStyleSheet("background-color: white;");
            ui->bnt_push_back->setEnabled(true);
            ui->bnt_push_back->setStyleSheet("background-color: white;");
            ui->bnt_reserve->setEnabled(true);
            ui->bnt_reserve->setStyleSheet("background-color: white;");
            ui->bnt_capacity->setEnabled(true);
            ui->bnt_capacity->setStyleSheet("background-color: white;");
            ui->bnt_resize->setEnabled(true);
            ui->bnt_resize->setStyleSheet("background-color: white;");
            ui->bnt_data->setEnabled(true);
            ui->bnt_data->setStyleSheet("background-color: white;");
            ui->bnt_empty->setEnabled(true);
            ui->bnt_empty->setStyleSheet("background-color: white;");
            ui->bnt_size->setEnabled(true);
            ui->bnt_size->setStyleSheet("background-color: white;");
        }
    });
    uptimer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillVectorWithRandom(My_vector<long long> &vec, int count)
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

void MainWindow::createLabelVector(const My_vector<long long> &data)
{
    QString vectorString = "[";
    for (size_t i = 0; i < data.size(); ++i) {
        vectorString += QString::number(data[i]);
        if (i != data.size() - 1) {
            vectorString += ", ";
        }
    }
    vectorString += "]";
    ui->lbl_vector->setText(vectorString);
}


void MainWindow::on_bnt_random_clicked()
{
    int count = ui->spb_kolvo_elements->value();
    fillVectorWithRandom(start_vector, count);
    createLabelVector(start_vector);
}

void MainWindow::on_bnt_erase_clicked()
{
    QString s = ui->spinBox->text();
    int i1 = s.toInt();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Erase", "Error");
            return;
        }
    }

    if (i1 >= 0 && i1 < start_vector.size()) {
        start_vector.erase(start_vector.cbegin() + i1);
        createLabelVector(start_vector);
        QMessageBox::information(this, "Erase", "Ok");
    } else QMessageBox::warning(this, "Erase", "Error");
}


void MainWindow::on_bnt_max_size_clicked()
{
    QMessageBox::information(this, "Max Size", QString::number(start_vector.max_size()));
}


void MainWindow::on_bnt_pop_back_clicked()
{
    if (start_vector.size() > 0)
        start_vector.pop_back();
    createLabelVector(start_vector);
}


void MainWindow::on_bnt_push_back_clicked()
{
    QString s = ui->spinBox->text();
    int i1 = s.toInt();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Erase", "Error");
            return;
        }
    }

    start_vector.push_back(i1);
    createLabelVector(start_vector);
    QMessageBox::information(this, "Push Back", tr("Элемент добавлен!"));
}


void MainWindow::on_bnt_reserve_clicked()
{
    QString s = ui->spinBox->text();
    int i1 = s.toInt();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Erase", "Error");
            return;
        }
    }

    start_vector.reserve(i1);
    QMessageBox::information(this, "Push Back", tr("Емкость увеличена!"));
    createLabelVector(start_vector);
}


void MainWindow::on_bnt_resize_clicked()
{
    QString s = ui->spinBox->text();
    int i1 = s.toInt();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "Erase", "Error");
            return;
        }
    }

    if (i1 >= 0) {
        start_vector.resize(i1);
        QMessageBox::information(this, "Resize", "Ok");
    } else QMessageBox::warning(this, "Resize", "Error");
    createLabelVector(start_vector);
}


void MainWindow::on_bnt_size_clicked()
{
    QMessageBox::information(this, "Size", QString::number(start_vector.size()));
}


void MainWindow::on_bnt_capacity_clicked()
{
    QMessageBox::information(this, "Capacity", QString::number(start_vector.capacity()));
}


void MainWindow::on_bnt_at_clicked()
{
    QString s = ui->spinBox->text();
    int i1 = s.toInt();
    if (i1 == 0) {
        if (s[0] != '0') {
            QMessageBox::warning(this, "At", "Error");
            return;
        }
    }

    if (i1 >= 0 && i1 < start_vector.size()) {
        QMessageBox::information(this, "At", QString::number(start_vector[i1]));
    } else QMessageBox::warning(this, "At", "Error");
    createLabelVector(start_vector);
}


void MainWindow::on_bnt_clear_clicked()
{
    start_vector.clear();
    createLabelVector(start_vector);
}


void MainWindow::on_bnt_data_clicked()
{
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(start_vector.data()),
                                         QT_POINTER_SIZE * 2, 16, QChar('0'));
    QMessageBox::information(this, "Data", ptrStr);
}


void MainWindow::on_bnt_empty_clicked()
{
    QMessageBox::information(this, "EmplaceBack", start_vector.empty() ? "Empty" : "Not");
}

