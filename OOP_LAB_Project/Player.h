#pragma once
#include "Character.h"
#include"Global.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace std;

class Player : public Character
{
private: 
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

public:
    sf::Texture PlayerTexture;
    sf::Sprite PlayerSprite;
    vector<sf::Sprite>playerFireSpriteVect;
    vector<pair <double, double> >player_fire;

	Player(sf::RenderWindow& window);

    void move(sf::RenderWindow& window) override;

    void fire(sf::RenderWindow& window) override;

    void draw(sf::RenderWindow& window, int tri) override;
     
};

