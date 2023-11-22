#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>


class BackgroundAndAudio 
{
private:
    sf::Texture menu_backgroundTexture;
    sf::Sprite menu_backgroundSprite;
    sf::Music backgroundMusic;

public:
    BackgroundAndAudio(sf::RenderWindow& window);

    void setBackgroundSprite(const sf::Sprite& sprite);

    void setBackgroundMusic(const sf::Music& music);

    void playMusic();

    void stopMusic();

    void draw(sf::RenderWindow& window);

    // Add other methods related to managing background and audio as needed
};

