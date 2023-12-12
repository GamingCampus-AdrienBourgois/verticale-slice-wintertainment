#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"
class MapComponent : public Component
{
public:
	MapComponent();
	~MapComponent() override;

	void LoadMap(std::string _name);
	void Render(sf::RenderWindow* _window) override;

private:
	std::string name;
};

