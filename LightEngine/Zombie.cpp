#include "Zombie.h"
#include <iostream>

void Zombie::OnUpdate()
{
	if (GetHP() <= 0)
	{
		Destroy();
	}
}

void Zombie::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(1))
		TakeDamage(1);
}
