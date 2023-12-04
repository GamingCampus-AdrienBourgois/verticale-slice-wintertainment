#include "Components/TextComponent.h"

#include <SFML/Graphics.hpp>
#include <iostream>

TextComponent::TextComponent()
{
	LoadFont();
}

TextComponent::~TextComponent()
{
}


void TextComponent::LoadFont()
{
    if (!font.loadFromFile("Assets/Indie_Flower/IndieFlower-Regular.ttf"))
    {
        std::cout << "File not found";
    }
}

void TextComponent::Render(sf::RenderWindow* _window)
{
    Component::Render(_window);
    const GameObject* owner = GetOwner();
    const Maths::Vector2<float> position = owner->GetPosition();

    text.setFont(font);
    text.setFillColor(color);
    text.setString(name);
    text.setCharacterSize(size);
    text.setPosition(position.x, position.y);
    _window->draw(text);
}
