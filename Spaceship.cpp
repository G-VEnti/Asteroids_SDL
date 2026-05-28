#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) : GameObject(renderer, Vector2(32, 40), Vector2(0, 0))
{
	position = pos;
	rotation = rot;
	scale = scl;

	linearVelocity = Vector2();
	angularVelocity = 0.0f;

	//linearAcceleration = Vector2();
	//angularAcceleration = 0.0f;

	linearDrag = 1.2f;
	angularDrag = 6.0f;

	linearAccFactor = 500.0f;		 // PX / seg²
	angularAccFactor = 1500.0f;	 // Deg / seg²


	linearAcceleration = Vector2(1.2, 1.2);
	angularAcceleration = 1.2;
}

void Spaceship::UpdateMovement(float dt)
{
	linearAcceleration = Vector2();

	if (IM.GetKey(SDLK_w, HOLD))
	{

		Vector2 dir;
		float rotInRad = rotation * (M_PI / 180.0f);
		dir.x = cos(rotInRad);
		dir.y = sin(rotInRad);


		linearAcceleration = dir * linearAccFactor;
	}

	angularAcceleration = 0.f;

	if (IM.GetKey(SDLK_d, HOLD))
	{
		angularAcceleration = angularAccFactor;
	}
	if (IM.GetKey(SDLK_a, HOLD))
	{
		angularAcceleration = -angularAccFactor;
	}

	GameObject::UpdateMovement(dt);
}