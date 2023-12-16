#include "Enemy.h"

using namespace std;

Enemy::Enemy(sf::RenderWindow& window)
{
	if (!EnemyTexture.loadFromFile("Image/enemy1.png"))
	{
		cout << "Enemy image error" << endl;
	}
	EnemySprite.setTexture(EnemyTexture);
	EnemySprite.setPosition(sf::Vector2f(500, 70));
}

void Enemy::move(sf::RenderWindow& window)
{
	sf::Vector2f healthBarSize(100, 10);
	EnemyHealthbar.setSize(sf::Vector2f(healthBarSize.x, healthBarSize.y));
	EnemyHealthbar.setFillColor(sf::Color::White);
	EnemyHealthbar.setPosition(EnemySprite.getPosition().x + 10, EnemySprite.getPosition().y + 110);

	if (EnemySprite.getPosition().x <= 0)
	{
		direction = 1;
	}
	else if ((EnemySprite.getPosition().x + 100) >= window.getSize().x)
	{
		direction = 0;
	}

	if (direction == 0) 
	{
		EnemySprite.move(-.2f, 0);//enemy plane speed control
	}
	else
	{
		EnemySprite.move(.2f, 0);//enemy plane speed control
	}
}

void Enemy::fire()
{
}

void Enemy::draw(sf::RenderWindow& window, int tri)
{
	if (tri == 1)
	{
		window.draw(EnemyHealthbar);
		window.draw(EnemySprite);
	}
}
