#include "view/screens/tutorialScreen/tutorialcontent.h"

#include <QGraphicsScene>

#include "model/turrets/turrettype.h"

using model::TurretStats;
using model::TurretType;
using model::turretTypes;

namespace view {

TutorialContent::TutorialContent(const QSizeF &size) : _size(size), currentStep(1) {
    nextStepButton = new StandardButton("NEXT", 200, this);
    nextStepButton->setPos(_size.width() / 2 - 100, _size.height() - 250);

    connect(nextStepButton, &StandardButton::pressed, this, &TutorialContent::nextStep);
}

QRectF TutorialContent::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void TutorialContent::paintTitle(QPainter *painter, const QString &title) {
    QFont font = painter->font();
    font.setPixelSize(50);
    painter->setFont(font);

    painter->drawText(
        QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
        Qt::AlignCenter | Qt::TextWordWrap,
        title);

    font.setPixelSize(30);
    painter->setFont(font);
}

void TutorialContent::paintTurretInfo(
    QPainter *painter,
    const QString &image,
    const QString &name,
    const QString &description,
    const QString &stats) {
    QFont font = painter->font();

    QPixmap pixmap = QPixmap(":/assets/images/turrets/" + image + ".png");
    painter->drawPixmap(QRect(_size.width() / 8, 200, 128, 128), pixmap);

    font.setPixelSize(40);
    painter->setFont(font);

    painter->drawText(
        QRectF(_size.width() / 8 + 200, 200, _size.width() * 3 / 4 - 200, 128),
        Qt::AlignVCenter | Qt::TextWordWrap,
        name);

    font.setPixelSize(25);
    painter->setFont(font);

    painter->drawText(
        QRectF(_size.width() / 8, 400, _size.width() * 3 / 4, 200),
        Qt::TextWordWrap,
        description);

    painter->drawText(
        QRectF(_size.width() / 8, 600, _size.width() * 3 / 4, 200),
        Qt::TextWordWrap,
        stats);

    font.setPixelSize(30);
    painter->setFont(font);
}

void TutorialContent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QFont font = painter->font();
    font.setPixelSize(30);
    font.setFamily("Press Start 2P");
    painter->setFont(font);
    painter->setPen(Qt::white);

    QPixmap pixmap;
    TurretStats stats;

    switch (currentStep) {
        case 1:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, _size.height() / 6, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Welcome to my course work project");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 6, _size.height() / 6 + 50, _size.width() * 2 / 3, _size.height() * 2 / 3),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Your aim is to destroy all the students, preventing them to reach 30 in the exam.\n"
                "You can achieve this by using some complex c++ concepts that they can't understand.");
            break;
        case 2:
            paintTitle(painter, "The game rules");

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, _size.height() * 3 / 4),
                Qt::AlignHCenter | Qt::TextWordWrap,
                "When the game starts students begin to spawn, trying to reach the end of the path.\n"
                "There are different students waves during a match, each one with different statistics.\n"
                "If a student reaches the end of the path you loose life. When your life reaches 0 the game is over.\n\n"
                "You have some initial game credits. Use them to strategically place turrets in order to defeat students.\n"
                "When a student dies you earn some credit.\n\n"
                "If you manage to destroy all students you win!");
            break;
        case 3:
            paintTitle(painter, "The game field");

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, 100),
                Qt::AlignCenter | Qt::TextWordWrap,
                "The game map consists of three different cells:");

            pixmap = QPixmap(":/assets/images/tiles/horizontal-tile.png");
            painter->drawPixmap(QRect(_size.width() / 8, 350, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Path cells:\n"
                "the cells where the students will walk");

            pixmap = QPixmap(":/assets/images/tiles/free-tile.png");
            painter->drawPixmap(QRect(_size.width() / 8, 500, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Free cells:\n"
                "the cells where you can place the turrets");

            pixmap = QPixmap(":/assets/images/tiles/blocked-tile.png");
            painter->drawPixmap(QRect(_size.width() / 8, 650, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 650, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Blocked cells:\n"
                "the cells where you can't place any turret");
            break;
        case 4:
            paintTitle(painter, "Turrets - Part 1");

            painter->drawText(
                QRectF(_size.width() / 8, 300, _size.width() * 3 / 4, _size.height() * 3 / 4),
                Qt::AlignHCenter | Qt::TextWordWrap,
                "There are 6 types of turrets in the game. Every turret has a specific cost and specific stats,"
                "and is characterised by a specific attack radius (how many cells in every side it can attack."
                "Diagonal cells also count).\n"
                "Other turrets stats are: damage (how much the health of the attacked enemy decrease), cooldown "
                "(how fast does the turret attack) and maxTargets (how many enemies are attacked simultaneously).");

            break;
        case 5:
            paintTitle(painter, "Turrets - Part 2");

            stats = turretTypes.at(TurretType::WeakTurret);

            paintTurretInfo(
                painter,
                "weak-turret",
                "Pointers Turret",
                "Pointers may seem difficult for a begginer, but IT students know how to handle them.\n"
                "So this turret doesn't do much damage. Indeed it's quite economic.",
                QString(
                    "Cost: %1\n"
                    "Max targets: %2\n"
                    "Radius: %3\n"
                    "Damage: %4\n"
                    "Cooldown: %5\n")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius)
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));
            break;
        case 6:
            paintTitle(painter, "Turrets - Part 3");

            stats = turretTypes.at(TurretType::MitraTurret);

            paintTurretInfo(
                painter,
                "mitra-turret",
                "Template Turret",
                "Some able students may escape the template's hell. But someone will be constantly hit by it's difficult syntax.",
                QString(
                    "Cost: %1\n"
                    "Max targets: %2\n"
                    "Radius: %3\n"
                    "Damage: %4\n"
                    "Cooldown: %5\n")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius)
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));
            break;
        case 7:
            paintTitle(painter, "Turrets - Part 4");

            stats = turretTypes.at(TurretType::GranadeTurret);

            paintTurretInfo(
                painter,
                "granade-turret",
                "Diamond Turret",
                "A diamond problem will strike hard the poor student that encounters it. Fortunately it doesn't happen often.",
                QString(
                    "Cost: %1\n"
                    "Max targets: %2\n"
                    "Radius: %3\n"
                    "Damage: %4 (decrement by 10 for every enemy after the one attacked)\n"
                    "Cooldown: %5\n")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius)
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));
            break;
        case 8:
            paintTitle(painter, "Turrets - Part 5");

            stats = turretTypes.at(TurretType::ComboTurret);

            paintTurretInfo(
                painter,
                "combo-turret",
                "Recursive Turret",
                "Recursive functions are a problem for a few students. But the ones that can't understand them"
                " will be penalised more and more with each recursion.",
                QString(
                    "Cost: %1\n"
                    "Max targets: %2\n"
                    "Radius: %3\n"
                    "Damage: %4 (increments on every attack to the same enemy)\n"
                    "Cooldown: %5\n")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius)
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));
            break;
        case 9:
            paintTitle(painter, "Turrets - Part 6");

            stats = turretTypes.at(TurretType::SplitTurret);

            paintTurretInfo(
                painter,
                "split-turret",
                "Inheritance Turret",
                "Let's be honest: inheritance is not so hard. When students join forces there's nothing that"
                " can stop them!",
                QString(
                    "Cost: %1\n"
                    "Max targets: %2\n"
                    "Radius: %3\n"
                    "Damage: %4 / number of attacked enemies\n"
                    "Cooldown: %5\n")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius)
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));
            break;
        case 10:
            paintTitle(painter, "Turrets - Part 7");

            stats = turretTypes.at(TurretType::SlowTimeTurret);

            paintTurretInfo(
                painter,
                "slowtime-turret",
                "IO Turret",
                "This turret doesn't have a standard attack. A well placed \"What does it prints?\" exercise will"
                " waste a lot of students' time.",
                QString(
                    "Cost: %1\n"
                    "Max targets: %2\n"
                    "Radius: %3\n"
                    "Damage: this turret slows enemies down by 50%")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius));
            break;
        case 11:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Additional infos");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, _size.height() * 3 / 4),
                Qt::AlignHCenter | Qt::TextWordWrap,
                "You can remove a turret by clicking on it.\n"
                "Removing a turret will restore half of its cost.\n\n"
                "If the game is too slow for you you can speed it up by clicking the fast forward button on the top right corner.\n\n"
                "Now you are ready to start playing.\n\n"
                "Go destroy some students!!!");
            break;
        default:
            // Nothing to do
            break;
    }
}

void TutorialContent::nextStep() {
    currentStep++;

    if (currentStep == 11) {
        scene()->removeItem(nextStepButton);
        delete nextStepButton;

        StandardButton *startGameButton = new StandardButton("START PLAYING", 500, this);
        startGameButton->setPos(_size.width() / 2 - 700, _size.height() - 250);

        connect(startGameButton, &StandardButton::pressed, this, &TutorialContent::startPlayPressed);

        StandardButton *mainMenuButton = new StandardButton("RETURN TO MENU", 500, this);
        mainMenuButton->setPos(_size.width() / 2 + 200, _size.height() - 250);

        connect(mainMenuButton, &StandardButton::pressed, this, &TutorialContent::returnToMenuPressed);
    }

    update();
}

}  // namespace view
