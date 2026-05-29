#include "GameplayScene.h"


void GamePlayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);

	playerShip = new Spaceship(rend, Vector2(750, 500), 0, Vector2(1, 1));
	objects.push_back(playerShip);

	AsteroidSpawn(rend);

}

void GamePlayScene::Update(float dt, SDL_Renderer* rend) {

	//Executes the update function for each item in objects
	Scene::Update(dt, rend);

	//Adds a bullet to the vector
	if (IM.GetKey(SDLK_SPACE, DOWN))
	{
		std::cout << "Bullet" << std::endl;
		bullets.push_back(new Bullet(rend, Vector2(objects[0]->GetPosition().x, objects[0]->GetPosition().y), objects[0]->GetRotation(), Vector2(1, 1)));
		playerShip->SetInvulnerable();
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

	//Asteroids and spaceship teleport
	playerShip->Teleport();

	for (int i = 1; i < objects.size(); ++i)
	{
		objects[i]->Teleport();
	}


	//Check collision between bullets and asteroids
	for (std::vector<GameObject*>::iterator bulletIt = bullets.begin(); bulletIt != bullets.end(); ) {
		GameObject* bullet = *bulletIt;
		bool bulletErased = false;

		for (int i = 1; i < objects.size(); ++i) {
			GameObject* asteroid = objects[i];

			if (bullet->CheckCollision(asteroid)) {

				delete bullet;
				bulletIt = bullets.erase(bulletIt);
				bulletErased = true;

				delete asteroid;
				objects.erase(objects.begin() + i);

				playerShip->SetScore();

				break;
			}
		}
		if (!bulletErased)
			++bulletIt;
	}

	//Check collision between spaceship and asteroids
	if (!playerShip->GetInvulnerable())
	{
		for (int i = 1; i < objects.size(); ++i) {
			if (playerShip->CheckCollision(objects[i])) {
				playerShip->LooseLife();
				if (playerShip->GetSpaceshipLives() <= 0)
				{
					Exit();
				}
				break;
			}
		}
	}

	//Asteroid respawn
	if (objects.size() < 2)
	{
		AsteroidSpawn(rend);
	}
}

void GamePlayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);
	for (GameObject* var : bullets)
	{
		var->Render(rend);
	}
}

void GamePlayScene::Exit() 
{
	SDL_Quit();
}

void GamePlayScene::AsteroidSpawn(SDL_Renderer* rend)
{
	for (int i = 0; i < 100; i++)
	{
		int randomWidth;
		int randomHeight;
		do
		{
			randomWidth = (-1000) + (rand() % 4500);
			randomHeight = (-1000) + (rand() % 4000);

		} while (randomWidth > -500 && randomWidth < 2000 &&
			randomHeight > -500 && randomHeight < 1500);

		objects.push_back(new Asteroid(rend, Vector2(randomWidth, randomHeight), objects[0]->GetRotation(), Vector2(1, 1)));
	}

	std::cout << "Asteroids spawned" << std::endl;
}
