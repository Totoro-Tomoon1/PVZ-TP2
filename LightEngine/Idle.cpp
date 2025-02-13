#include "Idle.h"
#include "Plant.h"
#include "Zombie.h"
#include "PVZScene.h"
#include <iostream>

Idle::Idle(Plant* plant) : State(plant)
{
}

void Idle::Start()
{
}

void Idle::Update()
{
	std::vector<Zombie*> mZombie = dynamic_cast<PVZScene*>(mPlant->GetScene())->GetZombie();

	if (mZombie.size() > 0)
		for (Zombie* zombie : mZombie)
		{
			sf::Vector2f zomPos = zombie->GetPosition();
			sf::Vector2f plantPos = mPlant->GetPosition();

			float distance = sqrt((zomPos.x - plantPos.x) * (zomPos.x - plantPos.x) + (zomPos.y - plantPos.y) * (zomPos.y - plantPos.y));
			//std::cout << distance << std::endl;
			if (distance < 400)
			{
				mPlant->ToShoot();
				return;
			}
		}
}
