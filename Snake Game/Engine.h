#pragma once

#include "SnakeSection.h"
#include "Fruit.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <deque>

using namespace sf;
using namespace std;

class Engine {
private:
	//Create game window
	Vector2f resolution;
	RenderWindow window;
	const unsigned int FPS = 60;
	static const Time TimePerFrame;

	vector<SnakeSection> snake;

	int snakeDirection;
	deque<int> directionQueue;
	int speed;
	int sectionsToAdd;

	Fruit fruit;

	Time timeSinceLastMove;

public:
	enum Direction {UP, DOWN, LEFT, RIGHT};
	Engine();
	
	void input();
	void addDirection(int newDirection);
	void update();
	void draw();

	void newSnake();
	void addSnakeSection();

	void moveFruit();

	void run();
};

