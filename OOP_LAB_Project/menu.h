#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Global.h"

class Menu
{
public:
    Menu(sf::RenderWindow& window);

    // Handle user input and update the main menu
    void handleInput(sf::RenderWindow& window, sf::Event& event);

    // Draw the main menu on the window
    void draw(sf::RenderWindow& window);

private:
    sf::Image cursor_image;
    sf::Cursor cursor;
    sf::Font font;
    sf::Text title;
    sf::Text startText;
    sf::Text exitText;
    sf::Text scoreText;
    sf::Text instructText;
    sf::Text creditText;

    sf::Text game_player;
    sf::Text player_score;
    sf::Text player_health;
 
    sf::SoundBuffer mouse_buffer;
    sf::Sound mouse_Sound;

    sf::RectangleShape start_r;
    sf::RectangleShape exit_r; 
    sf::RectangleShape score_r;
    sf::RectangleShape instruct_r; 
    sf::RectangleShape credit_r;
    sf::RectangleShape back_r;
    sf::RectangleShape score_box_player;
    sf::RectangleShape score_box_enemy;
};

