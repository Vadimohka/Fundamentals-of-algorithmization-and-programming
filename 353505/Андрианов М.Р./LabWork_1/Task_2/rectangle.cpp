#include "rectangle.h"

Rectangle::Rectangle() {
    amountOfVertexes = 4;
    vertexes = new QPointF[amountOfVertexes];

    width = 200;
    height = 100;

    TopLeftCorner = QPointF(380, 220);
    vertexes[0] = TopLeftCorner;
    vertexes[1] = TopLeftCorner + QPointF(width, 0);
    vertexes[2] = TopLeftCorner + QPointF(width, height);
    vertexes[3] = TopLeftCorner + QPointF(0, height);

    this->PrintInfo();

    ChangingSizeWidget = new QWidget();
    QPushButton* changeSizeRect = new QPushButton("Изменить размеры");
    changeSizeRect->setParent(this);
    QPushButton* confirmChangingSize = new QPushButton("Подтвердить");
    changeSizeRect->setGeometry(550, 0, 300, 25);

    newHeight = new QLineEdit();
    newWidth = new QLineEdit();
    QGridLayout* changingLayout = new QGridLayout(ChangingSizeWidget);
    changingLayout->addWidget(new QLabel("Новая высота (от 0 до 900):"), 0, 0);
    changingLayout->addWidget(newHeight, 0, 1);
    changingLayout->addWidget(new QLabel("Новая ширина (от 0 до 1820):"), 1, 0);
    changingLayout->addWidget(newWidth, 1, 1);
    changingLayout->addWidget(confirmChangingSize);
    QIntValidator* newMassCenterXval = new QIntValidator(0, this->size().width(), this);
    QIntValidator* newMassCenterYval = new QIntValidator(0, this->size().height(), this);
    newWidth->setValidator(newMassCenterXval);
    newHeight->setValidator(newMassCenterYval);

    ChangingSizeWidget->setWindowTitle("Изменение сторон");

    connect(changeSizeRect, &QPushButton::clicked, this, &Rectangle::on_changeSizeRect_clicked);
    connect(confirmChangingSize, &QPushButton::clicked, this, &Rectangle::on_confirmChangingSize_clicked);

    wrongInput = new ClickableLabel();

    changeSizeRect->setStyleSheet("QPushButton {"
                               "  background-color: #008631;"
                               "  color: #83F28F;"
                               "}"
                               "QPushButton:disabled {"
                               "  background-color: #CCCCCC;"
                               "  color: #666666;"
                               "}");

    QTimer* buttonsTimer = new QTimer(this);

    connect(buttonsTimer, &QTimer::timeout, [=]{
        changeSizeRect->setDisabled(isRotating || isScaling);
    });
    buttonsTimer->start(100);
}

Rectangle::~Rectangle()
{
    delete ChangingSizeWidget;
}

void Rectangle::hideWindows()
{
    ChangingSizeWidget->hide();
}

void Rectangle::on_changeSizeRect_clicked()
{
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
    ChangingSizeWidget->hide();
    ChangingSizeWidget->show();
}

void Rectangle::on_confirmChangingSize_clicked()
{
    bool inputAreNumbers = true;
    int newWidthSize = newWidth->text().toInt(&inputAreNumbers),
        newHeightSize = newHeight->text().toInt(&inputAreNumbers);
    if (!inputAreNumbers) {
        wrongInput->hide();
        wrongInput->setText("Неверный ввод!");
        wrongInput->show();
        return;
    }
    height = newHeightSize;
    width = newWidthSize;
    vertexes[0] = TopLeftCorner;
    vertexes[1] = TopLeftCorner + QPointF(width, 0);
    vertexes[2] = TopLeftCorner + QPointF(width, height);
    vertexes[3] = TopLeftCorner + QPointF(0, height);
    newHeight->clear();
    newWidth->clear();
    PrintInfo();
    ChangingSizeWidget->hide();
}
