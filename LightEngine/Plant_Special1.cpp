#include "Plant_Special1.h"

void Plant_Special1::ToShoot()
{
	if (!TransitionTo(States::Special_Shoot))
		return;
}
