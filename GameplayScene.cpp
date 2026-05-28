#include "GameplayScene.h"
#include "Asteroid.h"



void GamePlayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);

	Spaceship* ship = new Spaceship(rend, Vector2(750, 500), 0, Vector2(1, 1));

	//objects.push_back(new Spaceship(rend, Vector2(750, 500), 0, Vector2(1, 1)));
	objects.push_back(ship);

	for (int i = 0; i < 3; i++)
	{
		objects.push_back(new Asteroid(rend, Vector2(1100, 100), objects[0]->GetRotation(), Vector2(1, 1)));
	}

}

void GamePlayScene::Update(float dt, SDL_Renderer* rend) {

	//Executes the update function for each item in objects
	Scene::Update(dt, rend);

	//Adds a bullet to the vector
	if (IM.GetKey(SDLK_SPACE, DOWN))
	{
		bullets.push_back(new Bullet(rend, Vector2(objects[0]->GetPosition().x, objects[0]->GetPosition().y), objects[0]->GetRotation(), Vector2(1, 1)));
	}

	/*for (GameObject* var : bullets)
	{
		if (var->position.x < 0 ||
			var->position.x > SCREEN_WIDTH ||
			var->position.y < 0 ||
			var->position.y > SCREEN_HEIGHT)
		{
			delete var;
		}
		else
		{
			var->Update(dt);
		}
	}*/
	for (GameObject* var : bullets)
	{
		var->Update(dt);
	}
}

void GamePlayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);
	for (GameObject* var : bullets)
	{
		var->Render(rend);
	}
}

void GamePlayScene::Exit() {

}