#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "Components/ARendererComponent.h"

class RectangleShapeRenderer : public ARendererComponent
{
public:
	RectangleShapeRenderer();
	~RectangleShapeRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Color color = sf::Color::White;

	sf::RectangleShape* shape = nullptr;
};
