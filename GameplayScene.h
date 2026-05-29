#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Utils.h"
#include "Asteroid.h"
#include <iostream>

class GamePlayScene : public Scene {

private:
	std::vector<GameObject*> bullets;
	Spaceship* playerShip = nullptr;
	int round;

public:
	GamePlayScene() : Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt, SDL_Renderer* rend) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

	void AsteroidSpawn(SDL_Renderer* rend, int round);

};