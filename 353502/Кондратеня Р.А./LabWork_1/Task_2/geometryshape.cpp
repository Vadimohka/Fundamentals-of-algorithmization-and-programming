#include "geometryshape.h"

GeometryShape::GeometryShape(QWidget *parent)
    : QWidget{parent}
{
    isMoveble = false;
    perimetr = 0;
    area = 1;
    actualRotation = 0;
    actualScale = 1;

    showMassCenterChange = new QPushButton("Изменить координаты центра масс", this);
    showMassCenterChange->setGeometry(550, 25, 600, 25);
    windowMassCenterChange = new QWidget;
    changemasscenterlayout = new QGridLayout(windowMassCenterChange);
    windowMassCenterChange->setMinimumSize(300, 100);
    newMassCenterX = new QLineEdit();
    newMassCenterY = new QLineEdit();
    confirmMassCenterChange = new QPushButton("Подтвердить");
    changemasscenterlayout->addWidget(newMassCenterX, 0, 1);
    changemasscenterlayout->addWidget(new QLabel("Новая абсцисса центра масс (от 0 до 1820):"), 0, 0);
    changemasscenterlayout->addWidget(newMassCenterY, 1, 1);
    changemasscenterlayout->addWidget(new QLabel("Новая ордината центра масс (от 0 до 900):"), 1, 0);
    changemasscenterlayout->addWidget(confirmMassCenterChange);
    connect(showMassCenterChange, &QPushButton::clicked, this, &GeometryShape::on_showMassCenterChange_clicked);
    connect(confirmMassCenterChange, &QPushButton::clicked, this, &GeometryShape::on_confirmMassCenterChange_clicked);
    wronginput = new ClickableLabel();
    QIntValidator* newMassCenterXval = new QIntValidator(0, this->size().width(), this);
    QIntValidator* newMassCenterYval = new QIntValidator(0, this->size().height(), this);
    newMassCenterX->setValidator(newMassCenterXval);
    newMassCenterY->setValidator(newMassCenterYval);
    windowMassCenterChange->setWindowTitle("Смещение");

    SetRotation = new QPushButton("Анимировать поворот");
    SetScale = new QPushButton("Анимировать изменение размера");
    connect(SetRotation, SIGNAL(clicked()), this, SLOT(on_SetRotation_clicked()));
    connect(SetScale, SIGNAL(clicked()), this, SLOT(on_SetScale_clicked()));
    EnableMoving = new QCheckBox("Разрешить движение при зажатой клавише мыши");
    connect(EnableMoving, SIGNAL(stateChanged(int)), this, SLOT(on_EnableMoving_Clicked()));
    Info = new QLabel(this);
    Info->setText("Периметр фигуры: " + QString::number(perimetr) +
                  "\nПлощадь фигуры: " + QString::number(area) +
                  "\nАбсцисса центра масс: " + QString::number(massCenter.rx()) +
                  "\nОрдината центра масс: " + QString::number(massCenter.ry()));
    SetRotation->setGeometry(0, 0, 550, 25);
    SetScale->setGeometry(0, 25, 550, 25);
    EnableMoving->setGeometry(0, 50, 750, 25);
    Info->setGeometry(0,65, 500, 150);
    Info->setParent(this);
    SetRotation->setParent(this);
    SetScale->setParent(this);
    EnableMoving->setParent(this);


    RotateSettings = new QWidget;
    WrongInputRotation = new ClickableLabel(RotateSettings);
    WrongInputRotation->setText("Неверный ввод, введите только целые числа");
    RotateSettings->setFixedSize(1000, 400);
    SetRotationLayout = new QGridLayout(RotateSettings);
    ConfirmRotationSettings = new QPushButton("Подтвердить");
    connect(ConfirmRotationSettings, SIGNAL(clicked()), this, SLOT(on_ConfirmRotationSettings_clicked()));
    RotationDuration = new QLineEdit();
    RotationAngle = new QLineEdit();
    SetRotationLayout->addWidget(new QLabel("Время вращения, секунды (до 100):"), 0, 0);
    SetRotationLayout->addWidget(RotationDuration, 0, 1);
    SetRotationLayout->addWidget(new QLabel("Угол вращения, градусы (от -99999 до 99999):"), 1, 0);
    SetRotationLayout->addWidget(RotationAngle, 1, 1);
    SetRotationLayout->addWidget(ConfirmRotationSettings);
    QIntValidator* timeValidator = new QIntValidator(1, 99, this);
    RotationDuration->setValidator(timeValidator);
    QIntValidator* angleValidator = new QIntValidator(-36000, 36000, this);
    RotationAngle->setValidator(angleValidator);

    ScaleSettings = new QWidget;
    WrongInputScale = new QMessageBox(ScaleSettings);
    WrongInputScale->setText("Неверный ввод, введите только целые числа");
    ScaleSettings->setFixedSize(1200, 500);
    SetScaleLayout = new QGridLayout(ScaleSettings);
    ConfirmScaleSettings = new QPushButton("Подтвердить");
    connect(ConfirmScaleSettings, SIGNAL(clicked()), this, SLOT(on_ConfirmScaleSettings_clicked()));
    ScaleDuration = new QLineEdit();
    ScaleFactor = new QLineEdit();
    SetScaleLayout->addWidget(ScaleDuration, 0, 1);
    SetScaleLayout->addWidget(new QLabel("Продолжительность увеличения, секунды (до 100):"), 0, 0);
    SetScaleLayout->addWidget(ScaleFactor, 1, 1);
    SetScaleLayout->addWidget(new QLabel("Множитель (с минусом, если необходимо уменьшить, целое число от -5 до 5):"), 1, 0);
    SetScaleLayout->addWidget(ConfirmScaleSettings);
    this->setFixedSize(2500, 1300);
    ScaleDuration->setValidator(timeValidator);
    QIntValidator* scaleValidator = new QIntValidator(-5, 5, this);
    ScaleFactor->setValidator(scaleValidator);
    RotateSettings->setWindowTitle("Вращение");
    ScaleSettings->setWindowTitle("Растяжение");

    updateTimer = new QTimer;
    updateTimer->start(20);
    connect(updateTimer, &QTimer::timeout, [=] {
        update();
    });

    isRotating = false;
    isScaling = false;

    SetScale->setStyleSheet("QPushButton {"
                              "  background-color: #008631;"
                              "  color: #83F28F;"
                              "}"
                              "QPushButton:disabled {"
                              "  background-color: #CCCCCC;"
                              "  color: #666666;"
                              "}");

    SetRotation->setStyleSheet("QPushButton {"
                               "  background-color: #008631;"
                               "  color: #83F28F;"
                               "}"
                               "QPushButton:disabled {"
                               "  background-color: #CCCCCC;"
                               "  color: #666666;"
                               "}");

    showMassCenterChange->setStyleSheet("QPushButton {"
                                        "  background-color: #008631;"
                                        "  color: #83F28F;"
                                        "}"
                                        "QPushButton:disabled {"
                                        "  background-color: #CCCCCC;"
                                        "  color: #666666;"
                                        "}");

    QTimer* buttonsTimer = new QTimer(this);

    connect(buttonsTimer, &QTimer::timeout, [=]{
        SetRotation->setDisabled(isRotating);
        SetScale->setDisabled(isScaling);
        showMassCenterChange->setDisabled(isRotating || isScaling);
    });
    buttonsTimer->start(100);
}

GeometryShape::~GeometryShape()
{
    updateTimer->stop();

    delete windowMassCenterChange;
    delete showMassCenterChange;
    delete wronginput;

    delete SetRotationLayout;
    delete SetRotation;
    delete RotateSettings;
    delete WrongInputRotation;

    delete SetScaleLayout;
    delete SetScale;
    delete ScaleSettings;

    delete EnableMoving;
    delete Info;

    delete updateTimer;
}

void GeometryShape::draw(QPainter &) {}

void GeometryShape::deltaRotation(qreal) {

}

void GeometryShape::deltaScale(qreal scale, qreal deltascale) {
    qreal areascalefactor = ((scale + deltascale)/scale) * ((scale + deltascale)/scale);
    area *= areascalefactor;
}

void GeometryShape::deltaShift(QPointF shift) {
    massCenter.rx() += shift.rx();
    massCenter.ry() += shift.ry();
}

void GeometryShape::animateRotation(qreal angle, qreal duration) {
    isRotating = true;
    QTimer* animTimer = new QTimer;
    QTimer* endTimer = new QTimer;
    qreal deltaAngle = angle / (duration / 20);
    connect(animTimer, &QTimer::timeout, [=] {
        deltaRotation(deltaAngle);
        actualRotation += deltaAngle;
    });
    connect(endTimer, &QTimer::timeout, [=]{
        deltaRotation(angle - actualRotation);
        actualRotation = 0;
        animTimer->stop();
        endTimer->stop();
        delete animTimer;
        delete endTimer;
        isRotating = false;
    });
    animTimer->start(20);
    endTimer->start(duration - 20);
}

void GeometryShape::animateScaleChange(qreal scalefactor, qreal duration) {
    isScaling = true;
    QTimer* animTimer = new QTimer;
    QTimer* endTimer = new QTimer;
    qreal deltascale = (scalefactor - 1) / (duration / 20);
    connect(animTimer, &QTimer::timeout, [=] {
        deltaScale(actualScale, deltascale);
        actualScale += deltascale;
    });
    connect(endTimer, &QTimer::timeout, [=]{
        deltaScale(actualScale, scalefactor - actualScale);
        actualScale = 1;
        animTimer->stop();
        endTimer->stop();
        delete animTimer;
        delete endTimer;
        isScaling = false;
    });
    animTimer->start(20);
    endTimer->start(duration - 20);
}

void GeometryShape::mouseMoveEvent(QMouseEvent *me)
{
    if (!isMoveble) return;
    deltaShift(me->pos() - mouseOldPos);
    mouseOldPos = me->pos();
}

void GeometryShape::mousePressEvent(QMouseEvent *me)
{
    mouseOldPos = me->pos();
    if (isMoveble) setCursor(Qt::ClosedHandCursor);
}

void GeometryShape::mouseReleaseEvent(QMouseEvent *)
{
    unsetCursor();
}

void GeometryShape::updateArea(){}

void GeometryShape::updatePerimetr() {}

void GeometryShape::updateMassCenter() {}

void GeometryShape::PrintInfo()
{
    updateArea();
    updatePerimetr();
    updateMassCenter();
    Info->setText("Периметр фигуры: " + QString::number(perimetr) +
                  "\nПлощадь фигуры: " + QString::number(area) +
                  "\nАбсцисса центра масс: " + QString::number(massCenter.rx()) +
                  "\nОрдината центра масс: " + QString::number(massCenter.ry()));
}

void GeometryShape::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    draw(painter);
    PrintInfo();
}

void GeometryShape::hideWindows()
{

}

void GeometryShape::closeAllWindows()
{
    hideWindows();
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
}

void GeometryShape::on_SetRotation_clicked()
{
    hideWindows();
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
    RotateSettings->show();
}

void GeometryShape::on_ConfirmRotationSettings_clicked()
{
    if (isRotating) {
        WrongInputRotation->hide();
        WrongInputRotation->setText("Объект уже вращается!");
        WrongInputRotation->show();
        return;
    }
    bool inputAreNumbers = true;
    int animDuration = RotationDuration->text().toInt(&inputAreNumbers),
        animAngle = RotationAngle->text().toInt(&inputAreNumbers);
    if (inputAreNumbers && animDuration >= 0 && animDuration < 100) {
        RotateSettings->hide();
        RotationDuration->setText("");
        RotationAngle->setText("");
        animateRotation(1.0 * animAngle * PI / 180, animDuration * 1000);
    }
    else {
        WrongInputRotation->hide();
        WrongInputRotation->setText("Неверный ввод, введите только целые числа");
        WrongInputRotation->show();
    }
}

void GeometryShape::on_SetScale_clicked()
{
    hideWindows();
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
    ScaleSettings->show();
}

void GeometryShape::on_ConfirmScaleSettings_clicked()
{
    if (isScaling) {
        WrongInputRotation->hide();
        WrongInputRotation->setText("Объект уже меняет размер!");
        WrongInputRotation->show();
        return;
    }
    bool inputAreNumbers = true;
    int animDuration = ScaleDuration->text().toInt(&inputAreNumbers),
        animScale = ScaleFactor->text().toInt(&inputAreNumbers);
    if (inputAreNumbers && animDuration > 0 && animDuration < 50 && animScale >= -5 && animScale <= 5 && animScale != 0) {
        ScaleSettings->hide();
        ScaleDuration->setText("");
        ScaleFactor->setText("");
        if (animScale > 0) {
            animateScaleChange(animScale, animDuration * 1000);
        }
        else {
            animateScaleChange(-1.0 / animScale, animDuration * 1000);
        }
    }
    else {
        WrongInputScale->hide();
        WrongInputScale->setText("Нельзя увеличить в ноль раз!");
        WrongInputScale->show();
    }
}

void GeometryShape::on_EnableMoving_Clicked()
{
    isMoveble = !isMoveble;
}

void GeometryShape::on_showMassCenterChange_clicked()
{
    hideWindows();
    ScaleSettings->hide();
    windowMassCenterChange->hide();
    RotateSettings->hide();
    windowMassCenterChange->show();
}

void GeometryShape::on_confirmMassCenterChange_clicked()
{
    bool inputAreNumbers;
    int newx = newMassCenterX->text().toInt(&inputAreNumbers),
        newy = newMassCenterY->text().toInt(&inputAreNumbers);
    if (!inputAreNumbers) {
        wronginput->hide();
        wronginput->setText("Введите только целые числа");
        wronginput->show();
        return;
    }
    if (newx > 960 || newx < 0 || newy < 0 || newy > 540) {
        wronginput->hide();
        wronginput->setText("Новые координаты за пределами экрана");
        wronginput->show();
        return;
    }
    deltaShift(QPointF(newx, newy) - massCenter);
    windowMassCenterChange->hide();
    newMassCenterX->setText("");
    newMassCenterY->setText("");
}
