#pragma once
#include "GameObject.h"

class Asteroid : public GameObject
{
public:
	Asteroid(SDL_Renderer* renderer, Vector2 pos, float rotation, Vector2 scale);
	~Asteroid();

private:
	float speed = 0.f;
};