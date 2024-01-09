#include<iostream>
#include<vector>
#include<time.h>

#include"menu.h"
#include"BackgroundAndAudio.h"
#include"Global.h"
#include"Player.h"
#include"Enemy.h"
#include"Score.h"
#include"Asteroids.h"

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>

using namespace std;

sf::SoundBuffer reload_buffer;
sf::Sound reloadsound;
sf::SoundBuffer reload_power_buffer;
sf::Sound reload_power_sound;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1140, 670), "Space Shooter");// this window ratio is fixed. It will show the window with a height of 1140 and width of 670
    
    Menu menu(window);
    BackgroundAndAudio menu_background(window);
    Player player(window);
    Enemy enemy(window);
    Score gameScore(window);
    Asteroids asteroids(window);

    bool musicPlaying = false; // Flag to track music state

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }

            menu.handleInput(window,event);
            if (trigger == 11)
            {
                gameScore.PlayernameInput(event); // Call PlayernameInput
            }

            if (trigger == 10)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    trigger = 0;
                }
            }
            if (trigger == 1 || trigger == 6)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && ammo > 0)
                {
                    ammo--;
                    player.fire(window); // Normal firing
                    reset = 0; // So it tells that a new game starts
                    window.display();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P && power > 0)
                {
                    power--;
                    player.special_fire(window); // Powerups use
                    reset = 0; // So it tells that a new game starts
                    window.display();
                }
            }
            //Ammo reloading
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)) 
            {
                if (ammo == 0 && point >= 5)
                {
                    if (!reload_buffer.loadFromFile("Audio/reload_main.wav"))
                    {
                        cout << "reload sound error!!!\n";
                    }
                    reloadsound.setBuffer(reload_buffer);
                    reloadsound.play();
                    reload(); 
                    point = point - 5;
                    score_show = score_show - 5;
                }
            }
            //powerup reloading
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B))
            {
                if (power == 0 && point >= 10)
                {
                    if (!reload_power_buffer.loadFromFile("Audio/reload_main.wav"))
                    {
                        cout << "reload buffer sound error!!!\n";
                    }
                    reload_power_sound.setBuffer(reload_power_buffer);
                    reload_power_sound.play();
                    power = 5;
                    point = point - 10;
                    score_show = score_show - 10;
                }
            }
        }
        window.clear(); // Clear the window

        if (trigger == 9)
        {
            menu_background.startingSound.play();
            menu_background.updateAnimation(window);  
        }
        if (trigger != 9 && trigger != 10)
        {
            menu_background.startingSound.stop();
        }
        //Display main menu background
        menu_background.draw(window, trigger);
        gameScore.draw(window);
        // Display Menu
        menu.draw(window);

        if (trigger == 2)
        {
            gameScore.ShowScores(window);
        }

        if ((trigger == 1 || trigger == 6) && musicPlaying)
        {
            menu_background.stopMusic();
            window.clear(); // Clear the window before drawing frames
            //menu_background.updateAnimation(window);// Animation draw
            musicPlaying = false; // Update the flag
        }
        else if ((trigger == 9 || trigger == 0 || trigger == 7 || trigger == 8) && !musicPlaying)
        {
            menu_background.playMusic();
            musicPlaying = true; // Update the flag
        }

        if (trigger == 1 || trigger == 6)
        {
            player.draw(window, trigger);
            player.move(window);
            enemy.draw(window, trigger);
            enemy.move(window);
            enemy.fire(window);
            asteroids.draw(window);
            asteroids.spawnAsteroid();
            asteroids.move(window);

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
                        if (reset == 0)
                        {
                            enemy_health--;
                            point++;
                            score_show++;
                        }
                        if (enemy_health <= 0 && trigger == 1)
                        {
                            //reset_game();
                            enemy_health = enemyHeathFull;
                            trigger = 6;
                            level = 2;
                            break;
                        }
                        if(enemy_health <= 0 && trigger != 1)
                        {
                            trigger = 7;
                            score_show = score_show + player_health;
                            gameScore.ScoreUpdate();
                            reset_game();
                            new_game_start = 1;
                            window.clear();
                            break;
                        }
                        player.playerFireSpriteVect.erase(player.playerFireSpriteVect.begin() + i);
                        player.player_fire.erase(player.player_fire.begin() + i);
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
                    enemy.enemyFireSpriteVect[j].setPosition(sf::Vector2f(enemy.enemy_fire[j].first + 30, enemy.enemy_fire[j].second + 15));
                    enemy.enemyFireSpriteVect[j].move(sf::Vector2f(0, 2));
                    //enemy_fire character plane collision 
                    if (enemy.enemyFireSpriteVect[j].getGlobalBounds().intersects(player.PlayerSprite.getGlobalBounds()))
                    {
                        enemy.enemyFireSpriteVect.erase(enemy.enemyFireSpriteVect.begin() + j);
                        enemy.enemy_fire.erase(enemy.enemy_fire.begin() + j);
                        player_health--;
                        if (player_health <= 0)
                        {
                            gameScore.ScoreUpdate();
                            reset_game();
                            trigger = 8;
                            new_game_start = 1;
                            window.clear();
                            break;
                        }
                    }
                }
                for (size_t i = 0; i < enemy.enemyFireSpriteVect.size(); i++)
                {
                    window.draw(enemy.enemyFireSpriteVect[i]);
                }
            }

            // Update bullet positions and draw bullets
            if (!player.powerup_fire.empty())
            {
                for (int i = 0; i < player.powerup_fire.size(); i++)
                {
                    player.powerup_fire[i].second -= 0.6;

                    if (player.powerup_fire[i].second <= -60)
                    {
                        continue;
                    }
                    player.powerup_SpriteVect[i].setPosition(sf::Vector2f(player.powerup_fire[i].first + 30, player.powerup_fire[i].second + 5));
                    player.powerup_SpriteVect[i].move(sf::Vector2f(0, -2));
                    //enemy_main player fire collision
                    if (player.powerup_SpriteVect[i].getGlobalBounds().intersects(enemy.EnemySprite.getGlobalBounds()))
                    {
                        if (reset == 0)
                        {
                            enemy_health = enemy_health - 3;
                            point = point + 3;
                            score_show = score_show + 3;;
                        }
                        if (enemy_health <= 0 && trigger == 1)
                        {
                            //reset_game();
                            enemy_health = enemyHeathFull;
                            trigger = 6;
                            level = 2;
                            break;
                        }
                        if (enemy_health <= 0 && trigger != 1)
                        {
                            trigger = 7;
                            score_show = score_show + player_health;
                            gameScore.ScoreUpdate();
                            reset_game();
                            new_game_start = 1;
                            window.clear();
                            break;
                        }
                        player.powerup_SpriteVect.erase(player.powerup_SpriteVect.begin() + i);
                        player.powerup_fire.erase(player.powerup_fire.begin() + i);
                    }
                }
            }
            for (size_t i = 0; i < player.powerup_SpriteVect.size(); i++)
            {
                window.draw(player.powerup_SpriteVect[i]);
            }


            //player asteroid collision
            for (size_t i = 0; i < asteroids.asteroidSpriteVector.size(); i++)
            {
                if (asteroids.asteroidSpriteVector[i].getGlobalBounds().intersects(player.PlayerSprite.getGlobalBounds()))
                {
                    asteroids.asteroidSpriteVector.erase(asteroids.asteroidSpriteVector.begin() + i);
                    player_health--;
                    if (player_health <= 0)
                    {
                        gameScore.ScoreUpdate();
                        reset_game();
                        trigger = 8;
                        new_game_start = 1;
                        window.clear();
                        break;
                    }
                }
            }
        }

        // When ammo and power becomes 0 and points is less than 5 it will show game over
        if (ammo == 0 && power == 0 && point < 5)
        {
            reset_game();
            trigger = 8;
            new_game_start = 1;
        }

        window.display(); // Display the content on the window
    }
}