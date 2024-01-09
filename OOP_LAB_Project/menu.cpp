#include "menu.h"

using namespace std;

Menu::Menu(sf::RenderWindow& window) 
{
    try
    {
        if (!font.loadFromFile("Fonts/NEON GLOW-Bold.otf"))
        {
            throw menu_exception();
        }

        if (!font2.loadFromFile("Fonts/batmfa__.ttf"))
        {
            throw menu_exception();
        }
        //Mouse Cursor image
        cursor_image.loadFromFile("Image/click6.png");
        cursor.loadFromPixels(cursor_image.getPixelsPtr(), cursor_image.getSize(), sf::Vector2u(0, 0));

        if (!mouse_buffer.loadFromFile("Audio/mouse.wav"))
        {
            throw menu_exception();
        }
        mouse_Sound.setBuffer(mouse_buffer);

        //Mouse positiong sound
        if (trigger != 1)
        {
            if (!pos_buffer.loadFromFile("Audio/pos1.wav"))
            {
                throw menu_exception();
            }
            pos_sound.setBuffer(pos_buffer);
        }
    }
    catch (const menu_exception& e)
    {
        cout << "Menu error: Failed to load resources" << endl;
    }
    
    // SHOWING SPACE SHOOTER 
    title.setFont(font2);
    title.setString("Space Shooter");
    title.setCharacterSize(54);
    title.setFillColor(sf::Color::Yellow); // 102, 0, 255 // 0, 255, 255
    title.setStyle(sf::Text::Regular);
    title.setOutlineColor(sf::Color(0,0,0)); // 255, 255, 102
    title.setOutlineThickness(3);
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

    // SHOWING START GAME option
    startText.setFont(font2);
    startText.setString("Start Game");
    startText.setCharacterSize(40);
    startText.setFillColor(sf::Color::White);
    startText.setOutlineColor(sf::Color::Black);
    startText.setOutlineThickness(3);
    startText.setPosition(window.getSize().x / 2 - startText.getGlobalBounds().width / 2, 150);
    // Rectangle of start game option 
    start_r.setSize(sf::Vector2f(260, 50));
    start_r.setPosition(window.getSize().x / 2 - start_r.getGlobalBounds().width / 2, 150);
    start_r.setFillColor(sf::Color::Transparent);
    start_r.setOutlineColor(sf::Color::Black);
    start_r.setOutlineThickness(6);

    // SHOWING HIGH SCORES option
    scoreText.setFont(font2);
    scoreText.setString("High Scores");
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(3);
    scoreText.setPosition(window.getSize().x / 2 - scoreText.getGlobalBounds().width / 2, 250);
    // Rectangle of high score option
    score_r.setSize(sf::Vector2f(265, 50));
    score_r.setPosition(window.getSize().x / 2 - score_r.getGlobalBounds().width / 2, 250);
    score_r.setFillColor(sf::Color::Transparent);
    score_r.setOutlineColor(sf::Color::White);
    score_r.setOutlineThickness(4);

    //SHOWING INSTRUCTIONS option
    instructText.setFont(font2);
    instructText.setString("Instructions");
    instructText.setCharacterSize(40);
    instructText.setFillColor(sf::Color::White);
    instructText.setOutlineColor(sf::Color::Black);
    instructText.setOutlineThickness(3);
    instructText.setPosition(window.getSize().x / 2 - instructText.getGlobalBounds().width / 2, 350);
    // Rectangle of instruction option
    instruct_r.setSize(sf::Vector2f(295, 50));
    instruct_r.setPosition(window.getSize().x / 2 - instruct_r.getGlobalBounds().width / 2, 350);
    instruct_r.setFillColor(sf::Color::Transparent);
    instruct_r.setOutlineColor(sf::Color::White);
    instruct_r.setOutlineThickness(4);

    //SHOWING CREDITS OPTION
    creditText.setFont(font2);
    creditText.setString("Credits");
    creditText.setCharacterSize(40);
    creditText.setFillColor(sf::Color::White);
    creditText.setOutlineColor(sf::Color::Black);
    creditText.setOutlineThickness(3);
    creditText.setPosition(window.getSize().x / 2 - creditText.getGlobalBounds().width / 2, 450);
    // Rectangle of credits option
    credit_r.setSize(sf::Vector2f(165, 50));
    credit_r.setPosition(window.getSize().x / 2 - credit_r.getGlobalBounds().width / 2, 450);
    credit_r.setFillColor(sf::Color::Transparent);
    credit_r.setOutlineColor(sf::Color::White);
    credit_r.setOutlineThickness(4);

    // SHOWING EXIT option
    exitText.setFont(font2);
    exitText.setString("Exit");
    exitText.setCharacterSize(40);
    exitText.setFillColor(sf::Color::White);
    exitText.setOutlineColor(sf::Color::Black);
    exitText.setOutlineThickness(3);
    exitText.setPosition(window.getSize().x / 2 - exitText.getGlobalBounds().width / 2, 550);
    // Rectangle of exit option
    exit_r.setSize(sf::Vector2f(80, 50));
    exit_r.setPosition(window.getSize().x / 2 - exit_r.getGlobalBounds().width / 2, 550);
    exit_r.setFillColor(sf::Color::Transparent);
    exit_r.setOutlineColor(sf::Color::White);
    exit_r.setOutlineThickness(4);

    // Rectangle of back option
    back_r.setSize(sf::Vector2f(20, 20));
    back_r.setPosition(10, 10);
    back_r.setFillColor(sf::Color::Cyan);
    back_r.setOutlineColor(sf::Color::Red);
    back_r.setOutlineThickness(4);

    // Score and Health Box Player
    score_box_player.setSize(sf::Vector2f(165, 165));
    score_box_player.setPosition(35, 10);
    score_box_player.setFillColor(sf::Color::Transparent);
    score_box_player.setOutlineColor(sf::Color::Cyan);
    score_box_player.setOutlineThickness(4);

    // Health Box Enemy
    score_box_enemy.setSize(sf::Vector2f(165, 165));
    score_box_enemy.setPosition(940, 10);
    score_box_enemy.setFillColor(sf::Color::Transparent);
    score_box_enemy.setOutlineColor(sf::Color::Cyan);
    score_box_enemy.setOutlineThickness(4);
    
    // Space to continue text
    spacetoContinue.setFont(font2);
    spacetoContinue.setString("Press 'Space' to continue...");
    spacetoContinue.setPosition(window.getSize().x / 2 - 200, 550);
    spacetoContinue.setCharacterSize(25);
    spacetoContinue.setFillColor(sf::Color::Cyan);
    spacetoContinue.setOutlineThickness(2);
    spacetoContinue.setOutlineColor(sf::Color::Blue);

    // Instructions texts
    instruction_Text.setFont(font2);
    instruction_Text.setString("\t\t\t\t  Instructions\n\n\t## Press 'up', 'down', 'right', 'left'\n\t\t\tkeys for movement.\n\n\t## Press 'SPACE' Key for fire.\n\n\t## Press 'P' for Power-ups.\n\n\t## Press 'R' to reload Ammo.\n\t\t\t(5 points will deduct)\n\n\t## Press 'B' to reload Power-ups.\n\t\t\t(10 points will deduct)");
    instruction_Text.setCharacterSize(35);
    instruction_Text.setFillColor(sf::Color::Cyan);
    instruction_Text.setOutlineColor(sf::Color::Black);
    instruction_Text.setOutlineThickness(2.5);
    instruction_Text.setPosition(window.getSize().x / 2 - instruction_Text.getGlobalBounds().width / 2, 100);

    // Credits Name texts
    cred1Text.setFont(font2);
    cred1Text.setString("\t\t\t\t\t CREDITS\n\nSYED HUZZATULLAH MIHAD ID- 210041218\n\n  AKILAH JAHIN BUSHRA ID- 210041252\n\n\t ZARIF BIN ISLAM ID- 210041264\n\n   RUBAEEYAT HOSSAIN ID- 210041266"); 
    cred1Text.setCharacterSize(35);
    cred1Text.setFillColor(sf::Color::Cyan);
    cred1Text.setOutlineColor(sf::Color::Black);
    cred1Text.setOutlineThickness(3);
    cred1Text.setPosition(window.getSize().x / 2 - cred1Text.getGlobalBounds().width / 2, 150);

    // Final score text
    final_score_text.setFont(font2);
    final_score_text.setPosition(window.getSize().x / 2 - 200, 200);
    final_score_text.setCharacterSize(40);
    final_score_text.setFillColor(sf::Color::Cyan);
    final_score_text.setOutlineThickness(2);
    final_score_text.setOutlineColor(sf::Color::Blue);

    //score Instruction text
    ScoreInstruction.setFont(font2);
    ScoreInstruction.setPosition(window.getSize().x / 2 - 200, 600);
    ScoreInstruction.setString("Score = Health + Points");
    ScoreInstruction.setCharacterSize(25);
    ScoreInstruction.setFillColor(sf::Color::Cyan);
    ScoreInstruction.setOutlineThickness(2);
    ScoreInstruction.setOutlineColor(sf::Color::Blue);

}

void Menu::handleInput(sf::RenderWindow& window,sf::Event & event)
{
      // Clicking options
      if (event.type == sf::Event::MouseButtonPressed) 
      {
          if (event.mouseButton.button == sf::Mouse::Left && trigger != 1 && trigger != 6)
          {
              mouse_Sound.play();
          }
          if (event.mouseButton.button == sf::Mouse::Left && trigger == 0) // In manu background
          {
               sf::Vector2i mousePos = sf::Mouse::getPosition(window);

               if (start_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   //trigger = 11;
                   if (new_game_start == 1)
                   {
                       trigger = 11;
                       score_show = point;
                       //new_game_start = 0;
                   } 
                   if (new_game_start == 0)
                   {
                       if (level == 1)
                           trigger = 1;
                       if (level == 2)
                           trigger = 6;
                   }
                   cout << "Start game clicked" << endl;
               }
               else if (score_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   trigger = 2;
                   cout << "High score clicked" << endl;
               }
               else if (instruct_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   trigger = 3;
                   cout << "instruction clicked" << endl;
               }
               else if (credit_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   trigger = 4;
                   cout << "credit clicked" << endl;
               }
               else if (exit_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   trigger = 5;
                   cout << "Exit clicked" << endl;
                   window.close();
               }
          }
          if (event.mouseButton.button == sf::Mouse::Left && trigger != 0 && trigger != 10) // Not in menu background
          {
              sf::Vector2i mousePos = sf::Mouse::getPosition(window);
              if (back_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
              {
                  trigger = 0;
                  //new_game_start = 0;
                  cout << "Back clicked" << endl;
                  if (trigger == 1 || trigger == 6)
                  {
                      new_game_start = 0;
                  }
              }
          }
      }

      else if (event.type == sf::Event::MouseMoved && trigger == 0)
      {
          bool soundPlayed = false; // Flag to track if sound was played
          //Start game color theme
          if (start_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              pos_sound.play();
              start_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              startText.setFillColor(sf::Color(30, 144, 255));
              soundPlayed = true;
          }
          else
          {
              start_r.setOutlineColor(sf::Color::White); // Default color
              startText.setFillColor(sf::Color::White);
          }
          //score color theme
          if (score_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              pos_sound.play();
              score_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              scoreText.setFillColor(sf::Color(30, 144, 255));
              soundPlayed = true;
          }
          else
          {
              score_r.setOutlineColor(sf::Color::White); // Default color
              scoreText.setFillColor(sf::Color::White);
          }
          //Instruction color theme
          if (instruct_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              pos_sound.play();
              instruct_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              instructText.setFillColor(sf::Color(30, 144, 255));
              soundPlayed = true;
          }
          else
          {
              instruct_r.setOutlineColor(sf::Color::White); // Default color
              instructText.setFillColor(sf::Color::White);
          }
          //Credit color theme
          if (credit_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              pos_sound.play();
              credit_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              creditText.setFillColor(sf::Color(30, 144, 255));
              soundPlayed = true;
          }
          else
          {
              credit_r.setOutlineColor(sf::Color::White); // Default color
              creditText.setFillColor(sf::Color::White);
          }
          //Exit color theme
          if (exit_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              pos_sound.play();
              exit_r.setOutlineColor(sf::Color(255, 0, 0)); // Lighter shade
              exitText.setFillColor(sf::Color(255, 0, 0));
              soundPlayed = true;
          }
          else
          {
              exit_r.setOutlineColor(sf::Color::White); // Default color
              exitText.setFillColor(sf::Color::White);
          }
          if (!soundPlayed)
          {
              soundPlayed = false;
          }
      }
}

void Menu::draw(sf::RenderWindow& window)
{
    window.setMouseCursor(cursor);

    if (trigger != 0 && trigger!= 10)
    {
        window.draw(back_r);
    }
    if (trigger == 0)
    {
        /*
        window.draw(start_r);
        window.draw(score_r);
        window.draw(instruct_r);
        window.draw(exit_r);
        window.draw(credit_r);
        */

        window.draw(title);
        window.draw(startText);
        window.draw(scoreText);
        window.draw(instructText);
        window.draw(exitText);
        window.draw(creditText);
    }

    if (trigger == 1 || trigger == 6)
    {
        window.draw(score_box_player);
        window.draw(score_box_enemy);
    }

    if (trigger == 3)
    {
        window.draw(instruction_Text);
    }

    if (trigger == 4)
    {
        window.draw(cred1Text);
    }

    if (trigger == 7 || trigger == 8)
    {
        string final_scorestring = to_string(score_show);
        final_score_text.setString("Final score - " + final_scorestring);
        window.draw(final_score_text);
    }
    if (trigger == 10)
    {
        window.draw(spacetoContinue);
    }

    if (trigger == 2)
    {
        window.draw(ScoreInstruction);
    }
}
