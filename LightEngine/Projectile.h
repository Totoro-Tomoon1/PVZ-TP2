#pragma once
#include "Entity.h"
class Projectile :
    public Entity
{
public:
    void OnUpdate() override;
    void OnCollision(Entity* collidedWith) override;
};

