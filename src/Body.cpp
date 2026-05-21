#include "../include/Body.h"

Body::Body()
{
    pos = Vector2(0, 0);
    vel = Vector2(0, 0);
    acc = Vector2(0, 0);
    col = sf::Color::White;
    m = 1;
    rad = 1;
}

Body::Body(Vector2 sPos, Vector2 sVel, double sM, double sRad, sf::Color sCol)
{
    pos = sPos;
    vel = sVel;
    acc = Vector2(0, 0);
    m = sM;
    rad = sRad;
    col = sCol;
}

void Body::update(double dt)
{
    vel = vel.add(acc.multiply(dt));
    pos = pos.add(vel.multiply(dt));
}