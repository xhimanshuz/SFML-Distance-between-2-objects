#include "game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(786, 786), "Distance b/t Boxes"), box1(sf::Vector2f(100.f, 100.f)), box2(), font()
{
    box1.setFillColor(sf::Color::Yellow);
    box1.setOrigin(100.f, 100.f);

    box2.setOrigin(50.f, 50.f);
    box2.setSize(sf::Vector2f(100.f, 100.f));
    box2.setFillColor(sf::Color::Yellow);

    box2.setOrigin(100.f, 100.f);
    box2.setPosition(393.f, 393.f);

    if (!font.loadFromFile("monaco.ttf"))
    {
        printf("Error in loading font\n");
    }

    box1Title.setFont(font);
    box1Title.setFillColor(sf::Color::Red);
    box2Title.setFont(font);
    box2Title.setFillColor(sf::Color::Green);
    box2Title.setString(std::to_string((int)(box2.getPosition().x)) + "x" + std::to_string((int)(box2.getPosition().y)));

    otherText.setFont(font);
    otherText.setFillColor(sf::Color::White);
}

void Game::inputProcess()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            std::cout << "Closed\n";
            window.close();
        }

        else if (event.type == sf::Event::KeyPressed)
        {
            window.close();
        }
    }
}

void Game::update()
{
    box1Title.setString(std::to_string((int)(box1.getPosition().x)) + "x" + std::to_string((int)(box1.getPosition().y)));

    sf::Vector2f delta((box2.getPosition().x + box1.getPosition().x) / 2.f, (box2.getPosition().y + box1.getPosition().y) / 2.f);
    otherText.setPosition(delta);
    sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    box1.setPosition(mousePosition.x, mousePosition.y);

    sf::Vector2f otherTextPos((int)box2.getPosition().x - (int)box1.getPosition().x, (int)box2.getPosition().y - (int)box1.getPosition().y);
    otherText.setString(std::to_string((int)otherTextPos.x) + "x" + std::to_string((int)otherTextPos.y));
    
    sf::Vector2f push(0.f, 0.f);
    box1Title.setPosition(mousePosition);

    if (((int)otherTextPos.x > -100 && (int)otherTextPos.x < 100) && (int)otherTextPos.y > -100 && (int)otherTextPos.y < 100)
    {
        printf("Touched\n");
        box2.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }
    else
        box2.setFillColor(sf::Color::Blue);
    box2Title.setPosition(box2.getPosition().x, box2.getPosition().y);
}

void Game::render()
{
    window.clear();
    window.draw(box1);
    window.draw(box2);
    window.draw(box1Title);
    window.draw(box2Title);
    window.draw(otherText);
    window.display();
}

void Game::run()
{
    while (window.isOpen())
    {
        inputProcess();
        update();
        render();
    }
}
