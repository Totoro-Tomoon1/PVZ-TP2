#include "Plant.h"
#include "State.h"
#include "Idle.h"
#include "Shoot.h"
#include "Shoot_Special.h"
#include "PVZScene.h"
#include "Zombie.h"
#include <iostream>

Plant::Plant()
{
	mSta[0] = new Idle(this);
	mSta[1] = new Shoot(this, 0.5);
	mSta[2] = new Shoot_Special(this, 0.5);

	mState = States::Idle;
}

void Plant::OnUpdate()
{
	if (GetHP() <= 0)
	{
		Destroy();
	}

	State* state = mSta[static_cast<int>(mState)];

	state->Update();
	
	SetPosition(mPosition.x, mPosition.y);
}

void Plant::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(2))
	{
		TakeDamage(1);
	}
}

void Plant::ToIdle()
{
	if (!TransitionTo(States::Idle))
		return;
}

void Plant::ToShoot()
{
	if (!TransitionTo(States::Shoot))
		return;
}

void Plant::SetPermanentePosition(sf::Vector2f pos)
{
	mPosition = pos;
}

bool Plant::TransitionTo(States newState)
{
	int currentStateIndex = static_cast<int>(mState);
	int newStateIndex = static_cast<int>(newState);

	if (mTransitions[newStateIndex][currentStateIndex] == 0)
		return false;

	mState = newState;
	mSta[static_cast<int>(mState)]->Start();

	return true;
}
