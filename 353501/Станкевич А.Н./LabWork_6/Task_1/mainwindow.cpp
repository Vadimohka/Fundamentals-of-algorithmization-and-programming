#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Notebook notebook1 = {2023, 1488.01, "ASUS Vivobook M1161", true};

    Notebook notebook2;
    notebook2.price = 1666.99;
    notebook2.year = 2011;

    strcpy(notebook2.model, "HP Spectre x360");
    notebook2.isAvailable = false;
    ui->label->setText(QString::number(notebook1.year) + " | " + QString::number(notebook1.price) + " | " + notebook1.model + " | " + (notebook1.isAvailable ? "Yes" : "No") + " | " + notebook1.operatingSystem + " | ");
    for (int i = 0; i < 5; i++) {
        ui->label->setText(ui->label->text() + QString::number(notebook1.performanceScores[i]) + " ");
    }

    ui->label_2->setText(QString::number(notebook2.year) + " | " + QString::number(notebook2.price) + " | " + notebook2.model + " | " + (notebook2.isAvailable ? "Yes" : "No") + " | " + notebook2.operatingSystem + " | ");
    for (int i = 0; i < 5; i++) {
        ui->label_2->setText(ui->label_2->text() + QString::number(notebook2.performanceScores[i]) + " ");
    }
    Notebook notebook4;
    Notebook* ptr = &notebook4;
    ptr->price = 1500.0;
    ptr->year = 2024;

    strcpy(ptr->model, "TUF 15");
    ptr->isAvailable = true;

    ui->label_4->setText(QString::number(ptr->year) + " | " + QString::number(ptr->price) + " | " + ptr->model + " | " + (ptr->isAvailable ? "Да" : "Нет") + " | " + ptr->operatingSystem + " | ");
    for (int i = 0; i < 5; i++) {
        ui->label_4->setText(ui->label_4->text() + QString::number(ptr->performanceScores[i]) + " ");
    }

    Notebook notebook5;
    Notebook& ref = notebook5;
    ref.price = 1211.12;
    ref.year = 2020;

    strcpy(ref.model, "ROG XM 7");
    ref.isAvailable = false;
    ui->label_5->setText(QString::number(ref.year) + " | " + QString::number(ref.price) + " | " + ref.model + " | " + (ref.isAvailable ? "Да" : "Нет") + " | " + ref.operatingSystem + " | ");
    for (int i = 0; i < 5; i++) {
        ui->label_5->setText(ui->label_5->text() + QString::number(ref.performanceScores[i]) + " ");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Notebook notebook;

    bool ok;
    notebook.year = QInputDialog::getInt(this, tr("Введите данные"),
                                         tr("Год выпуска:"), 2000, 1900, 2024, 1, &ok);
    if (ok) {
        notebook.price = QInputDialog::getDouble(this, tr("Введите данные"),
                                                 tr("Цена:"), 1000, 0, 10000, 2, &ok);
        if (ok) {
            QString model = QInputDialog::getText(this, tr("Введите данные"),
                                                  tr("Модель:"), QLineEdit::Normal,
                                                  "", &ok);
            if (ok && !model.isEmpty()) {
                strncpy(notebook.model, model.toStdString().c_str(), sizeof(notebook.model) - 1);

                bool isAvailable;
                QDialog dialog(this);
                QRadioButton *radioYes = new QRadioButton(tr("Да"));
                QRadioButton *radioNo = new QRadioButton(tr("Нет"));
                QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                           Qt::Horizontal, &dialog);
                connect(&buttonBox, &QDialogButtonBox::accepted, [&]() {
                    isAvailable = radioYes->isChecked();
                    dialog.accept();
                });
                connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(radioYes);
                layout->addWidget(radioNo);
                layout->addWidget(&buttonBox);
                dialog.setLayout(layout);
                dialog.setWindowTitle(tr("Есть в наличии?:"));

                if (dialog.exec() == QDialog::Accepted) {
                    notebook.isAvailable = isAvailable;

                    ui->label_3->setText(QString::number(notebook.year) + " | " +
                                         QString::number(notebook.price) + " | " +
                                         notebook.model + " | " +
                                         (notebook.isAvailable ? "Да" : "Нет") + " | " +
                                         notebook.operatingSystem + " | ");
                    for (int i = 0; i < 5; i++) {
                        ui->label_3->setText(ui->label_3->text() + QString::number(notebook.performanceScores[i]) + " ");
                    }
                } else {
                    QMessageBox::critical(this,"Ошибка","Ошибка, попробуйте заново");
                    return;
                }
            } else {
                QMessageBox::critical(this,"Ошибка","Ошибка, попробуйте заново");
                return;
            }
        } else {
            QMessageBox::critical(this,"Ошибка","Ошибка, попробуйте заново");
            return;
        }
    } else {
        QMessageBox::critical(this,"Ошибка","Ошибка, попробуйте заново");
        return;
    }
}
