#include "Engine.h"

void Engine::input() {
	Event event{};

	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		}

		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == Keyboard::W)
			{
				addDirection(Direction::UP);
			}
			if (event.key.code == Keyboard::S)
			{
				addDirection(Direction::DOWN);
			}
			if (event.key.code == Keyboard::A)
			{
				addDirection(Direction::LEFT);
			}
			if (event.key.code == Keyboard::D)
			{
				addDirection(Direction::RIGHT);
			}

		}
	}
}

void Engine::addDirection(int newDirection) {
	if (directionQueue.empty()) {
		directionQueue.emplace_back(newDirection);
	}
	else {
		if (directionQueue.back() != newDirection) {
			directionQueue.emplace_back(newDirection);
		}
	}
}