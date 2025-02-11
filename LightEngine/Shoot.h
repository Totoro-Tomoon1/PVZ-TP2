#pragma once
#include "State.h"

class Shoot : public State
{
	float mShootCooldown;
	float mShootProgress;
public:
	Shoot(Plant* plant, float cooldown);

	void Start() override;
	void Update() override;
};

