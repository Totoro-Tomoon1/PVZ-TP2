#include "Zombie.h"
#include <iostream>
#include "PVZScene.h"
#include "Plant.h"
#include "PVZScene.h"

void Zombie::OnUpdate()
{
	if (GetHP() <= 0)
	{
		Destroy();
	}

	std::vector<Plant*> mPlants = dynamic_cast<PVZScene*>(GetScene())->GetPlant();

	if (mPlants.size() > 0)
	{
		sf::Vector2f shootDir = sf::Vector2f(mPlants[0]->GetPosition() - GetPosition());

		float dirX = mPlants[0]->GetPosition().x - GetPosition().x;
		float dirY = mPlants[0]->GetPosition().y - GetPosition().y;
		float minDist = sqrt(dirX * dirX + dirY * dirY);

		for (int i = 1; i < mPlants.size(); i++)
		{
			float newX = mPlants[i]->GetPosition().x - GetPosition().x;
			float newY = mPlants[i]->GetPosition().y - GetPosition().y;

			float newDist = sqrt(newX * newX + newY * newY);

			if (minDist > newDist)
			{
				minDist = newDist;
				shootDir = sf::Vector2f(mPlants[i]->GetPosition() - GetPosition());
			}
		}

		SetDirection(shootDir.x, shootDir.y);
	}
}

void Zombie::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(1))
		TakeDamage(1);
}
