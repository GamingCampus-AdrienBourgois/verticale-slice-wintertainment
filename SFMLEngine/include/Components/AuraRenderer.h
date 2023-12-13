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

	bool IsActive() { return isActive; }
	void Refill();
	float GetRadius() { return Radius; }

	void SwitchActive();

private :
	float Radius = 200;

	float MaxReserve = 800;
	float Reserve = 800;

	bool isActive = false;
};
