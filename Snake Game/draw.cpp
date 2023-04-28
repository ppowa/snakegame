#include "Engine.h"

void Engine::draw() {
	window.clear(Color::Black);

	window.draw(fruit.getSprite());

	for (auto& s : snake) {
		window.draw(s.getShape());
	}
	window.display();
}

