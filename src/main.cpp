#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

#include "entities.hpp"


int getDistance(sf::Vector2f p1, sf::Vector2f p2);
int randint(int min, int max);

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, 0);

    /* window*/
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Cumming Simulator 2022");
    window.setFramerateLimit(69);


    /* entities*/
    Dick dick;


    sf::Texture dick_up;
    dick_up.loadFromFile("./textures/dick.png");
    dick.setTexture(&dick_up);
    dick.setPosition(69, 750);


    Pussy pussy;
    sf::Texture     pussy_txt;
    pussy_txt.loadFromFile("./textures/pussy.png");
    pussy.setPosition(881, 50);

    sf::Sprite sperm;


    /* game loop */
    bool trend;
    sf::Clock clock;
    int fps;
    float curentTime;
    float lastTime = 0;
    while (window.isOpen())
    {
        curentTime = clock.restart().asSeconds();
        fps = 1.f / (curentTime - lastTime);
        lastTime = curentTime;

        fps_display.setString("sex");


        if(trend)
        {
            pussy.move(1, 0);
        }
        else
        {
            pussy.move(-1, 0);
        }

        if(pussy.getPosition().x < 20)
        {
            trend = 1;

            // dick.setRadius(dick.getRadius() + 1);
        }
        else if(pussy.getPosition().x > 880)
        {
            trend = 0;
        }
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }



            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dick.getPosition().x > 20)
            {
                dick.move(-2, 0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dick.getPosition().x < 880)
            {
                dick.move(2, 0);
            }
        }

        
        window.clear();
        window.draw(dick);
        window.draw(pussy);
        window.draw(fps_display);
        window.display();
    }
    

    return 0;
}

int getDistance(sf::Vector2f p1, sf::Vector2f p2)
{
    int distance = (p1.x - p2.x) - (p1.y - p2.y);

    return distance;
}

int randint(int min, int max)
{
    return rand() % max + min;
}