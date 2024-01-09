#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class Asteroids {
private:
    sf::Texture asteroidTexture;

    int asteroidSpawnTimer; // Timer for asteroid spawn

public:
    Asteroids(sf::RenderWindow& window);

    vector<sf::Sprite> asteroidSpriteVector;

    void spawnAsteroid();

    void draw(sf::RenderWindow& window);

    void move(sf::RenderWindow& window);
};

#endif //!ASTEROIDS_H