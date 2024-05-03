#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listView = new QListView();
    model = new QStringListModel(this);

    current = false;
    open = false;
    // QStringList l;
    // l << "Процессор" << "Видеокарта" << "Оперативная память" << "Материнская плата" << "Жесткий диск(HDD)" << "Твердотелый накопитель(SSD)" << "Блок питания" << "Корпус";
    // model->setStringList(l);


    // ui->listView->setModel(model);
    // ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model2 = new QStandardItemModel(this);
    ui->tableView->setModel(model2);

    model2->setColumnCount(5);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->model()->setHeaderData(0, Qt::Horizontal, "Фирма");
    ui->tableView->horizontalHeader()->model()->setHeaderData(1, Qt::Horizontal, "Модель");
    ui->tableView->horizontalHeader()->model()->setHeaderData(2, Qt::Horizontal, "Парамметры");
    ui->tableView->horizontalHeader()->model()->setHeaderData(3, Qt::Horizontal, "Цена");
    ui->tableView->horizontalHeader()->model()->setHeaderData(4, Qt::Horizontal, "Наличие");

    ui->tableView->hide();

    connect(ui->comboBoxFirm, SIGNAL(activated(int)), this, SLOT(updateComboBoxFirm()));
    connect(ui->comboBoxModel, SIGNAL(activated(int)), this, SLOT(updateComboBoxModel()));
    connect(ui->comboBoxPrice, SIGNAL(activated(int)), this, SLOT(updateComboBoxPrice()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    pathFile = QFileDialog::getOpenFileName(0, "Открыть файл","/home/skibidi-dop", "*txt");
    //ui->label->setText(pathFile);
    openfile();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(open)
    {
        //QModelIndex index = ui->listView->currentIndex();
        //QString text = index.data(Qt::DisplayRole).toString();


        currentComponentsInArray();
    }
}

void MainWindow::openfile()
{
    information = "";
    QFile file(pathFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Не удалось открыть файл для чтения, сосите");
        return;
    }
    QTextStream in(&file);

    while(!in.atEnd())
    {
        information += in.readLine();
        information += '\n';
    }
    file.close();
    makeBase();
}

void MainWindow::makeBase()
{
    model->removeRows(0, model->rowCount());

    QString temp = "";
    QString text = "";
    int schet = 0;
    kolvo = 0;
    int schetProbel = 5;
    bool param = false;
    for(int i = 0; i < information.length(); i++)
    {
        if(information[i] == ' ' && (information[i + 1] == ' ' || information[i + 1] == '\n'))
        {
            continue;
        }

        if(information[i] == ':')
        {
            param = true;

        }
        else if(information[i] == ';')
        {
            param = false;

        }
        if(!param && information[i] == ' ')
        {
            schet++;
        }

        if(information[i] == '\n')
        {
            if(schet == schetProbel)
            {
                kolvo++;
                schet = 0;
                text += temp;
                temp = "";
            }
        }

        temp += information[i];
    }

    temp = "";
    schet = 1;
    int j = 0;

    text += '\n';

    components = new component *[kolvo];
    for(int i = 0; i < kolvo; i++)
    {
        components[i] = new component();
    }

    for(int i = 0; i < text.length(); i++)
    {
        if(i != 0 && text[i] == ' ' && text[i - 1] == ';')
        {
            schet++;
            param = false;
            continue;
        }
        if(text[i] == ':')
        {
            param = true;
            temp = "";
            continue;
        }
        else if(text[i] == ';')
        {

            components[j]->getParametrs(temp);
            temp = "";
            continue;
        }
        if(param)
        {
            temp += text[i];
            continue;
        }
        if(text[i] == ' ' && schet == 1 && j < kolvo)
        {
            components[j]->getType(temp);
            schet++;
            temp = "";
            continue;
        }
        else if(text[i] == ' ' && schet == 2 && j < kolvo)
        {
            components[j]->getFirm(temp);
            schet++;
            temp = "";
            continue;
        }
        else if(text[i] == ' ' && schet == 3 && j < kolvo)
        {
            components[j]->getCompModel(temp);
            schet++;
            temp = "";
            continue;
        }
        else if(text[i] == ' ' && schet == 5 && j < kolvo)
        {
            temp.chop(1);
            int x = temp.toInt();
            components[j]->getPrice(x);
            schet++;
            temp = "";
            continue;
        }
        else if(text[i] == '\n' && j < kolvo)
        {
            if(temp == "есть")
            {
                components[j]->getAvailability(true);
            }
            else
            {
                components[j]->getAvailability(false);
            }
            j++;
            schet = 1;
            temp = "";
            continue;
        }
        temp += text[i];

    }

    QStringList l;
    bool stat;
    for(int i = 0; i < kolvo; i++)
    {
        stat = true;

        for(int m = 0; m < i; m++)
        {
            if(components[i]->retType() == components[m]->retType())
            {
                stat = false;
                break;
            }
        }

        if(stat)
        {
            l << components[i]->retType();
        }

    }
    model->setStringList(l);


    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    open = true;
}

void MainWindow::currentComponentsInArray()
{
    ui->comboBoxFirm->clear();
    ui->comboBoxModel->clear();
    ui->comboBoxPrice->clear();
    ui->text->clear();
    ui->yOrN->clear();

    skolko = 0;
    QModelIndex index = ui->listView->currentIndex();

    for(int i = 0; i < kolvo; i++)
    {
        if(components[i]->retType() == index.data(Qt::DisplayRole).toString())
        {
            skolko++;
        }
    }

    currentComponent = new component *[skolko];
    for(int i = 0; i < skolko; i++)
    {
        currentComponent[i] = new component();
    }

    int j = 0;

    for(int i = 0; i < kolvo; i++)
    {
        if(components[i]->retType() == index.data(Qt::DisplayRole).toString() && j < skolko)
        {
            currentComponent[j] = components[i];
            //ui->comboBoxFirm->addItem(currentComponent[j]->retFirm());
            j++;
        }
    }

    bool stat;

    for(int i = 0; i < skolko; i++)
    {
        stat = true;
        for(int m = 0; m < i; m++)
        {
            if(currentComponent[i]->retFirm() == currentComponent[m]->retFirm())
            {
                stat = false;
                break;
            }
        }
        if(stat)
        {
            ui->comboBoxFirm->addItem(currentComponent[i]->retFirm());
        }
    }

    current = true;
    updateComboBoxFirm();
}

void MainWindow::updateComboBoxFirm()
{
    ui->comboBoxModel->clear();
    bool stat;

    for(int i = 0; i < skolko; i++)
    {
        stat = true;
        if(currentComponent[i]->retFirm() == ui->comboBoxFirm->currentText())
        {
            for(int j = 0; j < ui->comboBoxModel->count(); j++)
            {
                if(currentComponent[i]->retCompModel() == ui->comboBoxModel->itemText(j))
                {
                    stat = false;
                    break;
                }
            }
        }
        else
        {
            continue;
        }
        if(stat)
        {
            ui->comboBoxModel->addItem(currentComponent[i]->retCompModel());
        }
    }
    updateComboBoxModel();
}

void MainWindow::updateComboBoxModel()
{
    ui->comboBoxPrice->clear();

    for(int i = 0; i < skolko; i++)
    {

        if(currentComponent[i]->retFirm() == ui->comboBoxFirm->currentText() && currentComponent[i]->retCompModel() == ui->comboBoxModel->currentText())
        {
            int n = currentComponent[i]->retPrice();
            QString text = QString::number(n) +'$';
            ui->comboBoxPrice->addItem(text);
        }
    }
    updateComboBoxPrice();
}

void MainWindow::updateComboBoxPrice()
{
    for(int i = 0; i < skolko; i++)
    {
        QString price = QString::number(currentComponent[i]->retPrice()) + '$';
        if(currentComponent[i]->retFirm() == ui->comboBoxFirm->currentText() && currentComponent[i]->retCompModel() == ui->comboBoxModel->currentText() && price == ui->comboBoxPrice->currentText())
        {
            ui->text->setText(currentComponent[i]->retParametrs());
            if(currentComponent[i]->retAvailability())
            {
                ui->yOrN->setText("есть");
            }
            else
            {
                ui->yOrN->setText("нету");
            }
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(current)
    {
        component *temp;
        for(int i = 0; i < skolko; i++)
        {
            int min = currentComponent[i]->retPrice();
            int min_pos = i;
            for(int j = i + 1; j < skolko; j++)
            {
                if(currentComponent[j]->retPrice() < min)
                {
                    min = currentComponent[j]->retPrice();
                    min_pos = j;
                }
            }
            if(min != currentComponent[i]->retPrice())
            {
                temp = currentComponent[i];
                currentComponent[i] = currentComponent[min_pos];
                currentComponent[min_pos] = temp;
            }
        }

        ui->listView->hide();
        ui->tableView->show();

        ui->tableView->clearSpans();

        model2->setRowCount(skolko);




        for(int i = 0; i < skolko; i++)
        {
            model2->setData(model2->index(i, 0), currentComponent[i]->retFirm());
            model2->setData(model2->index(i, 1), currentComponent[i]->retCompModel());
            model2->setData(model2->index(i, 2), currentComponent[i]->retParametrs());

            QString text = QString::number(currentComponent[i]->retPrice()) + '$';
            model2->setData(model2->index(i, 3), text);

            if(currentComponent[i]->retAvailability())
            {
                model2->setData(model2->index(i, 4), "есть");
            }
            else
            {
                model2->setData(model2->index(i, 4), "нету");
            }
        }

        updateComboBoxFirm();
    }

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->hide();
    ui->listView->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    if(open)
    {
        DialogSearch *dialog = new DialogSearch(this);
        dialog->setComponents(components, kolvo);
        connect(dialog, &DialogSearch::sendData, this, &MainWindow::receiveData);
        dialog->exec();
    }
}

void MainWindow::receiveData(const QString &searchType, const QString &searchFirm, const QString &searchModel)
{
    ui->comboBoxFirm->clear();
    ui->comboBoxModel->clear();
    ui->comboBoxPrice->clear();
    ui->text->clear();
    ui->yOrN->clear();
    ui->tableView->hide();
    ui->listView->show();

    skolko = 0;

    for(int i = 0; i < kolvo; i++)
    {
        if(components[i]->retType() == searchType && components[i]->retFirm() == searchFirm && components[i]->retCompModel() == searchModel)
        {
            skolko++;
        }
    }

    currentComponent = new component *[skolko];
    for(int i = 0; i < skolko; i++)
    {
        currentComponent[i] = new component();
    }

    int j = 0;

    for(int i = 0; i < kolvo; i++)
    {
        if(components[i]->retType() == searchType && components[i]->retFirm() == searchFirm && components[i]->retCompModel() == searchModel && j < skolko)
        {
            currentComponent[j] = components[i];
            j++;
        }
    }

    ui->comboBoxFirm->addItem(searchFirm);
    ui->comboBoxModel->addItem(searchModel);

    current = true;
    updateComboBoxModel();
}

void MainWindow::createSets(int minPrice, int maxPrice) {
    ui->listView->hide();
    ui->tableView->show();
    ui->tableView->clearMask();
    model2->setRowCount(0);

    component** currentSet = new component*[8];
    int currentSetSize = 0;
    std::unordered_set<QString> currentTypes;
    int maxSize = 0;
    int setNumber = 1;

    createSetsRec(0, 0, minPrice, maxPrice, currentSet, currentSetSize, currentTypes, maxSize, setNumber);

    delete[] currentSet;

}

void MainWindow::createSetsRec(int i, int currentPrice, int minPrice, int maxPrice, component** &currentSet, int &currentSetSize, std::unordered_set<QString> &currentTypes, int &maxSize, int &setNumber) {
    if (i >= kolvo) return;

    if (currentTypes.find(components[i]->retType()) == currentTypes.end() && currentSetSize < 8) {
        currentSet[currentSetSize++] = components[i];
        currentTypes.insert(components[i]->retType());
        currentPrice += components[i]->retPrice();

        if (currentSetSize > maxSize) {
            maxSize = currentSetSize;
        }

        if (currentPrice >= minPrice && currentPrice <= maxPrice && currentSetSize > 1 && currentSetSize == maxSize) {
            QList<QStandardItem *> items;
            items.append(new QStandardItem(QString("Комплект %1").arg(setNumber++)));
            model2->appendRow(items);
            ui->tableView->setSpan(model2->rowCount()-1, 0, 1, 5);

            for (int j = 0; j < currentSetSize; ++j) {
                QList<QStandardItem *> items;
                items.append(new QStandardItem(currentSet[j]->retFirm()));
                items.append(new QStandardItem(currentSet[j]->retCompModel()));
                items.append(new QStandardItem(currentSet[j]->retParametrs()));
                items.append(new QStandardItem(QString::number(currentSet[j]->retPrice()) + '$'));
                if(currentSet[j]->retAvailability())
                {
                    items.append(new QStandardItem("есть"));
                }
                else
                {
                    items.append(new QStandardItem("нету"));
                }

                model2->appendRow(items);
            }
        }

        createSetsRec(i + 1, currentPrice, minPrice, maxPrice, currentSet, currentSetSize, currentTypes, maxSize, setNumber);

        --currentSetSize;
        currentTypes.erase(components[i]->retType());
        currentPrice -= components[i]->retPrice();
    }

    createSetsRec(i + 1, currentPrice, minPrice, maxPrice, currentSet, currentSetSize, currentTypes, maxSize, setNumber);
}

void MainWindow::on_pushButton_6_clicked()
{
    if(open)
    {
        bool ok;
        int minPrice = QInputDialog::getInt(this, tr("Введите минимальную цену"),
                                            tr("Минимальная цена:"), 0, 0, 1000000, 1, &ok);
        if (ok) {
            int maxPrice = QInputDialog::getInt(this, tr("Введите максимальную цену"),
                                                tr("Максимальная цена:"), 0, 5000, 1000000, 1, &ok);
            if (ok) {
                createSets(minPrice, maxPrice);
            }
        }
    }
}

