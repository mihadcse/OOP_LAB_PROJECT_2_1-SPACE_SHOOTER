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
    sf::Texture game2_backgroundTexture;
    sf::Sprite game2_backgroundSprite;
    sf::Texture instruct_backgroundTexture;
    sf::Sprite instruct_backgroundSprite;
    sf::Texture credit_backgroundTexture;
    sf::Sprite credit_backgroundSprite;
    sf::Texture winner_backgroundTexture;
    sf::Sprite winner_backgroundSprite;
    sf::Texture gameover_backgroundTexture;
    sf::Sprite gameover_backgroundSprite;
    
    sf::SoundBuffer backgroundSound;
    sf::Sound backsound;
    sf::SoundBuffer game_backgroundsound;
    sf::Sound game_backsound;
    sf::SoundBuffer enemy_entry_buffer;

protected:


public:
    sf::Sound enemy_entry_sound;
    BackgroundAndAudio(sf::RenderWindow& window);

    void setBackgroundSprite(const sf::Sprite& sprite);

    void setBackgroundMusic(const sf::Music& music);

    void playMusic();

    void stopMusic();

    void draw(sf::RenderWindow& window, int tri);

    void updateAnimation(sf::RenderWindow& window);


    // Add other methods related to managing background and audio as needed
};

