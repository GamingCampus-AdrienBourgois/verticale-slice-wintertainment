#include "Renderer/CircleShapeRenderer.h"

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
	circle.setFillColor(sf::Color::Color(223, 109, 20, 255));
	circle.setPosition(position.x,position.y);
	circle.setRadius(Radius);
	circle.setOrigin(Radius, Radius);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(1);

	_window->draw(circle);
}
