#include "Player.h"
using namespace std;

Player::Player(sf::RenderWindow& window)
{
	if (!font2.loadFromFile("Fonts/batmfa__.ttf"))
	{
		// Handle font loading error
	}
	// Player Image
	if (!PlayerTexture.loadFromFile("Image/plane2.png"))
	{
		cout << "Player image error" << endl;
	}
	PlayerSprite.setTexture(PlayerTexture);
	PlayerSprite.setPosition(sf::Vector2f(500, 550));

	//Player Fire Create
	if (!Player_fire_texture.loadFromFile("Image/fire1.png"))
	{
		cout << "player fire error!!\n";
	}
	Player_fire_sprite.setTexture(Player_fire_texture);
	//Player_fire_sprite.setPosition(sf::Vector2f(500, 500));

	// Player fire sound
	if (!Player_fire_buffer.loadFromFile("Audio/fire1.wav"))
	{
		// Handle error
		cout << "Player fire Audio error" << endl;
	}
	Player_fire_sound.setBuffer(Player_fire_buffer);
	
	//Player text
	player_Text.setFont(font2);
	player_Text.setString("PLAYER");
	player_Text.setPosition(60, 20);
	player_Text.setCharacterSize(20);
	player_Text.setFillColor(sf::Color::Green);
	player_Text.setOutlineThickness(2);
	player_Text.setOutlineColor(sf::Color::Black);

	//Player health text
	player_health_Text.setFont(font2);
	player_health_Text.setPosition(40, 50);
	player_health_Text.setCharacterSize(20);
	player_health_Text.setFillColor(sf::Color::Green);
	player_health_Text.setOutlineThickness(2);
	player_health_Text.setOutlineColor(sf::Color::Black);

	// Player score text
	player_score_Text.setFont(font2);
	player_score_Text.setPosition(40, 80);
	player_score_Text.setCharacterSize(20);
	player_score_Text.setFillColor(sf::Color::Green);
	player_score_Text.setOutlineThickness(2);
	player_score_Text.setOutlineColor(sf::Color::Black);

	// Player Ammo text
	ammo_Text.setFont(font2);
	ammo_Text.setPosition(40, 110);
	ammo_Text.setCharacterSize(20);
	ammo_Text.setFillColor(sf::Color::Green);
	ammo_Text.setOutlineThickness(2);
	ammo_Text.setOutlineColor(sf::Color::Black);
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

void Player::fire(sf::RenderWindow& window)
{
	// Char_firing
	Player_fire_sound.play();
	player_fire.push_back(make_pair(PlayerSprite.getPosition().x, PlayerSprite.getPosition().y));
	playerFireSpriteVect.push_back(Player_fire_sprite);
}

void Player::draw(sf::RenderWindow& window, int tri)
{
	if (tri == 1)
	{
		window.draw(PlayerHealthbar);
		window.draw(PlayerSprite);
		window.draw(player_Text);

		string playerhealthstring = to_string(player_health);
		player_health_Text.setString("Health - " + playerhealthstring);
		window.draw(player_health_Text);

		string playerscorestring = to_string(point);
		player_score_Text.setString("Points - " + playerscorestring);
		window.draw(player_score_Text);

		string playerammostring = to_string(ammo);
		ammo_Text.setString("Ammo - " + playerammostring);
		window.draw(ammo_Text);
	}
}
