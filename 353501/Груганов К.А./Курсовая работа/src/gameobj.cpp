#include "gameobj.h"
#include "gamescene.h"

GameObj::GameObj()
{

}

void GameObj::PreUpdate() noexcept
{
    m_prevPos = pos();

    for (size_t i = 0; i < m_Scene->GetObjects().size(); i++) {
        auto obj = m_Scene->GetObjects().at(i);
        if(obj == nullptr) continue;
        if(obj == this) continue;

        float dx = this->x() - obj->x();
        float dy = this->y() - obj->y();

        float rx = dx < 0 ? this->boundingRect().width() : obj->boundingRect().width();
        float ry = dy < 0 ? this->boundingRect().height() : obj->boundingRect().height();

        if (rx >= std::abs(dx) && ry >= std::abs(dy)) {
            Colliding(obj);
        }
    }
}

void GameObj::PostUpdate() noexcept
{
    m_velocity = m_prevPos - pos();

    if(pos().x() - scene()->width() > killX
        || pos().y() - scene()->height() > killY
        || pos().x() < -killX
        || pos().y() < -killY)
    {
        Destroy();
    }
}
