#include "BackgroundAndAudio.h"

using namespace std;

BackgroundAndAudio::BackgroundAndAudio(sf::RenderWindow& window)
{
    // Load background texture and set it to the sprite
    if (!menu_backgroundTexture.loadFromFile("Image/back_menu.jpg"))
    {
        //Handle error
        cout << "Menu background error" << endl;
    }
    menu_backgroundSprite.setTexture(menu_backgroundTexture);

    // Load background music - This part is missing in your code
    // Example:
    if (!backgroundMusic.openFromFile("path_to_your_music_file.ogg")) 
    {
        // Handle error
    }
}


void BackgroundAndAudio::setBackgroundSprite(const sf::Sprite& sprite)
{
    menu_backgroundSprite = sprite;
}

void BackgroundAndAudio::setBackgroundMusic(const sf::Music& music)
{
    //backgroundMusic = music;
}

void BackgroundAndAudio::playMusic()
{
    backgroundMusic.play();
}

void BackgroundAndAudio::stopMusic()
{
    backgroundMusic.stop();
}

void BackgroundAndAudio::draw(sf::RenderWindow& window)
{
    window.draw(menu_backgroundSprite);
}


