#include "Fruit.h"


Fruit::Fruit() {
	Vector2f startingPosition(400, 300);
	sprite.setSize(Vector2f(20, 20));
	sprite.setFillColor(Color::Red);
	sprite.setPosition(startingPosition);
}

void Fruit::setPosition(Vector2f newPosition) {
	sprite.setPosition(newPosition);
}

RectangleShape Fruit::getSprite() {
	return sprite;
}