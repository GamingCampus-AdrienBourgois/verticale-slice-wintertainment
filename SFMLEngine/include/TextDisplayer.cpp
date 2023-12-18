#include "TextDisplayer.h"
#include "Components/PlayerInput.h"

TextDisplayer::TextDisplayer()
{
	LoadFont();

	box.setFillColor(sf::Color::Black);
	box.setOutlineColor(sf::Color::Yellow);
	box.setOutlineThickness(3);
	box.setSize(sf::Vector2f(220, 50));

	text.setFillColor(sf::Color::White);
	text.setCharacterSize(size);
	text.setFont(font);
	text.setString(" ");
	name = "J'AIME BEAUCOUP LES BURGERS BIEN GRAS ! ! !";
}

TextDisplayer::~TextDisplayer()
{
}

void TextDisplayer::LoadFont()
{
	if (!font.loadFromFile("Assets/Indie_Flower/IndieFlower-Regular.ttf"))
	{
		std::cout << "File not found";
	}

}

void TextDisplayer::Update(float _delta_time)
{
	if (write == true)
	{
		timer += _delta_time;
		if (timer > updatetimer)
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
			text.setString(text.getString() + name[currentChar]);
			currentChar++;
			if (currentChar >= name.size())
			{
				write = false;
				currentChar = 0;
			}
			timer = 0;
		}
	}
}

void TextDisplayer::Render(sf::RenderWindow* _window)
{
	if (open == true)
	{
		Maths::Vector2<float> position = Camera;
		float boxx = position.x - 110;
		float boxy = position.y + 10;

		float textx = position.x - 108;
		float texty = position.y + 11;

		box.setPosition(boxx, boxy);
		text.setPosition(textx, texty);
		text.setScale(0.2, 0.2);

		_window->draw(box);
		_window->draw(text);
	}
}
