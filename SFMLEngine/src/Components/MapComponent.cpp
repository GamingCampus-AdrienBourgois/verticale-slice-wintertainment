#pragma once 
#include <Components/MapComponent.h>
#include <SFML/Graphics.hpp>
#include <iostream>
MapComponent::MapComponent()
{
	//LoadMap();
}

MapComponent::~MapComponent()
{

}

void MapComponent::LoadMap(std::string _name)
{

}

void MapComponent::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);
	const GameObject* owner = GetOwner();
	const Maths::Vector2<float> position = owner->GetPosition();
}
