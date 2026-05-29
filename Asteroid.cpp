#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) : GameObject(renderer, Vector2(101, 91), Vector2(154, 0))
{
	position = pos;
	rotation = rot;
	scale = scl;
	speed = (2 + (rand() % (8 - 2))) / 100.f;

	/*Vector2 dir;
	float rotInRad = rotation * (M_PI / 180.0f);
	dir.x = cos(rotInRad);
	dir.y = sin(rotInRad);

	linearVelocity = Vector2(dir.x * speed, dir.y * speed);*/

	Vector2 centerDir;
	centerDir.x = (1500 / 2) - position.x;
	centerDir.y = (1000 / 2) - position.y;

	linearVelocity = centerDir * speed;
	float rotInRad = rotation * (M_PI / 180.0f);
}
