#include "Progressbar.h"
#include "cmath"

#include "../../Resources/ResourceManager.h"
#include "../../Renderer/Sprite.h"

ProgressBar::ProgressBar(const glm::vec2 &position, const glm::vec2 &size, const float rotation, const float layer,
                         Game::EGameMode gameMode)
        : IGameObject(IGameObject::EObjectType::ProgressBar, position, size, rotation, layer),
          m_barSprite(ResourceManager::getSprite("ProgressBar")), m_playerTankType(Game::getPlayerTankType()),
          m_activeTank(20), m_tankSprite(ResourceManager::getSprite("TankOnly")) {
    m_colliders.emplace_back(glm::vec2(0), m_size);
    if (gameMode == Game::EGameMode::OnePlayer) {
        m_closeSecondPlayerSprite = ResourceManager::getSprite("grey");
    }
    m_closeTankSprite = ResourceManager::getSprite("grey");
}

void ProgressBar::render() {
    m_barSprite->render(m_position, m_size, m_rotation, m_layer);
    if (m_closeSecondPlayerSprite) {
        m_closeSecondPlayerSprite->render(glm::vec2(m_position.x + 8, m_position.y + 64), glm::vec2(16, 16), m_rotation,
                                          m_layer + 0.1f);
    }
    m_closeTankSprite->render(glm::vec2(m_position.x + 8, m_position.y + 136), glm::vec2(16, 80), m_rotation,
                              m_layer + 0.1f);
    m_activeTank = 20 - Game::getDestroyTankCount();

    for (int i = 0; i < m_activeTank; ++i) {
        if (i % 2) {
            m_tankSprite->render(glm::vec2(m_position.x + 16, m_position.y + 136 + (8 * (i / 2))),
                                 glm::vec2(8, 8), m_rotation, m_layer + 0.2f);
        } else {
            m_tankSprite->render(glm::vec2(m_position.x + 8, m_position.y + 136 + (8 * (i / 2))),
                                 glm::vec2(8, 8), m_rotation, m_layer + 0.2f);
        }
    }
}

void ProgressBar::explosion() {}