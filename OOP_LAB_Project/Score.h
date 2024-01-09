#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Global.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Score
{
private:
	sf::Font font;
	sf::Text asktext;
	sf::Text inputtext;
	sf::Text scoreText1;
	sf::Text scoreText2;
	vector<int> file_scores;

public:
	class score_exception {};

	Score(sf::RenderWindow& window);
	void PlayernameInput(sf::Event& event);
	void ScoreUpdate();
	void draw(sf::RenderWindow& window);
	void ShowScores(sf::RenderWindow& window);
};


