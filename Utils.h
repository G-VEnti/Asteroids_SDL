#pragma once

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 1000


struct  Vector2
{
	float x;
	float y;

	//Constructors
	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}
	
	Vector2 operator+(Vector2 other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator*(float other) {
		return Vector2(x * other, y * other);
	}

};