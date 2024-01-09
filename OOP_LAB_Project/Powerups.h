#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <vector>

using namespace std;

class Powerups 
{
private:
    sf::SoundBuffer powerups_buffer;
    sf::Sound powerups_sound;

public:
    sf::Texture powerupTexture;
    sf::Sprite powerupSprite;

    class powerup_exception {};

    Powerups(sf::RenderWindow& window);

    void createPowerup(sf::RenderWindow& window);
    void PowerupsCollision(sf::RenderWindow& window);
};
