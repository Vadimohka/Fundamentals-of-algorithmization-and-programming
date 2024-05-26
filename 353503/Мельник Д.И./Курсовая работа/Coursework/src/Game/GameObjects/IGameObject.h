#pragma once

#include <glm/vec2.hpp>

#include "../../Physics/PhysicsEngine.h"

class IGameObject {
public:
    enum class EObjectType {
        BetonWall,
        Border,
        BrickWall,
        Bullet,
        Eagle,
        Ice,
        Tank,
        Trees,
        Water,
        ProgressBar,

        Unknown
    };

    IGameObject(const EObjectType objectType,
                const glm::vec2 &position,
                const glm::vec2 &size,
                const float rotation,
                const float layer);

    void setOwner(IGameObject *pOwner);

    [[nodiscard]] IGameObject *getOwner() const { return m_pOwner; }

    virtual void render() = 0;

    virtual void update(const double delta) {};

    virtual ~IGameObject();

    virtual glm::vec2 &getCurrentPosition() { return m_position; }

    virtual glm::vec2 &getTargetPosition() { return m_targetPosition; }

    virtual glm::vec2 &getCurrentDirection() { return m_direction; }

    virtual double getCurrentVelocity() { return m_velocity; }

    virtual void setVelocity(const double velocity);

    [[nodiscard]] const glm::vec2 &getSize() const { return m_size; }

    [[nodiscard]] const std::vector<Physics::Collider> &getColliders() const { return m_colliders; }

    EObjectType getObjectType() const { return m_objectType; }

    virtual void explosion() { };

    virtual bool isActive() { return m_isActive; }

    virtual bool collides(const EObjectType objectType) { return true; }

protected:
    IGameObject *m_pOwner;
    glm::vec2 m_position;
    glm::vec2 m_targetPosition;
    glm::vec2 m_size;
    float m_rotation;
    float m_layer;
    EObjectType m_objectType;

    glm::vec2 m_direction;
    double m_velocity;
    bool m_isActive = true;
    std::vector<Physics::Collider> m_colliders;
};