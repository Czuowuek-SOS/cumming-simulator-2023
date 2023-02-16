#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

class Spermatozoid : public sf::CircleShape
{
    public:
        float v = 6.0f;

    bool isInVagina(const sf::Vector2f pos)
    {
        // float distance = sqrt(pow(pos.x - x, 2) + pow(y - pos.y, 2));
        float distance = sqrt(pow(pos.x - getPosition().x, 2) + pow(pos.y - getPosition().y, 2));
        std::cout << distance << '\n';
        if(distance < 10.0)
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

class Pussy : public sf::CircleShape
{
    public:
        int x;
        int y; 

    void ohh()
    {

    }
};