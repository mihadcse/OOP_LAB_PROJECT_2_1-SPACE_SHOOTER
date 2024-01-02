#include "Powerups.h"

Powerups::Powerups(sf::RenderWindow& window)
{
	//Powerups Create
	if (!powerupTexture.loadFromFile("Image/rocket.png"))
	{
		cout << "Poerups error";
	}
	powerupSprite.setTexture(powerupTexture);

	// Powerups sound
	if (!powerups_buffer.loadFromFile("Audio/fire3.wav"))
	{
		// Handle error
		cout << "Powerups Audio error" << endl;
	}
	powerups_sound.setBuffer(powerups_buffer);
}

void Powerups::createPowerup(sf::RenderWindow& window)
{
	powerups_sound.play();
	//powerupSpritesVect.push_back(powerupSprite);
}

void Powerups::PowerupsCollision(sf::RenderWindow& window)
{

}



