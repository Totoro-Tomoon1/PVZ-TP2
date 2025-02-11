#include "Shoot.h"
#include "Plant.h"
#include "Zombie.h"
#include "PVZScene.h"
#include "Projectile.h"
#include <iostream>

Shoot::Shoot(Plant* plant, float cooldown) : State(plant)
{
	mShootCooldown = cooldown;
	mShootProgress = 0;
}

void Shoot::Start()
{
	//mShootProgress = mShootCooldown;
}

void Shoot::Update()
{
	mShootProgress -= mPlant->GetDeltaTime();

	std::vector<Zombie*> mZombie = dynamic_cast<PVZScene*>(mPlant->GetScene())->GetZombie();
	//std::cout << mZombie.size() << std::endl;
	if (mZombie.size() == 0)
	{
		mPlant->TransitionTo(mPlant->GetIdle());
		return;
	}

	if (mShootProgress <= 0)
	{
		sf::Vector2f shootDir = sf::Vector2f(mZombie[0]->GetPosition() - mPlant->GetPosition());

		float dirX = mZombie[0]->GetPosition().x - mPlant->GetPosition().x;
		float dirY = mZombie[0]->GetPosition().y - mPlant->GetPosition().y;
		float minDist = sqrt(dirX * dirX + dirY * dirY);

		for (int i = 1; i < mZombie.size(); i++)
		{
			float newX = mZombie[i]->GetPosition().x - mPlant->GetPosition().x;
			float newY = mZombie[i]->GetPosition().y - mPlant->GetPosition().y;

			float newDist = sqrt(newX * newX + newY * newY);

			if (minDist > newDist)
			{
				minDist = newDist;
				shootDir = sf::Vector2f(mZombie[i]->GetPosition() - mPlant->GetPosition());
			}
		}
		Projectile* bullet = mPlant->CreateEntity<Projectile>(10, sf::Color::Blue);
		bullet->SetPosition(mPlant->GetPosition().x, mPlant->GetPosition().y);
		bullet->SetTag(1);

		int speed = 20;

		bullet->SetSpeed(speed);

		if (minDist != speed)
		{
			float dif = speed / minDist;

			shootDir.x *= dif;
			shootDir.y *= dif;
		}
		bullet->SetDirection(shootDir.x, shootDir.y);

		mShootProgress = mShootCooldown;
	}
}
