#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"
#include "AnimationComponent.h"
#include "SquareCollider.h"



class PlayerInput final : public Component
{
public:
	PlayerInput();
	~PlayerInput();

	void Update(float _delta_time);
	void SetAnimationComponent(AnimationComponent* _animationComponent) { animationComponent = _animationComponent; }
	void SetRendererComponent(RendererComponent* _rendererComponent) { rendererComponent = _rendererComponent; }
	void SetWalls(std::vector<SquareCollider*> _walls) { walls = _walls; }
	void WasserEinstellen(std::vector<SquareCollider*> _wasser) { wasser = _wasser; }

private:
	float Speed = 100.0f;
	bool canMove = true;

	AnimationComponent* animationComponent = nullptr;
	RendererComponent* rendererComponent = nullptr;
	std::vector<SquareCollider*> walls;
	std::vector<SquareCollider*> wasser;
};