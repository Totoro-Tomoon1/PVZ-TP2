#pragma once
#include "Entity.h"
#include "Life.h"

class Special_Bullet : public Entity, public Life
{
    Entity* lastCollide = nullptr;
public:
    void OnUpdate() override;
    void OnCollision(Entity* collidedWith) override;
};

