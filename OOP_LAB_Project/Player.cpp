#include "Player.h"

using namespace std;

Player::Player(sf::RenderWindow& window)
{
	if (!PlayerTexture.loadFromFile("Image/plane2.png"))
	{
		cout << "Player image error" << endl;
	}
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setPosition(sf::Vector2f(500, 550));

}

void Player::move(sf::RenderWindow& window)
{
	sf::Vector2f healthBarSize(88, 10);
	PlayerHealthbar.setSize(sf::Vector2f(healthBarSize.x, healthBarSize.y));
	PlayerHealthbar.setFillColor(sf::Color::White);
	PlayerHealthbar.setPosition(PlayerSprite.getPosition().x + 3, PlayerSprite.getPosition().y - 6);

	//LEFT MOVEMENT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (PlayerSprite.getPosition().x >= -5)
		{
			PlayerSprite.move(sf::Vector2f(-0.35, 0));
			PlayerHealthbar.move(sf::Vector2f(-0.35, 0));
		}
	}

	//RIGHT MOVEMENT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (PlayerSprite.getPosition().x <= 1030)
		{
			PlayerSprite.move(sf::Vector2f(0.35, 0));
			PlayerHealthbar.move(sf::Vector2f(0.35, 0));
		}
	}

	//UP MOVEMENT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (PlayerSprite.getPosition().y >= 450)
		{
			PlayerSprite.move(sf::Vector2f(0, -0.35));
			PlayerHealthbar.move(sf::Vector2f(0, -0.35));
		}
	}

	//DOWN MOVEMENT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (PlayerSprite.getPosition().y <= 570)
		{
			PlayerSprite.move(sf::Vector2f(0, 0.35));
			PlayerHealthbar.move(sf::Vector2f(0, 0.35));
		}
	}

}

void Player::fire()
{
}

void Player::draw(sf::RenderWindow& window, int tri)
{
	if (tri == 1)
	{
		window.draw(PlayerHealthbar);
		window.draw(PlayerSprite);
	}
}
