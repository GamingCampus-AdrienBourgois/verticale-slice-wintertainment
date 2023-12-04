#pragma once

#include <SFML/Graphics.hpp>

#include "Component.h"
#include "TextComponent.h"

class MenuInput : public Component
{
public :
	MenuInput();
	~MenuInput() override;

	void SetMenu(std::vector < GameObject*> _menu) { menu = _menu; }
	void Update(float _delta_time);

private :
	std::vector<GameObject*> menu;
	int SelectedMenu = 0;
};