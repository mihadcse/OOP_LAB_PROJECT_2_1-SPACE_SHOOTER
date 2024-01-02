#include "Enemy.h"

using namespace std;

Enemy::Enemy(sf::RenderWindow& window)
{
	if (!font2.loadFromFile("Fonts/batmfa__.ttf"))
	{
		// Handle font loading error
	}
	//Enemy create
	if (!EnemyTexture1.loadFromFile("Image/enemy2.png"))
	{
		cout << "Enemy image error" << endl;
	}
	if (!EnemyTexture2.loadFromFile("Image/enemy4.png"))
	{
		cout << "Enemy image error" << endl;
	}
	EnemySprite.setPosition(sf::Vector2f(500, 70));



	//Enemy fire create
	if (!Enemy_fire_texture.loadFromFile("Image/bullet2.png"))
	{
		cout << "enemy fire error!!\n";
	}
	Enemy_fire_sprite.setTexture(Enemy_fire_texture);

	//Enemy text
	enemy_Text.setFont(font2);
	enemy_Text.setString("ENEMY");
	enemy_Text.setPosition(970, 20);
	enemy_Text.setCharacterSize(20);
	enemy_Text.setFillColor(sf::Color::Yellow);
	enemy_Text.setOutlineThickness(2);
	enemy_Text.setOutlineColor(sf::Color::Black);

	//Enemy health text
	enemy_health_text.setFont(font2);
	enemy_health_text.setPosition(945, 50);
	enemy_health_text.setCharacterSize(20);
	enemy_health_text.setFillColor(sf::Color::Green);
	enemy_health_text.setOutlineThickness(2);
	enemy_health_text.setOutlineColor(sf::Color::Black);
}

void Enemy::move(sf::RenderWindow& window)
{
	sf::Vector2f healthBarSize(100, 10);
	EnemyHealthbar.setSize(sf::Vector2f(healthBarSize.x, healthBarSize.y));
	EnemyHealthbar.setFillColor(sf::Color::Transparent);
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

void Enemy::fire(sf::RenderWindow& window)
{
	sf::Time deltaTime = clock.restart();
	float elapsedTime = deltaTime.asSeconds();

	static float timeSinceLastFire = 0.f;
	timeSinceLastFire += elapsedTime;
	if (timeSinceLastFire >= fireInterval) 
	{
		enemy_fire.push_back(make_pair(EnemySprite.getPosition().x, EnemySprite.getPosition().y));
		timeSinceLastFire = 1.2f;
		enemyFireSpriteVect.push_back(Enemy_fire_sprite);
	}
}

void Enemy::draw(sf::RenderWindow& window, int tri)
{
	if (tri == 1 || tri == 6)
	{
		if (tri == 1)
			EnemySprite.setTexture(EnemyTexture1);
		if (tri == 6)
			EnemySprite.setTexture(EnemyTexture2);
		window.draw(EnemyHealthbar);
		window.draw(EnemySprite);
		window.draw(enemy_Text);
		string enemyhealthstring = to_string(enemy_health);
		enemy_health_text.setString("Health - " + enemyhealthstring);
		window.draw(enemy_health_text);
	}
}
