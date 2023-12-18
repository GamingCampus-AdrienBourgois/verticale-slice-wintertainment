#pragma once

#include "Scene.h"
#include "TextComponent.h"
#include "MenuInput.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class OptionScene final : public Scene
{
public:
	OptionScene() : Scene("MenuScene")
	{
		GameObject* Play = CreateButton(sf::Color::Green, "Play", 50, 350, 100);
		GameObject* Settings = CreateButton(sf::Color::White, "Settings", 50, 350, 200);
		GameObject* Quit = CreateButton(sf::Color::White, "Quit", 50, 350, 300);
		GameObject* Menu = CreateMenu();
	}

	GameObject* CreateButton(sf::Color color, std::string name, int size, int positionX, int positionY)
	{
		GameObject* text = CreateGameObject(name);
		text->SetPosition(Maths::Vector2f(positionX, positionY));

		TextComponent* textComponent = text->CreateComponent<TextComponent>();
		textComponent->SetText(name);
		textComponent->SetSize(size);
		textComponent->SetColor(color);

		menu.push_back(text);

		return text;
	}

	GameObject* CreateMenu()
	{
		GameObject* _menu = CreateGameObject("Menu");
		MenuInput* menuInput = _menu->CreateComponent<MenuInput>();
		menuInput->SetMenu(menu);


		return _menu;
	}

private:
	std::vector<GameObject*> menu;
};