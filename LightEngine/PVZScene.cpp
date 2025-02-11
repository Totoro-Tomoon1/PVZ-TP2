#include "PVZScene.h"
#include <iostream>

//include des entités
#include "Plant.h"
#include "Projectile.h"
#include "Zombie.h"

#include "Debug.h"

void PVZScene::OnInitialize()
{
	mPlant = CreateEntity<Plant>(35, sf::Color::Green);
	mPlant->SetPosition(600, 300);
	//mPlant->SetRigidBody(true);
	mPlant->SetTag((int)Type::Plant);
	mPlant->SetLife(100);
}

void PVZScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		//mPlant->ToShoot();

		//Projectile* bullet = CreateEntity<Projectile>(10, sf::Color::Blue);
		////bullet->SetDirection(event.mouseButton.x - mPlant->GetPosition().x, event.mouseButton.y - mPlant->GetPosition().y);
		//bullet->SetPosition(mPlant->GetPosition().x, mPlant->GetPosition().y);
		//bullet->SetTag((int)Type::Bullet);

		//int speed = 20;

		//bullet->SetSpeed(speed);
		//
		//float dirX = event.mouseButton.x - mPlant->GetPosition().x;
		//float dirY = event.mouseButton.y - mPlant->GetPosition().y;

		//float distance = sqrt(dirX * dirX + dirY * dirY);

		//if (distance != speed)
		//{
		//	float dif = speed / distance;

		//	dirX *= dif;
		//	dirY *= dif;
		//}
		//bullet->SetDirection(dirX, dirY);

		//mBullets.push_back(bullet);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		Zombie* zombie = CreateEntity<Zombie>(25, sf::Color::Red);
		zombie->SetPosition(event.mouseButton.x, event.mouseButton.y);
		zombie->SetDirection(mPlant->GetPosition().x - event.mouseButton.x, mPlant->GetPosition().y - event.mouseButton.y);
		zombie->SetSpeed(0.5);
		zombie->SetRigidBody(true);
		zombie->SetLife(3);
		zombie->SetTag((int)Type::Zombie);

		mZombies.push_back(zombie);
	}
}

void PVZScene::OnUpdate()
{
	for (int i = mZombies.size() - 1; i >= 0; i--)
	{
		if (mZombies[i]->GetHP() <= 0)
		{
			mZombies.erase(mZombies.begin() + i);
		}
	}
}

std::vector<Zombie*> PVZScene::GetZombie()
{
	return mZombies;
}
