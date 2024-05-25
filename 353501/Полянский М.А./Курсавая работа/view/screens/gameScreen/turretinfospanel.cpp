#include "view/screens/gameScreen/turretinfospanel.h"

#include <QPainter>

namespace view {

TurretInfosPanel::TurretInfosPanel() : _show(false) {}

QRectF TurretInfosPanel::boundingRect() const {
    return QRectF(0, 0, 1920 - 96 * 16 - 10, 96 * 9);  // TODO: refactor all this numbers
}

void TurretInfosPanel::paintTitle(QPainter *painter, const QString &image, const QString &title) {
    QFont font = painter->font();
    font.setPixelSize(30);
    painter->setFont(font);

    QPixmap pixmap = QPixmap(":/assets/images/turrets/" + image + ".png");
    painter->drawPixmap(QRect((boundingRect().width() - 128) / 2, 20, 128, 128), pixmap);

    painter->drawText(
        QRect(20, 168, boundingRect().width() - 40, 70),
        Qt::AlignHCenter | Qt::TextWordWrap,
        title);

    font.setPixelSize(20);
    painter->setFont(font);
}

void TurretInfosPanel::paintTurretInfo(QPainter *painter, const QString &stats) {
    painter->drawText(
        QRect(20, 300, boundingRect().width() - 40, boundingRect().height() - 320),
        Qt::AlignHCenter | Qt::TextWordWrap,
        stats);
}

void TurretInfosPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor::fromRgb(70, 70, 70));

    painter->setBrush(brush);

    painter->drawRect(0, 0, 1920 - 96 * 16 - 10, 96 * 9);

    QFont font = painter->font();
    font.setPixelSize(20);
    font.setFamily("Press Start 2P");
    painter->setFont(font);
    painter->setPen(Qt::white);

    model::TurretStats stats;

    // Paint content
    if (_show) {
        switch (_turretType) {
            case model::TurretType::WeakTurret:
                paintTitle(painter, "weak-turret", "Pointer Turret");

                stats = turretTypes.at(TurretType::WeakTurret);

                paintTurretInfo(
                    painter,
                    QString(
                        "Cost: %1\n\n"
                        "Max targets: %2\n\n"
                        "Radius: %3\n\n"
                        "Damage: %4\n\n"
                        "Cooldown: %5\n\n")
                        .arg(stats.cost)
                        .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                        .arg(stats.attackRadius)
                        .arg(stats.initialAttackDamage)
                        .arg(stats.initialAttackCooldown));
                break;
            case model::TurretType::MitraTurret:
                paintTitle(painter, "mitra-turret", "Template Turret");

                stats = turretTypes.at(TurretType::MitraTurret);

                paintTurretInfo(
                    painter,
                    QString(
                        "Cost: %1\n\n"
                        "Max targets: %2\n\n"
                        "Radius: %3\n\n"
                        "Damage: %4\n\n"
                        "Cooldown: %5\n\n")
                        .arg(stats.cost)
                        .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                        .arg(stats.attackRadius)
                        .arg(stats.initialAttackDamage)
                        .arg(stats.initialAttackCooldown));
                break;
            case model::TurretType::GranadeTurret:
                paintTitle(painter, "granade-turret", "Diamond Turret");

                stats = turretTypes.at(TurretType::GranadeTurret);

                paintTurretInfo(
                    painter,
                    QString(
                        "Cost: %1\n\n"
                        "Max targets: %2\n\n"
                        "Radius: %3\n\n"
                        "Damage: %4 (decrement by 10 for every enemy after the one attacked)\n\n"
                        "Cooldown: %5\n\n")
                        .arg(stats.cost)
                        .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                        .arg(stats.attackRadius)
                        .arg(stats.initialAttackDamage)
                        .arg(stats.initialAttackCooldown));
                break;
            case model::TurretType::ComboTurret:
                paintTitle(painter, "combo-turret", "Recursive Turret");

                stats = turretTypes.at(TurretType::ComboTurret);

                paintTurretInfo(
                    painter,
                    QString(
                        "Cost: %1\n\n"
                        "Max targets: %2\n\n"
                        "Radius: %3\n\n"
                        "Damage: %4 (increments on every attack to the same enemy)\n\n"
                        "Cooldown: %5\n\n")
                        .arg(stats.cost)
                        .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                        .arg(stats.attackRadius)
                        .arg(stats.initialAttackDamage)
                        .arg(stats.initialAttackCooldown));
                break;
            case model::TurretType::SplitTurret:
                paintTitle(painter, "split-turret", "Inheritance Turret");

                stats = turretTypes.at(TurretType::SplitTurret);

                paintTurretInfo(
                    painter,
                    QString(
                        "Cost: %1\n\n"
                        "Max targets: %2\n\n"
                        "Radius: %3\n\n"
                        "Damage: %4 / number of attacked enemies\n\n"
                        "Cooldown: %5\n\n")
                        .arg(stats.cost)
                        .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                        .arg(stats.attackRadius)
                        .arg(stats.initialAttackDamage)
                        .arg(stats.initialAttackCooldown));
                break;
            case model::TurretType::SlowTimeTurret:
                paintTitle(painter, "slowtime-turret", "IO Turret");

                stats = turretTypes.at(TurretType::SlowTimeTurret);

                paintTurretInfo(
                    painter,
                    QString(
                        "Cost: %1\n\n"
                        "Max targets: %2\n\n"
                        "Radius: %3\n\n"
                        "Damage: this turret slows enemies down by 50%")
                        .arg(stats.cost)
                        .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                        .arg(stats.attackRadius));
                break;
        }
    } else {
        painter->drawText(
            QRect(20, 20, boundingRect().width() - 40, boundingRect().height() - 40),
            Qt::AlignCenter | Qt::TextWordWrap,
            "Hover a turret to see its infos.");
    }
}

void TurretInfosPanel::setTurretType(model::TurretType turretType) {
    _turretType = turretType;
    _show = true;
}

void TurretInfosPanel::hideInfos() {
    _show = false;
}

}  // namespace view
