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
	Sprite->setOrigin(OriginX, OriginY);
	Sprite->setPosition(position.x, position.y);
	Sprite->setScale(sf::Vector2f(scale, scale));
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

sf::Sprite* RendererComponent::CreateSprite(std::vector<int> _spriteData)
{
	sf::Sprite* sprite = new sf::Sprite();
	sf::IntRect coordonnees(_spriteData[0], _spriteData[1], _spriteData[2], _spriteData[3]);
	sprite->setTexture(*Texture);
	sprite->setTextureRect(coordonnees);

	Sprites.push_back(sprite);
	return(sprite);
}

void RendererComponent::CreateDownSprite(std::vector<int> _spriteData)
{
	sf::Sprite* sprite = nullptr;
	sprite = CreateSprite(_spriteData);
	DownSprites.push_back(sprite);
}

void RendererComponent::CreateUpSprite(std::vector<int> _spriteData)
{
	sf::Sprite* sprite = nullptr;
	sprite = CreateSprite(_spriteData);
	UpSprites.push_back(sprite);
}

void RendererComponent::CreateLeftSprite(std::vector<int> _spriteData)
{
	sf::Sprite* sprite = nullptr;
	sprite = CreateSprite(_spriteData);
	LeftSprites.push_back(sprite);
}

void RendererComponent::CreateRightSprite(std::vector<int> _spriteData)
{
	sf::Sprite* sprite = nullptr;
	sprite = CreateSprite(_spriteData);
	RightSprites.push_back(sprite);
}

void RendererComponent::InitSprites()
{
	CurrentSprites = DownSprites;
	Animation.emplace("DownSprites", DownSprites);
	Animation.emplace("UpSprites", UpSprites);
	Animation.emplace("LeftSprites", LeftSprites);
	Animation.emplace("RightSprites", RightSprites);
}


