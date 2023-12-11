#pragma once

#include "Component.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class SeasonComp : public Component
{
public :
	void SetSeason(int SeasonID)
	{
		currentSeason = SeasonID;
	}

	void Update(float _delta_time) override;

protected :

	int currentSeason;
	// 0 : Winter / 1 : Autumn / 2 : Spring / 3 : Summer
};