#include "triangle.h"

Triangle::Triangle() {
    selectVertexButton = new QPushButton("Переместить вершину");
    selectVertexButton->setGeometry(500, 0, 400, 25);
    selectVertexButton->setParent(this);
    selectVertexWidget = new QWidget;
    selectVertexLayout = new QGridLayout(selectVertexWidget);
    VertexNumber = new QLineEdit();
    newX = new QLineEdit();
    newY = new QLineEdit();
    confirmNewCoord = new QPushButton("Подтвердить");
    selectVertexLayout->addWidget(new QLabel("Номер вершины (от 1 до 3):"), 0, 0);
    selectVertexLayout->addWidget(VertexNumber, 0, 1);
    selectVertexLayout->addWidget(new QLabel("Новая абсцисса (от 0 до 1820):"), 1, 0);
    selectVertexLayout->addWidget(newX, 1, 1);
    selectVertexLayout->addWidget(new QLabel("Новая ордината (от 0 до 900):"), 2, 0);
    selectVertexLayout->addWidget(newY, 2, 1);
    selectVertexLayout->addWidget(confirmNewCoord);
    wronginput = new ClickableLabel;
    QIntValidator* newMassCenterXval = new QIntValidator(0, this->size().width(), this);
    QIntValidator* newMassCenterYval = new QIntValidator(0, this->size().height(), this);
    newX->setValidator(newMassCenterXval);
    newY->setValidator(newMassCenterYval);
    QIntValidator* vertNumVAl = new QIntValidator(1, 3, this);
    VertexNumber->setValidator(vertNumVAl);
    selectVertexWidget->setWindowTitle("Перемещение вершины");

    connect(selectVertexButton, &QPushButton::clicked, this, &Triangle::on_selectVertexButton_clicked);
    connect(confirmNewCoord, &QPushButton::clicked, this, &Triangle::on_confirmNewCoord_clicked);

    amountOfVertexes = 3;
    vertexes = new QPointF[amountOfVertexes];
    vertexes[0] = QPointF(250, 250);
    vertexes[1] = QPointF(250, 400);
    vertexes[2] = QPointF(600, 325);
    this->PrintInfo();

    selectVertexButton->setStyleSheet("QPushButton {"
                                      "  background-color: #008631;"
                                      "  color: #83F28F;"
                                      "}"
                                      "QPushButton:disabled {"
                                      "  background-color: #CCCCCC;"
                                      "  color: #666666;"
                                      "}");

    QTimer* buttonsTimer = new QTimer(this);

    connect(buttonsTimer, &QTimer::timeout, [=]{
        selectVertexButton->setDisabled(isRotating || isScaling);
    });
    buttonsTimer->start(100);
}

Triangle::~Triangle()
{
    delete selectVertexButton;
    delete selectVertexWidget;
    delete wronginput;
}

void Triangle::draw(QPainter &painter)
{
    painter.setBrush(QColor(252, 15, 192));
    painter.setPen(Qt::black);
    painter.drawPolygon(vertexes, amountOfVertexes);
    painter.setBrush(Qt::black);
    painter.drawText(vertexes[0], "1");
    painter.drawText(vertexes[1], "2");
    painter.drawText(vertexes[2], "3");

}

void Triangle::hideWindows()
{
    selectVertexWidget->hide();
}

void Triangle::on_selectVertexButton_clicked()
{
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
    selectVertexWidget->hide();
    selectVertexWidget->show();
}

void Triangle::on_confirmNewCoord_clicked()
{
    bool inputAreNumbers = true;
    int vertexnum = VertexNumber->text().toInt(&inputAreNumbers),
        newx = newX->text().toInt(&inputAreNumbers),
        newy = newY->text().toInt(&inputAreNumbers);
    if (!inputAreNumbers){
        wronginput->hide();
        wronginput->setText("Введите только числа");
        wronginput->show();
        return;
    }
    if (vertexnum > 3 || vertexnum < 1) {
        wronginput->hide();
        wronginput->setText("Номер вершины - 1, 2, 3");
        wronginput->show();
        return;
    }
    if (newx > 960 || newx < 0 || newy < 0 || newy > 540){
        wronginput->hide();
        wronginput->setText("Новые координаты должны быть в окне");
        wronginput->show();
        return;
    }
    VertexNumber->setText("");
    newX->setText("");
    newY->setText("");
    vertexes[vertexnum - 1] = QPointF(newx, newy);
    selectVertexWidget->hide();
}
