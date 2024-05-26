#pragma once

#include <glm/vec2.hpp>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "../Game.h"
#include "../../Renderer/Sprite.h"
#include "../../Resources/ResourceManager.h"
#include "../GameObjects/Eagle.h"
#include "IGameState.h"

class IGameObject;

class Tank;

class Level : public IGameState {
public:
    static constexpr unsigned int BLOCK_SIZE = 16;

    Level(const std::vector<std::string> &levelDescription,
          const Game::EGameMode eGameMode);

    virtual void render() const override;

    virtual void update(const double delta) override;

    virtual unsigned int getStateWidth() const override;

    virtual unsigned int getStateHeight() const override;

    virtual void processInput(const std::array<bool, 349> &keys) override;

    const glm::ivec2 &getPlayerRespawn_1() const { return m_playerRespawn_1; }

    const glm::ivec2 &getPlayerRespawn_2() const { return m_playerRespawn_2; }

    const glm::ivec2 &getEnemyRespawn_1() const { return m_enemyRespawn_1; }

    const glm::ivec2 &getEnemyRespawn_2() const { return m_enemyRespawn_2; }

    const glm::ivec2 &getEnemyRespawn_3() const { return m_enemyRespawn_3; }

    std::vector<std::shared_ptr<IGameObject>>
    getObjectsInArea(const glm::vec2 &bottomLeft,
                     const glm::vec2 &topRight) const;

    void initLevel();

private:
    size_t m_widthBlocks = 0;
    size_t m_heightBlocks = 0;
    unsigned int m_widthPixels = 0;
    unsigned int m_heightPixels = 0;

    bool m_isPause = false;
    bool m_keyReleased;
    std::shared_ptr<RenderEngine::Sprite> m_pPauseSprite;

    glm::ivec2 m_playerRespawn_1;
    glm::ivec2 m_playerRespawn_2;
    glm::ivec2 m_enemyRespawn_1;
    glm::ivec2 m_enemyRespawn_2;
    glm::ivec2 m_enemyRespawn_3;
    std::vector<glm::ivec2> m_eagleRespawn;
    std::vector<Tank::ETankType> m_playerType;
    std::vector<std::shared_ptr<IGameObject>> m_levelObjects;
    std::shared_ptr<Tank> m_pTank1;
    std::shared_ptr<Tank> m_pTank2;
    std::set<std::shared_ptr<Tank>> m_enemyTanks;
    std::set<std::shared_ptr<Eagle>> m_eagle;
    Game::EGameMode m_eGameMode;
};