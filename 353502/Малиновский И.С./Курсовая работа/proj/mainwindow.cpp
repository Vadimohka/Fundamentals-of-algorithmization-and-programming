#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800, 656);
    searchLine = new SearchLine();
    pictureLabel = new ClickableLabel();

    layout = new QVBoxLayout();

    QPixmap pixmap("/home/ilyamzy/proj/courseWork/Pictures/Belarus.png");
    pictureLabel->setPixmap(pixmap);
    pictureLabel->setScaledContents(true);
    pictureLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    randomButton = new QPushButton("Посмотреть рандомный населённый пункт", this);
    connect(randomButton, &QPushButton::clicked, this, &MainWindow::showRandomCity);
    randomButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    randomButton->setFixedHeight(50);

    layout->addWidget(searchLine);
    layout->addWidget(pictureLabel);
    layout->addWidget(randomButton);
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(pictureLabel, &ClickableLabel::clicked, [&](const QPoint& pos) {
        qDebug() << "Clicked at: " << pos;
    });

    buttons.setWindowSize(QSize(782, 531));
    buttons.createButtonsAndWidgets("/home/ilyamzy/proj/courseWork/Resources/positions.txt", pictureLabel);

    infoWidgets = buttons.getWidgets();
    searchLine->setInfoWidgets(infoWidgets);
    canResize = 0;
    randInd = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    canResize++;
    QMainWindow::resizeEvent(event);
    if (canResize < 2) { return; }
    buttons.handleResizeEvent(pictureLabel->size());
}

void MainWindow::showRandomCity()
{
    while (true)
    {
        int num = getRandom();
        if (!hashMap.contains(num) || randInd - hashMap[num] > RAND_DIAPOSON)
        {
            buttons.showInfoWidget(num);
            hashMap.insert(num, randInd++);
            break;
        }
    }
}

int MainWindow::getRandom()
{
    int number = QRandomGenerator::global()->bounded(2, 10);
    QVector<int> randNums(number);
    for (int i=0; i<number; i++) randNums[i] = QRandomGenerator::global()->bounded(1, 203) - 1;
    int randInd = randNums[QRandomGenerator::global()->bounded(1, number) - 1];
    return randInd;
}
