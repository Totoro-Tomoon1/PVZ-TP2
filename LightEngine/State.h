#pragma once

class Plant;

class State
{
protected:
	Plant* mPlant;

public:
	State(Plant* plant);

	virtual void Start() = 0;
	virtual void Update() = 0;
};

