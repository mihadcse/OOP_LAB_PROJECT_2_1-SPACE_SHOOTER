#pragma once
#include "Character.h"
#include"Global.h"
#include "Powerups.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace std;

class Player : public Character
{
private: 

    Powerups powerups; // Aggregation

    sf::Font font2;
    sf::RectangleShape PlayerHealthbar;
    sf::Texture Player_fire_texture;
    sf::Sprite Player_fire_sprite;
    
    sf::SoundBuffer Player_fire_buffer;
    sf::Sound Player_fire_sound;

    sf::Text player_Text;
    sf::Text player_score_Text;
    sf::Text player_health_Text;
    sf::Text ammo_Text;
    sf::Text power_Text;
    sf::Text level_text;

public:
    sf::Texture PlayerTexture1;
    sf::Texture PlayerTexture2;
    sf::Sprite PlayerSprite;
    vector<sf::Sprite>playerFireSpriteVect;
    vector<sf::Sprite>powerup_SpriteVect;
    vector<pair <double, double> >player_fire;
    vector<pair <double, double> >powerup_fire;

	Player(sf::RenderWindow& window);

    void move(sf::RenderWindow& window) override;

    void fire(sf::RenderWindow& window) override;

    void special_fire(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window, int tri) override;
     
};

