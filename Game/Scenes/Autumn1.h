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
#include "AudioComponent.h"
#include "MapComponent.h"

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		GameObject* map = CreateMap("map", 0, 0);

		//GameObject* WorldGame = CreateAudio("Music", "Assets/Audio/MusicBackground.ogg");
		GameObject* refill1 = CreateRefill("refill", 200, 100);

		std::vector<std::vector<int>> playerDownSprites{ {0,0,24,24},{24,0,24,24 },{48,0,24,24},{72,0,24,24} };
		std::vector<std::vector<int>> playerLeftSprites{ {96,0,24,24},{120,0,24,24 },{144,0,24,24},{168,0,24,24} };
		std::vector<std::vector<int>> playerRightSprites{ {192,0,24,24},{216,0,24,24 },{240,0,24,24},{264,0,24,24} };
		std::vector<std::vector<int>> playerUpSprites{ {288,0,24,24},{312,0,24,24 },{336,0,24,24},{360,0,24,24} };
		std::vector<std::vector<int>> playerGoingDownSprites{ {384,0,24,24},{408,0,24,24 },{432,0,24,24},{456,0,24,24},{480,0,24,24},{504,0,24,24} };
		std::vector<std::vector<int>> playerGoingLeftSprites{ {528,0,24,24},{552,0,24,24 },{576,0,24,24},{600,0,24,24},{624,0,24,24},{648,0,24,24} };
		std::vector<std::vector<int>> playerGoingRightSprites{ {672,0,24,24},{696,0,24,24 },{720,0,24,24},{744,0,24,24},{768,0,24,24},{792,0,24,24} };
		std::vector<std::vector<int>> playerGoingUpSprites{ {816,0,24,24},{840,0,24,24 },{864,0,24,24},{888,0,24,24},{912,0,24,24},{936,0,24,24} };
		std::vector<std::vector<int>> playerDieSprites{ {960,0,24,24},{984,0,24,24 },{1008,0,24,24},{1032,0,24,24}};

		GameObject* player = CreatePlayer("player", "Assets/Characters/Player/Girl-Sheet.png", playerDownSprites, playerLeftSprites, playerRightSprites, playerUpSprites, playerGoingDownSprites, playerGoingLeftSprites, playerGoingRightSprites, playerGoingUpSprites, playerDieSprites, 100, 100);

		std::vector<std::vector<int>> basilSprites{ {5,32,21,31},{37,32,21,31},{69,32,21,31},{101,32,21,31},{133,32,21,31} };
		SquareCollider* basil = CreateNPC("basil", "Assets/Characters/Basil/Idle/Pink_Head_Idle-Sheet.png", basilSprites, 50,60, 0.3);

		std::string Tree = "Assets/Objects/TREE-Sheet.png";
		std::vector<std::vector<int>> cowSprites{ {0,0,32,32}, {32,0,32,32} };
		GameObject* cow11 = CreateCow("cow", Tree, cowSprites, 184, 180);
		GameObject* cow12 = CreateCow("cow", Tree, cowSprites, 216, 180);
		GameObject* cow13 = CreateCow("cow", Tree, cowSprites, 248, 180);
		GameObject* cow14 = CreateCow("cow", Tree, cowSprites, 280, 180);
		GameObject* cow15 = CreateCow("cow", Tree, cowSprites, 312, 180);
		GameObject* cow16 = CreateCow("cow", Tree, cowSprites, 344, 180);
		GameObject* cow17 = CreateCow("cow", Tree, cowSprites, 376, 180);
		GameObject* cow18 = CreateCow("cow", Tree, cowSprites, 408, 180);
		GameObject* cow19 = CreateCow("cow", Tree, cowSprites, 440, 180);
		GameObject* cow1 = CreateCow("cow", Tree, cowSprites, 200, 200);
		GameObject* cow2 = CreateCow("cow", Tree, cowSprites, 232, 200);
		GameObject* cow3 = CreateCow("cow", Tree, cowSprites, 264, 200);
		GameObject* cow4 = CreateCow("cow", Tree, cowSprites, 296, 200);
		GameObject* cow5 = CreateCow("cow", Tree, cowSprites, 328, 200);
		GameObject* cow6 = CreateCow("cow", Tree, cowSprites, 360, 200);
		GameObject* cow7 = CreateCow("cow", Tree, cowSprites, 392, 200);
		GameObject* cow8 = CreateCow("cow", Tree, cowSprites, 424, 200);
		GameObject* cow9 = CreateCow("cow", Tree, cowSprites, 456, 200);
		


		std::vector<GameObject*> cows = { cow1, cow2, cow3, cow4, cow5, cow6, cow7,cow8,cow9,cow11,cow12,cow13,cow14,cow15,cow16,cow17,cow18,cow19 };

		player->GetComponent<RendererComponent>()->SetCows(cows);

		std::vector<std::vector<int>> gridcollider = {
			{142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142 },
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 66, 66, 66, 66, 66, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 66, 66, 66, 66, 66, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 66, 66, 66, 66, 66, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 66, 66, 66, 66, 66, 115, 115, 142},
			{142, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 142},
			{142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142, 142} };

		std::vector<SquareCollider*> walls = SetWalls(gridcollider, 142);

		player->GetComponent<PlayerInput>()->SetWalls(walls);

		std::vector<SquareCollider*> wasser = SetWalls(gridcollider, 66);

		player->GetComponent<PlayerInput>()->WasserEinstellen(wasser);

		player->GetComponent<PlayerInput>()->SetNPC(basil);

		GameObject* textbox = CreateTextBox("textbox");
	}

	GameObject* CreatePlayer(std::string name, std::string texture, std::vector<std::vector<int>> downsprites, std::vector<std::vector<int>> leftsprites, std::vector<std::vector<int>> rightsprites, std::vector<std::vector<int>> upsprites, std::vector<std::vector<int>> goingdownsprites, std::vector<std::vector<int>> goingleftsprites, std::vector<std::vector<int>> goingrightsprites, std::vector<std::vector<int>> goingupsprites, std::vector<std::vector<int>> diesprites, int positionX, int positionY)
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
		for (int i = 0; i < goingdownsprites.size(); i++)
		{
			rendererComponent->CreateGoingDownSprite(goingdownsprites[i]);
		}
		for (int i = 0; i < goingleftsprites.size(); i++)
		{
			rendererComponent->CreateGoingLeftSprite(goingleftsprites[i]);
		}
		for (int i = 0; i < goingrightsprites.size(); i++)
		{
			rendererComponent->CreateGoingRightSprite(goingrightsprites[i]);
		}
		for (int i = 0; i < goingupsprites.size(); i++)
		{
			rendererComponent->CreateGoingUpSprite(goingupsprites[i]);
		}
		for (int i = 0; i < diesprites.size(); i++)
		{
			rendererComponent->CreateDieSprite(diesprites[i]);
		}

		rendererComponent->InitSprites();
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(1);
		rendererComponent->SetOriginX(12);
		rendererComponent->SetOriginY(12);

		AnimationComponent* animationComponent = player->CreateComponent<AnimationComponent>();
		animationComponent->SetRendererComponent(rendererComponent);
		animationComponent->SetUpdateTimer(0.2);

		SquareCollider* squareCollider = player->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(24);
		squareCollider->SetWidth(16);
		squareCollider->SetX(12);
		squareCollider->SetY(12);

		AuraRenderer* auraRenderer = player->CreateComponent<AuraRenderer>();
		auraRenderer->SetRendererComponent(rendererComponent);

		PlayerInput* playerInput = player->CreateComponent<PlayerInput>();
		playerInput->SetAnimationComponent(animationComponent);
		playerInput->SetRendererComponent(rendererComponent);

		ViewComponent* viewComponent = player->CreateComponent<ViewComponent>();

		return player;
	}

	SquareCollider* CreateNPC(std::string name, std::string texture, std::vector<std::vector<int>> downsprites, int positionX, int positionY, float updateTimer)
	{
		GameObject* npc = CreateGameObject(name);
		npc->SetPosition(Maths::Vector2f(positionX, positionY));

		RendererComponent* rendererComponent = npc->CreateComponent<RendererComponent>();
		rendererComponent->SetTexture(texture);
		for (int i = 0; i < downsprites.size(); i++)
		{
			rendererComponent->CreateDownSprite(downsprites[i]);
		}
		rendererComponent->InitSprites();
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(1);
		rendererComponent->SetOriginX(10);
		rendererComponent->SetOriginY(15);

		AnimationComponent* animationComponent = npc->CreateComponent<AnimationComponent>();
		animationComponent->SetRendererComponent(rendererComponent);
		animationComponent->SetUpdateTimer(updateTimer);

		SquareCollider* squareCollider = npc->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(31);
		squareCollider->SetWidth(21);
		squareCollider->SetX(15);
		squareCollider->SetY(10);

		return squareCollider;
	}

	GameObject* CreateRefill(std::string name, int positionX, int positionY)
	{
		GameObject* refill = CreateGameObject(name);
		refill->SetPosition(Maths::Vector2f(positionX, positionY));

		CircleShapeRenderer* circleShapeRenderer = refill->CreateComponent<CircleShapeRenderer>();
		circleShapeRenderer->SetRadius(12);

		SquareCollider* squareCollider = refill->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(12);
		squareCollider->SetWidth(12);
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
		rendererComponent->SetScale(1);
		rendererComponent->SetOriginX(16);
		rendererComponent->SetOriginY(16);

		SquareCollider* autumnCollider = cow->CreateComponent<SquareCollider>();
		autumnCollider->SetWidth(32);
		autumnCollider->SetHeight(32);
		autumnCollider->SetX(16);
		autumnCollider->SetY(16);


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

	GameObject* CreateAudio(std::string name, std::string musicFile)
	{
		GameObject* musicName = CreateGameObject(name);

		AudioComponent* audioComponent = musicName->CreateComponent<AudioComponent>();
		audioComponent->SetMusic(musicFile);
		audioComponent->LoadMusic();

		return musicName;
	}

	std::vector<SquareCollider*> SetWalls(std::vector<std::vector<int>> gridcollider, int id)
	{
		std::vector<SquareCollider*> walls;
		for (unsigned int i = 0; i < 20; ++i)
		{
			for (unsigned int j = 0; j < 30; ++j)
			{
				if (gridcollider[i][j] == id)
				{
					SquareCollider* wall = CreateWalls("wall", j * 16, i * 16);
					walls.push_back(wall);
				}
			}
		}
		return walls;
	}
	SquareCollider* CreateWalls(const std::string& name, float positionX, float positionY)
	{
		GameObject* gameObject = CreateGameObject(name);
		gameObject->SetPosition(Maths::Vector2f(positionX, positionY));

		SquareCollider* collider = gameObject->CreateComponent<SquareCollider>();
		collider->SetWidth(16.0f);
		collider->SetHeight(16.0f);

		return collider;
	}


	GameObject* WasserErzeugen(std::string name, float positionX, float positionY)
	{
		GameObject* wasser = CreateGameObject(name);
		wasser->SetPosition(Maths::Vector2f(positionX, positionY));

		SquareCollider* wasserkollider = wasser->CreateComponent<SquareCollider>();
		wasserkollider->SetWidth(16.0f);
		wasserkollider->SetHeight(16.0f);

		return wasser;
	}
};