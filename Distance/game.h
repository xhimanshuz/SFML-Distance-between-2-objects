// EVERY THING IS SELF DEFINE, NO NEED TO EXPLAIN

#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>

class Game 
{
    private:
        sf::RectangleShape box1;
        sf::RectangleShape box2;
        sf::RenderWindow window;
        sf::Text box1Title;
        sf::Text box2Title;
        sf::Font font;
        sf::Text otherText;         // DISTANCE BETWEEN TWO BOX

        void inputProcess();
        void update();
        void render();

    public:

        Game();
        void run();
};

#endif