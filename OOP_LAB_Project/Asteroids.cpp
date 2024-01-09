#include "Asteroids.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Asteroids::Asteroids(sf::RenderWindow& window) : asteroidSpawnTimer(0)
{
    if (!asteroidTexture.loadFromFile("Image/meteor.png"))
    {
        cout << "asteroid error!!\n";
    }
}

void Asteroids::spawnAsteroid()
{
    if (asteroidSpawnTimer < 500)
    {
        asteroidSpawnTimer++;
    }
    else 
    {
        if (asteroidSpriteVector.size() < 5) 
        { // Limit the number of asteroids
            float pos_x = rand() % 1140;
            sf::Sprite asteroidSprite;
            asteroidSprite.setTexture(asteroidTexture);
            asteroidSprite.setPosition(pos_x, 0);
            asteroidSpriteVector.push_back(asteroidSprite);
        }
        asteroidSpawnTimer = 0;
    }
}

void Asteroids::move(sf::RenderWindow& window)
{
    for (size_t i = 0; i < asteroidSpriteVector.size(); i++) 
    {
        asteroidSpriteVector[i].move(0.f, 0.1f);
        if (asteroidSpriteVector[i].getPosition().y > window.getSize().y) 
        {
            asteroidSpriteVector.erase(asteroidSpriteVector.begin() + i);
        }
    }
}

void Asteroids::draw(sf::RenderWindow& window)
{
    for (const auto& asteroid : asteroidSpriteVector)
    {
        window.draw(asteroid);
    }
}
