#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

class Spermatozoid : public sf::CircleShape
{
    public:
        float x;
        float y; 

        float v;

    bool isInVagina(const sf::Vector2f pos)
    {
        float distance = sqrt(pow(pos.x - x, 2) + pow(y - pos.y, 2));
        if(distance < 0.5)
        {
            return true;
        }
        return false;
    }
};

class Dick : public sf::CircleShape
{
    public:
        float x;
        float y; 

        float size;
        
    void cum()
    {

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