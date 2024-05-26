#pragma once

#include <glm/vec2.hpp>
#include <memory>
#include <string>

#include "../../Renderer/SpriteAnimator.h"
#include "../../Renderer/Timer.h"
#include "../TankAI.h"
#include "IGameObject.h"

namespace RenderEngine {
    class Sprite;
}

class Bullet;

class Tank : public IGameObject {
public:
    enum class ETankType : uint8_t {
        Player1Yellow_type1,
        Player1Yellow_type2,
        Player1Yellow_type3,
        Player1Yellow_type4,

        Player2Green_type1,
        Player2Green_type2,
        Player2Green_type3,
        Player2Green_type4,

        EnemyWhite_type1,
        EnemyWhite_type2,
        EnemyWhite_type3,
        EnemyWhite_type4,

        EnemyGreen_type1,
        EnemyGreen_type2,
        EnemyGreen_type3,
        EnemyGreen_type4,

        EnemyRed_type1,
        EnemyRed_type2,
        EnemyRed_type3,
        EnemyRed_type4,
        destroy
    };
    enum class ETankExplosion {
        Top_right,
        Top_left,
        Bottom_right,
        Bottom_left,
    };

    inline static std::string TankTypeToSpriteString[] = {
            "player1_yellow_tank_type1_sprite", "player1_yellow_tank_type2_sprite",
            "player1_yellow_tank_type3_sprite", "player1_yellow_tank_type4_sprite",

            "player2_green_tank_type1_sprite", "player2_green_tank_type2_sprite",
            "player2_green_tank_type3_sprite", "player2_green_tank_type4_sprite",

            "enemy_white_tank_type1_sprite", "enemy_white_tank_type2_sprite",
            "enemy_white_tank_type3_sprite", "enemy_white_tank_type4_sprite",

            "enemy_green_tank_type1_sprite", "enemy_green_tank_type2_sprite",
            "enemy_green_tank_type3_sprite", "enemy_green_tank_type4_sprite",

            "enemy_red_tank_type1_sprite", "enemy_red_tank_type2_sprite",
            "enemy_red_tank_type3_sprite", "enemy_red_tank_type4_sprite"};
    inline static std::string TankExplosionToSpriteString[] = {
            "bigExplosion_top_right", "bigExplosion_top_left",
            "bigExplosion_bottom_right", "bigExplosion_bottom_left",};


    enum class EOrientation : uint8_t {
        Top, Bottom, Left, Right
    };

    Tank(const Tank::ETankType eType, const bool bHasAI,
         const bool bShieldOnSpawn, const EOrientation eOrientation,
         const double maxVelocity, const glm::vec2 &position,
         const glm::vec2 &size, const float layer);

    void render()  override;

    void setOrientation(const EOrientation eOrientation);

    void update(const double delta) override;

    double getMaxVelocity() const { return m_maxVelocity; }

    void setVelocity(const double velocity) override;

    void explosion() override;

    void fire();

    void reborn();

private:

    void tankLogic();

    void updateTankLogic();

    void updateTackType();

    void loadTankType();

    EOrientation m_eOrientation;
    glm::vec2 m_starPosition;
    std::shared_ptr<Bullet> m_pCurrentBullet;

    std::shared_ptr<RenderEngine::Sprite> m_pSprite_top;
    std::shared_ptr<RenderEngine::Sprite> m_pSprite_bottom;
    std::shared_ptr<RenderEngine::Sprite> m_pSprite_left;
    std::shared_ptr<RenderEngine::Sprite> m_pSprite_right;
    std::shared_ptr<RenderEngine::Sprite> m_pSprite_respawn;
    std::shared_ptr<RenderEngine::Sprite> m_pSprite_shield;

    std::shared_ptr<RenderEngine::Sprite> m_pBigExplosionBottomLeft;
    std::shared_ptr<RenderEngine::Sprite> m_pBigExplosionBottomRight;
    std::shared_ptr<RenderEngine::Sprite> m_pBigExplosionTopLeft;
    std::shared_ptr<RenderEngine::Sprite> m_pBigExplosionTopRight;
    std::shared_ptr<RenderEngine::Sprite> m_pLowExplosion;

    RenderEngine::SpriteAnimator m_spriteLowExplosion;
    RenderEngine::SpriteAnimator m_spriteBigExplosionBottomLeft;
    RenderEngine::SpriteAnimator m_spriteBigExplosionBottomRight;
    RenderEngine::SpriteAnimator m_spriteBigExplosionTopLeft;
    RenderEngine::SpriteAnimator m_spriteBigExplosionTopRight;

    RenderEngine::SpriteAnimator m_spriteAnimator_shield;
    RenderEngine::SpriteAnimator m_spriteAnimator_respawn;
    RenderEngine::SpriteAnimator m_spriteAnimator_top;
    RenderEngine::SpriteAnimator m_spriteAnimator_bottom;
    RenderEngine::SpriteAnimator m_spriteAnimator_left;
    RenderEngine::SpriteAnimator m_spriteAnimator_right;

    Timer m_respawnTimer;
    Timer m_shieldTimer;
    Timer m_explosionTimer;
    Timer m_lowExplosionTimer;

    double m_maxVelocity;
    bool m_isExplosion;
    bool m_isSpawning;
    bool m_hasShield;
    bool m_bShieldOnSpawn;

    int m_HP;

    std::unique_ptr<TankAI> m_pAIComponent;
    ETankType m_eTankType;
    ETankType m_startETankType;

    static const std::string &getTankSpriteFromType(const ETankType eType);
    static const std::string &getTankSpriteFromExplosion(const ETankExplosion eExplosion);
};
