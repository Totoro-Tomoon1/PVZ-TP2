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
		Special_Shoot,

		Count
	};
	static constexpr int StateCount = static_cast<int>(States::Count);

protected:
	State* mSta[StateCount];

	States mState;
	int mTransitions[StateCount][StateCount] =
	{
		//Idle, Shoot, Special_Shoot
		{0,     1,     1}, //Idle
		{1,     0,     0}, //Shoot
		{1,     0,     0} //Special_Shoot
	};

	sf::Vector2f mPosition;

public:
	Plant();

	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;

	void ToIdle();
	virtual void ToShoot();

	void SetPermanentePosition(sf::Vector2f pos);

	bool TransitionTo(States newState);
};

