#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sortingAnimation = new SortingAnimation;
    ui->arrayVisualization->setAlignment(Qt::AlignBottom);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addButton_clicked()
{
    if (ui->numbersEnterEdit->text().size() == 0) return;
    bool ok = false;
    int number = ui->numbersEnterEdit->text().toInt(&ok);

    if (!ok) return;

    array.push_back(number);
    ui->numbersEnterEdit->clear();
    SortingAnimation::drawNumber(ui->arrayVisualization, number);
    sorted = false;
}


void MainWindow::on_generateButton_clicked()
{
    array.resize(0);

    QLayoutItem* child;
    while ((child = ui->arrayVisualization->takeAt(0)) != nullptr) {
        if (child->layout() != nullptr) {
            // If the child is another layout, recursively clear it
            QLayout* childLayout = child->layout();
            while (childLayout->count() != 0) {
                QLayoutItem* layoutItem = childLayout->takeAt(0);
                delete layoutItem->widget();
                delete layoutItem;
            }
        }
        delete child->widget();
        delete child;
    }

    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(1, 500); // Define the range

    for (int i = 0; i < ui->sizeArray->text().toInt(); ++i) {
        int randomNum = distr(gen);
        array.push_back(randomNum);
        SortingAnimation::drawNumber(ui->arrayVisualization, randomNum);
        QCoreApplication::processEvents();
    }

    sorted = false;
}




void MainWindow::on_sortStartHeap_clicked()
{
    HeapSorting::sort(array, ui->arrayVisualization);
    sorted = true;
}

void MainWindow::on_sortStarting_clicked()
{
    QuickSorting::sort(array, ui->arrayVisualization);
    sorted = true;
}

void MainWindow::on_sortStartmerge_clicked()
{
    MergeSorting::sort(array, ui->arrayVisualization);
    sorted = true;
}


void MainWindow::on_sortStaringinterpolation_clicked()
{
    InterpolationSorting::sort(array, ui->arrayVisualization);
    sorted = true;
}


void MainWindow::on_searching_clicked()
{
    if (!sorted || ui->searchValue->text().size() == 0) return;
    int index = BinaryAlgorithms::binSearch(&array, ui->searchValue->text().toInt(), ui->arrayVisualization);
    if (index == -1) return;
    qobject_cast<NumberVisual*>(ui->arrayVisualization->itemAt(index)->widget())->setColor(Qt::red);
    ui->binPowResult->setText(QString::number(BinaryAlgorithms::binPow(index, array.size(), 1000000000)));
}

