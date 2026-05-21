#ifndef BODY_H
#define BODY_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Body
{
public:
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
    sf::Color col;
    double m;
    double rad;
    Body();
    Body(Vector2 pos, Vector2 vel, double m, double rad, sf::Color col);
    void update(double dt);
};

#endif