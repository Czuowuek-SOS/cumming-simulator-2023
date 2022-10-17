#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

class box_
{
    public:
        int velocity;
        int size[1];
};

int getDistance(sf::Vector2f p1, sf::Vector2f p2);
int randint(int min, int max);

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, 0);

    /* window*/
    sf::RenderWindow window(sf::VideoMode(1000, 800), "sex-simulator x84_64");
    window.setFramerateLimit(69);

    sf::Text fps_display;
    fps_display.setFillColor(sf::Color::White);
    fps_display.setPosition(900, 700);
    fps_display.setCharacterSize(32);


    /* entities*/
    sf::CircleShape dick(16);

    sf::Texture dick_up;
    dick_up.loadFromFile("./textures/dick.png");
    dick.setTexture(&dick_up);
    dick.setPosition(69, 69);

    
    sf::CircleShape pussy(32);
    sf::Texture     pussy_txt;
    pussy_txt.loadFromFile("./textures/pussy.png");
    pussy.setPosition(randint(1, 900), randint(1, 800));

    /* game loop */
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

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(getDistance(dick.getPosition(), pussy.getPosition()) < 1)
            {
                pussy.setPosition(randint(1, 900), randint(1, 800));

                // dick.setRadius(dick.getRadius() + 1);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                dick.move(-1, 0);
                dick.setRotation(270);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                dick.move(1, 0);
                dick.setRotation(90);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                dick.move(0, -1);
                dick.setRotation(0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                dick.move(0, 1);
                dick.setRotation(180);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                dick.setPosition(randint(1, 1000), randint(1, 800));
            }
            Sleep(0.05);


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