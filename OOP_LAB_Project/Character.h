#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

class Character 
{
protected:
    sf::Vector2f position;
    sf::Sprite sprite;
    float speed;

public:
    Character() : speed(0.0f) {} // Constructor with initialization

    // Setters for attributes
    void setPosition(const sf::Vector2f& pos) { position = pos; }
    void setSprite(const sf::Sprite& spr) { sprite = spr; }
    void setSpeed(float spd) { speed = spd; }

    // Getters for attributes
    sf::Vector2f getPosition() const { return position; }
    sf::Sprite getSprite() const { return sprite; }
    float getSpeed() const { return speed; }

    // Common methods for movement or actions (virtual for polymorphism)
    virtual void move() = 0; // Pure virtual function for movement
};
