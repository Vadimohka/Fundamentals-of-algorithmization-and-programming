#include "regularpolygon.h"

RegularPolygon::RegularPolygon() {}

RegularPolygon::RegularPolygon(int initamountofvertexes)
{
    showVertexAmountChange = new QPushButton("Изменить число вершин", this);
    showVertexAmountChange->setGeometry(550, 0, 300, 25);
    changeWidget = new QWidget();
    changingLayout = new QGridLayout(changeWidget);
    entervertexesAmount = new QLineEdit();
    confirmNewAmount = new QPushButton("Подтвердить");
    changingLayout->addWidget(new QLabel("Число вершин (от 3 до 100)"), 0, 0);
    changingLayout->addWidget(entervertexesAmount, 0, 1);
    changingLayout->addWidget(confirmNewAmount);
    QIntValidator* amVerVal = new QIntValidator(3, 99, this);
    entervertexesAmount->setValidator(amVerVal);
    changeWidget->setWindowTitle("Изменение числа вершин");

    connect(showVertexAmountChange, &QPushButton::clicked, this, &RegularPolygon::on_showVertexAmountChange_clicked);
    connect(confirmNewAmount, &QPushButton::clicked, this, &RegularPolygon::on_confirmNewAmount_clicked);

    amountOfVertexes = initamountofvertexes;
    vertexes = new QPointF[amountOfVertexes];
    qreal angle = 2 * PI / amountOfVertexes;
    for (int i = 0; i < amountOfVertexes; ++i) {
        vertexes[i] = QPointF(480, 270) + QPointF(100 * qCos(i * angle), 100 * qSin(i * angle));
    }

    showVertexAmountChange->setStyleSheet("QPushButton {"
                                  "  background-color: #008631;"
                                  "  color: #83F28F;"
                                  "}"
                                  "QPushButton:disabled {"
                                  "  background-color: #CCCCCC;"
                                  "  color: #666666;"
                                  "}");

    QTimer* buttonsTimer = new QTimer(this);

    connect(buttonsTimer, &QTimer::timeout, [=]{
        showVertexAmountChange->setDisabled(isRotating || isScaling);
    });
    buttonsTimer->start(100);

    wronginput = new QMessageBox(this);
}

RegularPolygon::~RegularPolygon()
{
    delete changeWidget;
}

void RegularPolygon::hideWindows()
{
    changeWidget->hide();
}

void RegularPolygon::on_showVertexAmountChange_clicked()
{
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
    changeWidget->hide();
    changeWidget->show();
}

void RegularPolygon::on_confirmNewAmount_clicked()
{
    bool inputAreNumbers = true;
    int newVertamount = entervertexesAmount->text().toInt(&inputAreNumbers);
    if (!inputAreNumbers || newVertamount > 100 || newVertamount <= 2) {
        wronginput->setText("Введите натуральное число от 3 до 100");
        wronginput->show();
        return;
    }
    delete[] vertexes;
    amountOfVertexes = newVertamount;
    vertexes = new QPointF[amountOfVertexes];
    qreal angle = 2 * PI / amountOfVertexes;
    for (int i = 0; i < amountOfVertexes; ++i) {
        vertexes[i] = QPointF(480, 270) + QPointF(100 * qCos(i * angle), 100 * qSin(i * angle));
    }
    entervertexesAmount->clear();
    changeWidget->hide();
}
