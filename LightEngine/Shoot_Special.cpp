#include "Shoot_Special.h"
#include "Zombie.h"
#include <vector>
#include "PVZScene.h"
#include "Plant.h"
#include "Special_Bullet.h"

Shoot_Special::Shoot_Special(Plant* plant, float cooldown) : State(plant)
{
	mShootCooldown = cooldown;
	mShootProgress = 0;
}

void Shoot_Special::Start()
{
}

void Shoot_Special::Update()
{
	mShootProgress -= mPlant->GetDeltaTime();

	std::vector<Zombie*> mZombie = dynamic_cast<PVZScene*>(mPlant->GetScene())->GetZombie();
	//std::cout << mZombie.size() << std::endl;

	bool shoot = false;

	if (mZombie.size() > 0)
		for (Zombie* zombie : mZombie)
		{
			sf::Vector2f zomPos = zombie->GetPosition();
			sf::Vector2f plantPos = mPlant->GetPosition();
			float distance = sqrt((zomPos.x - plantPos.x) * (zomPos.x - plantPos.x) + (zomPos.y - plantPos.y) * (zomPos.y - plantPos.y));
			if (distance < 400)
			{
				shoot = true;
			}
		}

	//std::cout << shoot << std::endl;

	if (mShootProgress <= 0 && shoot)
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
		Special_Bullet* bullet = mPlant->CreateEntity<Special_Bullet>(10, sf::Color::Blue);
		bullet->SetPosition(mPlant->GetPosition().x, mPlant->GetPosition().y);
		bullet->SetTag(1);
		bullet->SetLife(2);

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
	else if (!shoot)
	{
		mPlant->ToIdle();
	}
}
