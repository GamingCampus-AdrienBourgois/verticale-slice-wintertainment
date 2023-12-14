#include "AuraRenderer.h"
#include "SquareCollider.h"

AuraRenderer::AuraRenderer()
{
}

AuraRenderer::~AuraRenderer()
{
}

void AuraRenderer::Update(float _delta_time)
{
	if (isActive)
	{
		Reserve -= _delta_time * 25;
		if (Reserve < 0)
		{
			isActive = false;
		}
	}
	GameObject* refill = GetOwner()->GetSceneOwner()->FindGameObject("refill");
	SquareCollider* refillCollider = refill->GetComponent<SquareCollider>();
	SquareCollider* playerCollider = GetOwner()->GetComponent<SquareCollider>();

	if (GetOwner()->GetComponent<SquareCollider>()->IsColliding(*refillCollider, *playerCollider))
	{
		Reserve = MaxReserve;
	}
}

void AuraRenderer::Render(sf::RenderWindow* _window)
{
	if (isActive)
	{
		const auto position = GetOwner()->GetPosition();

		sf::CircleShape Zone;
		Zone.setPosition(position.x, position.y);
		Zone.setRadius(Radius);
		Zone.setOrigin(Radius,Radius);
		Zone.setFillColor(sf::Color::Transparent);
		Zone.setOutlineThickness(5);
		Zone.setOutlineColor(sf::Color::White);

		sf::RectangleShape Jauge;
		Jauge.setSize(sf::Vector2f(40*Reserve/100,10));
		Jauge.setPosition(position.x+24, position.y-24);
		Jauge.setFillColor(sf::Color::Magenta);
		Jauge.setOutlineThickness(1);
		Jauge.setOutlineColor(sf::Color::White);

		_window->draw(Zone);
		_window->draw(Jauge);
	}
}

void AuraRenderer::Refill()
{
}

void AuraRenderer::SwitchActive()
{
	if (isActive)
	{
		isActive = false;
		rendererComponent->SetCurrentSeason(1);
	}
	else
	{
		if (Reserve > 0)
		{
			isActive = true;
		}
		rendererComponent->SetCurrentSeason(0);
	}
}
