#pragma once

class Life
{
protected:
	float mMaxHP;
	float mCurrentHP;

public:
	void SetLife(float hp);

	void TakeDamage(float damage);
	float GetHP();
};