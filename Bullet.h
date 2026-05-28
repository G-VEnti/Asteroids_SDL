#pragma once
#include "GameObject.h"
#include "Spaceship.h"

class Bullet : public GameObject
{
public:
	Bullet(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);
	~Bullet();

private:

	float speed = 500.f;
	void UpdateMovement(float dt) override;
};