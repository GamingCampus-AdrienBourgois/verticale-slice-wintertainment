#include "CircleShapeRenderer.h"

CircleShapeRenderer::CircleShapeRenderer()
{
}

CircleShapeRenderer::~CircleShapeRenderer()
{
}

void CircleShapeRenderer::Render(sf::RenderWindow* _window)
{
	const auto position = GetOwner()->GetPosition();

	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Cyan);
	circle.setPosition(position.x,position.y);
	circle.setRadius(Radius);
	circle.setOrigin(Radius, Radius);

	_window->draw(circle);
}
