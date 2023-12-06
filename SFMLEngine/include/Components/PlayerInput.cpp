#include "PlayerInput.h"
#include "AuraRenderer.h"

PlayerInput::PlayerInput()
{
}

PlayerInput::~PlayerInput()
{
}

void PlayerInput::Update(float _delta_time)
{
	Maths::Vector2<float> position = GetOwner()->GetPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		GetOwner()->SetPosition(position + Maths::Vector2f::Down * _delta_time * Speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		GetOwner()->SetPosition(position + Maths::Vector2f::Up * _delta_time * Speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		GetOwner()->SetPosition(position + Maths::Vector2f::Left * _delta_time * Speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		GetOwner()->SetPosition(position + Maths::Vector2f::Right * _delta_time * Speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		GetOwner()->GetComponent<AuraRenderer>()->SwitchActive();
	}
}
