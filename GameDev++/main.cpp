#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Matrix.h"
#include "StandardRules.h"
#include "Context.h"

sf::Vector2u windowSize{ 750,750 };
constexpr unsigned TPS = 60;
const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
sf::Vector2f tileSize(30.f, 30.f);

// Rule Sets
// StandardRules
// Rule1
// Rule2

void RunGame(Matrix& matrix)
{
	Context context(std::make_unique<StandardRules>()); // Change Rules for different generation
	context.PerformLogic(matrix);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Cellular Automaton!");
	window.setPosition(sf::Vector2i{ window.getPosition().x,0 });
	window.setFramerateLimit(60);

	auto view = window.getDefaultView();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate
		= sf::Time::Zero;
	sf::Time FrameTime = sf::seconds(1.f / 60.f);

	Matrix matrix = Matrix(25, 25, 50.f); // change seed for different starting pattern
	Context context;
	

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			}
		}
		window.clear();
		RunGame(matrix);
		matrix.DrawMatrix(window);		
		window.display();
	}

	return 0;

}
