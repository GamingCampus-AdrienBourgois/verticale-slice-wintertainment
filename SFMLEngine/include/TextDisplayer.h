#pragma once

#include "Component.h"
#include "Components/TextComponent.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class TextDisplayer : public Component
{
public :
	TextDisplayer();
	~TextDisplayer();

	void Open() { open = true; write = true; text.setString(" "); }
	void Close() { open = false; write = false; }
	void Switch() {
		if (open) { Close(); }
		else { Open(); }
	}

	void LoadFont();

	void Update(float _delta_time);
	void Render(sf::RenderWindow* _window) override;

private :

	sf::Color color;
	std::string name;
	int size = 30;
	bool open = false;
	bool write = false;
	sf::Font font;
	float timer = 0.0;
	float updatetimer = 0.025;

	sf::Text text;
	int currentChar = 0;

	sf::RectangleShape box;
	Maths::Vector2<float> Camera;
};