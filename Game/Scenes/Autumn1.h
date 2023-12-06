#pragma once

#include "Scene.h"
#include "RendererComponent.h"

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		std::vector<std::vector<int>> playerSprites{ {0,0,24,24},{24,0,24,24 },{48,0,24,24},{72,0,24,24} };
		GameObject* player = CreatePlayer("player", "Assets/Characters/Player/Girl-Sheet.png", playerSprites, 100,100);
	}

	GameObject* CreatePlayer(std::string name, std::string texture, std::vector<std::vector<int>> sprites, int positionX, int positionY)
	{
		GameObject* player = CreateGameObject(name);
		player->SetPosition(Maths::Vector2f(positionX, positionY));

		RendererComponent* rendererComponent = player->CreateComponent<RendererComponent>();
		rendererComponent->SetTexture(texture);
		for (int i = 0; i < sprites.size(); i++)
		{
			rendererComponent->CreateSprite(sprites[i]);
		}
		rendererComponent->SetSprite(0);


		return player;
	}
};