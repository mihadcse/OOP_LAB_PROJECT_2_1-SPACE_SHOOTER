#include "Score.h"

Score::Score(sf::RenderWindow& window)
{
    try
    {
        if (!font.loadFromFile("Fonts/batmfa__.ttf"))
        {
            throw score_exception();
        }
    }
    catch (const score_exception& e)
    {
        cout << "Score error: Failed to load resources" << endl;
    }

    // Asking for player name
    asktext.setFont(font);
    asktext.setString("Write your name- ");
    asktext.setCharacterSize(35);
    asktext.setFillColor(sf::Color(0, 255, 255)); // 102, 0, 255 // 0, 255, 255
    asktext.setOutlineColor(sf::Color(0, 0, 0)); // 255, 255, 102
    asktext.setOutlineThickness(3);
    asktext.setPosition(window.getSize().x / 2 - asktext.getGlobalBounds().width / 2, 150);

    // Asking for player name
    inputtext.setFont(font);
    inputtext.setCharacterSize(35);
    inputtext.setFillColor(sf::Color(0, 255, 255)); // 102, 0, 255 // 0, 255, 255
    inputtext.setOutlineColor(sf::Color(0, 0, 0)); // 255, 255, 102
    inputtext.setOutlineThickness(3);
    inputtext.setPosition(window.getSize().x / 2 - 90, 250);

    scoreText1.setFont(font);
    scoreText1.setPosition(window.getSize().x / 2 - 200, 100);
    scoreText1.setCharacterSize(50);
    scoreText1.setFillColor(sf::Color::Cyan);
    scoreText1.setOutlineThickness(3);
    scoreText1.setOutlineColor(sf::Color::Black);
    scoreText1.setString("HIGH SCORES");
}


void Score::PlayernameInput(sf::Event& event)
{
    if (event.type == sf::Event::TextEntered) 
    {
        if (event.text.unicode == '\b' && !playername.empty())
        {
            playername.pop_back(); // Backspace to remove a character
        }
        else if (event.text.unicode < 128)
        {
            playername += static_cast<char>(event.text.unicode); // Append entered character
        }
    }
    inputtext.setString(playername); // Update the displayed text
    playername_file = playername;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
    {
        if (level == 1)
            trigger = 1;
        if (level == 2)
            trigger = 6;
    }
}


void Score::ScoreUpdate()
{
    // READ SCORE FROM FILE
    ifstream File("highscores.txt");
    if (!File.is_open()) 
    {
        cout << "Error opening highscore file." << endl;
        return;
    }

    struct ScoreEntry 
    {
        int score;
        string name;
    };

    vector<ScoreEntry> scores;
    string line;
    while (getline(File, line))
    {
        stringstream ss(line);
        ScoreEntry entry;
        ss >> entry.name >> entry.score;
        scores.push_back(entry);
    }
    /*cout << "file read- " << endl;
    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i].name << " " << scores[i].score << endl;
    }*/
    File.close();

    // Check if the player's score and name exist in the scores vector
    bool playerFound = false;
    for (auto& entry : scores) 
    {
        if (entry.name == playername_file)
        {
            entry.score = score_show;
            playerFound = true;
            break;
        }
    }

    // If player's name not found, add it to the scores vector
    if (!playerFound) 
    {
        scores.push_back({ score_show, playername_file });
    }

    // Sort the scores
    sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
        return a.score > b.score;
        });
    /*cout << "Sort- " << endl;
    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i].name <<" "<<scores[i].score << endl;
    }*/
    // Write the scores back to the file
    ofstream File_new("highscores.txt");
    if (!File_new.is_open())
    {
        cout << "Error opening highscore file." << endl;
        return;
    }
    else 
    {
        for (size_t i = 0; i < min(scores.size(), static_cast<size_t>(5)); ++i) 
        {
            File_new << scores[i].name << "  " << scores[i].score << '\n';
        }
    }
    File_new.close();
    update = 0;
}


void Score::draw(sf::RenderWindow& window)
{
    if (trigger == 11)
    {
        window.draw(asktext);
        window.draw(inputtext);
    }
    if (trigger == 2)
    {
        window.draw(scoreText1);
    }
}

void Score::ShowScores(sf::RenderWindow& window)
{
    // READ SCORE FROM FILE
    ifstream File("highscores.txt");
    if (!File.is_open())
    {
        cout << "Error opening highscore file." << endl;
        return;
    }

    string fileContents = "";
    string line;
    while (getline(File, line))
    {
        fileContents += line + "\n\n";
    }
    File.close();

    scoreText2.setFont(font);
    scoreText2.setPosition(window.getSize().x / 2 - scoreText2.getGlobalBounds().width / 2, 200);
    scoreText2.setCharacterSize(35);
    scoreText2.setFillColor(sf::Color::Cyan);
    scoreText2.setOutlineThickness(2);
    scoreText2.setOutlineColor(sf::Color::Black);
    scoreText2.setString(fileContents);

    window.draw(scoreText2);
}
