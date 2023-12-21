#pragma once

#include "Components/SeasonComp.h"
#include "Components/SquareCollider.h"
#include "Renderer/AuraRenderer.h"

class CowTest : public SeasonComp
{
public :
	CowTest();
	~CowTest();

	void Update(float _delta_time);

private :
	bool isPlayer = false;
};