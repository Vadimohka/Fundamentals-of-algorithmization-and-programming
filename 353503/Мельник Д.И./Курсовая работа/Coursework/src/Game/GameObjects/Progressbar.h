#include "IGameObject.h"
#include "../Game.h"

#include <array>
#include <memory>

namespace RenderEngine{
    class Sprite;
}

class ProgressBar : public IGameObject {
public:

    ProgressBar(const glm::vec2& position, const glm::vec2& size, const float rotation, const float layer, Game::EGameMode gameMode);
    virtual void render()  override;
    void explosion() override;

private:
    unsigned int m_activeTank;

    std::shared_ptr<RenderEngine::Sprite> m_barSprite;
    std::vector<Tank::ETankType> m_playerTankType;
    std::vector<std::shared_ptr<RenderEngine::Sprite>> m_playerSprite;
    std::vector<std::shared_ptr<RenderEngine::Sprite>> m_digitSprite;
    std::shared_ptr<RenderEngine::Sprite> m_closeSecondPlayerSprite;
    std::shared_ptr<RenderEngine::Sprite> m_closeTankSprite;
    std::shared_ptr<RenderEngine::Sprite> m_tankSprite;
};