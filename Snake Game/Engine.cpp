#include "Engine.h" 

const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);
 
Engine::Engine() {
	resolution = Vector2f(800, 600);
	window.create(VideoMode(resolution.x, resolution.y), "Snake Game", Style::Default);
	window.setFramerateLimit(FPS);

	speed = 10;
	snakeDirection = Direction::RIGHT;

	timeSinceLastMove = Time::Zero;  
	sectionsToAdd = 0;
	newSnake();
	moveFruit();
}

void Engine::newSnake() {
	snake.clear();
	snake.emplace_back(Vector2f(100, 100));
	snake.emplace_back(Vector2f(80, 100));
	snake.emplace_back(Vector2f(60, 100));
}

void Engine::addSnakeSection() {
	Vector2f newSectionPosition = snake[snake.size() - 1].getPosition();
	snake.emplace_back(newSectionPosition);
}

void Engine::moveFruit() {
	Vector2f FruitResolution = Vector2f(resolution.x / 20 - 2, resolution.y / 20 - 2);
	Vector2f newFruitLocation;
	bool badLocation = false;
	srand(time(nullptr));

	do {
		badLocation = false;
		newFruitLocation.x = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)FruitResolution.x)) * 20;
		newFruitLocation.y = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)FruitResolution.y)) * 20;

		for (auto& s : snake) {
			if (s.getShape().getGlobalBounds().intersects(Rect<float>(newFruitLocation.x, newFruitLocation.y, 20, 20))) {
				badLocation = true;
				break;
			}
		}

	} while (badLocation);
	fruit.setPosition(newFruitLocation);
}

void Engine::run() {
	Clock clock;

	while (window.isOpen()) {
		Time dt = clock.restart();
		timeSinceLastMove += dt;
		
		input();
		update();
		draw();
	}
}

