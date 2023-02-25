#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdint.h>

#include "entities.hpp"

/* resources*/

#include "resources/icon.h"

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
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Cumming Simulator 2023");
    window.setFramerateLimit(69);
    window.setVerticalSyncEnabled(true);

    sf::Image icon;
    icon.loadFromMemory(icon_png, (std::size_t)sizeof(icon_png));

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Font font;
    font.loadFromFile("./resources/fonts/Roboto-Bold.ttf");

    sf::Text points_count;
    points_count.setFont(font);
    points_count.setCharacterSize(20);
    points_count.setPosition(sf::Vector2f(20, 20));

    /* entities*/
    Dick dick;
    Pussy pussy;
    Spermatozoid sperm;

    sf::Texture dick_texture;
    sf::Texture pussy_texture;
    sf::Texture sperm_texture;

    dick_texture.loadFromFile("./resources/textures/dick.png");
    pussy_texture.loadFromFile("./resources/textures/pussy.png");
    sperm_texture.loadFromFile("./resources/textures/sperm.png");

    dick.setTexture(&dick_texture);
    pussy.setTexture(&pussy_texture);
    sperm.setTexture(&sperm_texture);

    dick.setPosition(69, 745);
    pussy.setPosition(881, 50);
    sperm.setPosition(0, -1);

    dick.setRadius(25);
    pussy.setRadius(35);
    sperm.setRadius(20);

    sf::Sound bed_sex_sounds;
    sf::SoundBuffer sound_buffer;

    sound_buffer.loadFromFile("./resources/sounds/bed-sex-sounds.wav");

    bed_sex_sounds.setBuffer(sound_buffer);

    bed_sex_sounds.play();
    bed_sex_sounds.setLoop(true);

    /* game loop */
    dick.cumming = false;
    bool trend;
    sf::Clock clock;
    int points = 0;
    int fps;
    float curentTime;
    float lastTime = 0;
    while (window.isOpen())
    {
        curentTime = clock.restart().asSeconds();
        fps = 1.f / (curentTime - lastTime);
        lastTime = curentTime;

        points_count.setString(std::to_string(points));

        if(trend)
        {
            pussy.move(pussy.v, 0);
        }
        else
        {
            pussy.move(-pussy.v, 0);
        }

        if(pussy.getPosition().x < 20)
        {
            trend = 1;

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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !dick.cumming)
            {
                dick.cum(sperm);
                dick.cumming = true;
                sperm.setPosition(dick.getPosition());
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dick.getPosition().x > 20)
            {
                dick.move(-2, 0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dick.getPosition().x < 880)
            {
                dick.move(2, 0);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                
            }
        }

        if(dick.cumming)
        {
            sperm.move(0, -sperm.v);
            if(sperm.isInVagina(pussy))
            {
                dick.cumming = false;
                pussy.ohh();
                pussy.v += 0.5f;

                dick.setRadius(dick.getRadius() + 2);
                dick.move(0, -5);
                
                points++;
            }
        }

        
        window.clear();
        window.draw(dick);
        window.draw(pussy);
        if(sperm.getPosition().y > 0 && dick.cumming)
        {
            window.draw(sperm);
        }
        else
        {
            dick.cumming = false;
        }

        window.draw(points_count);
        window.display();
    }
    

    return 0;
}

int getDistance(sf::Vector2f p1, sf::Vector2f p2)
{
    int distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    return distance;
}

int randint(int min, int max)
{
    return rand() % max + min;
}
