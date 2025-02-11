#pragma once
#include "Entity.h"
#include "Life.h"

class Zombie : public Entity, public Life
{
public:
	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
};

