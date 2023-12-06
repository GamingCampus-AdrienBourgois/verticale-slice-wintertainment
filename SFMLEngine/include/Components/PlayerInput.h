#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"



class PlayerInput final : public Component
{
public:
	PlayerInput();
	~PlayerInput();

	void Update(float _delta_time);

private:
	float Speed = 200.0f;
};