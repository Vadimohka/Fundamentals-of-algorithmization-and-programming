#include "StartScreen.h"

#include <array>
#include <iostream>

#include "../../Renderer/Sprite.h"
#include "../../Resources/ResourceManager.h"
#include "../Game.h"

#include <GLFW/glfw3.h>

std::shared_ptr<RenderEngine::Sprite>
getSpriteForDescription(const char description) {
    switch (description) {
        case '0':
            return ResourceManager::getSprite("brickWall_All");
        case '1':
            return ResourceManager::getSprite("brickWall_TopLeft");
        case '2':
            return ResourceManager::getSprite("brickWall_TopRight");
        case '3':
            return ResourceManager::getSprite("brickWall_Top");
        case '4':
            return ResourceManager::getSprite("brickWall_BottomLeft");
        case '5':
            return ResourceManager::getSprite("brickWall_Left");
        case '6':
            return ResourceManager::getSprite("brickWall_TopRight_BottomLeft");
        case '7':
            return ResourceManager::getSprite("brickWall_Top_BottomLeft");
        case '8':
            return ResourceManager::getSprite("brickWall_BottomRight");
        case '9':
            return ResourceManager::getSprite("brickWall_TopLeft_BottomRight");
        case 'A':
            return ResourceManager::getSprite("brickWall_Right");
        case 'B':
            return ResourceManager::getSprite("brickWall_Top_BottomRight");
        case 'C':
            return ResourceManager::getSprite("brickWall_Bottom");
        case 'D':
            return ResourceManager::getSprite("brickWall_TopLeft_Bottom");
        case 'E':
            return ResourceManager::getSprite("brickWall_TopRight_Bottom");
        case 'F':
            return nullptr;
        default:
            std::cerr << "Unknown Start Level description: " << description << std::endl;
    }
    return nullptr;
}

StartScreen::StartScreen(const std::vector<std::string> &startScreenDescription)
        : m_currentMenuSelection(0),
          m_firstTankTypeSelection(0),
          m_keyReleased(true),
          m_backgroundSprite(std::make_pair(ResourceManager::getSprite("background"),
                                            glm::vec2(0, 0))),
          m_menuSprite(std::make_pair(ResourceManager::getSprite("menu"),
                                      glm::vec2(11 * BLOCK_SIZE,
                                                STARTSCREEN_HEIGHT - startScreenDescription.size() * BLOCK_SIZE -
                                                MENU_HEIGHT - 5 * BLOCK_SIZE))),
          m_firstTankSprite(std::make_pair(
                  ResourceManager::getSprite("player1_yellow_tank_type1_sprite_right"), glm::vec2(8 * BLOCK_SIZE,
                                                                                                  m_menuSprite.second.y +
                                                                                                  6 * BLOCK_SIZE -
                                                                                                  m_currentMenuSelection *
                                                                                                  2 * BLOCK_SIZE))),
          m_secondTankSprite(std::make_pair(
                  ResourceManager::getSprite("player1_yellow_tank_type1_sprite_right"), glm::vec2(6 * BLOCK_SIZE,
                                                                                                  m_menuSprite.second.y +
                                                                                                  6 * BLOCK_SIZE -
                                                                                                  m_currentMenuSelection *
                                                                                                  2 * BLOCK_SIZE))),
          m_firstTankSpriteAnimator(m_firstTankSprite.first),
          m_secondTankSpriteAnimator(m_secondTankSprite.first) {
    if (startScreenDescription.empty()) {
        std::cerr << "Empty start screen description!" << std::endl;
    }

    auto leftOffsetPixels = 4 * BLOCK_SIZE;
    auto bottomOffset = STARTSCREEN_HEIGHT - 4 * BLOCK_SIZE;

    unsigned int currentBottomOffset = bottomOffset;
    for (const std::string &currentRow: startScreenDescription) {
        unsigned int currentLeftOffset = leftOffsetPixels;
        for (const char currentElement: currentRow) {
            m_sprites.emplace_back(
                    std::make_pair(getSpriteForDescription(currentElement),
                                   glm::vec2(currentLeftOffset, currentBottomOffset)));
            currentLeftOffset += BLOCK_SIZE;
        }
        currentBottomOffset -= BLOCK_SIZE;
    }
}

unsigned int StartScreen::getStateWidth() const { return STARTSCREEN_WIDTH; }

unsigned int StartScreen::getStateHeight() const { return STARTSCREEN_HEIGHT; }

void StartScreen::render() const {
    for (const auto &current: m_sprites) {
        if (current.first) {
            current.first->render(current.second, glm::vec2(BLOCK_SIZE), 0.f);
        }
    }
    m_menuSprite.first->render(m_menuSprite.second, glm::vec2(MENU_WIDTH, MENU_HEIGHT), 0.f);
    m_backgroundSprite.first->render(m_backgroundSprite.second,
                                     glm::vec2(STARTSCREEN_WIDTH + BLOCK_SIZE * 4, STARTSCREEN_HEIGHT + BLOCK_SIZE * 4),
                                     0.f, -0.1f);
    m_firstTankSprite.first->render(
            glm::vec2(m_firstTankSprite.second.x, m_firstTankSprite.second.y - m_currentMenuSelection * 2 * BLOCK_SIZE),
            glm::vec2(TANK_SIZE), 0.f, 0.f, m_firstTankSpriteAnimator.getCurrentFrame());
    if (m_currentMenuSelection == 1) {
        m_secondTankSprite.first->render(
                glm::vec2(m_secondTankSprite.second.x,
                          m_secondTankSprite.second.y - m_currentMenuSelection * 2 * BLOCK_SIZE),
                glm::vec2(TANK_SIZE), 0.f, 0.f, m_secondTankSpriteAnimator.getCurrentFrame());
    }
}

void StartScreen::update(const double delta) {
    m_firstTankSpriteAnimator.update(delta);
    if (m_currentMenuSelection == 1) {
        m_secondTankSpriteAnimator.update(delta);
    }
}

void StartScreen::processInput(const std::array<bool, 349> &keys) {
    if (!keys[GLFW_KEY_W] and !keys[GLFW_KEY_S] and
        !keys[GLFW_KEY_A] and !keys[GLFW_KEY_D] and
        !keys[GLFW_KEY_LEFT] and !keys[GLFW_KEY_RIGHT]) {
        m_keyReleased = true;
    }

    if (m_keyReleased) {
        if (keys[GLFW_KEY_W]) {
            m_keyReleased = false;
            --m_currentMenuSelection;
            if (m_currentMenuSelection < 0) {
                m_currentMenuSelection = 2;
            }
        } else if (keys[GLFW_KEY_S]) {
            m_keyReleased = false;
            ++m_currentMenuSelection;
            if (m_currentMenuSelection > 2) {
                m_currentMenuSelection = 0;
            }
        } else if (keys[GLFW_KEY_A]) {
            m_keyReleased = false;
            --m_firstTankTypeSelection;
            if (m_firstTankTypeSelection < 0) {
                m_firstTankTypeSelection = 3;
            }
        } else if (keys[GLFW_KEY_D]) {
            m_keyReleased = false;
            ++m_firstTankTypeSelection;
            if (m_firstTankTypeSelection > 3) {
                m_firstTankTypeSelection = 0;
            }
        } else if (keys[GLFW_KEY_LEFT]) {
            m_keyReleased = false;
            --m_secondTankTypeSelection;
            if (m_secondTankTypeSelection < 0) {
                m_secondTankTypeSelection = 3;
            }
        } else if (keys[GLFW_KEY_RIGHT]) {
            m_keyReleased = false;
            ++m_secondTankTypeSelection;
            if (m_secondTankTypeSelection > 3) {
                m_secondTankTypeSelection = 0;
            }
        }
        switch (m_firstTankTypeSelection) {
            case 0: {
                m_firstTankType = Tank::ETankType::Player1Yellow_type1;
                m_firstTankSprite.first = ResourceManager::getSprite("player1_yellow_tank_type1_sprite_right");
                break;
            }
            case 1: {
                m_firstTankType = Tank::ETankType::Player1Yellow_type2;
                m_firstTankSprite.first = ResourceManager::getSprite("player1_yellow_tank_type2_sprite_right");
                break;
            }
            case 2: {
                m_firstTankType = Tank::ETankType::Player1Yellow_type3;
                m_firstTankSprite.first = ResourceManager::getSprite("player1_yellow_tank_type3_sprite_right");
                break;
            }
            case 3: {
                m_firstTankType = Tank::ETankType::Player1Yellow_type4;
                m_firstTankSprite.first = ResourceManager::getSprite("player1_yellow_tank_type4_sprite_right");
                break;
            }
        }
        if (m_currentMenuSelection == 1){
            switch (m_secondTankTypeSelection) {
                case 0: {
                    m_secondTankType = Tank::ETankType::Player2Green_type1;
                    m_secondTankSprite.first = ResourceManager::getSprite("player2_green_tank_type1_sprite_right");
                    break;
                }
                case 1: {
                    m_secondTankType = Tank::ETankType::Player2Green_type2;
                    m_secondTankSprite.first = ResourceManager::getSprite("player2_green_tank_type2_sprite_right");
                    break;
                }
                case 2: {
                    m_secondTankType = Tank::ETankType::Player2Green_type3;
                    m_secondTankSprite.first = ResourceManager::getSprite("player2_green_tank_type3_sprite_right");
                    break;
                }
                case 3: {
                    m_secondTankType = Tank::ETankType::Player2Green_type4;
                    m_secondTankSprite.first = ResourceManager::getSprite("player2_green_tank_type4_sprite_right");
                    break;
                }
            }
        }
    }

    if (keys[GLFW_KEY_ENTER]) {
        switch (m_currentMenuSelection) {
            case 0:
                Game::setFirstPlayerTank(m_firstTankType);
                Game::changeScreen();
                Game::startNewLevel(0, Game::EGameMode::OnePlayer);
                break;
            case 1:
                Game::setFirstPlayerTank(m_firstTankType);
                Game::setSecondPlayerTank(m_secondTankType);
                Game::changeScreen();
                Game::startNewLevel(0, Game::EGameMode::TwoPlayers);
                break;
            default:
                break;
        }
    }
}