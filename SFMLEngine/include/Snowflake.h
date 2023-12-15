#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

class Snowflake
{
public :
	Snowflake(float X, float Y) { positionX = X;positionY = Y; speed = rand() % 200 + 100; }
	~Snowflake(){}

	void Update(float _delta_time) { positionY += _delta_time * speed; }
	void Render(sf::RenderWindow& window) {
		sf::CircleShape shape(2);
		shape.setPosition(positionX, positionY);
		shape.setFillColor(sf::Color::White);
		window.draw(shape);
	}

	float GetX() { return positionX; }
	float GetY() { return positionY; }

private :
	float positionX;
	float positionY;
	float speed;
};
