#include "../include/Renderer.h"

Renderer::Renderer()
{
}

void Renderer::draw(sf::RenderWindow& window, Simulation& simulation)
{
    for (int i = 0; i < simulation.bodies.size(); i++)
    {
        Body body = simulation.bodies[i];
        sf::CircleShape circle(body.rad);
        circle.setOrigin(body.rad, body.rad);
        circle.setPosition(body.pos.x, body.pos.y);
        circle.setFillColor(body.col);
        window.draw(circle);
    }
}