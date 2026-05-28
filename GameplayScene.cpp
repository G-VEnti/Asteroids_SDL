#include "GameplayScene.h"



void GamePlayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);

	objects.push_back(new Spaceship(rend, Vector2(250,250), 0, Vector2(1,1)));

}

void GamePlayScene::Update(float dt)  {
	Scene::Update(dt);



}

void GamePlayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);
}

void GamePlayScene::Exit() {

}