#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <math.h>

class Pussy : public sf::CircleShape
{
    public:
        int x;
        int y;

        sf::Sound ohh_;
        sf::SoundBuffer soundBuffer;

        Pussy()
        {
            soundBuffer.loadFromFile(".\\resources\\sounds\\ohh.wav");
            ohh_.setBuffer(soundBuffer);
        }

        void ohh()
        {
            ohh_.play();
        }
};

class Spermatozoid : public sf::CircleShape
{
    public:
        float v = 6.0f;

        bool isInVagina(Pussy pussy)
        {
            sf::Vector2f pos = pussy.getPosition();
            float distance = sqrt(pow(pos.x - getPosition().x, 2) + pow(pos.y - getPosition().y, 2));
            std::cout << distance << '\n';
            if(distance < getRadius() + pussy.getRadius())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class Dick : public sf::CircleShape
{
    public:
        float x;
        float y; 

        bool cumming = false;

        void cum(Spermatozoid sperm)
        {
            cumming = true;
            sperm.setPosition(getPosition());
        }
};
