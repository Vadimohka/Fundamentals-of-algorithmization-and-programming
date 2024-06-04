
#include "MyCard.h"
#include "Main.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QDrag>
#include <QMimeData>
#include <QPainter>
#include <QApplication>
#include <QGraphicsRotation>

// Set cardTileSize and cardSizeFactor
QSize MyCard::cardTileSize = QSize(170, 255);
float MyCard::cardSizeFactor = 0.6;

// Global streaming operator to serialzie a CardDndPayload into a data stream
QDataStream& operator<<(QDataStream& s, const CardDndPayload* payloadPtr)
{
    // Just serialize the pointer
    qulonglong ptrval(*reinterpret_cast<qulonglong*>(&payloadPtr));
    return s << ptrval;
}

// Global streaming operator to deserialize a CardDndPayload from a data stream
QDataStream& operator>>(QDataStream& s, CardDndPayload*& payloadPtr)
{
    // Deserialize the pointer value from the stream
    qulonglong ptrval;
    s >> ptrval;

    // Reinterpret the pointer
    payloadPtr = *reinterpret_cast<CardDndPayload**>(&ptrval);
    return s;
}

MyCard::MyCard(QWidget *parent, const CardSymbol symbol, const CardType type, const int numberValue)
    : QLabel(parent)
    , cardSymbol(symbol)
    , cardType(type)
    , cardNumberValue(numberValue)
    , isFlipped(true)
    , canInteract(true)
{
    // Load the pixmap of the cards tileset
    QPixmap tileset(":/assets/card_tileset.png");

    // Calculate the position of the card on the tileset
    int tilesetX = (type == CardType::Number ? numberValue - 2 : (int) type);
    int tilesetY = (int)symbol;

    // Extract that region off the tileset
    // We're creating this pixmap on the heap using the copy constructor of QPixmap(const QPixmap&) so we have access to it later
    cardFrontPixmap = new QPixmap(tileset.copy(tilesetX * cardTileSize.width(), tilesetY * cardTileSize.height(), cardTileSize.width(), cardTileSize.height()));

    // Create the pixmap for the back of the card
    cardBackPixmap = new QPixmap(":/assets/card_back.png");

    // Flipped by default, also applys the pixmap
    this->setCardFlipped(true);

    // Apply the screen size to this whole widget's geometry
    this->setGeometry(0, 0, cardTileSize.width(), cardTileSize.height());
    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Hide the background which this card (a QLabel-child) will inherit from it's parent (the MainWindow)
    this->setStyleSheet("background-color: rgba(0, 0, 0, 0); background: transparent;");

    // Set up the hover anim to just animate the position property
    this->hoverAnim = new QPropertyAnimation(this, "pos");
    this->hoverAnim->setDuration(100);

    // Set up the flip animation. This is a little bit more complex, we're not animating a property,
    // but only a variable.
    this->flipAnim = new QVariantAnimation(this);
    this->flipAnim->setDuration(500);
    this->flipAnim->setStartValue(0.f);
    this->flipAnim->setEndValue(179.9f); // When using 180°, it's sometimes confused in which direction to rotate
    this->flipAnim->setEasingCurve(QEasingCurve::InOutCubic);

    // Called when the animation ticks so we can update
    QObject::connect(this->flipAnim, &QVariantAnimation::valueChanged, [=](const QVariant& value) {
        // We store a "targetFlipped" property in the animation to remember the target to animate to
        bool targetFlipped = this->flipAnim->property("targetFlipped").toBool();

        // Create a transform to use for the rotation of the card
        QTransform t;
        QPoint center = currentPixmap.rect().center();

        // Translate to the center, then rotate, then translate back
        // That sets the rotation origin to the center instead of the top left corner
        t.translate(center.x(), center.y());
        t.rotate(value.toReal(), Qt::YAxis);

        // If we reached half the animation (we know that by checking whether we already reached the flip target),
        // mirror the X axis of the card (as otherwise it'd be mirrored)
        if (this->getFlipped() == targetFlipped) t.scale(-1, 1);

        // Move the origin back to the top left
        t.translate(-center.x(), -center.y());

        // Create a new pixmap where we can draw the rotated version on
        QPixmap rotatedPixmap(currentPixmap.width(), currentPixmap.height());

        // Important, otherwise it will display random bytes
        rotatedPixmap.fill(QColor(0, 0, 0, 0));

        // Create a new painter and assign the transform
        QPainter p(&rotatedPixmap);
        p.setTransform(t);

        // Enable smooth rendering (from https://forum.qt.io/topic/13290/antialiasing-for-qpixmap-scaled-in-a-qgraphicsscene/5)
        p.setRenderHint(QPainter::SmoothPixmapTransform, true);

        // Now draw the current pixmap on the rotated pixmap (this will take the transform into account!)
        p.drawPixmap(currentPixmap.rect(), currentPixmap);

        // If we passed half the animation's time and we have to flip over the card
        if (this->flipAnim->currentTime() >= this->flipAnim->duration() / 2 && this->getFlipped() != targetFlipped)
        {
            // Flip over the card. We do that as the animation alone wouldn't change the card's image between front and back
            this->setCardFlipped(targetFlipped);
        }

        // Apply the newly rotated pixmap. Note that we're not overriding "currentPixmap", so we can use it as a reference
        // again next time we're rotating.
        this->setPixmap(rotatedPixmap);
    });

    // Called when the flip animation finishes
    QObject::connect(this->flipAnim, &QVariantAnimation::finished, [=] {
        // Fall back to the original pixmap to clean up any left over animation states
        this->setPixmap(currentPixmap);
    });

    // Set up the cannot move animation
    this->cannotMoveAnim = new QPropertyAnimation(this, "pos");
    this->cannotMoveAnim->setDuration(200);
    this->cannotMoveAnim->setEasingCurve(QEasingCurve::InOutBounce);
}

QSize MyCard::getCardScreenSize()
{
    return cardTileSize * cardSizeFactor;
}

void MyCard::setCardFlipped(bool shouldFlip)
{
    // Set the variable
    this->isFlipped = shouldFlip;

    // Apply the correct pixmap
    QPixmap pixmap = isFlipped ? *cardFrontPixmap : *cardBackPixmap;

    // Set the card image to the container, scaled by the desired screensize of the card
    currentPixmap = pixmap.scaled(getCardScreenSize().width(), getCardScreenSize().height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setPixmap(currentPixmap);

    // Create a drop shadow effect to make it easier to distinguish cards on one stack
    QGraphicsDropShadowEffect* DropShadowEffect = new QGraphicsDropShadowEffect();
    DropShadowEffect->setBlurRadius(50);
    DropShadowEffect->setOffset(0, 0);
    DropShadowEffect->setColor(QColor(0, 0, 0, 64));
    this->setGraphicsEffect(DropShadowEffect);
}

void MyCard::requestCardFlip(bool shouldFlip)
{
    // Set the targetFlipped property so the animation knows where to stop
    this->flipAnim->setProperty("targetFlipped", shouldFlip);

    // Start the animation. setCardFlipped will be called from the animation when it's time
    this->flipAnim->start();

    // Flipping a card changes the score
    Main::get()->getGameInstance()->addScore(ScoreAttributes::TURN_OVER_TABLEAU_CARD);
}

void MyCard::setCardStack(CardStack *newStack)
{
    currentStack = newStack;
}

QString MyCard::toString()
{
    QString str;
    QTextStream stream(&str);

    // Format type and symbol strings
    QString typeStr, symbolStr;
    switch (getType()) {
    case CardType::Number:
        typeStr = "Number";
        break;
    case CardType::Jack:
        typeStr = "Jack";
        break;
    case CardType::King:
        typeStr = "King";
        break;
    case CardType::Queen:
        typeStr = "Queen";
        break;
    case CardType::Ace:
        typeStr = "Ace";
        break;
    }
    switch (getSymbol()) {
    case CardSymbol::Heart:
        symbolStr = "Heart";
        break;
    case CardSymbol::Diamond:
        symbolStr = "Diamond";
        break;
    case CardSymbol::Spade:
        symbolStr = "Spade";
        break;
    case CardSymbol::Club:
        symbolStr = "Club";
        break;
    }

    // Create final string
    stream << "(Card " << this << " type=" << typeStr << " symbol=" << symbolStr << " numVal=" << getNumberValue() << " overallValue=" << getOverallValue() << ")";
    return str;
}

void MyCard::setCanInteract(bool canInteract)
{
    this->canInteract = canInteract;
}

void MyCard::mousePressEvent(QMouseEvent *ev)
{
    // If the left mouse button was pressed, is flipped and we can interact
    if (ev->button() == Qt::LeftButton && this->getFlipped() && canInteract)
    {
        // Remember this position
        dragStartPos = ev->pos();
    }
}

void MyCard::mouseReleaseEvent(QMouseEvent *ev)
{
    // Only trigger when didn't move
    if ((ev->pos() - dragStartPos).manhattanLength() < 1)
    {
        // Try to move the card
        bool didMoveCard = Main::get()->getGameInstance()->moveCard(this, getCardStack());

        // If moving didn't work and we're not playing the "cannot move" animation already
        if (!didMoveCard && this->cannotMoveAnim->state() != QAbstractAnimation::Running)
        {
            // Set up the keyframes and play the animation
            this->cannotMoveAnim->setKeyValueAt(0, this->pos());
            this->cannotMoveAnim->setKeyValueAt(0.35, this->pos() - QPoint(10, 0));
            this->cannotMoveAnim->setKeyValueAt(0.65, this->pos() + QPoint(10, 0));
            this->cannotMoveAnim->setKeyValueAt(1, this->pos());
            this->cannotMoveAnim->start();
        }
    }
}

void MyCard::mouseMoveEvent(QMouseEvent *ev)
{
    // Make sure the left button is held and we dragged a minimum distance to further handle the dragging
    if (!(ev->buttons() & Qt::LeftButton) || (ev->pos() - dragStartPos).manhattanLength() < 1 || !this->getFlipped() || !canInteract) return;

    // Create a new QDrag object to enable drag and drop
    QDrag* drag = new QDrag(this);

    // Every drag'n'drop action needs MIME data to identify whether drops are allowed at certain
    // places or not.
    QMimeData* mimeData = new QMimeData();
    CardDndPayload* payload = new CardDndPayload();

    // Try to cast the stack this card is currently on to a holding stack
    HoldingStack *myHoldingStack = dynamic_cast<HoldingStack *>(this->getCardStack());

    // If this card is in a holding stack
    if (myHoldingStack)
    {
        // Get all cards above this card
        QList<MyCard *> cardsAboveMe = myHoldingStack->getCardsAbove(this);

        // Draw a pixmap containing all cards of the "substack"
        QPixmap dragPixmap = QPixmap(this->pixmap().width(),
                                     this->pixmap().height()
                                         + ((cardsAboveMe.length() - 1)
                                            * HoldingStack::CardOffsetInStack));
        QPainter painter;
        painter.begin(&dragPixmap);

        for (int i = 0; i < cardsAboveMe.length(); i++)
        {
            MyCard *c = cardsAboveMe[i];
            painter.drawPixmap(0,
                               i * HoldingStack::CardOffsetInStack,
                               c->pixmap().width(),
                               c->pixmap().height(),
                               c->pixmap());

            // Add this card to the payload
            payload->cards.push_back(c);

            // Hide all the "real" cards
            c->hide();
        }

        // Not a single card
        payload->isSingleCard = false;

        // Stop painting and set the pixmap
        painter.end();
        drag->setPixmap(dragPixmap);
    }
    else
    {
        // Just draw the pixmap of this card
        drag->setPixmap(this->pixmap());

        // Hide this card
        this->hide();

        // Add this single card to the dnd payload
        payload->cards.push_back(this);
        payload->isSingleCard = true;
    }

    // Serialize the payload into the MIME data
    QByteArray payloadData;
    QDataStream payloadDataStream(&payloadData, QIODevice::WriteOnly);
    payloadDataStream << payload;
    mimeData->setData("application/x-solitaire-dnd", payloadData);

    // Apply the new mime data and set the pixmap image to show when dragging this card
    drag->setMimeData(mimeData);

    // ev->pos() is relative to the pivot point of the card (topleft)
    // this->pos() is relative to the parent widget (the card stack)
    // Therefore we need to map these coordinates first to a common coordinate origin, which is
    // the main window in this case
    QPoint mousePosInWindow = this->mapTo(Main::get()->getGameWindow(), ev->pos());
    QPoint cardPosInWindow = this->mapTo(Main::get()->getGameWindow(), this->pos());

    // The "hot spot" is the offset in pixels used to offset the pixmap from the mouse cursor when
    // dragging. Subtracting this->pos() from the cardPosInWindow makes sure that the offset of the
    // card in it's parent container (the stacks) is not taken into account. More on that here:
    // https://doc.qt.io/archives/qt-4.8/qdrag.html
    QPoint dndHotSpot = mousePosInWindow - (cardPosInWindow - this->pos());
    drag->setHotSpot(dndHotSpot);

    // Paint a gray overlay to indicate this is a card we're dragging
    // TODO: a better visual effect?
    QPainter painter;
    QPixmap temp = drag->pixmap();
    painter.begin(&temp);
    painter.setCompositionMode(QPainter::CompositionMode_Multiply);
    painter.fillRect(temp.rect(), QColor(0, 0, 0, 127));
    painter.end();
    drag->setPixmap(temp);

    // Start the drag and drop action. This call is blocking!
    Qt::DropAction dropAction = drag->exec(Qt::MoveAction);
    Q_UNUSED(dropAction);

    // Since the above call is blocking, code here get's executed once the d'n'd operation
    // is finished. Show all cards again
    for (MyCard *card : payload->cards) {
        card->show();
    }
}

void MyCard::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);

    // Only play the hover animation if this card is flipped and not playing the animation already
    //    if (this->getFlipped() && this->hoverAnim->state() == QAbstractAnimation::Stopped && canInteract)
    //    {
    //        this->hoverAnim->setStartValue(this->pos());
    //        this->hoverAnim->setEndValue(this->pos() + QPoint(0, 10));
    //        this->hoverAnim->setDirection(QPropertyAnimation::Direction::Forward);
    //        stackBeforeHoverAnim = this->getCardStack();
    //        this->hoverAnim->start();
    //    }
}

void MyCard::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev);

    // Check whether the stack changed (e.g. because the card was moved)
    bool didStackChange = stackBeforeHoverAnim != this->getCardStack();

    // Don't play this animation if not flipped, or because this card was moved by code and not by hand
    //    if (this->getFlipped() && !didStackChange && canInteract)
    //    {
    //        this->hoverAnim->setDirection(QPropertyAnimation::Direction::Backward);
    //        this->hoverAnim->start();
    //    }

    // Reset the wasClicked flag if set
    if (didStackChange) stackBeforeHoverAnim = this->getCardStack();
}
