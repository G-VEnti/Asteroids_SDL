#pragma once

#include "Scene.h"

class MenuScene : public Scene {

private:
	int userInput = 0;
public:
	MenuScene() : Scene() {}
	~MenuScene();

	void Start(SDL_Renderer* rend) override;
	void Update(float dt, SDL_Renderer* rend) override;
	void Render(SDL_Renderer* rend) override {};
	void Exit() override {};

};