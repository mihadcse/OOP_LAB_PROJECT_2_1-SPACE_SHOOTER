#include<iostream>
#include<vector>
#include"menu.h"
#include"BackgroundAndAudio.h"

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
        menu_background.draw(window);

        // Display the main menu
        menu.draw(window);


        window.display(); // Display the content on the window
    }
}