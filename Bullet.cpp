#include "Bullet.h"

Bullet::Bullet(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) : GameObject(renderer, Vector2(7, 7), Vector2(33, 31))
{
	position = pos;
	rotation = rot;
	scale = scl;

	Vector2 dir;
	float rotInRad = rotation * (M_PI / 180.0f);
	dir.x = cos(rotInRad);
	dir.y = sin(rotInRad);

	linearVelocity = Vector2(dir.x * speed, dir.y * speed);
	//angularVelocity = 0.0f;

	//linearAcceleration = Vector2();
	//angularAcceleration = 0.0f;

	//linearDrag = 0.f;
	//angularDrag = 0.f;

	//linearAccFactor = 0.f;		 // PX / seg²
	//angularAccFactor = 0.f;	 // Deg / seg²


	//linearAcceleration = Vector2();
	//angularAcceleration = 0.f;

}

void Bullet::UpdateMovement(float dt)
{
	GameObject::UpdateMovement(dt);
}
