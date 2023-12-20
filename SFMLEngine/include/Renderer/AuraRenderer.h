#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"
#include "Components/RendererComponent.h"
#include "Snowflake.h"

class AuraRenderer final : public Component
{
public :
	AuraRenderer();
	~AuraRenderer();

	void Update(float _delta_time);
	void Render(sf::RenderWindow* _window) override;
	void SetRendererComponent(RendererComponent* _rendererComponent) { rendererComponent = _rendererComponent; }
	void SetReserve(float _reserve) { MaxReserve = _reserve; }
	void SetRadius(float _radius) { Radius = _radius; }

	bool IsActive() { return isActive; }
	void Refill();
	float GetRadius() { return Radius; }

	void Activate() { isActive = true;}
	void Deactivate() { isActive = false; }

	void SwitchActive();

private :
	RendererComponent* rendererComponent = nullptr;

	float Radius = 50;

	float UpdateTimer = 0.05;
	float Timer = 0;
	std::vector<Snowflake*> snowflakes;
	float MaxReserve = 500;
	float Reserve = 500;

	bool isActive = false;

	Maths::Vector2<float> Camera;
};
