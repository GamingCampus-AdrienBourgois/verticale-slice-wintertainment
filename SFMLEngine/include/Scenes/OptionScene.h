#pragma once

#include "Scene.h"
#include "Components/TextComponent.h"
#include "Input/MenuInput.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class OptionScene final : public Scene
{
public:
	OptionScene() : Scene("MenuScene")
	{
		GameObject* Resize = CreateButton(sf::Color::Green, "Resize", 50, 350, 100);
		GameObject* Volume = CreateButton(sf::Color::White, "Settings", 50, 350, 200);
		GameObject* Credit = CreateButton(sf::Color::White, "Credit", 50, 350, 300);
		GameObject* Quit = CreateButton(sf::Color::White, "Quit", 50, 350, 400);
		GameObject* Option = CreateOption();
	}

	GameObject* CreateButton(sf::Color color, std::string name, int size, int positionX, int positionY)
	{
		GameObject* text = CreateGameObject(name);
		text->SetPosition(Maths::Vector2f(positionX, positionY));

		TextComponent* textComponent = text->CreateComponent<TextComponent>();
		textComponent->SetText(name);
		textComponent->SetSize(size);
		textComponent->SetColor(color);

		option.push_back(text);

		return text;
	}

	GameObject* CreateOption()
	{
		GameObject* _option = CreateGameObject("Option");
		MenuInput* optionInput = _option->CreateComponent<MenuInput>();
		optionInput->SetMenu(option);


		return _option;
	}

private:
	std::vector<GameObject*> option;
};