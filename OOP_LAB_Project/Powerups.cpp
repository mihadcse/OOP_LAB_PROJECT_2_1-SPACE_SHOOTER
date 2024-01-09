#include "Powerups.h"

Powerups::Powerups(sf::RenderWindow& window)
{
    try
    {
        // Powerups Create
        if (!powerupTexture.loadFromFile("Image/rocket.png"))
        {
            throw powerup_exception(); // Throws an exception if image loading fails
        }
        powerupSprite.setTexture(powerupTexture);

        // Powerups sound
        if (!powerups_buffer.loadFromFile("Audio/fire3.wav"))
        {
            throw powerup_exception(); // Throws an exception if sound loading fails
        }
        powerups_sound.setBuffer(powerups_buffer);
    }
    catch (const powerup_exception& e)
    {
        cout << "Powerups error: Failed to load resources" << endl;
    }
}

void Powerups::createPowerup(sf::RenderWindow& window)
{
	powerups_sound.play();
	//powerupSpritesVect.push_back(powerupSprite);
}

void Powerups::PowerupsCollision(sf::RenderWindow& window)
{

}



