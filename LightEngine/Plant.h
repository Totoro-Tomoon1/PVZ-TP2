#pragma once
#include "Entity.h"
#include "Life.h"

class State;

class Plant : public Entity, public Life
{
public:
	enum class States
	{
		Idle,
		Shoot,

		Count
	};
	static constexpr int StateCount = static_cast<int>(States::Count);

private:
	State* mSta[StateCount];

	States mState;
	int mTransitions[StateCount][StateCount] =
	{
		//Idle, Shoot
		{0,     1}, //Idle
		{1,     0}  //Shoot
	};

public:
	Plant();

	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;

	void ToIdle();
	void ToShoot();

	bool TransitionTo(States newState);

	States GetShoot();
	States GetIdle();
};

