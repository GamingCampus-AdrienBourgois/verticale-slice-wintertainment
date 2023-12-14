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
	sf::Sprite* CreateSprite(std::vector<int> _spriteData);
	void SetSprite(int _id) { Sprite = CurrentSprites[_id]; }
	void SetSprite(sf::Sprite* sprite) { Sprite = sprite; }
	std::vector<sf::Sprite*> GetSprites() { return CurrentSprites; }
	void SetCurrentSprites(std::string name) { CurrentSprites = Animation[name]; }
	void SetCows(std::vector<GameObject*> _cows) { cows = _cows; }
	std::vector<GameObject*> GetCows() { return cows; }
	void SetCurrentSeason(int id) { currentSeason = id; }

	void CreateDownSprite(std::vector<int> _spriteData);
	void CreateUpSprite(std::vector<int> _spriteData);
	void CreateLeftSprite(std::vector<int> _spriteData);
	void CreateRightSprite(std::vector<int> _spriteData);
	void InitSprites();

	void SetScale(float _scale) { scale = _scale; }
	void SetOriginX(float originX) { OriginX = originX; }
	void SetOriginY(float originY) { OriginY = originY; }

private:
	sf::Texture* Texture = nullptr;
	sf::Sprite* Sprite = nullptr;

	float scale = 1.0f;
	float OriginX = 0;
	float OriginY = 0;
	std::vector<sf::Sprite*> Sprites;
	std::vector<sf::Sprite*> CurrentSprites;

	int currentSeason = 0;

	std::vector<GameObject*> cows;
	std::map<std::string, std::vector<sf::Sprite*>> Animation;

	std::vector<sf::Sprite*> DownSprites;
	std::vector<sf::Sprite*> UpSprites;
	std::vector<sf::Sprite*> LeftSprites;
	std::vector<sf::Sprite*> RightSprites;

	std::vector<sf::Texture*> Textures;
};
