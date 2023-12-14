#include "PlayerInput.h"
#include "AuraRenderer.h"
#include "Modules/InputModule.h"
#include "TextDisplayer.h"

PlayerInput::PlayerInput()
{
}

PlayerInput::~PlayerInput()
{
}

void PlayerInput::Update(float _delta_time)
{
	Maths::Vector2<float> position = GetOwner()->GetPosition();
	if (canMove == true)
	{
		Maths::Vector2f OriginalPosition = GetOwner()->GetPosition();
		if (InputModule::GetKey(sf::Keyboard::Z))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Down * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("UpSprites");
		}
		else if (InputModule::GetKey(sf::Keyboard::S))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Up * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("DownSprites");
		}
		else if (InputModule::GetKey(sf::Keyboard::Q))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Left * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("LeftSprites");
		}
		else if (InputModule::GetKey(sf::Keyboard::D))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Right * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("RightSprites");
		}
		if (InputModule::GetKeyDown(sf::Keyboard::E))
		{
			GetOwner()->GetComponent<AuraRenderer>()->SwitchActive();
		}
		for (int i = 0; i < rendererComponent->GetCows().size(); i++)
		{
		}

	}
	if (InputModule::GetKeyDown(sf::Keyboard::T))
	{
		GetOwner()->GetSceneOwner()->FindGameObject("textbox")->GetComponent<TextDisplayer>()->Switch();
		canMove = !canMove;
		animationComponent->SwitchPause();
		
	}
}
