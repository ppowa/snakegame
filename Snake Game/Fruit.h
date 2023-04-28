#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Fruit
{
private:
	RectangleShape sprite;

public:
	Fruit();

	void setPosition(Vector2f newPosition);
	RectangleShape getSprite();
};

