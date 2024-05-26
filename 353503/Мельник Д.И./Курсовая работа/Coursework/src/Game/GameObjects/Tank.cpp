#include "Tank.h"

#include "../../Physics/PhysicsEngine.h"
#include "../../Renderer/Sprite.h"
#include "../Game.h"
#include "../../Resources/ResourceManager.h"
#include "Bullet.h"
#include "iostream"

const std::string &Tank::getTankSpriteFromType(const ETankType eType) {
    return TankTypeToSpriteString[static_cast<size_t>(eType)];
}

const std::string &Tank::getTankSpriteFromExplosion(const ETankExplosion eExplosion) {
    return TankExplosionToSpriteString[static_cast<size_t>(eExplosion)];
}

Tank::Tank(const Tank::ETankType eType, const bool bHasAI,
           const bool bShieldOnSpawn, const EOrientation eOrientation,
           const double maxVelocity, const glm::vec2 &position,
           const glm::vec2 &size, const float layer)
        : IGameObject(IGameObject::EObjectType::Tank, position, size, 0.f, layer),
          m_eOrientation(eOrientation),
          m_pCurrentBullet(std::make_shared<Bullet>(0.1, m_position + m_size / 4.f,
                                                    m_size / 2.f, m_size, layer)),
          m_pBigExplosionBottomLeft(
                  ResourceManager::getSprite(getTankSpriteFromExplosion(ETankExplosion::Bottom_left))),
          m_pBigExplosionBottomRight(
                  ResourceManager::getSprite(getTankSpriteFromExplosion(ETankExplosion::Bottom_right))),
          m_pBigExplosionTopLeft(ResourceManager::getSprite(getTankSpriteFromExplosion(ETankExplosion::Top_left))),
          m_pBigExplosionTopRight(ResourceManager::getSprite(getTankSpriteFromExplosion(ETankExplosion::Top_right))),
          m_spriteBigExplosionBottomLeft(m_pBigExplosionBottomLeft),
          m_spriteBigExplosionBottomRight(m_pBigExplosionBottomRight),
          m_spriteBigExplosionTopLeft(m_pBigExplosionTopLeft),
          m_spriteBigExplosionTopRight(m_pBigExplosionTopRight),
          m_pLowExplosion(ResourceManager::getSprite("explosion")),
          m_spriteLowExplosion(m_pLowExplosion),
          m_pSprite_top(ResourceManager::getSprite(getTankSpriteFromType(eType) + "_top")),
          m_pSprite_bottom(ResourceManager::getSprite(getTankSpriteFromType(eType) + "_bottom")),
          m_pSprite_left(ResourceManager::getSprite(getTankSpriteFromType(eType) + "_left")),
          m_pSprite_right(ResourceManager::getSprite(getTankSpriteFromType(eType) + "_right")),
          m_spriteAnimator_top(m_pSprite_top),
          m_spriteAnimator_bottom(m_pSprite_bottom),
          m_spriteAnimator_left(m_pSprite_left),
          m_spriteAnimator_right(m_pSprite_right),
          m_pSprite_respawn(ResourceManager::getSprite("respawn")),
          m_spriteAnimator_respawn(m_pSprite_respawn),
          m_pSprite_shield(ResourceManager::getSprite("shield")),
          m_spriteAnimator_shield(m_pSprite_shield), m_maxVelocity(maxVelocity),
          m_isSpawning(true),
          m_hasShield(false),
          m_isExplosion(false),
          m_eTankType(eType),
          m_bShieldOnSpawn(bShieldOnSpawn),
          m_starPosition(position),
          m_startETankType(eType) {
    setOrientation(m_eOrientation);
    m_respawnTimer.setCallback([&]() {
        m_isSpawning = false;
        if (m_pAIComponent) {
            m_velocity = m_maxVelocity;
        }
        if (m_bShieldOnSpawn) {
            m_hasShield = true;
            m_shieldTimer.start(2000);
        }
    });

    auto onCollisionCallback = [&](const IGameObject &object, const Physics::ECollisionDirection) {
        setVelocity(0);
    };
    m_colliders.emplace_back(glm::vec2(0), m_size, onCollisionCallback);

    m_lowExplosionTimer.setCallback([&]() {
        m_isExplosion = false;
        m_isActive = false;
        reborn();
    });
    m_explosionTimer.setCallback([&]() {
        m_spriteBigExplosionTopRight.reset();
        m_spriteBigExplosionTopLeft.reset();
        m_spriteBigExplosionBottomRight.reset();
        m_spriteBigExplosionBottomLeft.reset();
        m_lowExplosionTimer.start(m_spriteLowExplosion.getTotalDuration());
    });

    updateTankLogic();
    tankLogic();
    loadTankType();

    m_isActive = true;

    m_respawnTimer.start(1500);

    m_shieldTimer.setCallback([&]() { m_hasShield = false; });

    m_colliders.emplace_back(glm::vec2(0), m_size);

    m_pCurrentBullet->setOwner(this);
    Physics::PhysicsEngine::addDynamicGameObject(m_pCurrentBullet);

    if (bHasAI) {
        m_pAIComponent = std::make_unique<TankAI>(this);
    }
}

void Tank::setVelocity(const double velocity) {
    if (!m_isSpawning) {
        m_velocity = velocity;
    }
}

void Tank::render() {
    if (!m_isExplosion) {
        if (m_isSpawning) {
            m_pSprite_respawn->render(m_position, m_size, m_rotation, m_layer,
                                      m_spriteAnimator_respawn.getCurrentFrame());
        } else {
            switch (m_eOrientation) {
                case Tank::EOrientation::Top:
                    m_pSprite_top->render(m_position, m_size, m_rotation, m_layer,
                                          m_spriteAnimator_top.getCurrentFrame());
                    break;
                case Tank::EOrientation::Bottom:
                    m_pSprite_bottom->render(m_position, m_size, m_rotation, m_layer,
                                             m_spriteAnimator_bottom.getCurrentFrame());
                    break;
                case Tank::EOrientation::Left:
                    m_pSprite_left->render(m_position, m_size, m_rotation, m_layer,
                                           m_spriteAnimator_left.getCurrentFrame());
                    break;
                case Tank::EOrientation::Right:
                    m_pSprite_right->render(m_position, m_size, m_rotation, m_layer,
                                            m_spriteAnimator_right.getCurrentFrame());
                    break;
            }

            if (m_hasShield) {
                m_pSprite_shield->render(m_position, m_size, m_rotation, m_layer + 0.1f,
                                         m_spriteAnimator_shield.getCurrentFrame());
            }
        }
    } else if (!m_explosionTimer.isActive()) {
        std::cout << "low explosion " << std::endl;
        m_pLowExplosion->render(m_position, m_size, m_rotation, m_layer + 0.2f,
                                m_spriteLowExplosion.getCurrentFrame());
    } else {
        m_pBigExplosionTopRight->render(m_position + glm::vec2(8, 8), m_size, m_rotation, m_layer + 0.1f,
                                        m_spriteBigExplosionTopRight.getCurrentFrame());
        m_pBigExplosionTopLeft->render(m_position + glm::vec2(-8, 8), m_size, m_rotation, m_layer + 0.1f,
                                       m_spriteBigExplosionTopLeft.getCurrentFrame());
        m_pBigExplosionBottomRight->render(m_position + glm::vec2(8, -8), m_size, m_rotation, m_layer + 0.1f,
                                           m_spriteBigExplosionBottomRight.getCurrentFrame());
        m_pBigExplosionBottomLeft->render(m_position + glm::vec2(-8, -8), m_size, m_rotation, m_layer + 0.1f,
                                          m_spriteBigExplosionBottomLeft.getCurrentFrame());

    }

    m_pCurrentBullet->render();

}

void Tank::setOrientation(const EOrientation eOrientation) {
    m_eOrientation = eOrientation;
    switch (m_eOrientation) {
        case Tank::EOrientation::Top:
            m_direction.x = 0.f;
            m_direction.y = 1.f;
            break;
        case Tank::EOrientation::Bottom:
            m_direction.x = 0.f;
            m_direction.y = -1.f;
            break;
        case Tank::EOrientation::Left:
            m_direction.x = -1.f;
            m_direction.y = 0.f;
            break;
        case Tank::EOrientation::Right:
            m_direction.x = 1.f;
            m_direction.y = 0.f;
            break;
    }
}

void Tank::update(const double delta) {
    m_pCurrentBullet->update(delta);

    if (!m_isExplosion) {
        if (m_isSpawning) {
            m_velocity = 0;
            m_spriteAnimator_respawn.update(delta);
            m_respawnTimer.update(delta);
        } else if (m_isActive) {
            if (m_pAIComponent) {
                m_velocity = m_maxVelocity;
                m_pAIComponent->update(delta);
            }

            if (m_hasShield) {
                m_spriteAnimator_shield.update(delta);
                m_shieldTimer.update(delta);
            }

            if (m_velocity > 0) {
                switch (m_eOrientation) {
                    case Tank::EOrientation::Top:
                        m_spriteAnimator_top.update(delta);
                        break;
                    case Tank::EOrientation::Bottom:
                        m_spriteAnimator_bottom.update(delta);
                        break;
                    case Tank::EOrientation::Left:
                        m_spriteAnimator_left.update(delta);
                        break;
                    case Tank::EOrientation::Right:
                        m_spriteAnimator_right.update(delta);
                        break;
                }
            }
        }
    } else {
        m_explosionTimer.update(delta);
        if (!m_explosionTimer.isActive()) {
            m_lowExplosionTimer.update(delta);
        }
    }
}

void Tank::tankLogic() {
    if (m_HP < 1) {
        std::cout << "Fatal hp" << std::endl;
        m_isActive = false;
        m_isExplosion = true;
        m_velocity = 0;
        m_explosionTimer.start(m_spriteBigExplosionTopRight.getTotalDuration());
    }
}

void Tank::updateTankLogic() {
    switch (m_eTankType) {
        case ETankType::Player1Yellow_type1:
            m_HP = 1;
            m_maxVelocity = 0.06;
            break;
        case ETankType::Player1Yellow_type2:
            m_HP = 2;
            m_maxVelocity = 0.05;
            break;
        case ETankType::Player1Yellow_type3:
            m_HP = 3;
            m_maxVelocity = 0.04;
            break;
        case ETankType::Player1Yellow_type4:
            m_HP = 4;
            m_maxVelocity = 0.02;
            break;
        case ETankType::Player2Green_type1:
            m_HP = 1;
            m_maxVelocity = 0.06;
            break;
        case ETankType::Player2Green_type2:
            m_HP = 2;
            m_maxVelocity = 0.05;
            break;
        case ETankType::Player2Green_type3:
            m_HP = 3;
            m_maxVelocity = 0.04;
            break;
        case ETankType::Player2Green_type4:
            m_HP = 4;
            m_maxVelocity = 0.02;
            break;
        case ETankType::EnemyWhite_type1:
            m_HP = 1;
            m_maxVelocity = 0.06;
            break;
        case ETankType::EnemyWhite_type2:
            m_HP = 1;
            m_maxVelocity = 0.12;
            break;
        case ETankType::EnemyWhite_type3:
            m_HP = 2;
            m_maxVelocity = 0.04;
            break;
        case ETankType::EnemyWhite_type4:
            m_HP = 3;
            m_maxVelocity = 0.02;
            break;
        case ETankType::EnemyGreen_type1:
            m_HP = 1;
            m_maxVelocity = 0.06;
            break;
        case ETankType::EnemyGreen_type2:
            m_HP = 2;
            m_maxVelocity = 0.12;
            break;
        case ETankType::EnemyGreen_type3:
            m_HP = 2;
            m_maxVelocity = 0.04;
            break;
        case ETankType::EnemyGreen_type4:
            m_HP = 3;
            m_maxVelocity = 0.02;
            break;
        case ETankType::EnemyRed_type1:
            m_HP = 1;
            m_maxVelocity = 0.06;
            break;
        case ETankType::EnemyRed_type2:
            m_HP = 3;
            m_maxVelocity = 0.12;
            break;
        case ETankType::EnemyRed_type3:
            m_HP = 2;
            m_maxVelocity = 0.04;
            break;
        case ETankType::EnemyRed_type4:
            m_HP = 3;
            m_maxVelocity = 0.02;
            break;
        case ETankType::destroy:
            m_HP = 0;
            m_maxVelocity = 0;
    }
    tankLogic();
}

void Tank::updateTackType() {
    switch (m_eTankType) {
        case ETankType::Player1Yellow_type1:
            m_eTankType = ETankType::destroy;
            break;
        case ETankType::Player1Yellow_type2:
            m_eTankType = ETankType::Player1Yellow_type1;
            break;
        case ETankType::Player1Yellow_type3:
            m_eTankType = ETankType::Player1Yellow_type2;
            break;
        case ETankType::Player1Yellow_type4:
            m_eTankType = ETankType::Player1Yellow_type3;
            break;
        case ETankType::Player2Green_type1:
            m_eTankType = ETankType::destroy;
            break;
        case ETankType::Player2Green_type2:
            m_eTankType = ETankType::Player2Green_type1;
            break;
        case ETankType::Player2Green_type3:
            m_eTankType = ETankType::Player2Green_type2;
            break;
        case ETankType::Player2Green_type4:
            m_eTankType = ETankType::Player2Green_type3;
            break;
        case ETankType::EnemyWhite_type1:
            m_eTankType = ETankType::destroy;
            break;
        case ETankType::EnemyWhite_type2:
            m_eTankType = ETankType::destroy;
            break;
        case ETankType::EnemyWhite_type3:
            m_eTankType = ETankType::EnemyWhite_type1;
            break;
        case ETankType::EnemyWhite_type4:
            m_eTankType = ETankType::EnemyWhite_type3;
            break;
        case ETankType::EnemyGreen_type1:
            m_eTankType = ETankType::EnemyWhite_type4;
            break;
        case ETankType::EnemyGreen_type2:
            m_eTankType = ETankType::EnemyWhite_type2;
            break;
        case ETankType::EnemyGreen_type3:
            m_eTankType = ETankType::EnemyGreen_type1;
            break;
        case ETankType::EnemyGreen_type4:
            m_eTankType = ETankType::EnemyGreen_type3;
            break;
        case ETankType::EnemyRed_type1:
            m_eTankType = ETankType::EnemyGreen_type4;
            break;
        case ETankType::EnemyRed_type2:
            m_eTankType = ETankType::EnemyGreen_type2;
            break;
        case ETankType::EnemyRed_type3:
            m_eTankType = ETankType::EnemyRed_type1;
            break;
        case ETankType::EnemyRed_type4:
            m_eTankType = ETankType::EnemyRed_type3;
            break;
        case ETankType::destroy:
            break;
    }
    loadTankType();
}

void Tank::loadTankType() {
    if (m_eTankType != Tank::ETankType::destroy) {
        m_pSprite_right.reset();
        m_pSprite_left.reset();
        m_pSprite_top.reset();
        m_pSprite_bottom.reset();
        m_pSprite_top = ResourceManager::getSprite(getTankSpriteFromType(m_eTankType) + "_top");
        m_pSprite_bottom = ResourceManager::getSprite(getTankSpriteFromType(m_eTankType) + "_bottom");
        m_pSprite_left = ResourceManager::getSprite(getTankSpriteFromType(m_eTankType) + "_left");
        m_pSprite_right = ResourceManager::getSprite(getTankSpriteFromType(m_eTankType) + "_right");
        m_spriteAnimator_top.reset();
        m_spriteAnimator_bottom.reset();
        m_spriteAnimator_left.reset();
        m_spriteAnimator_left.reset();
        m_spriteAnimator_top = m_pSprite_top;
        m_spriteAnimator_bottom = m_pSprite_bottom;
        m_spriteAnimator_left = m_pSprite_left;
        m_spriteAnimator_right = m_pSprite_right;
    }
}

void Tank::explosion() {
    if (!m_hasShield and !m_isSpawning) {
        updateTackType();
        updateTankLogic();
    }
}

void Tank::fire() {
    if (!m_isSpawning && !m_pCurrentBullet->isActive()) {
        m_pCurrentBullet->fire(m_position + m_size / 4.f + m_size * m_direction / 4.f, m_direction);
    }
}

void Tank::reborn() {
    m_isSpawning = true;
    m_position = m_starPosition;
    m_targetPosition = m_position;
    m_eTankType = m_startETankType;
    m_respawnTimer.start(1500);
    m_isActive = true;
    updateTankLogic();
    loadTankType();
    render();
    Game::increaseDestroyTank();
}
