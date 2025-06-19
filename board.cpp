#include "board.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

void plot_the_board(sf::RenderWindow &window)
{
    sf::RectangleShape block;
    block.setOrigin(0,0);
    // Outer wooden frame
    block.setSize({600,600});
    block.setPosition(0,0);
    block.setTexture(&woodTexture);
    window.draw(block);
    // Dark Blue background
    block.setSize({570,570});
    block.setPosition(15,15);
    block.setFillColor(sf::Color(0, 0, 255, 200));
    window.draw(block);
    
    block.setTexture(NULL);

    block.setSize({150,150});
    block.setFillColor(sf::Color(200, 230, 250));
    block.setOutlineColor(sf::Color(240, 240, 240));
    block.setOutlineThickness(15);

    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {

            block.setPosition(35+i*190,35+j*190);
            window.draw(block);

            H_black_line.setPosition(35+i*190, 83+j*190);
            window.draw(H_black_line);
            H_black_line.setPosition(35+i*190, 133+j*190);
            window.draw(H_black_line);
            V_black_line.setPosition(83+i*190, 35+j*190);
            window.draw(V_black_line);
            V_black_line.setPosition(133+i*190, 35+j*190);
            window.draw(V_black_line);

        }
    }
}