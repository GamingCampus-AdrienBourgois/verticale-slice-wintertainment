#pragma once

#include "Scene.h"
#include "Components/RendererComponent.h"
#include "Input/PlayerInput.h"
#include "Components/SquareCollider.h"
#include "Renderer/AuraRenderer.h"
#include "Renderer/CircleShapeRenderer.h"
#include "Components/ViewComponent.h"
#include "Components/SeasonComp.h"
#include "Components/CowTest.h"
#include "TextDisplayer.h"
#include "Components/TextComponent.h"
#include "Components/AnimationComponent.h"
#include "Components/AudioComponent.h"
#include "Components/MapComponent.h"

class Autumn1 final : public Scene
{
public :

	Autumn1() : Scene("Autumn1")
	{
		GameObject* map = CreateMap("map2", 0, 0);

		//GameObject* WorldGame = CreateAudio("Music", "Assets/Audio/MusicBackground.ogg");

		std::vector<std::vector<int>> playerDownSprites{ {0,0,24,24},{24,0,24,24 },{48,0,24,24},{72,0,24,24} };
		std::vector<std::vector<int>> playerLeftSprites{ {96,0,24,24},{120,0,24,24 },{144,0,24,24},{168,0,24,24} };
		std::vector<std::vector<int>> playerRightSprites{ {192,0,24,24},{216,0,24,24 },{240,0,24,24},{264,0,24,24} };
		std::vector<std::vector<int>> playerUpSprites{ {288,0,24,24},{312,0,24,24 },{336,0,24,24},{360,0,24,24} };
		std::vector<std::vector<int>> playerGoingDownSprites{ {384,0,24,24},{408,0,24,24 },{432,0,24,24},{456,0,24,24},{480,0,24,24},{504,0,24,24} };
		std::vector<std::vector<int>> playerGoingLeftSprites{ {528,0,24,24},{552,0,24,24 },{576,0,24,24},{600,0,24,24},{624,0,24,24},{648,0,24,24} };
		std::vector<std::vector<int>> playerGoingRightSprites{ {672,0,24,24},{696,0,24,24 },{720,0,24,24},{744,0,24,24},{768,0,24,24},{792,0,24,24} };
		std::vector<std::vector<int>> playerGoingUpSprites{ {816,0,24,24},{840,0,24,24 },{864,0,24,24},{888,0,24,24},{912,0,24,24},{936,0,24,24} };
		std::vector<std::vector<int>> playerDieSprites{ {960,0,24,24},{984,0,24,24 },{1008,0,24,24},{1032,0,24,24}};
		std::vector<std::vector<int>> playerFallSprites{ {1056,0,24,24},{1080,0,24,24 },{1104,0,24,24},{1128,0,24,24},{1152,0,24,24},{1176,0,24,24} };

		std::vector<std::vector<int>> basilSprites{ {5,32,21,31},{37,32,21,31},{69,32,21,31},{101,32,21,31},{133,32,21,31} };
		SquareCollider* basil = CreateNPC("basil", "Assets/Characters/Basil/Idle/Pink_Head_Idle-Sheet.png", basilSprites, 50,60, 0.3);
		
		std::string Tree = "Assets/Objects/TREE-Sheet.png";
		std::string Leaves = "Assets/Objects/Leaf-Sheet.png";
		std::string Rocks = "Assets/Objects/ROCK-Sheet.png";
		std::vector<std::vector<int>> cowSprites{ {0,0,32,32}, {32,0,32,32} };
		std::vector<std::vector<int>> leavesSprites{ {0,0,16,16}, {16,0,16,16} };

		std::vector<std::vector<int>> gridcollider = { 
			{88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 0, 0, 0, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88},
			{88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88}
		};

		std::vector<SquareCollider*> walls = SetWalls(gridcollider, 88);
		

		std::vector<SquareCollider*> wasser = WasserEinstellen(gridcollider, "Assets/Objects/ICE-sheet.png", leavesSprites, 1);

		std::vector<std::vector<int>> refillSprites{ {480,0,32,32}, {448,0,32,32},{416,0,32,32},{384,0,32,32},{352,0,32,32},{320,0,32,32},{288,0,32,32},{256,0,32,32},{224,0,32,32},{192,0,32,32},{160,0,32,32},{128,0,32,32},{96,0,32,32},{64,0,32,32},{32,0,32,32},{0,0,32,32} };
		GameObject* refill1 = CreateRefill("refill1", "Assets/Objects/REFILL-Sheet.png", refillSprites, 48, 192);
		GameObject* refill2 = CreateRefill("refill2", "Assets/Objects/REFILL-Sheet.png", refillSprites, 224, 202);

		std::vector<std::vector<int>> totemSprites{ {0,0,32,32},{32,0,32,32} };
		SquareCollider* totem1 = CreateTotem("totem1", "Assets/Objects/TOTEM-Sheet.png", totemSprites, 216, 124);
		SquareCollider* totem2 = CreateTotem("totem2", "Assets/Objects/TOTEM-Sheet.png", totemSprites, 408, 160);

		std::vector<std::vector<int>> rocksData = { {256,16},{256,32},{256,48},{256,64},{128,64},{144,64},{160,64},{176,64},{192,64},{240,64},{112,112},{112,128},{112,144},{112,160},{112,176},{136,224},{152,224},{168,224},{184,224},{200,224},{216,224},{232,224},{248,224},{264,224},{280,224},{296,224},{120,224},{200,208},{200,192} };
		std::vector<SquareCollider*> rocks = CreateRock("rock", Rocks, leavesSprites, rocksData);

		std::vector<std::vector<int>> treeData = { {120,248},{152,248},{184,248},{216,248},{248,248},{280,248},{312,248},{344,248},{376,248},{88,248},{136,268},{168,268},{200,268},{232,268},{264,268},{296,268},{328,268},{360,268},{396,268},{104,268},{88,288},{120,288},{152,288},{184,288},{216,288},{248,288},{280,288},{312,288},{344,288},{376,288} };
		std::vector<GameObject*> trees = CreateCow("trees", Tree, cowSprites, treeData);
		
		std::vector<std::vector<int>> leavesData = { {128,28},{144,28},{160,28},{176,28},{128,44},{144,44},{160,44},{176,44},{304,140},{304,108},{304,124},{304,60},{304,76},{304,92},{272,28},{288,28},{272,44},{288,44},{304,28},{304,44},{312,224},{328,224},{344,224},{360,224} };
		std::vector<GameObject*> leaves = CreateLeaves("leaves", Leaves, leavesSprites, leavesData);
		
		
		GameObject* player = CreatePlayer("player", "Assets/Characters/Player/Girl-Sheet.png", playerDownSprites, playerLeftSprites, playerRightSprites, playerUpSprites, playerGoingDownSprites, playerGoingLeftSprites, playerGoingRightSprites, playerGoingUpSprites, playerDieSprites, playerFallSprites, 16, 144);


		PlayerInput* playerInput = player->GetComponent<PlayerInput>();
		playerInput->SetWalls(walls);
		playerInput->WasserEinstellen(wasser);
		playerInput->SetNPC(basil);
		playerInput->SetTotem(totem1);
		playerInput->SetTotem(totem2);
		playerInput->SetLeaves(leaves);
		playerInput->SetRocks(rocks);
		playerInput->SetCows(trees);


		GameObject* textbox = CreateTextBox("textbox");
		textbox->GetComponent<TextDisplayer>()->SetPlayer(player);
	}

	GameObject* CreatePlayer(std::string name, std::string texture, std::vector<std::vector<int>> downsprites, std::vector<std::vector<int>> leftsprites, std::vector<std::vector<int>> rightsprites, std::vector<std::vector<int>> upsprites, std::vector<std::vector<int>> goingdownsprites, std::vector<std::vector<int>> goingleftsprites, std::vector<std::vector<int>> goingrightsprites, std::vector<std::vector<int>> goingupsprites, std::vector<std::vector<int>> diesprites, std::vector<std::vector<int>> fallsprites, int positionX, int positionY)
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
		for (int i = 0; i < fallsprites.size(); i++)
		{
			rendererComponent->CreateFallSprite(fallsprites[i]);
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
		squareCollider->SetHeight(6);
		squareCollider->SetWidth(12);
		squareCollider->SetX(8);
		squareCollider->SetY(-6);

		AuraRenderer* auraRenderer = player->CreateComponent<AuraRenderer>();
		auraRenderer->SetRendererComponent(rendererComponent);
		auraRenderer->SetReserve(500);
		auraRenderer->SetRadius(50);

		PlayerInput* playerInput = player->CreateComponent<PlayerInput>();
		playerInput->SetAnimationComponent(animationComponent);
		playerInput->SetRendererComponent(rendererComponent);
		playerInput->SetSquareCollider(squareCollider);

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

	GameObject* CreateRefill(std::string name, std::string texture, std::vector<std::vector<int>> downsprites, int positionX, int positionY)
	{
		GameObject* refill = CreateGameObject(name);
		refill->SetPosition(Maths::Vector2f(positionX, positionY));

		CircleShapeRenderer* circleShapeRenderer = refill->CreateComponent<CircleShapeRenderer>();
		circleShapeRenderer->SetRadius(12);

		RendererComponent* rendererComponent = refill->CreateComponent<RendererComponent>();
		rendererComponent->SetTexture(texture);
		for (int i = 0; i < downsprites.size(); i++)
		{
			rendererComponent->CreateDownSprite(downsprites[i]);
		}
		rendererComponent->InitSprites();
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(1);
		rendererComponent->SetOriginX(16);
		rendererComponent->SetOriginY(16);

		AnimationComponent* animationComponent = refill->CreateComponent<AnimationComponent>();
		animationComponent->SetRendererComponent(rendererComponent);
		animationComponent->SetUpdateTimer(0.05);

		SquareCollider* squareCollider = refill->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(32);
		squareCollider->SetWidth(32);
		squareCollider->SetX(16);
		squareCollider->SetY(16);

		return refill;
	}

	std::vector<GameObject*> CreateCow(std::string name, std::string texture, std::vector<std::vector<int>> sprites, std::vector<std::vector<int>> position)
	{
		std::vector<GameObject*> Cows;
		for (int j = 0;j < position.size();j++)
		{
			GameObject* cow = CreateGameObject(name);
			cow->SetPosition(Maths::Vector2f(position[j][0], position[j][1]));

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

			Cows.push_back(cow);
		}

		return Cows;
	}

	std::vector<SquareCollider*> CreateRock(std::string name, std::string texture, std::vector<std::vector<int>> sprites, std::vector<std::vector<int>> position)
	{
		std::vector<SquareCollider*> rocks;
		for (int j = 0;j < position.size();j++)
		{
			GameObject* rock = CreateGameObject(name);
			rock->SetPosition(Maths::Vector2f(position[j][0], position[j][1]));

			RendererComponent* rendererComponent = rock->CreateComponent<RendererComponent>();
			rendererComponent->SetTexture(texture);
			for (int i = 0; i < sprites.size(); i++)
			{
				rendererComponent->CreateDownSprite(sprites[i]);
			}
			rendererComponent->InitSprites();
			rendererComponent->SetSprite(0);
			rendererComponent->SetScale(1);
			rendererComponent->SetOriginX(8);
			rendererComponent->SetOriginY(8);

			SquareCollider* Collider = rock->CreateComponent<SquareCollider>();
			Collider->SetWidth(16);
			Collider->SetHeight(16);
			Collider->SetX(8);
			Collider->SetY(8);

			CowTest* cowTest = rock->CreateComponent<CowTest>();

			rocks.push_back(Collider);
		}
		return rocks;
	}

	std::vector<GameObject*> CreateLeaves(std::string name, std::string texture, std::vector<std::vector<int>> sprites, std::vector<std::vector<int>> position)
	{
		std::vector<GameObject*> Leaves;
		for (int j = 0;j < position.size();j++)
		{
			GameObject* leaves = CreateGameObject(name);
			leaves->SetPosition(Maths::Vector2f(position[j][0], position[j][1]));

			RendererComponent* rendererComponent = leaves->CreateComponent<RendererComponent>();
			rendererComponent->SetTexture(texture);
			for (int i = 0; i < sprites.size(); i++)
			{
				rendererComponent->CreateDownSprite(sprites[i]);
			}
			rendererComponent->InitSprites();
			rendererComponent->SetSprite(0);
			rendererComponent->SetScale(1);
			rendererComponent->SetOriginX(8);
			rendererComponent->SetOriginY(8);

			SquareCollider* winterCollider = leaves->CreateComponent<SquareCollider>();
			winterCollider->SetWidth(16);
			winterCollider->SetHeight(16);
			winterCollider->SetX(8);
			winterCollider->SetY(8);


			CowTest* cowTest = leaves->CreateComponent<CowTest>();

			cowTest->SetWinterCollider(winterCollider);

			Leaves.push_back(leaves);
		}
		return Leaves;
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

	std::vector<SquareCollider*> WasserEinstellen(std::vector<std::vector<int>> netzkollider, std::string textur, std::vector<std::vector<int>> sprites, int identifizieren)
	{
		std::vector<SquareCollider*> teich;
		for (unsigned int i = 0; i < 20; ++i)
		{
			for (unsigned int j = 0; j < 30; ++j)
			{
				if (netzkollider[i][j] == identifizieren)
				{
					GameObject* wasser = CreateGameObject("wasser");
					wasser->SetPosition(Maths::Vector2f(j*16, i*16-4));

					SquareCollider* wasserKollider = wasser->CreateComponent<SquareCollider>();
					wasserKollider->SetWidth(16);
					wasserKollider->SetHeight(16);
					wasserKollider->SetX(8);
					wasserKollider->SetY(8);

					RendererComponent* renderKomponente = wasser->CreateComponent<RendererComponent>();
					renderKomponente->SetTexture(textur);
					for (int i = 0; i < sprites.size(); i++)
					{
						renderKomponente->CreateDownSprite(sprites[i]);
					}
					renderKomponente->InitSprites();
					renderKomponente->SetSprite(0);
					renderKomponente->SetScale(1);
					renderKomponente->SetOriginX(8);
					renderKomponente->SetOriginY(8);

					CowTest* kuhPrüfen = wasser->CreateComponent<CowTest>();
					kuhPrüfen->SetAutumnCollider(wasserKollider);

					teich.push_back(wasserKollider);
				}
			}
		}
		return teich;
	}
	SquareCollider* CreateTotem(std::string name, std::string texture, std::vector<std::vector<int>> downsprites, int positionX, int positionY)
	{
		GameObject* totem = CreateGameObject(name);
		totem->SetPosition(Maths::Vector2f(positionX, positionY));

		RendererComponent* rendererComponent = totem->CreateComponent<RendererComponent>();
		rendererComponent->SetTexture(texture);
		for (int i = 0; i < downsprites.size(); i++)
		{
			rendererComponent->CreateDownSprite(downsprites[i]);
		}

		rendererComponent->InitSprites();
		rendererComponent->SetSprite(0);
		rendererComponent->SetScale(0.5);
		rendererComponent->SetOriginX(16);
		rendererComponent->SetOriginY(16);

		SquareCollider* squareCollider = totem->CreateComponent<SquareCollider>();
		squareCollider->SetHeight(16);
		squareCollider->SetWidth(14);
		squareCollider->SetX(8);
		squareCollider->SetY(8);

		AuraRenderer* auraRenderer = totem->CreateComponent<AuraRenderer>();
		auraRenderer->SetRendererComponent(rendererComponent);
		auraRenderer->SetReserve(0);
		auraRenderer->SetRadius(150);

		return squareCollider;;
	}
};