#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ARendererComponent.h"

class CircleShapeRenderer : public Component
{
public:
	CircleShapeRenderer();
	~CircleShapeRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }
	void SetRadius(float _radius) { Radius = _radius; }
	void Render(sf::RenderWindow* _window) override;

private:
	sf::Color color = sf::Color::White;
	float Radius=24;
};

