#pragma once

#include "Component.h"

class ViewComponent final : public Component
{
public:
	ViewComponent();
	~ViewComponent();

	void Render(sf::RenderWindow* _window) override;
	Maths::Vector2<float> GetCamera() { return Camera; }


private:
	sf::View view;
	Maths::Vector2<float> Camera;
};
