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

    if (!game_backgroundTexture.loadFromFile("Image/game3.jpg"))
    {
        //Handle error
        cout << "game background error" << endl;
    }
    game_backgroundSprite.setTexture(game_backgroundTexture);

    // Load background music - This part is missing in your code
    
    if (!backgroundSound.loadFromFile("Audio/back.wav"))
    {
        // Handle error
        cout << "BAck Audio error" << endl;
    }
    backsound.setBuffer(backgroundSound);
    backsound.setLoop(true);
    
    if (!game_backgroundsound.loadFromFile("Audio/space.wav"))
    {
        // Handle error
        cout << "Game BAck Audio error" << endl;
    }
    game_backsound.setBuffer(game_backgroundsound);
    game_backsound.setLoop(true);

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
}

void BackgroundAndAudio::updateAnimation(sf::RenderWindow& window)
{
    string img_files_names[] = { "video/1 (25).jpg", "video/1 (26).jpg", "video/1 (27).jpg", "video/1 (28).jpg", "video/1 (29).jpg", "video/1 (30).jpg", "video/1 (31).jpg", "video/1 (32).jpg", "video/1 (33).jpg", "video/1 (34).jpg", "video/1 (35).jpg", "video/1 (36).jpg", "video/1 (37).jpg", "video/1 (38).jpg", "video/1 (39).jpg", "video/1 (40).jpg",
                "video/1 (41).jpg", "video/1 (42).jpg", "video/1 (43).jpg", "video/1 (44).jpg", "video/1 (45).jpg", "video/1 (46).jpg", "video/1 (47).jpg", "video/1 (48).jpg", "video/1 (49).jpg", "video/1 (50).jpg", "video/1 (51).jpg", "video/1 (52).jpg", "video/1 (53).jpg", "video/1 (54).jpg", "video/1 (55).jpg", "video/1 (56).jpg", "video/1 (57).jpg", "video/1 (58).jpg",
                "video/1 (59).jpg", "video/1 (60).jpg", "video/1 (61).jpg", "video/1 (62).jpg", "video/1 (63).jpg", "video/1 (64).jpg", "video/1 (65).jpg", "video/1 (66).jpg", "video/1 (67).jpg", "video/1 (68).jpg", "video/1 (69).jpg", "video/1 (70).jpg", "video/1 (71).jpg", "video/1 (72).jpg", "video/1 (73).jpg", "video/1 (74).jpg", "video/1 (75).jpg", "video/1 (76).jpg",
                "video/1 (77).jpg", "video/1 (78).jpg", "video/1 (79).jpg", "video/1 (80).jpg", "video/1 (81).jpg", "video/1 (82).jpg", "video/1 (83).jpg", "video/1 (84).jpg", "video/1 (85).jpg", "video/1 (86).jpg", "video/1 (87).jpg", "video/1 (88).jpg", "video/1 (89).jpg", "video/1 (90).jpg", "video/1 (91).jpg", "video/1 (92).jpg", "video/1 (93).jpg", "video/1 (94).jpg",
                "video/1 (95).jpg", "video/1 (96).jpg", "video/1 (97).jpg", "video/1 (98).jpg", "video/1 (99).jpg", "video/1 (100).jpg", "video/1 (101).jpg", "video/1 (102).jpg", "video/1 (103).jpg", "video/1 (104).jpg", "video/1 (105).jpg", "video/1 (106).jpg", "video/1 (107).jpg", "video/1 (108).jpg", "video/1 (109).jpg", "video/1 (110).jpg", "video/1 (111).jpg", "video/1 (112).jpg",
                "video/1 (113).jpg", "video/1 (114).jpg", "video/1 (115).jpg", "video/1 (116).jpg", "video/1 (117).jpg", "video/1 (118).jpg", "video/1 (119).jpg", "video/1 (120).jpg", "video/1 (121).jpg", "video/1 (122).jpg", "video/1 (123).jpg", "video/1 (124).jpg", "video/1 (125).jpg", "video/1 (126).jpg", "video/1 (127).jpg", "video/1 (128).jpg", "video/1 (129).jpg", "video/1 (130).jpg",
                "video/1 (131).jpg", "video/1 (132).jpg", "video/1 (133).jpg", "video/1 (134).jpg", "video/1 (135).jpg", "video/1 (136).jpg", "video/1 (137).jpg", "video/1 (138).jpg", "video/1 (139).jpg", "video/1 (140).jpg", "video/1 (141).jpg", "video/1 (142).jpg", "video/1 (143).jpg", "video/1 (144).jpg", "video/1 (145).jpg", "video/1 (146).jpg", "video/1 (147).jpg", "video/1 (148).jpg",
                "video/1 (149).jpg", "video/1 (150).jpg", "video/1 (151).jpg", "video/1 (152).jpg", "video/1 (153).jpg", "video/1 (154).jpg", "video/1 (155).jpg", "video/1 (156).jpg", "video/1 (157).jpg", "video/1 (158).jpg", "video/1 (159).jpg", "video/1 (160).jpg", "video/1 (161).jpg", "video/1 (162).jpg", "video/1 (163).jpg", "video/1 (164).jpg", "video/1 (165).jpg", "video/1 (166).jpg",
                "video/1 (167).jpg", "video/1 (168).jpg", "video/1 (169).jpg", "video/1 (170).jpg", "video/1 (171).jpg", "video/1 (172).jpg", "video/1 (173).jpg", "video/1 (174).jpg", "video/1 (175).jpg", "video/1 (176).jpg", "video/1 (177).jpg", "video/1 (178).jpg", "video/1 (179).jpg", "video/1 (180).jpg", "video/1 (181).jpg", "video/1 (182).jpg", "video/1 (183).jpg", "video/1 (184).jpg", "video/1 (185).jpg",
                "video/1 (186).jpg", "video/1 (187).jpg", "video/1 (188).jpg", "video/1 (189).jpg", "video/1 (190).jpg", "video/1 (191).jpg", "video/1 (192).jpg", "video/1 (193).jpg", "video/1 (194).jpg", "video/1 (195).jpg", "video/1 (196).jpg", "video/1 (197).jpg", "video/1 (198).jpg", "video/1 (199).jpg", "video/1 (200).jpg", };
    for (int i = 0; i < 120; i++)
    {
        sf::Texture game_animTexture;
        sf::Sprite game_animSprite;

        if (!game_animTexture.loadFromFile(img_files_names[i]))
        {
            cout << "Error loading image " << i << endl;
        }
        else
        {
            cout << "Loaded image " << i << endl;
            game_animSprite.setTexture(game_animTexture);
            window.draw(game_animSprite); // Draw the sprite
            window.display(); // Update the window display
            sf::sleep(sf::seconds(0.008)); // Add a slight delay between frames
            window.clear(); // Clear the window for the next frame
        }
    }
}



