#include "MenuInput.h"
#include "Modules/InputModule.h"
#include <math.h>

MenuInput::MenuInput()
{
}

MenuInput::~MenuInput()
{
}

void MenuInput::Update(float _delta_time)
{
	// si tu appuie sur Z au dessus sur le menu seras en vert
	if (InputModule::GetKeyDown(sf::Keyboard::Z))
	{
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::White);
		SelectedMenu--;
		if (SelectedMenu < 0)
		{
			SelectedMenu = menu.size() - 1;
		}
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::Green);
	}
	// si tu appuie sur S au dessous sur le menu seras en vert
	else if (InputModule::GetKeyDown(sf::Keyboard::S))
	{
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::White);
		SelectedMenu++;
		if (SelectedMenu > menu.size()-1)
		{
			SelectedMenu = 0;
		}
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::Green);
	}
	// si tu appuie sur Enter il t'enverra en fonction de la ou tu es situé en vert
	else if (InputModule::GetKeyDown(sf::Keyboard::Enter))
	{
		if (SelectedMenu == 0)
		{
			
		}
		if (SelectedMenu == 1)
		{

		}
		if (SelectedMenu == 2)
		{

		}
	}
}
