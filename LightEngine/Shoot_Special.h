#pragma once
#include "State.h"

class Shoot_Special : public State
{
	float mShootCooldown;
	float mShootProgress;
public:
	Shoot_Special(Plant* plant, float cooldown);

	void Start() override;
	void Update() override;
};

