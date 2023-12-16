#pragma once
#include "Character.h"

class Player : public Character
{
private:
    sf::Texture PlayerTexture;
    sf::Sprite PlayerSprite;
    sf::RectangleShape PlayerHealthbar;

public:
	Player(sf::RenderWindow& window);

    void move(sf::RenderWindow& window) override;

    void fire() override;

    void draw(sf::RenderWindow& window, int tri) override;
     
};

