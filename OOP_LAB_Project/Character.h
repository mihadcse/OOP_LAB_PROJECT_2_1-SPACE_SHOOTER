#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

class Character 
{
protected:
    sf::Vector2f position;
    sf::Sprite sprite;
    float speed;
    int health_length = 110;
    int health_width = 10;

public:
    Character() : speed(0.0f) {} // Constructor with initialization

    // Common methods for movement or actions (virtual for polymorphism)
    virtual void move(sf::RenderWindow& window) = 0; // Pure virtual function for movement
    virtual void fire() = 0; // pure virtual function for firing
    virtual void draw(sf::RenderWindow& window, int tri) = 0;
};
