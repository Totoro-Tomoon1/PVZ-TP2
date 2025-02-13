#pragma once
#include "Scene.h"
#include <vector>
#include "fstream"

class Plant;
class Projectile;
class Zombie;

class PVZScene : public Scene
{
	//Les entites

	std::vector<Plant*> mPlants;

	std::vector<Projectile*> mBullets;
	std::vector<Zombie*> mZombies;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	std::vector<Zombie*> GetZombie();
	std::vector<Plant*> GetPlant();


	enum class Type
	{
		Plant,
		Bullet,
		Zombie,

		Count
	};
};

