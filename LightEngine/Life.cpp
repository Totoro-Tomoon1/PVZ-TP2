#include "Life.h"

void Life::SetLife(float hp)
{
	mMaxHP = hp;
	mCurrentHP = hp;
}

void Life::TakeDamage(float damage)
{
	mCurrentHP -= damage;
}

float Life::GetHP()
{
	return mCurrentHP;
}