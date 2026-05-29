#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend)
{
	std::cout << "=== Welcome to Asteroids === \n\n 1 - Start game";

}

void MenuScene::Update(float dt, SDL_Renderer* rend)
{
	do
	{
		std::cin >> userInput;

	} while (userInput != 1);

	finished = true;
	targetScene = "Gameplay";
}