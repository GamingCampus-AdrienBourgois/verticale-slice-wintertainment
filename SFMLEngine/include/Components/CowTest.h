#pragma once

#include "SeasonComp.h"
#include "SquareCollider.h"
#include "AuraRenderer.h"

class CowTest : public SeasonComp
{
public :
	CowTest();
	~CowTest();

	void Update(float _delta_time);

private :
	bool isPlayer = false;
};