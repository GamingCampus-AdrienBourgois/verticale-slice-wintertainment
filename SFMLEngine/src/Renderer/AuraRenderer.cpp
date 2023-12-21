#include "Renderer/AuraRenderer.h"
#include "Components/SquareCollider.h"
#include "Snowflake.h"

AuraRenderer::AuraRenderer()
{
}

AuraRenderer::~AuraRenderer()
{
}

void AuraRenderer::Update(float _delta_time)
{
	Camera = GetOwner()->GetSceneOwner()->FindGameObject("player")->GetPosition();
	if (Camera.x < 120)
	{
		Camera.x = 120;
	}
	else if (Camera.x > 360)
	{
		Camera.x = 360;
	}
	if (Camera.y < 68)
	{
		Camera.y = 68;
	}
	else if (Camera.y > 252)
	{
		Camera.y = 252;
	}

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
		Reserve -= _delta_time * 250;
		if (Reserve < 0 && MaxReserve!=0)
		{
			SwitchActive();
		}
	}
	GameObject* refill1 = GetOwner()->GetSceneOwner()->FindGameObject("refill1");
	GameObject* refill2 = GetOwner()->GetSceneOwner()->FindGameObject("refill2");

	SquareCollider* refillCollider1 = refill1->GetComponent<SquareCollider>();
	SquareCollider* refillCollider2 = refill2->GetComponent<SquareCollider>();

	SquareCollider* playerCollider = GetOwner()->GetComponent<SquareCollider>();

	if (SquareCollider::IsColliding(*refillCollider1, *playerCollider)|| SquareCollider::IsColliding(*refillCollider2, *playerCollider))
	{
		Refill();
	}
}

void AuraRenderer::Render(sf::RenderWindow* _window)
{
	const auto position = GetOwner()->GetPosition();
	if (isActive)
	{
		sf::CircleShape Zone;
		Zone.setPosition(position.x, position.y);
		Zone.setRadius(Radius);
		Zone.setOrigin(Radius,Radius);
		Zone.setFillColor(sf::Color::Transparent);
		Zone.setOutlineThickness(2);
		Zone.setOutlineColor(sf::Color::White);

		for (int i = 0; i < snowflakes.size();i++)
		{
			snowflakes[i]->Render(*_window);
		}
		_window->draw(Zone);
		
	}
	sf::RectangleShape JaugeOutline;
	JaugeOutline.setSize(sf::Vector2f(10 * MaxReserve / 100, 3));
	JaugeOutline.setPosition(Camera.x + 50, Camera.y - 50);
	JaugeOutline.setFillColor(sf::Color::Transparent);
	JaugeOutline.setOutlineThickness(1);
	JaugeOutline.setOutlineColor(sf::Color::White);

	sf::RectangleShape Jauge;
	Jauge.setSize(sf::Vector2f(10 * Reserve / 100, 3));
	Jauge.setPosition(Camera.x + 50, Camera.y - 50);
	Jauge.setFillColor(sf::Color::Magenta);
	if (MaxReserve != 0)
	{
		_window->draw(Jauge);
		_window->draw(JaugeOutline);

	}
}

void AuraRenderer::Refill()
{
	Reserve = MaxReserve;
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
			rendererComponent->SetCurrentSeason(0);
		}
	}
}
