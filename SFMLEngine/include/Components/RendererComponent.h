#pragma once

#include "Component.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class RendererComponent : public Component 
{
public:
	RendererComponent();
	~RendererComponent() override;

	void Render(sf::RenderWindow* _window) override;

	void SetTexture(std::string _texture);
	void CreateSprite(std::vector<int> _spriteData);
	void SetSprite(int _id) { Sprite = Sprites[_id]; }
	void SetScale(float _scale) { scale = _scale; }
	void SetOriginX(float originX) { OriginX = originX; }
	void SetOriginY(float originY) { OriginY = originY; }

private:
	sf::Texture* Texture = nullptr;
	sf::Sprite* Sprite = nullptr;

	bool LookingLeft = false;
	bool LookingRight = false;
	bool LookingUp = false;
	bool LookingDown = true;

	float scale = 1.0f;
	float OriginX = 0;
	float OriginY = 0;
	std::vector<sf::Sprite*> Sprites;
	std::vector<sf::Texture*> Textures;
};
