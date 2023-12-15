#include "AuraRenderer.h"
#include "SquareCollider.h"
#include "Snowflake.h"

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
		Timer += _delta_time;
		Maths::Vector2f position = GetOwner()->GetPosition();
		if (Timer >= UpdateTimer)
		{
			float positionX = -10000;
			float positionY = -10000;
			while (Maths::Vector2f(positionX, positionY).Distance(position) > Radius)
			{
				positionX = position.x + rand() % 400 - 200;
				positionY = position.y + rand() % 200 - 200;
			}
			Snowflake* _snowflake = new Snowflake(positionX,positionY);
			snowflakes.push_back(_snowflake);
			Timer = 0;
		}
		for (int i = 0; i < snowflakes.size();i++)
		{
			Maths::Vector2f snowflakePosition = Maths::Vector2f(snowflakes[i]->GetX(), snowflakes[i]->GetY());
			if (snowflakePosition.Distance(position) < Radius)
			{
				snowflakes[i]->Update(_delta_time);
			}
			else
			{
				delete snowflakes[i];
				snowflakes.erase(snowflakes.begin()+i);
			}
		}
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

		for (int i = 0; i < snowflakes.size();i++)
		{
			snowflakes[i]->Render(*_window);
		}
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
		snowflakes.clear();
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
