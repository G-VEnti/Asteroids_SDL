#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject
{
public:
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rotation, Vector2 scale);
	~Spaceship();


	void LooseLife();

	bool GetInvulnerable() { return invulnerable; }
	int GetSpaceshipLives() { return lives; }
	int GetScore() { return score; }

	void SetInvulnerable() { invulnerable = false; }
	void SetScore();
private:

	int lives = 3;
	int score = 0;
	bool invulnerable = false;
	void UpdateMovement(float dt) override;


};
