#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Global.h"

class Menu
{
public:
    class menu_exception {};

    Menu(sf::RenderWindow& window);

    // Handle user input and update the main menu
    void handleInput(sf::RenderWindow& window, sf::Event& event);

    // Draw the main menu on the window
    void draw(sf::RenderWindow& window);


private:
    sf::Image cursor_image;
    sf::Cursor cursor;
    sf::Font font;
    sf::Font font2;
    sf::Text title;
    sf::Text startText;
    sf::Text exitText;
    sf::Text scoreText;
    sf::Text instructText;
    sf::Text creditText;
    sf::Text cred1Text;
    sf::Text instruction_Text;
    sf::Text final_score_text;
    sf::Text spacetoContinue;
 
    sf::SoundBuffer mouse_buffer;
    sf::Sound mouse_Sound;
    sf::SoundBuffer pos_buffer;
    sf::Sound pos_sound;

    sf::RectangleShape start_r;
    sf::RectangleShape exit_r; 
    sf::RectangleShape score_r;
    sf::RectangleShape instruct_r; 
    sf::RectangleShape credit_r;
    sf::RectangleShape back_r;
    sf::RectangleShape score_box_player;
    sf::RectangleShape score_box_enemy;
};

