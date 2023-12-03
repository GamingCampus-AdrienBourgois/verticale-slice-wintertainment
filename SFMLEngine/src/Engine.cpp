#include "Engine.h"

#include <imgui.h>
#include <SFML/Graphics/RenderWindow.hpp>

Engine* Engine::instance = nullptr;

Engine* Engine::GetInstance()
{
	if (instance == nullptr)
		instance = new Engine();

	return instance;
}

void Engine::Init() const
{
	moduleManager->CreateDefaultModules();
	moduleManager->Init();
}

void Engine::Run() const
{
	moduleManager->Start();

	while (!shouldQuit)
	{
		moduleManager->Update();
		moduleManager->PreRender();
		moduleManager->Render();
		moduleManager->PostRender();
	}

	moduleManager->Release();
	moduleManager->Finalize();
}
