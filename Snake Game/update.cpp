#include "Engine.h"

void Engine::update() {
	if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(speed)).asSeconds()) {
		Vector2f thisSectionPosition = snake[0].getPosition();
		Vector2f lastSectionPosition = thisSectionPosition;

		if (!directionQueue.empty()) {
			switch (snakeDirection) {
			case Direction::UP:
				if (directionQueue.front() != Direction::DOWN) {
					snakeDirection = directionQueue.front();
				}
				break;
			case Direction::DOWN:
				if (directionQueue.front() != Direction::UP) {
					snakeDirection = directionQueue.front();
				}
				break;
			case Direction::LEFT:
				if (directionQueue.front() != Direction::RIGHT) {
					snakeDirection = directionQueue.front();
				}
				break;
			case Direction::RIGHT:
				if (directionQueue.front() != Direction::LEFT) {
					snakeDirection = directionQueue.front();
				}
				break;
			}
			directionQueue.pop_front();

			//Check if we need to grow snake.
			if (sectionsToAdd) {
				addSnakeSection();
				sectionsToAdd--; 
			}

		}
		switch (snakeDirection) {
		case Direction::RIGHT:
			snake[0].setPosition(Vector2f(thisSectionPosition.x += 20, thisSectionPosition.y));
			break;
		case Direction::DOWN:
			snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y += 20));
			break;
		case Direction::LEFT:
			snake[0].setPosition(Vector2f(thisSectionPosition.x -= 20, thisSectionPosition.y));
			break;
		case Direction::UP:
			snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y -= 20));
			break;
		}

		for (int s = 1; s < snake.size(); s++) {
			thisSectionPosition = snake[s].getPosition();
			snake[s].setPosition(lastSectionPosition);
			lastSectionPosition = thisSectionPosition;
		}

		for (auto& s : snake) {
			s.update();
		}

		//Collision detection
		if (snake[0].getShape().getGlobalBounds().intersects(fruit.getSprite().getGlobalBounds())) {
			//Snake hits the apple, add section to snake. Move apple.
			sectionsToAdd += 4;
			moveFruit();
		}

		timeSinceLastMove = Time::Zero;
	} //End of updating snake directions
}