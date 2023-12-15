#pragma once 

#include <Components/MapComponent.h>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <iostream>

MapComponent::MapComponent()
{

}

MapComponent::~MapComponent()
{

}

void MapComponent::LoadMap()
{
	if (!tilemap.loadmap(name))
	{
		std::cout << "LA MAAAAAAAAAAAAAAP";
	}
}

void MapComponent::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);
	const GameObject* owner = GetOwner();
	const Maths::Vector2<float> position = owner->GetPosition();
	_window->draw(tilemap);
}
