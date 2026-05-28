#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject
{
public:
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rotation, Vector2 scale);
	~Spaceship();

private:

	void UpdateMovement(float dt) override;

};
