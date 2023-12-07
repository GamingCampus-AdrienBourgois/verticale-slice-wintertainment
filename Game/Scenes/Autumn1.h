#pragma once

#include "Scene.h"
#include "RendererComponent.h"
#include "PlayerInput.h"
#include "SquareCollider.h"
#include "AuraRenderer.h"
#include "CircleShapeRenderer.h"
#include "ViewComponent.h"

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		GameObject* refill1 = CreateRefill("refill", 400, 400);

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

		SquareCollider* squareCollider = player->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(24);
		squareCollider->SetWidth(24);

		AuraRenderer* auraRenderer = player->CreateComponent<AuraRenderer>();

		PlayerInput* playerInput = player->CreateComponent<PlayerInput>();

		ViewComponent* viewComponent = player->CreateComponent<ViewComponent>();

		return player;
	}

	GameObject* CreateRefill(std::string name, int positionX, int positionY)
	{
		GameObject* refill = CreateGameObject(name);
		refill->SetPosition(Maths::Vector2f(positionX, positionY));

		CircleShapeRenderer* circleShapeRenderer = refill->CreateComponent<CircleShapeRenderer>();
		circleShapeRenderer->SetRadius(24);

		SquareCollider* squareCollider = refill->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(24);
		squareCollider->SetWidth(24);

		return refill;
	}
};