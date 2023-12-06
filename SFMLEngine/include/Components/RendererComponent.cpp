#include "RendererComponent.h"

RendererComponent::RendererComponent()
{
}

RendererComponent::~RendererComponent()
{
	delete Texture;
	Texture = nullptr;
	for (int i = 0; i < Sprites.size(); i++)
	{
		delete Sprites[i];
		Sprites[i] = nullptr;
	}
}

void RendererComponent::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	Sprite->setOrigin(12.0f, 12.0f);
	Sprite->setPosition(position.x, position.y);
	Sprite->setScale(sf::Vector2f(2.0f, 2.0f));
	_window->draw(*Sprite);
}

void RendererComponent::SetTexture(std::string _texture)
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(_texture))
	{
		std::cout << "LOOOOOOOOOOOOL";
	}
	else
	{
		Texture = texture;
	}
}

void RendererComponent::CreateSprite(std::vector<int> _spriteData)
{
	sf::Sprite* sprite = new sf::Sprite();
	sf::IntRect coordonnees(_spriteData[0], _spriteData[1], _spriteData[2], _spriteData[3]);
	sprite->setTexture(*Texture);
	sprite->setTextureRect(coordonnees);

	Sprites.push_back(sprite);
}
