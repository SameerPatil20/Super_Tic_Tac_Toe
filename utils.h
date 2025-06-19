#pragma once
#include <SFML/Graphics.hpp>

// Global assets (declared, not defined)
extern sf::Texture woodTexture;
extern sf::Font font;

extern sf::RectangleShape Poss;
extern sf::RectangleShape Hline;
extern sf::RectangleShape Vline;
extern sf::RectangleShape Pline;
extern sf::RectangleShape Nline;
extern sf::RectangleShape H_black_line;
extern sf::RectangleShape V_black_line;
extern sf::Text text;
extern sf::Text bigtext;
extern sf::Text text_turn;

// Function to load them
void load_requirements();

std::pair<int,int> status(std::vector<int> &table,int start);
