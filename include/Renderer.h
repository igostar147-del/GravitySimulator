#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Simulation.h"

class Renderer
{
public:
    Renderer();

    void draw(sf::RenderWindow& window, Simulation& simulation);
};

#endif