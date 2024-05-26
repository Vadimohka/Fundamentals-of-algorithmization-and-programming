#include "Game.h"

#include "../Renderer/ShaderProgram.h"
#include "../Renderer/Sprite.h"
#include "../Renderer/Texture2D.h"
#include "../Resources/ResourceManager.h"

#include "GameObjects/Bullet.h"
#include "GameObjects/Tank.h"

#include "../Physics/PhysicsEngine.h"
#include "../Renderer/Renderer.h"
#include "GameStates/Level.h"
#include "GameStates/StartScreen.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>


unsigned int Game::m_enemyDestroyCount;
std::array<bool, 349> Game::m_keys;
bool Game::m_changeNewLvl;
glm::uvec2 Game::m_windowSize;
glm::vec2 Game::m_losePosition;
Game::EGameMode Game::m_eCurrentGameMode;
Game::EGameState Game::m_eCurrentGameState;
std::shared_ptr<IGameState> Game::m_pCurrentGameState;
std::shared_ptr<RenderEngine::Sprite> Game::m_greyBackground;
std::shared_ptr<RenderEngine::Sprite> Game::m_stageSprite;
std::shared_ptr<RenderEngine::Sprite> Game::m_pLoseSprite;
std::shared_ptr<RenderEngine::ShaderProgram> Game::m_pSpriteShaderProgram;
std::vector<std::shared_ptr<RenderEngine::Sprite>> Game::m_pDigitsSprite;
std::vector<Tank::ETankType> Game::m_playerTankType;
Tank::ETankType Game::m_firstsPlayerTankType;
Tank::ETankType Game::m_secondPlayerTankType;
size_t Game::m_currentLevelIndex;
Timer Game::m_changeScreenTimer;
Timer Game::m_changeNewScreenTimer;

void Game::initStartScreen(glm::uvec2 &windowSize) {
    m_windowSize = windowSize;
}

void Game::setWindowSize(glm::uvec2 &windowSize) {
    m_windowSize = windowSize;
    updateViewport();
}

Game::Game() {}

Game::~Game() {}

void Game::render() {
    m_pCurrentGameState->render();
    if (m_enemyDestroyCount < 1 and m_changeScreenTimer.isActive()) {
        m_pLoseSprite->render(glm::vec2(m_losePosition.x, ++m_losePosition.y), glm::vec2(136, 32), 0, 1.f);
    } else if (m_changeNewLvl) {
        m_greyBackground->render(glm::vec2(0, 0), m_windowSize, 0.f, 1.2f);
        m_stageSprite->render(glm::vec2(43, 130), glm::vec2(136, 32), 0.f, 1.3f);
        m_pDigitsSprite[m_currentLevelIndex + 1]->render(glm::vec2(179, 130), glm::vec2(32, 32), 0.f, 1.4f);
    }
}

void Game::updateViewport() {
    const float level_aspect_ratio = static_cast<float>(getCurrentWidth()) / getCurrentHeight();
    unsigned int viewPortWidth = m_windowSize.x;
    unsigned int viewPortHeight = m_windowSize.y;
    unsigned int viewPortLeftOffset = 0;
    unsigned int viewPortBottomOffset = 0;

    if (static_cast<float>(m_windowSize.x) / m_windowSize.y > level_aspect_ratio) {
        viewPortWidth = static_cast<unsigned int>(m_windowSize.y * level_aspect_ratio);
        viewPortLeftOffset = (m_windowSize.x - viewPortWidth) / 2;
    } else {
        viewPortHeight = static_cast<unsigned int>(m_windowSize.x / level_aspect_ratio);
        viewPortBottomOffset = (m_windowSize.y - viewPortHeight) / 2;
    }

    RenderEngine::Renderer::setViewport(viewPortWidth,
                                        viewPortHeight,
                                        viewPortLeftOffset,
                                        viewPortBottomOffset);

    glm::mat4 projectionMatrix = glm::ortho(0.f, static_cast<float>(getCurrentWidth()),
                                            0.f, static_cast<float>(getCurrentHeight()),
                                            -100.f, 100.f);
    m_pSpriteShaderProgram->setMatrix4("projectionMat", projectionMatrix);
}

void Game::startNewLevel(const size_t level, const EGameMode eGameMode) {
    m_currentLevelIndex = level;

    m_enemyDestroyCount = 0;
    m_eCurrentGameMode = eGameMode;
    auto pLevel = std::make_shared<Level>(ResourceManager::getLevels()[m_currentLevelIndex], m_eCurrentGameMode);
    m_pCurrentGameState = pLevel;
    Physics::PhysicsEngine::setCurrentLevel(pLevel);
    updateViewport();
}

void Game::changeScreen() {
    m_changeNewLvl = true;
    m_changeNewScreenTimer.setCallback([&] {
        m_changeNewLvl = false;
    });
    m_changeNewScreenTimer.start(1000);
}

void Game::nextLevel() {
    ++m_currentLevelIndex;
    if (m_currentLevelIndex > 1){
        m_currentLevelIndex = 0;
    }
    m_changeScreenTimer.setCallback([&] {
        startNewLevel(m_currentLevelIndex, m_eCurrentGameMode);
    });
    m_changeScreenTimer.start(1500);
    changeScreen();
}

void Game::update(const double delta) {
    if (!m_changeScreenTimer.isActive() and m_enemyDestroyCount == 20) {
        nextLevel();
    }
    if (m_changeScreenTimer.isActive()) {

        m_changeScreenTimer.update(delta);
    } else {
        m_pCurrentGameState->processInput(m_keys);
        m_pCurrentGameState->update(delta);
    }
    if (m_changeNewScreenTimer.isActive()) {
        m_changeNewScreenTimer.update(delta);
    }
}

unsigned int Game::getDestroyTankCount() {
    return m_enemyDestroyCount;
}

void Game::setKey(const int key, const int action) { m_keys[key] = action; }

void Game::getStartScreen() {
    m_losePosition = glm::vec2(60, 20);
    m_changeScreenTimer.setCallback([&] {
        m_pCurrentGameState = std::make_shared<StartScreen>(ResourceManager::getStartScreen());
        m_eCurrentGameState = EGameState::StartScreen;
        m_currentLevelIndex = 0;
    });

    m_changeScreenTimer.start(1500);
    setWindowSize(m_windowSize);
}

bool Game::init() {
    ResourceManager::loadJSONResources("res/resources.json");

    m_pSpriteShaderProgram = ResourceManager::getShaderProgram("spriteShader");
    if (!m_pSpriteShaderProgram) {
        std::cerr << "Can't find shader program: " << "spriteShader" << std::endl;
        return false;
    }

    m_pSpriteShaderProgram->use();
    m_pSpriteShaderProgram->setInt("tex", 0);

    m_pLoseSprite = ResourceManager::getSprite("GAMEOVER");
    m_greyBackground = ResourceManager::getSprite("grey");
    m_stageSprite = ResourceManager::getSprite("STAGE");
    for (int i = 0; i < 10; ++i) {
        m_pDigitsSprite.emplace_back(ResourceManager::getSprite(getDigitSpriteFromInt(i)));
    }

    m_losePosition = glm::vec2(60, 20);
    m_pCurrentGameState = std::make_shared<StartScreen>(ResourceManager::getStartScreen());
    m_eCurrentGameState = EGameState::StartScreen;
    m_currentLevelIndex = 0;
    m_keys.fill(false);
    setWindowSize(m_windowSize);

    return true;
}

unsigned int Game::getCurrentWidth() {
    return m_pCurrentGameState->getStateWidth();
}

unsigned int Game::getCurrentHeight() {
    return m_pCurrentGameState->getStateHeight();
}

void Game::setSecondPlayerTank(const Tank::ETankType &type2) {
    m_secondPlayerTankType = type2;
}

void Game::setFirstPlayerTank(const Tank::ETankType &type1) {
    m_firstsPlayerTankType = type1;
}

void Game::increaseDestroyTank() {
    ++m_enemyDestroyCount;
}

const std::string &Game::getDigitSpriteFromInt(int i) {
    return intToSpriteString[i];
}

std::vector<Tank::ETankType> Game::getPlayerTankType() {
    m_playerTankType.clear();
    m_playerTankType.emplace_back(m_firstsPlayerTankType);
    m_playerTankType.emplace_back(m_secondPlayerTankType);
    return m_playerTankType;
}

