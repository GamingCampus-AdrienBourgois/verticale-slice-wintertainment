#include "PlayerInput.h"
#include "AuraRenderer.h"
#include "Modules/InputModule.h"
#include "TextDisplayer.h"
#include "SquareCollider.h"
#include "CowTest.h"

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
		if (InputModule::GetKeyUp(sf::Keyboard::Z))
		{
			rendererComponent->SetCurrentSprites("UpSprites");
			animationComponent->SetID(0);
		}
		else if (InputModule::GetKeyUp(sf::Keyboard::S))
		{
			rendererComponent->SetCurrentSprites("DownSprites");
			animationComponent->SetID(0);
		}
		else if (InputModule::GetKeyUp(sf::Keyboard::Q))
		{
			rendererComponent->SetCurrentSprites("LeftSprites");
			animationComponent->SetID(0);
		}
		else if (InputModule::GetKeyUp(sf::Keyboard::D))
		{
			rendererComponent->SetCurrentSprites("RightSprites");
			animationComponent->SetID(0);
		}
		if (InputModule::GetKey(sf::Keyboard::Z))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Down * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("GoingUpSprites");
		}
		else if (InputModule::GetKey(sf::Keyboard::S))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Up * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("GoingDownSprites");
		}
		else if (InputModule::GetKey(sf::Keyboard::Q))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Left * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("GoingLeftSprites");
		}
		else if (InputModule::GetKey(sf::Keyboard::D))
		{
			GetOwner()->SetPosition(position + Maths::Vector2f::Right * _delta_time * Speed);
			animationComponent->ResetDirection();
			rendererComponent->SetCurrentSprites("GoingRightSprites");
		}
		if (InputModule::GetKeyDown(sf::Keyboard::E))
		{
			GetOwner()->GetComponent<AuraRenderer>()->SwitchActive();
		}
		std::vector<GameObject*> cows = rendererComponent->GetCows();
		SquareCollider* playerCollider = GetOwner()->GetComponent<SquareCollider>();
		for (int i = 0; i < cows.size(); i++)
		{
			if (rendererComponent->GetCurrentSeason() == 0)
			{
				SquareCollider* cowCollider = cows[i]->GetComponent<CowTest>()->GetWinterCollider();
				if (cowCollider != nullptr && SquareCollider::IsColliding(*cowCollider, *playerCollider))
				{
					GetOwner()->SetPosition(OriginalPosition);
				}
			}
			else
			{
				SquareCollider* cowCollider = cows[i]->GetComponent<CowTest>()->GetAutumnCollider();
				if (cowCollider != nullptr && SquareCollider::IsColliding(*cowCollider, *playerCollider))
				{
					GetOwner()->SetPosition(OriginalPosition);
				}
			}
		}
		for (int i = 0; i < walls.size(); ++i)
		{
			if (SquareCollider::IsColliding(*playerCollider, *walls[i]))
			{
				GetOwner()->SetPosition(OriginalPosition);
			}
		}
		if (rendererComponent->GetCurrentSeason() == 1)
		{
			for (int i = 0; i < wasser.size(); ++i)
			{
				if (SquareCollider::IsColliding(*playerCollider, *wasser[i]))
				{
					GetOwner()->SetPosition(OriginalPosition);
				}
			}
		}
		for (int i = 0; i < npcs.size(); ++i)
		{
			if (SquareCollider::IsColliding(*playerCollider, *npcs[i]))
			{
				GetOwner()->SetPosition(OriginalPosition);
			}
		}
	}
	if (InputModule::GetKeyDown(sf::Keyboard::T))
	{
		GetOwner()->GetSceneOwner()->FindGameObject("textbox")->GetComponent<TextDisplayer>()->Switch();
		canMove = !canMove;
		animationComponent->SwitchPause();
		
	}
	if (InputModule::GetKeyDown(sf::Keyboard::P))
	{
		animationComponent->SetID(0);
		rendererComponent->SetCurrentSprites("DieSprites");
	}
}
