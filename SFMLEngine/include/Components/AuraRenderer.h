#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"
#include "RendererComponent.h"
#include "Snowflake.h"

class AuraRenderer final : public Component
{
public :
	AuraRenderer();
	~AuraRenderer();

	void Update(float _delta_time);
	void Render(sf::RenderWindow* _window) override;
	void SetRendererComponent(RendererComponent* _rendererComponent) { rendererComponent = _rendererComponent; }

	bool IsActive() { return isActive; }
	void Refill();
	float GetRadius() { return Radius; }

	void SwitchActive();

private :
	RendererComponent* rendererComponent = nullptr;

	float Radius = 200;

	float UpdateTimer = 0.05;
	float Timer = 0;
	std::vector<Snowflake*> snowflakes;
	float MaxReserve = 800;
	float Reserve = 800;

	bool isActive = false;
};
