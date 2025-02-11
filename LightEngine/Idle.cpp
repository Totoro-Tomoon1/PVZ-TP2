#include "Idle.h"
#include "Plant.h"
#include "Zombie.h"
#include "PVZScene.h"

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
		mPlant->TransitionTo(mPlant->GetShoot());
}
