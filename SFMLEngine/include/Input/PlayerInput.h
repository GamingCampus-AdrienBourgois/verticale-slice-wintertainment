#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Component.h"
#include "Components/AnimationComponent.h"
#include "Components/SquareCollider.h"
#include "Components/CowTest.h"



class PlayerInput final : public Component
{
public:
	PlayerInput();
	~PlayerInput();

	void Update(float _delta_time);
	void SetAnimationComponent(AnimationComponent* _animationComponent) { animationComponent = _animationComponent; }
	void SetRendererComponent(RendererComponent* _rendererComponent) { rendererComponent = _rendererComponent; }
	void SetSquareCollider(SquareCollider* _squareCollider) { playerCollider = _squareCollider; }

	void SetWalls(std::vector<SquareCollider*> _walls) { walls = _walls; }
	void Die(std::string name, Maths::Vector2f position);
	void DoneReading() { doneReading = true; }

	void WasserEinstellen(std::vector<SquareCollider*> _wasser) { 
		wasser = _wasser; 		
		for (int i = 0; i < wasser.size(); ++i)
		{
			wasserRenderer.push_back(wasser[i]->GetOwner()->GetComponent<RendererComponent>());
		}
	}
	void SetNPC(SquareCollider* _npc) { npcs.push_back(_npc); }
	void SetTotem(SquareCollider* totem) { totems.push_back(totem); }
	
	void SetLeaves(std::vector<GameObject*> _leaves) { 
		for (int i = 0; i < _leaves.size(); i++)
		{
			leaves.push_back(_leaves[i]->GetComponent<CowTest>()->GetWinterCollider());
			leavesRenderer.push_back(_leaves[i]->GetComponent<RendererComponent>());

		}
	}

	void SetCows(std::vector<GameObject*> _cows) {
		for (int i = 0; i < _cows.size(); i++)
		{
			cows.push_back(_cows[i]->GetComponent<CowTest>()->GetAutumnCollider());
			cowsRenderer.push_back(_cows[i]->GetComponent<RendererComponent>());

		}
	}

	void SetRocks(std::vector<SquareCollider*> _rocks) { rocks = _rocks; }


	void CanAct() { canAct = true; }

private:
	float Speed = 150.0f;
	bool canAct = true;
	bool canMove = true;
	bool reading = false;
	bool doneReading = true;

	bool isInWall = false;
	bool wasInWall = false;
	bool schmoove = false;
	bool lookingDown = true;
	bool lookingUp = false;
	bool lookingLeft = false;
	bool lookingRight = false;

	AnimationComponent* animationComponent = nullptr;
	RendererComponent* rendererComponent = nullptr;
	SquareCollider* playerCollider = nullptr;
	std::vector<SquareCollider*> walls;

	std::vector<SquareCollider*> wasser;
	std::vector<RendererComponent*> wasserRenderer;

	std::vector<SquareCollider*> leaves;
	std::vector<RendererComponent*> leavesRenderer;

	std::vector<SquareCollider*> cows;
	std::vector<RendererComponent*> cowsRenderer;


	std::vector<SquareCollider*> npcs;
	std::vector<SquareCollider*> totems;
	std::vector<SquareCollider*> rocks;
};