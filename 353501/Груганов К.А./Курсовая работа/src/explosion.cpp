#include "explosion.h"

Explosion::Explosion()
{
    m_explosion = QPixmap(":/img/взрыв.png")
                      .scaled(QSize(60, 60), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(m_explosion);
}
