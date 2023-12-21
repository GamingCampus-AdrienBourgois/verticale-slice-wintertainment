#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include "Component.h"
#include "TileMap.h"

class MapComponent : public Component
{
public:
	MapComponent();
	~MapComponent() override;

	void LoadMap();
	void Render(sf::RenderWindow* _window) override;
	void SetName(std::string _name) { name = _name; }

private:
	std::string name;
	TileMap tilemap;
};

