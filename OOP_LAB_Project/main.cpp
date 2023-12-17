#include<iostream>
#include<vector>
#include"menu.h"
#include"BackgroundAndAudio.h"
#include"Global.h"
#include"Player.h"
#include"Enemy.h"
#include"Score.h"

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>

using namespace std;

sf::SoundBuffer reload_buffer;
sf::Sound reloadsound;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1140, 670), "Space Shooter");// this window ratio is fixed. It will show the window with a height of 1140 and width of 670
    
    Menu menu(window);
    BackgroundAndAudio menu_background(window);
    Player player(window);
    Enemy enemy(window);

    bool musicPlaying = false; // Flag to track music state

    cout << ammo << endl;

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
            if (trigger == 1 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && ammo > 0)
            {
                ammo--;
                player.fire(window); // Pass the event here if needed
                window.display();
            } 
            //Ammo reloading
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)) 
            {
                if (ammo == 0)
                {
                    if (!reload_buffer.loadFromFile("Audio/reload_main.wav"))
                    {
                        cout << "reload sound error!!!\n";
                    }
                    reloadsound.setBuffer(reload_buffer);
                    reloadsound.play();
                    reload(); 
                }
            }
        }
  
        window.clear(); // Clear the window

        //Display main menu background
        menu_background.draw(window, trigger);
  
        if (trigger == 1 && musicPlaying)
        {
            menu_background.stopMusic();
            // Display game animation frames
            window.clear(); // Clear the window before drawing frames
            //menu_background.updateAnimation(window);// Animation draw
            musicPlaying = false; // Update the flag
        }
        else if (trigger == 0 && !musicPlaying)
        {
            menu_background.playMusic();
            musicPlaying = true; // Update the flag
        }

        // Display Menu
        menu.draw(window);
        if (trigger == 1)
        {
            player.draw(window, trigger);
            player.move(window);
            enemy.draw(window, trigger);
            enemy.move(window);
            enemy.fire(window);
            // Update bullet positions and draw bullets
            if (!player.player_fire.empty())
            {
                for (int i = 0; i < player.player_fire.size(); i++)
                {
                    player.player_fire[i].second -= 0.6;

                    if (player.player_fire[i].second <= -60)
                    {
                        continue;
                    }
                    player.playerFireSpriteVect[i].setPosition(sf::Vector2f(player.player_fire[i].first + 30, player.player_fire[i].second + 5));
                    player.playerFireSpriteVect[i].move(sf::Vector2f(0, -2));

                    //enemy_main player fire collision
                    if (player.playerFireSpriteVect[i].getGlobalBounds().intersects(enemy.EnemySprite.getGlobalBounds()))
                    {
                        enemy_health--;
                        if (enemy_health == 0)
                        {
                            //window.clear();
                            //window.draw(winnerbackgroundsprite);
                            //window.display();
                            //clicked = 7;
                            reset_game();
                            trigger = 0;
                            break;
                        }
                        player.playerFireSpriteVect.erase(player.playerFireSpriteVect.begin() + i);
                        player.player_fire.erase(player.player_fire.begin() + i);
                        //if (enemy_health--)
                        point++;
                        score_show++;
                        //scoring
                    }
                }
            }
            for (size_t i = 0; i < player.playerFireSpriteVect.size(); i++)
            {
                window.draw(player.playerFireSpriteVect[i]);
            }

            //Enemy firing
            if (!enemy.enemy_fire.empty())
            {
                for (int j = 0; j < enemy.enemy_fire.size(); j++)
                {
                    enemy.enemy_fire[j].second += 0.6;

                    if (enemy.enemy_fire[j].second <= -60)
                    {
                        continue;
                    }
                    /*if (enemyFireBox.getGlobalBounds().intersects(charHealthBarBack.getGlobalBounds())) {
                        player.health -= 40;
                        window.draw(rectangle6);
                    }*/
                    enemy.enemyFireSpriteVect[j].setPosition(sf::Vector2f(enemy.enemy_fire[j].first + 30, enemy.enemy_fire[j].second + 15));
                    enemy.enemyFireSpriteVect[j].move(sf::Vector2f(0, 2));
                    //enemy_fire character plane collision 
                    if (enemy.enemyFireSpriteVect[j].getGlobalBounds().intersects(player.PlayerSprite.getGlobalBounds()))
                    {
                        enemy.enemyFireSpriteVect.erase(enemy.enemyFireSpriteVect.begin() + j);
                        enemy.enemy_fire.erase(enemy.enemy_fire.begin() + j);
                        player_health--;
                        if (player_health == 0)
                        {
                            //window.clear();
                            //window.draw(gameoverbackgroundsprite);
                            //window.display();
                            //clicked = 8;
                            reset_game();
                            trigger = 0;
                            break;
                        }
                    }
                }
                for (size_t i = 0; i < enemy.enemyFireSpriteVect.size(); i++)
                {
                    window.draw(enemy.enemyFireSpriteVect[i]);
                }
            }
        }

        window.display(); // Display the content on the window
    }
}