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
	if (reading == false)
	{
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
			if (InputModule::GetKeyDown(sf::Keyboard::K))
			{
				GetOwner()->GetComponent<AuraRenderer>()->SwitchActive();
			}
			canMove = true;

			isInWall = false;

			for (int i = 0; i < wasser.size(); ++i)
			{
				if (wasserRenderer[i]->GetCurrentSeason() == 1)
				{
					if (SquareCollider::IsColliding(*playerCollider, *wasser[i]))
					{
						Die("FallSprites", wasser[i]->GetOwner()->GetPosition());
						break;
					}
				}
				else
				{
					if (SquareCollider::IsColliding(*playerCollider, *wasser[i]))
					{
						schmoove = true;
					}
				}
			}
			for (int i = 0; i < leaves.size(); i++)
			{
				if (leavesRenderer[i]->GetCurrentSeason() == 0)
				{
					if (leaves[i] != nullptr && SquareCollider::IsColliding(*leaves[i], *playerCollider))
					{
						Die("FallSprites", leaves[i]->GetOwner()->GetPosition());
						break;
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

			for (int i = 0; i < cows.size(); i++)
			{
				if (cowsRenderer[i]->GetCurrentSeason() == 1)
				{
					if (cows[i] != nullptr && SquareCollider::IsColliding(*cows[i], *playerCollider))
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
					if (InputModule::GetKeyDown(sf::Keyboard::J))
					{
						GetOwner()->GetSceneOwner()->FindGameObject("textbox")->GetComponent<TextDisplayer>()->Switch();
						reading = !reading;
						animationComponent->SwitchPause();
						doneReading = false;
					}
				}
			}

			for (int i = 0; i < rocks.size(); ++i)
			{
				if (SquareCollider::IsColliding(*playerCollider, *rocks[i]))
				{
					GetOwner()->SetPosition(OriginalPosition);
					canMove = true;
				}
			}

			for (int i = 0; i < totems.size(); ++i)
			{
				if (SquareCollider::IsColliding(*playerCollider, *totems[i]))
				{
					GetOwner()->SetPosition(OriginalPosition);

					canMove = true;
					if (InputModule::GetKeyDown(sf::Keyboard::J))
					{
						if (totems[i]->GetOwner()->GetComponent<AuraRenderer>()->IsActive())
						{
							totems[i]->GetOwner()->GetComponent<RendererComponent>()->SetSprite(0);
							totems[i]->GetOwner()->GetComponent<AuraRenderer>()->Deactivate();

						}
						else
						{
							totems[i]->GetOwner()->GetComponent<RendererComponent>()->SetSprite(1);
							totems[i]->GetOwner()->GetComponent<AuraRenderer>()->Activate();

						}
					}
				}
			}
		}
		if (InputModule::GetKeyDown(sf::Keyboard::R))
		{
			GetOwner()->SetPosition(Maths::Vector2f(16, 144));
			for (int i = 0; i < totems.size(); ++i)
			{
				totems[i]->GetOwner()->GetComponent<AuraRenderer>()->Deactivate();
			}
			canAct = true;
			canMove = true;
			rendererComponent->SetCurrentSprites("DownSprites");
			animationComponent->SetID(0);
			animationComponent->SetPlayOnce(false);
			GetOwner()->GetComponent<AuraRenderer>()->Refill();
		}
	}
	else
	{
		if (doneReading)
		{
			if (InputModule::GetKeyDown(sf::Keyboard::J))
			{
				GetOwner()->GetSceneOwner()->FindGameObject("textbox")->GetComponent<TextDisplayer>()->Switch();
				reading = !reading;
				animationComponent->SwitchPause();
			}
		}
	}
}

void PlayerInput::Die(std::string name, Maths::Vector2f position)
{
	animationComponent->SetID(0);
	animationComponent->SetPlayOnce(true);
	rendererComponent->SetCurrentSprites(name);
	GetOwner()->SetPosition(position);
	canAct = false;
}
