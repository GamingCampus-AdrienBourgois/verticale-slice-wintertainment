#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"
#include "Components/AnimationComponent.h"
#include "Components/SquareCollider.h"



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
	void SetNPC(SquareCollider* _npc) { npcs.push_back(_npc); }
	void SetTotem(SquareCollider* totem) { totems.push_back(totem); }
	void SetLeaves(std::vector<GameObject*> _leaves) { leaves = _leaves; }


	void CanAct() { canAct = true; }

private:
	float Speed = 150.0f;
	bool canAct = true;
	bool canMove = true;

	bool isInWall = false;
	bool wasInWall = false;
	bool schmoove = false;
	bool lookingDown = true;
	bool lookingUp = false;
	bool lookingLeft = false;
	bool lookingRight = false;

	AnimationComponent* animationComponent = nullptr;
	RendererComponent* rendererComponent = nullptr;
	std::vector<SquareCollider*> walls;
	std::vector<SquareCollider*> wasser;
	std::vector<GameObject*> leaves;
	std::vector<SquareCollider*> npcs;
	std::vector<SquareCollider*> totems;
};