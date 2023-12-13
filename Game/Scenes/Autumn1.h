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

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		GameObject* refill1 = CreateRefill("refill", 200, 100);

		std::vector<std::vector<int>> playerDownSprites{ {0,0,24,24},{24,0,24,24 },{48,0,24,24},{72,0,24,24} };
		std::vector<std::vector<int>> playerLeftSprites{ {96,0,24,24},{120,0,24,24 },{144,0,24,24},{168,0,24,24} };
		std::vector<std::vector<int>> playerRightSprites{ {192,0,24,24},{216,0,24,24 },{240,0,24,24},{264,0,24,24} };
		std::vector<std::vector<int>> playerUpSprites{ {288,0,24,24},{312,0,24,24 },{336,0,24,24},{360,0,24,24} };
		GameObject* player = CreatePlayer("player", "Assets/Characters/Player/Girl-Sheet.png", playerDownSprites, playerLeftSprites, playerRightSprites, playerUpSprites, 100,100);

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
		rendererComponent->SetScale(2.0);
		rendererComponent->SetOriginX(12);
		rendererComponent->SetOriginY(12);

		AnimationComponent* animationComponent = player->CreateComponent<AnimationComponent>();
		animationComponent->SetRendererComponent(rendererComponent);
		animationComponent->SetUpdateTimer(0.1);

		SquareCollider* squareCollider = player->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(24);
		squareCollider->SetWidth(24);

		AuraRenderer* auraRenderer = player->CreateComponent<AuraRenderer>();

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