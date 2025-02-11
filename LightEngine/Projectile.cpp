#include "Projectile.h"
#include "Scene.h"
#include <iostream>

void Projectile::OnUpdate()
{
	sf::Vector2f pos = GetPosition();
	if (pos.x < 0 || pos.y < 0 || pos.x > GetScene()->GetWindowWidth() || pos.y > GetScene()->GetWindowHeight())
	{
		Destroy();
	}
}

void Projectile::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(2))
		Destroy();
}
