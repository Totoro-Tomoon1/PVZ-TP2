#pragma once
#include "Scene.h"

class Plant;
class Projectile;
class Zombie;

class PVZScene : public Scene
{
	//Les entites
	Plant* mPlant;

	std::vector<Projectile*> mBullets;
	std::vector<Zombie*> mZombies;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	std::vector<Zombie*> GetZombie();

	enum class Type
	{
		Plant,
		Bullet,
		Zombie,

		Count
	};
};

