#pragma once

#include <array>
#include <glm/vec2.hpp>
#include <memory>
#include "../Renderer/SpriteAnimator.h"
#include "../Renderer/Timer.h"
#include "./GameObjects/Tank.h"

class IGameState;

namespace RenderEngine {
    class ShaderProgram;
}

class Game {
public:
    enum class EGameMode {
        OnePlayer, TwoPlayers
    };

    Game();

    ~Game();

    static void render();

    static void update(const double delta);

    static void setKey(const int key, const int action);

    static bool init();

    static void initStartScreen(glm::uvec2 &windowSize);

    static unsigned int getCurrentWidth();

    static unsigned int getCurrentHeight();

    static void startNewLevel(const size_t level, const EGameMode eGameMode);

    static void nextLevel();

    static void updateViewport();

    static unsigned int getDestroyTankCount();

    static void increaseDestroyTank();

    static void setSecondPlayerTank(const Tank::ETankType &type2);

    static void setFirstPlayerTank(const Tank::ETankType &type1);

    static std::vector<Tank::ETankType> getPlayerTankType();

    static void getStartScreen();

    static void changeScreen();

    static void setWindowSize(glm::uvec2 &windowSize);

private:
    enum class EGameState {
        StartScreen,
        LevelStart,
        Level,
        Pause,
        Scores,
        GameOver
    };

    static std::array<bool, 349> m_keys;
    static bool m_changeNewLvl;

    static unsigned int m_enemyDestroyCount;

    static glm::uvec2 m_windowSize;
    static glm::vec2 m_losePosition;
    static EGameState m_eCurrentGameState;
    static EGameMode m_eCurrentGameMode;

    static Timer m_changeScreenTimer;
    static Timer m_changeNewScreenTimer;

    static Tank::ETankType m_firstsPlayerTankType;
    static Tank::ETankType m_secondPlayerTankType;
    static std::vector<Tank::ETankType> m_playerTankType;

    static std::shared_ptr<RenderEngine::Sprite> m_greyBackground;
    static std::shared_ptr<RenderEngine::Sprite> m_stageSprite;
    static std::vector<std::shared_ptr<RenderEngine::Sprite>> m_pDigitsSprite;
    static std::shared_ptr<RenderEngine::Sprite> m_pLoseSprite;
    static std::shared_ptr<IGameState> m_pCurrentGameState;
    static std::shared_ptr<RenderEngine::ShaderProgram> m_pSpriteShaderProgram;
    static size_t m_currentLevelIndex;


    inline static std::string intToSpriteString[] = {
            "0", "1",
            "2", "3",
            "4", "5",
            "6", "7",
            "8", "9"
    };

    static const std::string &getDigitSpriteFromInt(int i);
};