#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"
#include "AnimationComponent.h"



class PlayerInput final : public Component
{
public:
	PlayerInput();
	~PlayerInput();

	void Update(float _delta_time);
	void SetAnimationComponent(AnimationComponent* _animationComponent) { animationComponent = _animationComponent; }
	void SetRendererComponent(RendererComponent* _rendererComponent) { rendererComponent = _rendererComponent; }

private:
	float Speed = 200.0f;
	bool canMove = true;

	AnimationComponent* animationComponent = nullptr;
	RendererComponent* rendererComponent = nullptr;
};