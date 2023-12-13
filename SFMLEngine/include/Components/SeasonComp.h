#pragma once

#include "Component.h"
#include "SquareCollider.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class SeasonComp : public Component
{
public :
	void SetSeason(int SeasonID)
	{
		currentSeason = SeasonID;
	}
	void SetWinterCollider(SquareCollider* WinterCollider)
	{
		winterCollider = WinterCollider;
	}
	void SetAutumnCollider(SquareCollider* AutumnCollider)
	{
		autumnCollider = AutumnCollider;
	}
	SquareCollider* GetWinterCollider() { return winterCollider; }
	SquareCollider* GetAutumnCollider() { return autumnCollider; }

	void Update(float _delta_time) override;

protected :
	SquareCollider* winterCollider = nullptr;
	SquareCollider* autumnCollider = nullptr;
	SquareCollider* springCollider = nullptr;
	SquareCollider* summerCollider = nullptr;
	int currentSeason;
	// 0 : Winter / 1 : Autumn / 2 : Spring / 3 : Summer
};