#include "utils.h"

sf::Texture woodTexture;
sf::Font font;
sf::RectangleShape Poss(sf::Vector2f(40, 40));
sf::RectangleShape Hline(sf::Vector2f(150, 4));
sf::RectangleShape Vline(sf::Vector2f(4, 150));
sf::RectangleShape Pline(sf::Vector2f(215, 4));
sf::RectangleShape Nline(sf::Vector2f(4, 215));
sf::RectangleShape H_black_line(sf::Vector2f(150, 4));
sf::RectangleShape V_black_line(sf::Vector2f(4, 150));

sf::Text text;
sf::Text bigtext;
sf::Text text_turn;
void load_requirements()
{
    woodTexture.loadFromFile("image/wood_texture.png");
    
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    
    Poss.setFillColor(sf::Color::Yellow);
    
    Hline.setFillColor(sf::Color::Blue);
    Vline.setFillColor(sf::Color::Blue);
    
    Pline.rotate(45);
    Pline.setFillColor(sf::Color::Blue);
    
    Nline.rotate(45);
    Nline.setFillColor(sf::Color::Blue);
    
    text.setFont(font);
    text.setCharacterSize(40);
    bigtext.setFont(font);
    bigtext.setCharacterSize(150);
    
    H_black_line.setFillColor(sf::Color::Black);
    V_black_line.setFillColor(sf::Color::Black);

    text_turn.setFont(font);
    text_turn.setCharacterSize(50);
    text_turn.setPosition({100,620});
    
}


// Returns {state,how_ended}
std::pair<int,int> status(std::vector<int> &table,int start)
{
    for(int i=0;i<3;i++)
    {
        if(table[start+i*3] && table[start+i*3]==table[start+i*3+1] && table[start+i*3+1]==table[start+i*3+2])return {table[start+i*3],i+1};
        if(table[start+i] && table[start+i]==table[start+i+3] && table[start+i+3]==table[start+i+6])return {table[start+i],4+i};
    }
    if(table[start] && table[start]==table[start+4] && table[start]==table[start+8])return {table[start],7};
    if(table[start+2] && table[start+2]==table[start+4] && table[start+2]==table[start+6])return {table[start+2],8};
    
    int left=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(table[start+i*3+j]==0)left++;
        }
    }

    if(left==0)return {-1,0}; // Board Drawn
    return {0,0};             // Not decided
}