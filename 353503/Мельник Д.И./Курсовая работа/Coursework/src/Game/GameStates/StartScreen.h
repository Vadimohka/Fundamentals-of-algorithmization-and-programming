#pragma once

#include <glm/vec2.hpp>
#include <memory>
#include <string>
#include <vector>

#include "../../Renderer/SpriteAnimator.h"
#include "../GameObjects/Tank.h"
#include "IGameState.h"

namespace RenderEngine {
    class Sprite;
}

class Game;

class StartScreen : public IGameState {
public:
    static constexpr unsigned int BLOCK_SIZE = 8;
    static constexpr unsigned int STARTSCREEN_WIDTH = 15 * BLOCK_SIZE * 2;
    static constexpr unsigned int STARTSCREEN_HEIGHT = 14 * BLOCK_SIZE * 2;
    static constexpr unsigned int MENU_WIDTH = 128;
    static constexpr unsigned int MENU_HEIGHT = 64;
    static constexpr unsigned int TANK_SIZE = BLOCK_SIZE * 2;

    StartScreen(const std::vector<std::string> &startScreenDescription);

    virtual void render() const override;

    virtual void update(const double delta) override;

    virtual void processInput(const std::array<bool, 349> &keys) override;

    virtual unsigned int getStateWidth() const override;

    virtual unsigned int getStateHeight() const override;

private:
    Game *m_pGame;
    Tank::ETankType m_firstTankType;
    Tank::ETankType m_secondTankType;
    int m_firstTankTypeSelection;
    int m_secondTankTypeSelection;
    int m_currentMenuSelection;
    bool m_keyReleased;

    std::vector<std::pair<std::shared_ptr<RenderEngine::Sprite>, glm::vec2>> m_sprites;

    std::pair<std::shared_ptr<RenderEngine::Sprite>, glm::vec2> m_menuSprite;
    std::pair<std::shared_ptr<RenderEngine::Sprite>, glm::vec2> m_backgroundSprite;
    std::pair<std::shared_ptr<RenderEngine::Sprite>, glm::vec2> m_firstTankSprite;
    std::pair<std::shared_ptr<RenderEngine::Sprite>, glm::vec2> m_secondTankSprite;
    RenderEngine::SpriteAnimator m_secondTankSpriteAnimator;
    RenderEngine::SpriteAnimator m_firstTankSpriteAnimator;
};
