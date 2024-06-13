#include "paint.h"

Paint::Paint() {
    amountOfUsedPoints = 0;
    painting = new QPointF[5001];
    newPaintings = new int[2500];
    newPaintings[0] = 0;
    amountOfPaintings = 0;

    isPaintingCheckBox = new QCheckBox("Разрешить рисование");
    isPaintingCheckBox->setParent(this);
    isPaintingCheckBox->setGeometry(555, 0, 300, 25);
    connect(isPaintingCheckBox, &QCheckBox::clicked, this, &Paint::on_checkBox_clicked);

    clearButton = new QPushButton("Очистить");
    clearButton->setParent(this);
    clearButton->setGeometry(850, 25, 100, 25);
    connect(clearButton, &QPushButton::clicked, this, &Paint::on_clear_clicked);

    isPainting = false;
    enabledPainting = false;

    amountOfUsedPoints = 0;
    EnableMoving->setStyleSheet("QCheckBox:disabled { color: gray; }");
    isPaintingCheckBox->setStyleSheet("QCheckBox:disabled { color: gray; }");

    clearButton->setStyleSheet("QPushButton {"
                                      "  background-color: #008631;"
                                      "  color: #83F28F;"
                                      "}"
                                      "QPushButton:disabled {"
                                      "  background-color: #CCCCCC;"
                                      "  color: #666666;"
                                      "}");

    QTimer* buttonsTimer = new QTimer(this);

    connect(buttonsTimer, &QTimer::timeout, [=]{
        clearButton->setDisabled(isRotating || isScaling || amountOfUsedPoints == 0);
        SetRotation->setDisabled(isRotating || amountOfUsedPoints == 0);
        SetScale->setDisabled(isScaling || amountOfUsedPoints == 0);
        showMassCenterChange->setDisabled(isRotating || isScaling || amountOfUsedPoints == 0);
        EnableMoving->setDisabled(amountOfUsedPoints == 0 || enabledPainting);
        if (enabledPainting) isMoveble = false;

    });
    buttonsTimer->start(100);
}

void Paint::draw(QPainter &painter)
{
    painter.setBrush(Qt::black);
    QPen penis;
    penis.setWidth(3);
    painter.setPen(penis);
    int currNextPainting = 0, amOfPaintings = 1;

    for (int i = 0; i < amountOfUsedPoints; ++i) {
        if (i != currNextPainting) {
            painter.drawLine(painting[i], painting[i - 1]);
        }
        else {
            amOfPaintings++;
            currNextPainting = newPaintings[amOfPaintings - 1];
        }
    }
}

void Paint::mouseMoveEvent(QMouseEvent *me)
{
    if (!isPainting) {
        if (!isMoveble) return;
        deltaShift(me->pos() - mouseOldPos);
        mouseOldPos = me->pos();
        return;
    }
    if (amountOfUsedPoints < 5000 && isPainting) {
        amountOfUsedPoints++;
        painting[amountOfUsedPoints] = me->pos();
    }
}

void Paint::mousePressEvent(QMouseEvent *me)
{
    mouseOldPos = me->pos();
    if (enabledPainting && amountOfUsedPoints < 5000) {
        isPainting = true;
        amountOfUsedPoints++;
        painting[amountOfUsedPoints] = me->pos();
        amountOfPaintings++;
        newPaintings[amountOfPaintings] = amountOfUsedPoints;
    }
    if (isMoveble) setCursor(Qt::ClosedHandCursor);
}

void Paint::mouseReleaseEvent(QMouseEvent *)
{
    isPainting = false;
    unsetCursor();
}

void Paint::updateMassCenter()
{
    int amountOfPoints = 0;
    if (amountOfUsedPoints == 0) return;
    QPointF newMassCenter = QPointF(0, 0);
    for (int i = 0; i <= amountOfUsedPoints; ++i) {
        newMassCenter += painting[i];
        amountOfPoints++;
    }
    massCenter = newMassCenter / amountOfPoints;
}

void Paint::deltaRotation(qreal angle)
{
    if (amountOfUsedPoints == 0) return;
    qreal xtranslated{};
    qreal ytranslated{};
    for (int i = 0; i <= amountOfUsedPoints; ++i) {
        xtranslated = painting[i].rx() - massCenter.rx();
        ytranslated = painting[i].ry() - massCenter.ry();
        painting[i].rx() = massCenter.rx() + xtranslated * qCos(angle) - ytranslated * qSin(angle);
        painting[i].ry() = massCenter.ry() + xtranslated * qSin(angle) + ytranslated * qCos(angle);
    }
}

void Paint::deltaScale(qreal currsize, qreal deltascale)
{
    if (amountOfUsedPoints == 0) return;
    for (int i = 0; i <= amountOfUsedPoints; ++i) {
        painting[i] = massCenter + (painting[i] - massCenter) * (currsize + deltascale) / currsize;
    }
}

void Paint::deltaShift(QPointF shift)
{
    if (amountOfUsedPoints == 0) return;
    for (int i = 0; i <= amountOfUsedPoints; ++i) {
        painting[i] += shift;
    }
}

void Paint::on_checkBox_clicked()
{
    enabledPainting = !enabledPainting;
    if (isMoveble) {
        EnableMoving->animateClick();
        isMoveble = false;
    }
    EnableMoving->setEnabled(!enabledPainting);
}

void Paint::on_clear_clicked()
{
    if (isRotating || isScaling) return;
    amountOfPaintings = 0;
    amountOfUsedPoints = 0;
    PrintInfo();
}

void Paint::PrintInfo(){
    updateMassCenter();
    Info->setText("\nАбсцисса центра масс: " + QString::number(massCenter.rx()) +
                  "\nОрдината центра масс: " + QString::number(massCenter.ry()));
}
