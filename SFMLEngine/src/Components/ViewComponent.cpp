#include "Components/ViewComponent.h"

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
	if (Camera.x < 120)
	{
		Camera.x = 120;
	}
	else if (Camera.x > 360 )
	{
		Camera.x = 360;
	}
	if (Camera.y < 68)
	{
		Camera.y = 68;
	}
	else if (Camera.y > 252)
	{
		Camera.y = 252;
	}
	view.setCenter(Camera.x, Camera.y);
	_window->setView(view);
}
