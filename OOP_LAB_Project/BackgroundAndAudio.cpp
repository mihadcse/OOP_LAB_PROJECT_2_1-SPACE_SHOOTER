#include "BackgroundAndAudio.h"

using namespace std;

BackgroundAndAudio::BackgroundAndAudio(sf::RenderWindow& window)
{
    try
    {
        if (!start_texture.loadFromFile("Image/start.jpg"))
        {
            throw back_exception();
        }
        start_sprite.setTexture(start_texture);
        // Load background texture and set it to the sprite
        if (!menu_backgroundTexture.loadFromFile("Image/back_menu.jpg"))
        {
            throw back_exception();
        }
        menu_backgroundSprite.setTexture(menu_backgroundTexture);

        if (!game_backgroundTexture.loadFromFile("Image/game3.jpg"))
        {
            throw back_exception();
        }
        game_backgroundSprite.setTexture(game_backgroundTexture);

        //Level 2 background
        if (!game2_backgroundTexture.loadFromFile("Image/5.jpg"))
        {
            throw back_exception();
        }
        game2_backgroundSprite.setTexture(game2_backgroundTexture);

        if (!instruct_backgroundTexture.loadFromFile("Image/i3.jpg"))
        {
            throw back_exception();
        }
        instruct_backgroundSprite.setTexture(instruct_backgroundTexture);

        if (!score_backgroundTexture.loadFromFile("Image/game2.jpg"))
        {
            throw back_exception();
        }
        score_backgroundSprite.setTexture(score_backgroundTexture);

        if (!winner_backgroundTexture.loadFromFile("Image/11.jpg"))
        {
            throw back_exception();
        }
        winner_backgroundSprite.setTexture(winner_backgroundTexture);

        if (!gameover_backgroundTexture.loadFromFile("Image/gameover.jpg"))
        {
            throw back_exception();
        }
        gameover_backgroundSprite.setTexture(gameover_backgroundTexture);

        if (!credit_backgroundTexture.loadFromFile("Image/credit.jpg"))
        {
            throw back_exception();
        }
        credit_backgroundSprite.setTexture(credit_backgroundTexture);

        if (!name_backgroundTexture.loadFromFile("Image/1.jpg"))
        {
            throw back_exception();
        }
        name_backgroundSprite.setTexture(name_backgroundTexture);

        // Load background music - This part is missing in your code

        if (!backgroundSound.loadFromFile("Audio/back.wav"))
        {
            throw back_exception();
        }
        backsound.setBuffer(backgroundSound);
        backsound.setLoop(true);

        if (!game_backgroundsound.loadFromFile("Audio/space.wav"))
        {
            throw back_exception();
        }
        game_backsound.setBuffer(game_backgroundsound);
        game_backsound.setLoop(true);

        if (!enemy_entry_buffer.loadFromFile("Audio/entry_enemy.wav"))
        {
            throw back_exception();
        }
        enemy_entry_sound.setBuffer(enemy_entry_buffer);

        if (!startingBuffer.loadFromFile("Audio/new.wav"))
        {
            throw back_exception();
        }
        startingSound.setBuffer(startingBuffer);
        startingSound.setLoop(true);
    }
    catch (const back_exception& e)
    {
        cout << "Background error: Failed to load resources" << endl;
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
    backsound.play();
    game_backsound.stop();
}

void BackgroundAndAudio::stopMusic()
{
    game_backsound.play();
    backsound.stop();
}

void BackgroundAndAudio::draw(sf::RenderWindow& window,int tri)
{
    if (tri == 0)
    {
        window.draw(menu_backgroundSprite);
    }
    if (tri == 1)
    {
        window.draw(game_backgroundSprite);
    }
    if (tri == 2)
    {
        window.draw(score_backgroundSprite);
    }
    if (tri == 3)
    {
        window.draw(instruct_backgroundSprite);
    }
    if (tri == 4)
    {
        window.draw(credit_backgroundSprite);
    }
    if (tri == 6)
    {
        window.draw(game2_backgroundSprite);
    }
    if (tri == 7)
    {
        window.draw(winner_backgroundSprite);
    }
    if (tri == 8)
    {
        window.draw(gameover_backgroundSprite);
    }
    if (tri == 10)
    {
        window.draw(start_sprite);
    }
    if (tri == 11)
    {
        window.draw(name_backgroundSprite);
    }
}

void BackgroundAndAudio::updateAnimation(sf::RenderWindow& window)
{
    string img_files_names[] = { "video/1 (25).jpg", "video/1 (26).jpg", "video/1 (27).jpg", "video/1 (28).jpg", "video/1 (29).jpg", "video/1 (30).jpg", "video/1 (31).jpg", "video/1 (32).jpg", "video/1 (33).jpg", "video/1 (34).jpg", "video/1 (35).jpg", "video/1 (36).jpg", "video/1 (37).jpg", "video/1 (38).jpg", "video/1 (39).jpg", "video/1 (40).jpg",
                "video/1 (41).jpg", "video/1 (42).jpg", "video/1 (43).jpg", "video/1 (44).jpg", "video/1 (45).jpg", "video/1 (46).jpg", "video/1 (47).jpg", "video/1 (48).jpg", "video/1 (49).jpg", "video/1 (50).jpg", "video/1 (51).jpg", "video/1 (52).jpg", "video/1 (53).jpg", "video/1 (54).jpg", "video/1 (55).jpg", "video/1 (56).jpg", "video/1 (57).jpg", "video/1 (58).jpg",
                "video/1 (59).jpg", "video/1 (60).jpg", "video/1 (61).jpg", "video/1 (62).jpg", "video/1 (63).jpg", "video/1 (64).jpg", "video/1 (65).jpg", "video/1 (66).jpg", "video/1 (67).jpg", "video/1 (68).jpg", "video/1 (69).jpg", "video/1 (70).jpg", "video/1 (71).jpg", "video/1 (72).jpg", "video/1 (73).jpg", "video/1 (74).jpg", "video/1 (75).jpg", "video/1 (76).jpg",
                "video/1 (77).jpg", "video/1 (78).jpg", "video/1 (79).jpg", "video/1 (80).jpg", "video/1 (81).jpg", "video/1 (82).jpg", "video/1 (83).jpg", "video/1 (84).jpg", "video/1 (85).jpg", "video/1 (86).jpg", "video/1 (87).jpg", "video/1 (88).jpg", "video/1 (89).jpg", "video/1 (90).jpg", "video/1 (91).jpg", "video/1 (92).jpg", "video/1 (93).jpg", "video/1 (94).jpg",
                "video/1 (95).jpg", "video/1 (96).jpg", "video/1 (97).jpg", "video/1 (98).jpg", "video/1 (99).jpg", "video/1 (100).jpg", "video/1 (101).jpg", "video/1 (102).jpg", "video/1 (103).jpg", "video/1 (104).jpg", "video/1 (105).jpg", "video/1 (106).jpg", "video/1 (107).jpg", "video/1 (108).jpg", "video/1 (109).jpg", "video/1 (110).jpg", "video/1 (111).jpg", "video/1 (112).jpg"};
    
    for (int i = 0; i < 80; i++)
    {
        sf::Texture game_animTexture;
        sf::Sprite game_animSprite;
        if (!game_animTexture.loadFromFile(img_files_names[i]))
        {
            cout << "Error loading image " << i << endl;
        }
        //cout << "image " << i << endl;
        game_animSprite.setTexture(game_animTexture);
        window.draw(game_animSprite); // Draw the sprite
        window.display(); // Update the window display
        sf::sleep(sf::seconds(0.008)); // Add a slight delay between frames
        window.clear(); // Clear the window for the next frame
    }
    trigger = 10;
}



