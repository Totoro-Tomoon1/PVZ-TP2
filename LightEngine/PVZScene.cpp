#include "PVZScene.h"
#include <iostream>

//include des entités
#include "Plant.h"
#include "Plant_Classique.h"
#include "Plant_Special1.h"
#include "Projectile.h"
#include "Zombie.h"

#include "Debug.h"

void PVZScene::OnInitialize()
{
	Plant* plant = CreateEntity<Plant_Classique>(35, sf::Color::Green);
	plant->SetPosition(600, 300);
	plant->SetPermanentePosition(plant->GetPosition());
	plant->SetTag((int)Type::Plant);
	plant->SetLife(100);
	plant->SetRigidBody(true);

	Plant* plant1 = CreateEntity<Plant_Special1>(35, sf::Color::Green);
	plant1->SetPosition(670, 300);
	plant1->SetPermanentePosition(plant1->GetPosition());
	plant1->SetTag((int)Type::Plant);
	plant1->SetLife(100);
	plant1->SetRigidBody(true);

	Plant* plant2 = CreateEntity<Plant_Classique>(35, sf::Color::Green);
	plant2->SetPosition(635, 370);
	plant2->SetPermanentePosition(plant2->GetPosition());
	plant2->SetTag((int)Type::Plant);
	plant2->SetLife(100);
	plant2->SetRigidBody(true);

	mPlants.push_back(plant);
	mPlants.push_back(plant1);
	mPlants.push_back(plant2);
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

	//if (event.mouseButton.button == sf::Mouse::Button::Right)
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		Zombie* zombie = CreateEntity<Zombie>(25, sf::Color::Red);
		zombie->SetPosition(event.mouseButton.x, event.mouseButton.y);

		if (mPlants.size() > 0)
		{
			sf::Vector2f shootDir = sf::Vector2f(mPlants[0]->GetPosition() - zombie->GetPosition());

			float dirX = mPlants[0]->GetPosition().x - zombie->GetPosition().x;
			float dirY = mPlants[0]->GetPosition().y - zombie->GetPosition().y;
			float minDist = sqrt(dirX * dirX + dirY * dirY);

			for (int i = 1; i < mPlants.size(); i++)
			{
				float newX = mPlants[i]->GetPosition().x - zombie->GetPosition().x;
				float newY = mPlants[i]->GetPosition().y - zombie->GetPosition().y;

				float newDist = sqrt(newX * newX + newY * newY);

				if (minDist > newDist)
				{
					minDist = newDist;
					shootDir = sf::Vector2f(mPlants[i]->GetPosition() - zombie->GetPosition());
				}
			}

			zombie->SetDirection(shootDir.x, shootDir.y);
			zombie->SetSpeed(0.5);
			zombie->SetRigidBody(true);
			zombie->SetLife(3);
			zombie->SetTag((int)Type::Zombie);

			mZombies.push_back(zombie);
		}
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

	for (int i = mPlants.size() - 1; i >= 0; i--)
	{
		if (mPlants[i]->GetHP() <= 0)
		{
			mPlants.erase(mPlants.begin() + i);
		}
	}
}

std::vector<Zombie*> PVZScene::GetZombie()
{
	return mZombies;
}

std::vector<Plant*> PVZScene::GetPlant()
{
	return mPlants;
}