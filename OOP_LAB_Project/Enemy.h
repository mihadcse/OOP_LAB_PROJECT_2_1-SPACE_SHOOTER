#pragma once
#include"Character.h"

class Enemy : public Character
{
private:
    sf::Texture EnemyTexture;
    sf::Sprite EnemySprite;
    sf::RectangleShape EnemyHealthbar;
    int direction = 0;

public:
    Enemy(sf::RenderWindow& window);

    void move(sf::RenderWindow& window) override;

    void fire() override;

    void draw(sf::RenderWindow& window, int tri) override;
};

