#pragma once
#include "Utils.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class GameObject
{
protected:
	
	Vector2 scale;

	SDL_Texture* texture;
	Vector2 size; // width and height
	Vector2 padding; // texture pos

	//Movement
	Vector2 linearVelocity;
	float angularVelocity;

	Vector2 linearAcceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

	float linearAccFactor;
	float angularAccFactor;

	SDL_Texture* CreateTexture(SDL_Renderer* renderer);

	virtual void UpdateMovement(float dt);
public:
	GameObject(SDL_Renderer* renderer, Vector2 txtSize, Vector2 txtPadding);
	void Render(SDL_Renderer* renderer);
	void Update(float dt);

	Vector2 position;
	float rotation;

	Vector2 GetPosition() { return position; }
	float GetRotation() { return rotation; }
};
