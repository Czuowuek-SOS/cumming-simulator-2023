#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdint.h>

#include "entities.hpp"

using std::vector;

// auto icon = vector<sf::Uint8>
// {
//     #include "resources/icon.ico"
// };

// auto icon_size = sf::Vector2u{32, 32};

int getDistance(sf::Vector2f p1, sf::Vector2f p2);
int randint(int min, int max);

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, 0);

    /* window*/
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Cumming Simulator 2022");
    window.setFramerateLimit(69);
    window.setVerticalSyncEnabled(true);

    // window.setIcon(icon_size.x, icon_size.y, icon.data());


    /* entities*/
    Dick dick;
    Pussy pussy;
    sf::Sprite sperm;


    sf::Texture dick_texture;
    sf::Texture pussy_texture;

    dick_texture.loadFromFile("./resources/textures/dick.png");
    pussy_texture.loadFromFile("./resources/textures/pussy.png");

    dick.setTexture(&dick_texture);
    pussy.setTexture(&pussy_texture);

    dick.setPosition(69, 745);
    pussy.setPosition(881, 50);

    dick.setRadius(25);
    pussy.setRadius(35);

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