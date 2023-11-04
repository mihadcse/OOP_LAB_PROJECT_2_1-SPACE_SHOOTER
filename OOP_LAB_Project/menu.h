#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Menu
{
public:
    Menu(sf::RenderWindow& window);

    // Handle user input and update the main menu
    void handleInput(sf::RenderWindow& window, sf::Event& event);

    // Draw the main menu on the window
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text title;
    sf::Text startText;
    sf::Text exitText;
    sf::Text scoreText;
    sf::Text instructText;
    sf::Text creditText;

    sf::RectangleShape start_r;
    sf::RectangleShape exit_r; 
    sf::RectangleShape score_r;
    sf::RectangleShape instruct_r; 
    sf::RectangleShape credit_r;

};

