#include "TextDisplayer.h"

TextDisplayer::TextDisplayer()
{
	LoadFont();

	box.setFillColor(sf::Color::Black);
	box.setOutlineColor(sf::Color::Yellow);
	box.setOutlineThickness(10);
	box.setSize(sf::Vector2f(820, 200));

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
		float boxx = position.x - 410;
		float boxy = position.y + 100;

		float textx = position.x - 400;
		float texty = position.y + 110;

		box.setPosition(boxx, boxy);
		text.setPosition(textx, texty);

		_window->draw(box);
		_window->draw(text);
	}
}
