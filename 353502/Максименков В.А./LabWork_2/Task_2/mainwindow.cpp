#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->priceChoiseSpinBox->setMinimum(0);
    ui->priceChoiseSpinBox->setMaximum(0);

    ui->orderChoiseSpinBox->setMinimum(0);
    ui->orderChoiseSpinBox->setMaximum(0);

    ui->textBrowser->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->costLabel->hide();
    ui->numberLabel->hide();
    ui->formingTable->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPriceList()
{
    ui->priceTable->show();
    QString ans;
    QTableWidgetItem* item;
    QVector<int> code = priceList.getCode();
    QVector<double> price = priceList.getPrice();
    QVector<QString> name = priceList.getName();

    ui->priceTable->setRowCount(priceList.getNumber());

    for (int i = 0; i < priceList.getNumber(); ++i)
    {
        ans = "0";
        ans += QString::number(code[i]);
        item = new QTableWidgetItem(ans);
        ui->priceTable->setItem(i, 0, item);
    }

    for (int i = 0; i < priceList.getNumber(); ++i)
    {
        ans = QString::number(price[i]);
        item = new QTableWidgetItem(ans);
        ui->priceTable->setItem(i, 1, item);
    }

    for (int i = 0; i < priceList.getNumber(); ++i)
    {
        ans = QString(name[i]);
        item = new QTableWidgetItem(ans);
        ui->priceTable->setItem(i, 2, item);
    }
}

void MainWindow::showOrderList()
{
    ui->orderTable->show();
    QTableWidgetItem* item;
    QString ans, ans1;
    QVector<QDate> dates = listOfOrders.getDate();
    QVector<QString> name = listOfOrders.getName();
    QVector<GoodsInOrders> goods = listOfOrders.getGoods();

    ui->orderTable->setRowCount(listOfOrders.getNumber());

    for (int i = 0; i < listOfOrders.getNumber(); ++i)
    {
        ans = QString::number(i+1);
        item = new QTableWidgetItem(ans);
        ui->orderTable->setItem(i, 0, item);
    }

    for (int i = 0; i < listOfOrders.getNumber(); ++i)
    {
        ans = dates[i].toString(Qt::RFC2822Date);
        item = new QTableWidgetItem(ans);
        ui->orderTable->setItem(i, 3, item);
    }

    for (int i = 0; i < listOfOrders.getNumber(); ++i)
    {
        ans = name[i];
        item = new QTableWidgetItem(ans);
        ui->orderTable->setItem(i, 4, item);
    }

    for (int i = 0; i < listOfOrders.getNumber(); ++i)
    {
        ans = "";
        ans1 = "";
        QMap<int, int> m = goods[i].getM();
        QMap<int, int>::iterator ii;
        for (ii = m.begin(); ii != m.end(); ++ii)
        {
            if (ii.value() != 0)
            {
                ans += "0";
                ans += QString::number(ii.key());
                ans1 += QString::number(ii.value());
                ans += '/';
                ans1 += '/';
            }
        }
        if (ans == "")
        {
            item = new QTableWidgetItem(ans);
            ui->orderTable->setItem(i, 1, item);
            item = new QTableWidgetItem(ans1);
            ui->orderTable->setItem(i, 2, item);
            continue;
        }
        ans.remove(ans.size()-1, 1);
        ans1.remove(ans1.size()-1, 1);
        item = new QTableWidgetItem(ans);
        ui->orderTable->setItem(i, 1, item);
        item = new QTableWidgetItem(ans1);
        ui->orderTable->setItem(i, 2, item);
    }
}

void MainWindow::showForm()
{
    ui->formingTable->setRowCount(0);

    ui->textBrowser->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->costLabel->show();
    ui->numberLabel->show();
    ui->formingTable->show();

    int row = ui->orderChoiseSpinBox->value();
    double sum = 0.0;

    QMap<int, int> m = listOfOrders.getGoods()[row-1].getM();
    QMap<int, int>::iterator ii;
    QString code, quantity, price;
    QTableWidgetItem* item, *item1;
    int cnt = 0;
    for (ii = m.begin(); ii != m.end(); ++ii)
    {
        if (ii.value() != 0)
        {
            int nowCode = ii.key();
            int nowQuantity = ii.value();
            double nowPrice = 0.0;
            QVector<int> codeVector = priceList.getCode();
            QVector<double> priceVector = priceList.getPrice();
            for (int i = 0; i < codeVector.size(); ++i)
            {
                if (codeVector[i] == nowCode) nowPrice = priceVector[i];
            }
            sum += nowPrice*nowQuantity;
            price = QString::number(nowPrice*nowQuantity);
            item = new QTableWidgetItem(price);
            ui->formingTable->insertRow(cnt);
            ui->formingTable->setItem(cnt, 2, item);

            code = "0";
            code += QString::number(ii.key());
            quantity = QString::number(ii.value());
            item = new QTableWidgetItem(code);
            item1 = new QTableWidgetItem(quantity);
            ui->formingTable->setItem(cnt, 0, item);
            ui->formingTable->setItem(cnt, 1, item1);
            ++cnt;
        }
    }
    ui->costLabel->setText(QString::number(sum));
    ui->numberLabel->setText(QString::number(row));
}


void MainWindow::on_showPriceButton_clicked()
{
    showPriceList();
}


void MainWindow::on_addingPriceButton_clicked()
{
    ui->priceChoiseSpinBox->setMaximum(ui->priceChoiseSpinBox->maximum() + 1);
    int code = ui->priceCodespinBox->value();
    double price = ui->priceDoubleSpinBox->value();
    QString name = ui->priceNameEdit->toPlainText();
    priceList.add(code, price, name);
    showPriceList();
}


void MainWindow::on_priceHideButton_clicked()
{
    ui->priceTable->hide();
}


void MainWindow::on_priceCorrectButton_clicked()
{
    if (ui->priceChoiseSpinBox->value() == 0) return;
    int row = ui->priceChoiseSpinBox->value();
    int code = ui->priceCodespinBox->value();
    double price = ui->priceDoubleSpinBox->value();
    QString name = ui->priceNameEdit->toPlainText();
    priceList.correct(row, code, price, name);
    showPriceList();
}


void MainWindow::on_priceDeleteButton_clicked()
{
    if (ui->priceChoiseSpinBox->value() == 0) return;
    priceList.del(ui->priceChoiseSpinBox->value());
    showPriceList();
    ui->priceChoiseSpinBox->setMaximum(ui->priceChoiseSpinBox->maximum() - 1);
}


void MainWindow::on_showOrderButton_clicked()
{
    showOrderList();
}


void MainWindow::on_addingOrderButton_clicked()
{
    ui->orderChoiseSpinBox->setMaximum(ui->orderChoiseSpinBox->maximum() + 1);
    QDate date = ui->dateEdit->date();
    QString name = ui->orderNameEdit->toPlainText();
    GoodsInOrders goods = GoodsInOrders();
    listOfOrders.add(date, name, goods);
    showOrderList();
}


void MainWindow::on_addGoodsButton_clicked()
{
    if (ui->orderChoiseSpinBox->value() == 0) return;
    int row = ui->orderChoiseSpinBox->value();
    int code = ui->codeSpinBox->value();
    int quantity = ui->quantitySpinBox->value();
    listOfOrders.goods[row-1].add(code, quantity);
    showOrderList();
}


void MainWindow::on_formingButton_clicked()
{
    if (ui->orderChoiseSpinBox->value() == 0) return;
    showForm();
}


void MainWindow::on_orderHideButton_clicked()
{
    ui->orderTable->hide();
}


void MainWindow::on_priceFileAddingButton_clicked()
{
    QFile file("/home/vlad/QTprojects/Lab_2__Task_2/price_list.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << "Файл для чтения открыт!";
    else qDebug() << "Не удалось открыть файл для чтения!!!";

    QString temp, ans;
    int code;
    double price;
    QString name;
    int cnt = 0;
    int kol = 0;

    while (!file.atEnd())
    {
        ans = "";
        cnt = 1;
        temp = file.readLine();
        for (int i = cnt; i < temp.size(); ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
            ans += temp[i];
        }
        code = ans.toInt();
        ans = "";
        for (int i = cnt; i < temp.size(); ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
            ans += temp[i];
        }
        price = ans.toDouble();
        ans = "";
        for (int i = cnt; i < temp.size()-1; ++i)
        {
            ans += temp[i];
        }
        name = ans;
        priceList.add(code, price, name);
        ++kol;
    }
    file.close();
    qDebug() << "Данные успешно считаны!";

    ui->priceChoiseSpinBox->setMaximum(ui->priceChoiseSpinBox->maximum() + kol);
    showPriceList();
}


void MainWindow::on_orderFileAddingButton_clicked()
{
    QFile file1("/home/vlad/QTprojects/Lab_2__Task_2/orders.txt");
    QFile file2("/home/vlad/QTprojects/Lab_2__Task_2/list_of_goods.txt");

    if (file1.open(QIODevice::ReadOnly | QIODevice::Text) && file2.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << "Файл для чтения открыт!";
    else qDebug() << "Не удалось открыть файл для чтения!!!";

    QString temp, ans, ans1;
    QDate date;
    QString name;
    GoodsInOrders goods = GoodsInOrders();
    int code;
    int quantity;
    int kol = 0;

    int cnt;
    while (!file1.atEnd())
    {
        ++kol;
        ans = "";
        cnt = 0;
        temp = file1.readLine();
        for (int i = cnt; i < temp.size(); ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
        }
        for (int i = cnt; i < temp.size(); ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
            ans += temp[i];
        }
        int year, month, day;
        QString now, now1;
        int counter = 0;
        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i] == '.' ||  i == ans.size()-1)
            {
                if (i == ans.size()-1) now += ans[i];
                if (counter == 0) day = now.toInt();
                if (counter == 1) month = now.toInt();
                if (counter == 2) year = now.toInt();
                ++counter;
                now = "";
            }
            else now += ans[i];
        }
        date = QDate(year, month, day);
        ans = "";
        for (int i = cnt; i < temp.size()-1; ++i)
        {
            ans += temp[i];
        }
        name = ans;


        temp = file2.readLine();
        ans = "";
        cnt = 0;
        for (int i = cnt; i < temp.size(); ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
        }
        for (int i = cnt; i < temp.size(); ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
            ans += temp[i];
        }
        ans1 = "";
        for (int i = cnt; i < temp.size()-1; ++i)
        {
            if (temp[i] == ' ')
            {
                cnt = i+1;
                break;
            }
            ans1 += temp[i];
        }
        now = "";
        now1 = "";
        cnt = 1;
        counter = 0;
        //qDebug() << ans << "      " << ans1;
        for (int i = cnt; i < ans.size(); ++i)
        {
            if (ans[i] == "/" || i == ans.size()-1)
            {
                if (i == ans.size()-1) now += ans[i];
                for (int j = counter; j < ans1.size(); ++j)
                {
                    if (ans1[j] == '/' || j == ans1.size()-1)
                    {
                        if (j == ans1.size()-1) now1 += ans1[j];

                        code = now.toInt();
                        quantity = now1.toInt();
                        goods.add(code, quantity);
                        //qDebug() << now << " " << now1;

                        counter = j+1;

                        now1 = "";
                        break;
                    }
                    else now1 += ans1[j];
                }
                ++i;
                //qDebug() << "Here" << i;
                now = "";
            }
            else now += ans[i];
        }

        listOfOrders.add(date, name, goods);
        goods = GoodsInOrders();
    }

    file1.close();
    file2.close();
    qDebug() << "Данные успешно считаны!";

    ui->orderChoiseSpinBox->setMaximum(ui->orderChoiseSpinBox->maximum() + kol);
    showOrderList();
}


void MainWindow::on_orderCorrectButton_clicked()
{
    if (ui->orderChoiseSpinBox->value() == 0) return;
    int row = ui->orderChoiseSpinBox->value();
    QDate date = ui->dateEdit->date();
    QString name = ui->orderNameEdit->toPlainText();
    listOfOrders.correct(row, date, name);
    showOrderList();
}


void MainWindow::on_orderDeleteButton_clicked()
{
    if (ui->orderChoiseSpinBox->value() == 0) return;
    int row = ui->orderChoiseSpinBox->value();
    listOfOrders.del(row);
    showOrderList();
    ui->orderChoiseSpinBox->setMaximum(ui->orderChoiseSpinBox->maximum()-1);
}


void MainWindow::on_priceFileWritingButton_clicked()
{
    QVector<int> code = priceList.getCode();
    QVector<double> price = priceList.getPrice();
    QVector<QString> name = priceList.getName();
    int number = priceList.getNumber();

    QString ans = "";

    QFile file("/home/vlad/QTprojects/Lab_2__Task_2/out_price.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) qDebug() << "Файл для записи успешно открыт!";
    else qDebug() << "Не удалось открыть файл для записи!!!";

    QTextStream fout(&file);
    for (int i = 0; i < number; ++i)
    {
        ans.push_back('0');
        ans += QString::number(code[i]);
        ans.push_back(' ');
        ans += QString::number(price[i]);
        ans.push_back(' ');
        ans += name[i];
        fout << ans << '\n';
        ans = "";
    }
    file.close();
    qDebug() << "Данные успешно записаны!";
}


void MainWindow::on_orderFileWriteButton_clicked()
{
    QVector<QDate> date = listOfOrders.getDate();
    QVector<QString> name = listOfOrders.getName();
    int number = listOfOrders.getNumber();
    QVector<GoodsInOrders> goods = listOfOrders.getGoods();

    QString ans = "", temp1 = "", temp2 = "";
    QFile file1("/home/vlad/QTprojects/Lab_2__Task_2/out_orders.txt");
    QFile file2("/home/vlad/QTprojects/Lab_2__Task_2/out_list_of_goods.txt");
    if (file1.open(QIODevice::WriteOnly | QIODevice::Text) && file2.open(QIODevice::WriteOnly | QIODevice::Text)) qDebug() << "Файл для записи успешно открыт!";
    else qDebug() << "Не удалось открыть файл для записи!!!";
    QTextStream f1out(&file1);
    QTextStream f2out(&file2);

    for (int i = 0; i < number; ++i)
    {
        ans += QString::number(i+1);
        ans.push_back(' ');
        ans += QString::number(date[i].day());
        ans.push_back('.');
        ans += QString::number(date[i].month());
        ans.push_back('.');
        ans += QString::number(date[i].year());
        ans.push_back(' ');
        ans += name[i];
        f1out << ans << '\n';
        ans = "";

        temp1 = "0";
        ans += QString::number(i+1);
        ans.push_back(' ');
        QMap<int, int> m = goods[i].getM();
        QMap<int, int>::iterator ii;
        for (ii = m.begin(); ii != m.end(); ++ii)
        {
            if (ii.value() != 0)
            {
                temp1 += QString::number(ii.key());
                temp1 += "/0";

                temp2 += QString::number(ii.value());
                temp2.push_back('/');
            }
        }

        temp1.remove(temp1.size()-2, 2);
        temp2.remove(temp2.size()-1, 1);

        ans += temp1;
        ans.push_back(' ');
        ans += temp2;
        f2out << ans << '\n';
        ans = "";
        temp1 = "";
        temp2 = "";
    }

    file1.close();
    file2.close();
    qDebug() << "Данные успешно записаны!";
}


void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0) priceList.codeSort();
    if (index == 1) priceList.priceSort();
    showPriceList();
}





