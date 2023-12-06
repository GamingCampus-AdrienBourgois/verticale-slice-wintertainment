#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"

class AuraRenderer final : public Component
{
public :
	AuraRenderer();
	~AuraRenderer();

	void Update(float _delta_time);
	void Render(sf::RenderWindow* _window) override;

	void Refill();

	void SwitchActive();

private :
	float Radius = 200;

	float Reserve = 100;

	bool isActive = false;
};
