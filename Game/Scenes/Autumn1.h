#pragma once

#include "Scene.h"
#include "RendererComponent.h"
#include "PlayerInput.h"
#include "SquareCollider.h"
#include "AuraRenderer.h"
#include "CircleShapeRenderer.h"
#include "ViewComponent.h"
#include "SeasonComp.h"
#include "CowTest.h"
#include "TextDisplayer.h"
#include "TextComponent.h"

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		GameObject* refill1 = CreateRefill("refill", 200, 100);

		std::vector<std::vector<int>> playerSprites{ {0,0,24,24},{24,0,24,24 },{48,0,24,24},{72,0,24,24} };
		GameObject* player = CreatePlayer("player", "Assets/Characters/Player/Girl-Sheet.png", playerSprites, 100,100);

		std::vector<std::vector<int>> cowSprites{ {0,128,220,128}, {220,128,220,128} };
		GameObject* cow1 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 200, 200);

		GameObject* cow2 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 300, 200);

		GameObject* cow3 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 400, 200);

		GameObject* cow4 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 200, 300);

		GameObject* cow5 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 300, 300);

		GameObject* cow6 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 400, 300);

		GameObject* cow7 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 200, 400);

		GameObject* cow8 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 300, 400);

		GameObject* cow9 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 400, 400);

		GameObject* textbox = CreateTextBox("textbox");
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
		rendererComponent->SetScale(2.0);
		rendererComponent->SetOriginX(12);
		rendererComponent->SetOriginY(12);

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

	GameObject* CreateCow(std::string name, std::string texture, std::vector<std::vector<int>> sprites, int positionX, int positionY)
	{
		GameObject* cow = CreateGameObject(name);
		cow->SetPosition(Maths::Vector2f(positionX, positionY));

		RendererComponent* rendererComponent = cow->CreateComponent<RendererComponent>();
		rendererComponent->SetTexture(texture);
		for (int i = 0; i < sprites.size(); i++)
		{
			rendererComponent->CreateSprite(sprites[i]);
		}
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(0.5);
		rendererComponent->SetOriginX(110);
		rendererComponent->SetOriginY(64);

		CowTest* cowTest = cow->CreateComponent<CowTest>();

		return cow;
	}

	GameObject* CreateTextBox(std::string name)
	{
		GameObject* textbox = CreateGameObject(name);

		TextDisplayer* textDisplayer = textbox->CreateComponent<TextDisplayer>();

		return textbox;
	}
};