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
#include "AnimationComponent.h"
#include "MapComponent.h"

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		GameObject* map = CreateMap("map", 0, 0);

		GameObject* refill1 = CreateRefill("refill", 200, 100);

		std::vector<std::vector<int>> playerDownSprites{ {4,0,16,24},{28,0,16,24 },{52,0,16,24},{76,0,16,24} };
		std::vector<std::vector<int>> playerLeftSprites{ {100,0,16,24},{124,0,16,24 },{148,0,16,24},{172,0,16,24} };
		std::vector<std::vector<int>> playerRightSprites{ {196,0,16,24},{220,0,16,24 },{244,0,16,24},{268,0,16,24} };
		std::vector<std::vector<int>> playerUpSprites{ {292,0,16,24},{316,0,16,24 },{340,0,16,24},{364,0,16,24} };
		GameObject* player = CreatePlayer("player", "Assets/Characters/Player/Girl-Sheet.png", playerDownSprites, playerLeftSprites, playerRightSprites, playerUpSprites, 100, 100);

		std::vector<std::vector<int>> cowSprites{ {10,139,204,120}, {230,139,204,120} };
		GameObject* cow1 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 200, 200);

		GameObject* cow2 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 300, 200);

		GameObject* cow3 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 400, 200);

		GameObject* cow4 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 200, 300);

		GameObject* cow5 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 300, 300);

		GameObject* cow6 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 400, 300);

		GameObject* cow7 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 200, 400);

		GameObject* cow8 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 300, 400);

		GameObject* cow9 = CreateCow("cow", "Assets/Characters/NKC/NKC.png", cowSprites, 400, 400);

		std::vector<GameObject*> cows = { cow1, cow2, cow3, cow4, cow5, cow6, cow7,cow8,cow9 };

		player->GetComponent<RendererComponent>()->SetCows(cows);

		GameObject* textbox = CreateTextBox("textbox");
	}

	GameObject* CreatePlayer(std::string name, std::string texture, std::vector<std::vector<int>> downsprites, std::vector<std::vector<int>> leftsprites, std::vector<std::vector<int>> rightsprites, std::vector<std::vector<int>> upsprites, int positionX, int positionY)
	{
		GameObject* player = CreateGameObject(name);
		player->SetPosition(Maths::Vector2f(positionX, positionY));

		RendererComponent* rendererComponent = player->CreateComponent<RendererComponent>();
		rendererComponent->SetTexture(texture);
		for (int i = 0; i < downsprites.size(); i++)
		{
			rendererComponent->CreateDownSprite(downsprites[i]);
		}
		for (int i = 0; i < leftsprites.size(); i++)
		{
			rendererComponent->CreateLeftSprite(leftsprites[i]);
		}
		for (int i = 0; i < rightsprites.size(); i++)
		{
			rendererComponent->CreateRightSprite(rightsprites[i]);
		}
		for (int i = 0; i < upsprites.size(); i++)
		{
			rendererComponent->CreateUpSprite(upsprites[i]);
		}
		rendererComponent->InitSprites();
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(1);
		rendererComponent->SetOriginX(8);
		rendererComponent->SetOriginY(12);

		AnimationComponent* animationComponent = player->CreateComponent<AnimationComponent>();
		animationComponent->SetRendererComponent(rendererComponent);
		animationComponent->SetUpdateTimer(0.1);

		SquareCollider* squareCollider = player->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(24);
		squareCollider->SetWidth(16);
		squareCollider->SetX(12);
		squareCollider->SetY(8);

		AuraRenderer* auraRenderer = player->CreateComponent<AuraRenderer>();
		auraRenderer->SetRendererComponent(rendererComponent);

		PlayerInput* playerInput = player->CreateComponent<PlayerInput>();
		playerInput->SetAnimationComponent(animationComponent);
		playerInput->SetRendererComponent(rendererComponent);

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
		squareCollider->SetX(0);
		squareCollider->SetY(0);

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
			rendererComponent->CreateDownSprite(sprites[i]);
		}
		rendererComponent->InitSprites();
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(0.5);
		rendererComponent->SetOriginX(102);
		rendererComponent->SetOriginY(60);

		SquareCollider* autumnCollider = cow->CreateComponent<SquareCollider>();
		autumnCollider->SetWidth(102);
		autumnCollider->SetHeight(60);
		autumnCollider->SetX(61);
		autumnCollider->SetY(30);


		CowTest* cowTest = cow->CreateComponent<CowTest>();

		cowTest->SetAutumnCollider(autumnCollider);

		return cow;
	}

	GameObject* CreateTextBox(std::string name)
	{
		GameObject* textbox = CreateGameObject(name);

		TextDisplayer* textDisplayer = textbox->CreateComponent<TextDisplayer>();

		return textbox;
	}

	GameObject* CreateMap(std::string name, float positionX, float positionY)
	{
		GameObject* map = CreateGameObject(name);
		map->SetPosition(Maths::Vector2f(positionX, positionY));

		MapComponent* mapComponent = map->CreateComponent<MapComponent>();
		mapComponent->SetName(name);
		mapComponent->LoadMap();

		return map;
	}
};