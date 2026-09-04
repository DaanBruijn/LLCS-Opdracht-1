#pragma once
#include <SFML/Graphics.hpp>

class test
{
public:
    test();
    void update();
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape rectangle;

    float width;
    float height;
    float rotation;
};