#include <SFML/Graphics.hpp>
#include "board.h"
#include "utils.h"
#include <vector>
#include <iostream>


int main()
{
    load_requirements();
    
    sf::RenderWindow window(sf::VideoMode(600, 700), "Super Tic Tac Toe");
    window.setFramerateLimit(60);
    
    std::vector<int> BigBoard(9,0);  // Stores result of 9 small boards 
    std::vector<int> endLine(9,0);   // Stores how small boards ended
    std::vector<int> Board(81,0);    // Complete 9*9 board

    
    int current_player = 1;
    int block_allowed = -1;   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                int block_placed=-1;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(x>=35+i*190 && x<185+i*190 && y>=35+j*190 && y<185+j*190)block_placed=j*3+i;
                    }
                }
                if(block_placed==-1 || BigBoard[block_placed]!=0)continue;

                if(block_allowed!=-1 && block_allowed!=block_placed)continue;

                int xi=(x-35-190*(block_placed%3))/50;
                int yj=(y-35-190*(block_placed/3))/50;
                int cell_no = 9 * block_placed + 3*yj + xi;

                if(Board[cell_no]!=0)continue;

                // Valid Input has been given

                Board[cell_no] = current_player;
                current_player = 3 - current_player;
                int tile_no = cell_no%9;
                auto retVal = status(Board,9*block_placed);
                BigBoard[block_placed] = retVal.first;
                endLine[block_placed] = retVal.second;
                block_allowed = tile_no;
                if(BigBoard[block_allowed]!=0)
                {
                    block_allowed = -1;
                }

                retVal = status(BigBoard,0);

                if(retVal.first!=0)
                {
                    // Game Completed
                    current_player=-retVal.first;
                    block_allowed=9;
                }

                
            }
        }

    
        
        plot_the_board(window);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int tile_number=(j/3)*9+j%3+27*(i/3)+(i%3)*3;
                if(Board[tile_number]==0)
                {
                    if((block_allowed==-1 || block_allowed==tile_number/9) && BigBoard[tile_number/9]==0)
                    {
                        Poss.setPosition({40+int(j/3)*190+50*(j%3),40+int(i/3)*190+50*(i%3)});
                        window.draw(Poss);
                    }
                    continue;
                }
                if(Board[tile_number]==1)
                {
                    text.setString("X");
                    text.setFillColor(sf::Color(0, 100, 0));
                }
                else
                {
                    text.setString("O");
                    text.setFillColor(sf::Color::Red);
                }
                text.setPosition({int(j/3)*190+45+50*(j%3),int(i/3)*190+35+50*(i%3)});
                window.draw(text);
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(BigBoard[i*3+j]<1)continue;
                if(endLine[i*3+j]<4)
                {
                    Hline.setPosition({j*190+35,i*190+60+(endLine[i*3+j]-1)*50});
                    window.draw(Hline);
                }
                else if(endLine[i*3+j]<7)
                {
                    Vline.setPosition({j*190+60+(endLine[i*3+j]-4)*50,i*190+35});
                    window.draw(Vline);
                }
                else if(endLine[i*3+j]==7)
                {
                    Pline.setPosition({j*190+35,i*190+35});
                    window.draw(Pline);
                }
                else if(endLine[i*3+j]==8)
                {
                    Nline.setPosition({j*190+185,i*190+35});
                    window.draw(Nline);
                }
                if(BigBoard[i*3+j]==1)
                {
                    bigtext.setString("X");
                    bigtext.setFillColor(sf::Color(0, 100, 0));
                }
                else if(BigBoard[i*3+j]==2)
                {
                    bigtext.setString("O");
                    bigtext.setFillColor(sf::Color::Red);
                }
                bigtext.setPosition({j*190+60,i*190+15});
                window.draw(bigtext);

            }
        }
        
        // Print the current state of the Game
        if(current_player==1) text_turn.setString("Current Turn : X");
        else if(current_player==2)text_turn.setString("Current Turn : O");
        else if(current_player==-1)text_turn.setString("Player 1 Won(X)");
        else if(current_player==-2)text_turn.setString("Player 2 Win(O)");
        else if(current_player==0)text_turn.setString("Game Drawn");
        window.draw(text_turn);


        window.display();
        window.clear(sf::Color::Black);
    }
}