#include "Special_Bullet.h"
#include "Zombie.h"
#include "PVZScene.h"

void Special_Bullet::OnUpdate()
{
	sf::Vector2f pos = GetPosition();
	if (pos.x < 0 || pos.y < 0 || pos.x > GetScene()->GetWindowWidth() || pos.y > GetScene()->GetWindowHeight() || GetHP() <= 0 )
	{
		Destroy();
	}
}

void Special_Bullet::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(2))
	{
		
		if (lastCollide != collidedWith)
		{
			TakeDamage(1);
		}
		lastCollide = collidedWith;
		std::vector<Zombie*> zombies = dynamic_cast<PVZScene*>(GetScene())->GetZombie();

		int nb = 0;

		if (zombies.size() > 0)
		{
			if (zombies[0] == collidedWith && zombies.size() >= 2)
			{
				nb = 1;
			}

			sf::Vector2f shootDir = sf::Vector2f(zombies[nb]->GetPosition() - GetPosition());

			float dirX = zombies[nb]->GetPosition().x - GetPosition().x;
			float dirY = zombies[nb]->GetPosition().y - GetPosition().y;
			float minDist = sqrt(dirX * dirX + dirY * dirY);

			for (int i = 1 + nb; i < zombies.size(); i++)
			{
				float newX = zombies[i]->GetPosition().x - GetPosition().x;
				float newY = zombies[i]->GetPosition().y - GetPosition().y;

				float newDist = sqrt(newX * newX + newY * newY);

				if (minDist > newDist)
				{
					minDist = newDist;
					shootDir = sf::Vector2f(zombies[i]->GetPosition() - GetPosition());
				}
			}
			int speed = 20;

			SetSpeed(speed);

			if (minDist != speed)
			{
				float dif = speed / minDist;

				shootDir.x *= dif;
				shootDir.y *= dif;
			}
			SetDirection(shootDir.x, shootDir.y);
		}
	}
}
