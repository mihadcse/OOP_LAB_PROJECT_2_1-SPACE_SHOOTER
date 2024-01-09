#pragma once
#include"Character.h"
#include"Global.h"

class Enemy : public Character
{
protected:
    sf::Font font2;
    sf::RectangleShape EnemyHealthbar;
    sf::Texture Enemy_fire_texture;
    sf::Sprite Enemy_fire_sprite;

    //TIME DELAY FOR ENEMY FIRING
    sf::Clock clock;
    float fireInterval = 2.8f;

    int direction = 0;
    sf::Text enemy_health_text;
    sf::Text enemy_Text;

public:
    sf::Texture EnemyTexture1;
    sf::Texture EnemyTexture2;
    sf::Sprite EnemySprite;
    vector<sf::Sprite>enemyFireSpriteVect;
    vector<pair <double, double> >enemy_fire;

    class enemy_exception {};

    Enemy(sf::RenderWindow& window);

    void move(sf::RenderWindow& window) override;

    void fire(sf::RenderWindow& window) override;

    void draw(sf::RenderWindow& window, int tri) override;
};

