#pragma once

#include <SFML/Graphics.hpp>

#include "Component.h"

class TextComponent : public Component
{
public :
	TextComponent();
	~TextComponent() override;

	void SetFont(sf::Font _font) { font = _font; }
	void SetColor(sf::Color _color) { color = _color; }
	void SetSize(int _size) { size = _size; }
	void SetText(std::string _name) { name = _name; }

	void LoadFont();
	void CreateText();

	void Render(sf::RenderWindow* _window) override;

private :
	sf::Text text;
	std::string name;
	sf::Font font;
	sf::Color color = sf::Color::White;
	int size;
};