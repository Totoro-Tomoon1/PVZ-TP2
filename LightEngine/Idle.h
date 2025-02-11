#pragma once
#include "State.h"

class Idle : public State
{
public:
	Idle(Plant* plant);

	void Start() override;
	void Update() override;
};

