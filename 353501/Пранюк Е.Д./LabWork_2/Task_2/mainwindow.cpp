#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->hide();
    re = QRegularExpression("(\\w+)\\s+(\\w+)\\s+(\\w+)\\s+(\\d+)\\s+(\\d+)");
    table = new Table(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    pathToFile = QFileDialog::getOpenFileName(this,tr("Open File"),"/Documents");
    if (pathToFile.isEmpty())
    {
        QMessageBox::warning(this, "Error!!!", "No one file selected.");
        WasOpen = false;
        return;
    }
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString str;
    while (!fileStream.atEnd())
    {
        str = fileStream.readLine();
        QRegularExpressionMatch match = re.match(str);
        if (!match.hasMatch())
        {
            QMessageBox::warning(this, "Error", "Error to read information from file / Wrong Format of Book info");
            qDebug() << str;
            WasOpen = false;
            file.close();
            return;
        }
    }
    file.close();
    putDataFromFileToTable();
}

void MainWindow::putDataFromFileToTable()
{
    if (pathToFile.isEmpty())
    {
        return;
    }
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QRegularExpressionMatch match;
    QString s;
    do {
        s = fileStream.readLine();
        if (!s.isEmpty())
        {
            match = re.match(s);
            if (match.hasMatch())
            {
                QString author = match.captured(1);
                QString title = match.captured(2);
                QString publisher = match.captured(3);
                int year = match.captured(4).toInt();
                int number = match.captured(5).toInt();
                Book *b = new Book(author,title,year,publisher,number);
                books.push_back(b);
            }
        }
    } while (!fileStream.atEnd());
    WasOpen = true;
    ui->tableWidget->show();
    table->setTableInfo(books);
    file.close();
}

void MainWindow::on_btnSelectFile_clicked()
{
    openFile();
    qDebug() << pathToFile;
}

void MainWindow::on_line_author_returnPressed()
{
    author = ui->line_author->text();
    WasAuthor = true;
}

void MainWindow::on_lineEdit_title_returnPressed()
{
    title = ui->lineEdit_title->text();
    WasTitle = true;
}

void MainWindow::on_lineEdit_publisher_returnPressed()
{
    publisher = ui->lineEdit_publisher->text();
    WasPubl = true;
}

void MainWindow::on_lineEdit_year_returnPressed()
{
    bool Ok;
    year = ui->lineEdit_year->text().toInt(&Ok);
    if(!Ok)
    {
        QMessageBox::warning(this, "Error", "Error to to convert text to Year format.");
        WasYear = false;
        return;
    }
    WasYear = true;
}

void MainWindow::on_lineEdit_pages_returnPressed()
{
    bool Ok;
    pages = ui->lineEdit_pages->text().toInt(&Ok);
    if(!Ok)
    {
        QMessageBox::warning(this, "Error", "Error to to convert text to Pages format.");
        WasPages = false;
        return;
    }
    WasPages = true;
}

void MainWindow::on_btn_AddBook_clicked()
{
    if(WasOpen && WasAuthor && WasPages && WasPubl && WasTitle && WasYear)
    {
        table->addRow(&file,new Book(author,title,year,publisher,pages));
        ui->lineEdit_year->clear();
        ui->line_author->clear();
        ui->lineEdit_pages->clear();
        ui->lineEdit_publisher->clear();
        ui->lineEdit_title->clear();
        WasAuthor  = 0;
        WasPages = 0;
        WasPubl = 0;
        WasTitle = 0;
        WasYear = 0;
    }
    else
    {
        QMessageBox::warning(this, "Error", "Error to create book without enough info.");
        return;
    }
}

void MainWindow::on_lineEdit_NumToEdit_returnPressed()
{
    bool Ok = true;
    n = ui->lineEdit_NumToEdit->text().toInt(&Ok);
    if(!Ok)
    {
        QMessageBox::warning(this, "Error", "Error to to convert text to int format.");
        return;
    }
}

void MainWindow::on_lineEdit_EditedRow_returnPressed()
{
    QString str = ui->lineEdit_EditedRow->text();
    QRegularExpressionMatch match = re.match(str);
    if (!match.hasMatch())
    {
        QMessageBox::warning(this, "Error", "Error to read information.");
        return;
    }
    QString author = match.captured(1);
    QString title = match.captured(2);
    QString publisher = match.captured(3);
    int year = match.captured(4).toInt();
    int number = match.captured(5).toInt();
    Book *b = new Book(author,title,year,publisher,number);

    table->setRow(b,n-1);
    books[n-1] = b;
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream fileStream(&file);
    fileStream.seek(0);
    for (int var = 0; var < ui->tableWidget->rowCount(); ++var)
    {
        fileStream << books.at(var)->toString();
    }
    file.close();
    ui->lineEdit_EditedRow->clear();
    ui->lineEdit_NumToEdit->clear();
}

void MainWindow::on_btn_SortYear_clicked()
{
    if(WasOpen)
        table->SortByYear();
}

void MainWindow::on_btn_SortPublisher_clicked()
{
    if(WasOpen)
        table->SortByPublisher();
}
void MainWindow::on_lineInput_returnPressed()
{
    int status = 0;
    if(ui->btn_delete->isChecked())
    {
        status = 1;
    }
    if(ui->btn_find->isChecked())
    {
        status = 2;
    }
    bool Ok = true;
    int num = 0;
    switch (status)
    {
    case 0:
        ui->lbl_info->setText("you did not choose the state!");
        break;

    case 1:
        num = ui->lineInput->text().toInt(&Ok);
        if(!Ok)
        {
            QMessageBox::warning(this, "Error", "Error to to convert text to Pages format.");
            return;
        }
        table->DelRow(&file,num);
        break;
    case 2:
        table->ShowNecessary(ui->lineInput->text());
        break;
    default:
        break;
    }
}


void MainWindow::on_btn_delete_clicked(bool checked)
{
    if(checked)
    {
        ui->lbl_info->setText("Enter row number to delete");
        ui->btn_find->setChecked(false);
    }
}


void MainWindow::on_btn_find_clicked(bool checked)
{
    if(checked)
    {
        ui->lbl_info->setText("Enter keyword to find in the title!");
        ui->btn_delete->setChecked(false);
    }
}


