#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include"Global.h"

class BackgroundAndAudio 
{
private:
    sf::Texture menu_backgroundTexture;
    sf::Sprite menu_backgroundSprite;
    sf::Texture game_backgroundTexture;
    sf::Sprite game_backgroundSprite;
    
    sf::SoundBuffer backgroundSound;
    sf::Sound backsound;
    sf::SoundBuffer game_backgroundsound;
    sf::Sound game_backsound;

protected:


public:
    BackgroundAndAudio(sf::RenderWindow& window);

    void setBackgroundSprite(const sf::Sprite& sprite);

    void setBackgroundMusic(const sf::Music& music);

    void playMusic();

    void stopMusic();

    void draw(sf::RenderWindow& window, int tri);

    void updateAnimation(sf::RenderWindow& window);


    // Add other methods related to managing background and audio as needed
};

