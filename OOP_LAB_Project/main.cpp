#include<iostream>
#include<vector>
#include"menu.h"
#include"BackgroundAndAudio.h"
#include"Global.h"
#include"Player.h"
#include"Enemy.h"

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1140, 670), "Space Shooter");// this window ratio is fixed. It will show the window with a height of 1140 and width of 670
    
    Menu menu(window);
    BackgroundAndAudio menu_background(window);
    Player player(window);
    Enemy enemy(window);
    
    bool musicPlaying = false; // Flag to track music state

    //menu_background.playMusic();

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            // Pass the event to the MainMenu for handling user input
            menu.handleInput(window,event);
        }
  
        window.clear(); // Clear the window

        //Display main menu background
        menu_background.draw(window, trigger);
  
        if (trigger == 1 && musicPlaying)
        {
            menu_background.stopMusic();
            // Display game animation frames
            window.clear(); // Clear the window before drawing frames
           // menu_background.updateAnimation(window);// Animation draw
            musicPlaying = false; // Update the flag
        }
        else if (trigger == 0 && !musicPlaying)
        {
            menu_background.playMusic();
            musicPlaying = true; // Update the flag
        }

        
        // Display Menu
        menu.draw(window);

        player.draw(window,trigger);
        player.move(window);
        enemy.draw(window, trigger);
        enemy.move(window);

        window.display(); // Display the content on the window
    }
}