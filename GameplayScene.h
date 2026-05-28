#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Utils.h"

class GamePlayScene : public Scene {

private:
	std::vector<GameObject*> bullets;

public:
	GamePlayScene() : Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt, SDL_Renderer* rend) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;

};