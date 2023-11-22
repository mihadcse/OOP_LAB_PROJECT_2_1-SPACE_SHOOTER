#include "menu.h"

using namespace std;


Menu::Menu(sf::RenderWindow& window) 
{
    if (!font.loadFromFile("Fonts/Bootcamp.otf")) 
    {
        // Handle font loading error
    }

    // SHOWING SPACE SHOOTER 
    title.setFont(font);
    title.setString("Space Shooter");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Yellow);
    title.setStyle(sf::Text::Bold);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(2);
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

    // SHOWING START GAME option
    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(40);
    startText.setFillColor(sf::Color::White);
    startText.setOutlineColor(sf::Color::Blue);
    startText.setOutlineThickness(.5);
    startText.setPosition(window.getSize().x / 2 - startText.getGlobalBounds().width / 2, 150);
    // Rectangle of start game option
    start_r.setSize(sf::Vector2f(195, 50));
    start_r.setPosition(window.getSize().x / 2 - start_r.getGlobalBounds().width / 2, 150);
    start_r.setFillColor(sf::Color::Black);
    start_r.setOutlineColor(sf::Color::White);
    start_r.setOutlineThickness(4);

    // SHOWING HIGH SCORES option
    scoreText.setFont(font);
    scoreText.setString("High Scores");
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Blue);
    scoreText.setOutlineThickness(.5);
    scoreText.setPosition(window.getSize().x / 2 - scoreText.getGlobalBounds().width / 2, 250);
    // Rectangle of high score option
    score_r.setSize(sf::Vector2f(195, 50));
    score_r.setPosition(window.getSize().x / 2 - score_r.getGlobalBounds().width / 2, 250);
    score_r.setFillColor(sf::Color::Black);
    score_r.setOutlineColor(sf::Color::White);
    score_r.setOutlineThickness(4);

    //SHOWING INSTRUCTIONS option
    instructText.setFont(font);
    instructText.setString("Instructions");
    instructText.setCharacterSize(40);
    instructText.setFillColor(sf::Color::White);
    instructText.setOutlineColor(sf::Color::Blue);
    instructText.setOutlineThickness(.5);
    instructText.setPosition(window.getSize().x / 2 - instructText.getGlobalBounds().width / 2, 350);
    // Rectangle of instruction option
    instruct_r.setSize(sf::Vector2f(195, 50));
    instruct_r.setPosition(window.getSize().x / 2 - instruct_r.getGlobalBounds().width / 2, 350);
    instruct_r.setFillColor(sf::Color::Black);
    instruct_r.setOutlineColor(sf::Color::White);
    instruct_r.setOutlineThickness(4);

    //SHOWING CREDITS OPTION
    creditText.setFont(font);
    creditText.setString("Credits");
    creditText.setCharacterSize(40);
    creditText.setFillColor(sf::Color::White);
    creditText.setOutlineColor(sf::Color::Blue);
    creditText.setOutlineThickness(.5);
    creditText.setPosition(window.getSize().x / 2 - creditText.getGlobalBounds().width / 2, 450);
    // Rectangle of credits option
    credit_r.setSize(sf::Vector2f(120, 50));
    credit_r.setPosition(window.getSize().x / 2 - credit_r.getGlobalBounds().width / 2, 450);
    credit_r.setFillColor(sf::Color::Black);
    credit_r.setOutlineColor(sf::Color::White);
    credit_r.setOutlineThickness(4);

    // SHOWING EXIT option
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(40);
    exitText.setFillColor(sf::Color::White);
    exitText.setOutlineColor(sf::Color::Blue);
    exitText.setOutlineThickness(.5);
    exitText.setPosition(window.getSize().x / 2 - exitText.getGlobalBounds().width / 2, 550);
    // Rectangle of exit option
    exit_r.setSize(sf::Vector2f(85, 50));
    exit_r.setPosition(window.getSize().x / 2 - exit_r.getGlobalBounds().width / 2, 550);
    exit_r.setFillColor(sf::Color::Black);
    exit_r.setOutlineColor(sf::Color::White);
    exit_r.setOutlineThickness(4);
}

void Menu::handleInput(sf::RenderWindow& window,sf::Event & event)
{
      if (event.type == sf::Event::MouseButtonPressed) 
      {
          if (event.mouseButton.button == sf::Mouse::Left) 
          {
               sf::Vector2i mousePos = sf::Mouse::getPosition(window);

               if (start_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   cout << "Start game clicked" << endl;
                    // Handle the start button click
                    // You can transition to your game or game settings here
               }
               else if (score_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   cout << "score clicked" << endl;
                   // Handle the exit button click
                   // You can close the window or implement an exit mechanism here
               }
               else if (instruct_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   cout << "instruction clicked" << endl;
                   // Handle the exit button click
                   // You can close the window or implement an exit mechanism here
               }
               else if (credit_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {
                   cout << "credit clicked" << endl;
                   // Handle the exit button click
                   // You can close the window or implement an exit mechanism here
               }
               else if (exit_r.getGlobalBounds().contains(mousePos.x, mousePos.y))
               {    
                   cout << "Exit clicked" << endl;
                   window.close();
                    // Handle the exit button click
                    // You can close the window or implement an exit mechanism here
               }
          }
      }

      else if (event.type == sf::Event::MouseMoved)
      {
          //Start game color theme
          if (start_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              start_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              startText.setFillColor(sf::Color(30, 144, 255));
          }
          else
          {
              start_r.setOutlineColor(sf::Color::White); // Default color
              startText.setFillColor(sf::Color::White);
          }
          //score color theme
          if (score_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              score_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              scoreText.setFillColor(sf::Color(30, 144, 255));
          }
          else
          {
              score_r.setOutlineColor(sf::Color::White); // Default color
              scoreText.setFillColor(sf::Color::White);
          }
          //Instruction color theme
          if (instruct_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              instruct_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              instructText.setFillColor(sf::Color(30, 144, 255));
          }
          else
          {
              instruct_r.setOutlineColor(sf::Color::White); // Default color
              instructText.setFillColor(sf::Color::White);
          }
          //Credit color theme
          if (credit_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              credit_r.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
              creditText.setFillColor(sf::Color(30, 144, 255));
          }
          else
          {
              credit_r.setOutlineColor(sf::Color::White); // Default color
              creditText.setFillColor(sf::Color::White);
          }
          //Exit color theme
          if (exit_r.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
              exit_r.setOutlineColor(sf::Color(255, 0, 0)); // Lighter shade
              exitText.setFillColor(sf::Color(255, 0, 0));
          }
          else
          {
              exit_r.setOutlineColor(sf::Color::White); // Default color
              exitText.setFillColor(sf::Color::White);
          }
          
      }
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(start_r);
    window.draw(score_r);
    window.draw(instruct_r);
    window.draw(exit_r);
    window.draw(credit_r);

    window.draw(title);
    window.draw(startText);
    window.draw(scoreText);
    window.draw(instructText);
    window.draw(exitText);
    window.draw(creditText);

}
