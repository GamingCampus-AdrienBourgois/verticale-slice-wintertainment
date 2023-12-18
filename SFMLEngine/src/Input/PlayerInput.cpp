#include "Input/PlayerInput.h"
#include "Renderer/AuraRenderer.h"
#include "Modules/InputModule.h"
#include "TextDisplayer.h"
#include "Components/SquareCollider.h"
#include "Components/CowTest.h"

PlayerInput::PlayerInput()
{
}

PlayerInput::~PlayerInput()
{
}

void PlayerInput::Update(float _delta_time)
{
	Maths::Vector2<float> position = GetOwner()->GetPosition();
	if (canAct == true)
	{
		Maths::Vector2f OriginalPosition = GetOwner()->GetPosition();
		if (InputModule::GetKeyUp(sf::Keyboard::Z))
		{
			rendererComponent->SetCurrentSprites("UpSprites");
			animationComponent->SetID(0);
			animationComponent->SetPlayOnce(false);
		}
		else if (InputModule::GetKeyUp(sf::Keyboard::S))
		{
			rendererComponent->SetCurrentSprites("DownSprites");
			animationComponent->SetID(0);
			animationComponent->SetPlayOnce(false);
		}
		else if (InputModule::GetKeyUp(sf::Keyboard::Q))
		{
			rendererComponent->SetCurrentSprites("LeftSprites");
			animationComponent->SetID(0);
			animationComponent->SetPlayOnce(false);
		}
		else if (InputModule::GetKeyUp(sf::Keyboard::D))
		{
			rendererComponent->SetCurrentSprites("RightSprites");
			animationComponent->SetID(0);
			animationComponent->SetPlayOnce(false);
		}
		if (canMove == true)
		{
			if (InputModule::GetKey(sf::Keyboard::Z))
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Down * _delta_time * Speed);
				animationComponent->ResetDirection();
				rendererComponent->SetCurrentSprites("GoingUpSprites");
				animationComponent->SetPlayOnce(false);
				lookingDown = true;
				lookingUp = false;
				lookingLeft = false;
				lookingRight = false;
			}
			else if (InputModule::GetKey(sf::Keyboard::S))
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Up * _delta_time * Speed);
				animationComponent->ResetDirection();
				rendererComponent->SetCurrentSprites("GoingDownSprites");
				animationComponent->SetPlayOnce(false);
				lookingDown = false;
				lookingUp = true;
				lookingLeft = false;
				lookingRight = false;
			}
			else if (InputModule::GetKey(sf::Keyboard::Q))
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Left * _delta_time * Speed);
				animationComponent->ResetDirection();
				rendererComponent->SetCurrentSprites("GoingLeftSprites");
				animationComponent->SetPlayOnce(false);
				lookingDown = false;
				lookingUp = false;
				lookingLeft = true;
				lookingRight = false;
			}
			else if (InputModule::GetKey(sf::Keyboard::D))
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Right * _delta_time * Speed);
				animationComponent->ResetDirection();
				rendererComponent->SetCurrentSprites("GoingRightSprites");
				animationComponent->SetPlayOnce(false);
				lookingDown = false;
				lookingUp = false;
				lookingLeft = false;
				lookingRight = true;
			}
		}
		if (InputModule::GetKeyDown(sf::Keyboard::E))
		{
			GetOwner()->GetComponent<AuraRenderer>()->SwitchActive();
		}
		SquareCollider* playerCollider = GetOwner()->GetComponent<SquareCollider>();

		canMove = true;
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
		else
		{
			for (int i = 0; i < wasser.size(); ++i)
			{
				if (SquareCollider::IsColliding(*playerCollider, *wasser[i]))
				{
					schmoove = true;
				}
			}
		}
		if (schmoove == true)
		{
			canMove = false;
			if (lookingUp == true)
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Up * _delta_time * Speed);
			}
			else if (lookingDown == true)
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Down * _delta_time * Speed);
			}
			else if (lookingLeft == true)
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Left * _delta_time * Speed);
			}
			else if (lookingRight == true)
			{
				GetOwner()->SetPosition(position + Maths::Vector2f::Right * _delta_time * Speed);
			}
			schmoove = false;
		}

		std::vector<GameObject*> cows = rendererComponent->GetCows();
		for (int i = 0; i < cows.size(); i++)
		{
			if (rendererComponent->GetCurrentSeason() == 0)
			{
				SquareCollider* cowCollider = cows[i]->GetComponent<CowTest>()->GetWinterCollider();
				if (cowCollider != nullptr && SquareCollider::IsColliding(*cowCollider, *playerCollider))
				{
					GetOwner()->SetPosition(OriginalPosition);
					canMove = true;
				}
			}
			else
			{
				SquareCollider* cowCollider = cows[i]->GetComponent<CowTest>()->GetAutumnCollider();
				if (cowCollider != nullptr && SquareCollider::IsColliding(*cowCollider, *playerCollider))
				{
					GetOwner()->SetPosition(OriginalPosition);
					canMove = true;
				}
			}
		}
		for (int i = 0; i < walls.size(); ++i)
		{
			if (SquareCollider::IsColliding(*playerCollider, *walls[i]))
			{
				GetOwner()->SetPosition(OriginalPosition);
				canMove = true;
			}
		}
		
		for (int i = 0; i < npcs.size(); ++i)
		{
			if (SquareCollider::IsColliding(*playerCollider, *npcs[i]))
			{
				GetOwner()->SetPosition(OriginalPosition);
				canMove = true;
			}
		}
	}
	if (InputModule::GetKeyDown(sf::Keyboard::T))
	{
		GetOwner()->GetSceneOwner()->FindGameObject("textbox")->GetComponent<TextDisplayer>()->Switch();
		canAct = !canAct;
		animationComponent->SwitchPause();
		
	}
	if (InputModule::GetKeyDown(sf::Keyboard::P))
	{
		animationComponent->SetID(0);
		animationComponent->SetPlayOnce(true);
		rendererComponent->SetCurrentSprites("DieSprites");
	}
}
