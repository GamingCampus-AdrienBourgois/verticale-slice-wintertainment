#include "MenuInput.h"
#include <math.h>

MenuInput::MenuInput()
{
}

MenuInput::~MenuInput()
{
}

void MenuInput::Update(float _delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::White);
		SelectedMenu--;
		if (SelectedMenu < 0)
		{
			SelectedMenu = menu.size() - 1;
		}
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::Green);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::White);
		SelectedMenu++;
		if (SelectedMenu > menu.size()-1)
		{
			SelectedMenu = 0;
		}
		menu[SelectedMenu]->GetComponent<TextComponent>()->SetColor(sf::Color::Green);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
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
