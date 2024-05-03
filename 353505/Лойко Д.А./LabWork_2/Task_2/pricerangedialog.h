#ifndef PRICERANGEDIALOG_H
#define PRICERANGEDIALOG_H
#include<QtWidgets>

class PriceRangeDialog:public QDialog
{
    Q_OBJECT
public:
    PriceRangeDialog(QWidget *parent = nullptr):QDialog(parent){
        setWindowTitle("Поиск по ценовому диапазону");
        setFixedSize(300, 150);

        QLabel* minPriceLabel = new QLabel("Минимальная цена:");
        QLineEdit* minPriceLineEdit = new QLineEdit;

        QLabel* maxPriceLabel = new QLabel("Максимальная цена:");
        QLineEdit* maxPriceLineEdit = new QLineEdit;

        QPushButton* searchButton = new QPushButton("Поиск");

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(minPriceLabel);
        layout->addWidget(minPriceLineEdit);
        layout->addWidget(maxPriceLabel);
        layout->addWidget(maxPriceLineEdit);
        layout->addWidget(searchButton);

        setLayout(layout);

        connect(searchButton, &QPushButton::clicked, this, &PriceRangeDialog::searchComponents);
    }
signals:
    void searchComponents(); // Сигнатура слота изменена на не требующую аргументов
private slots:
    void search();
};

#endif // PRICERANGEDIALOG_H
