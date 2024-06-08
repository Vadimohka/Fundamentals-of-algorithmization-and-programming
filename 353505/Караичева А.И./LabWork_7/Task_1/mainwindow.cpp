#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Queue methods");
    ui->tabWidget->setTabText(1, "Solving the task");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    queue.push(ui->insertedElComboBox->value());
    showQueue(ui->demoMethodsList, queue);

}


void MainWindow::on_popButton_clicked()
{

    queue.pop();
    if (queue.size() == 0) ui->popButton->setDisabled(true);
    showQueue(ui->demoMethodsList, queue);

}

void MainWindow::on_frontButton_clicked()
{

    QMessageBox msgBox;
    if( queue.empty() )
    {

        msgBox.setText( "Queue is empty" );
        msgBox.exec();
        return;

    }
    msgBox.setText(QString :: number( queue.front() ));
    msgBox.exec();

}


void MainWindow::on_backButton_clicked()
{

    QMessageBox msgBox;
    if( queue.empty() )
    {

        msgBox.setText( "Queue is empty" );
        msgBox.exec();
        return;

    }
    msgBox.setText(QString :: number( queue.back() ));
    msgBox.exec();

}


void MainWindow::on_sizeButton_clicked()
{

    QMessageBox msgBox;
    if( queue.empty() )
    {

        msgBox.setText( "Queue is empty" );
        msgBox.exec();
        return;

    }
    msgBox.setText(QString :: number( queue.size() ));
    msgBox.exec();

}


void MainWindow::on_emptyButton_clicked()
{

    QMessageBox msgBox;
    if( queue.empty() )
    {

        msgBox.setText( "Queue is empty" );
        msgBox.exec();
        return;

    }
    msgBox.setText("Queue is not empty");
    msgBox.exec();

}

void MainWindow::on_fillButton_clicked()
{

    queue1.clear();
    Min = 101;

    for (int i = 0; i < 20; ++i)
    {

        queue1.push(QRandomGenerator64::global()->bounded(100));
        if( queue1.back() < Min )
            Min = queue1.back();

    }

    showQueue(ui->queue1Widget, queue1);

}

void MainWindow::on_makeMinButton_clicked()
{

    queue2.clear();
    queue3.clear();

    for(int i = 0; i < 20; ++i)
    {

        if( queue1.front() != Min )
        {

            queue2.push( queue1.front() );
            queue1.pop();

        }
        else
        {

            queue3.push( queue1.front() );
            queue1.pop();

        }

    }

    while ( !queue3.empty() )
    {

        queue1.push( queue3.front() );
        queue3.pop();

    }

    while ( !queue2.empty() )
    {

        queue1.push( queue2.front() );
        queue2.pop();

    }

    showQueue(ui->queue1Widget, queue1);

}


void MainWindow::showQueue(QListWidget* showingWidget, Queue<int>& showedQueue)
{
    showingWidget->clear();
    for (auto el : showedQueue.toVector())
        showingWidget->addItem(QString::number(el));

}
