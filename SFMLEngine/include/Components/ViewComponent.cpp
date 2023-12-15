#include "ViewComponent.h"

ViewComponent::ViewComponent()
{
}

ViewComponent::~ViewComponent()
{
}

void ViewComponent::Render(sf::RenderWindow* _window)
{
	view.setSize(240, 135);
	Camera = GetOwner()->GetPosition();
	view.setCenter(Camera.x, Camera.y);
	_window->setView(view);
}
