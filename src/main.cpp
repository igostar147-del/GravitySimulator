#include <SFML/Graphics.hpp>
#include <cmath>
#include "../include/Simulation.h"
#include "../include/Renderer.h"
#include "../include/GalaxyGenerator.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Simulator");
    Simulation simulation;
    Renderer renderer;
    GalaxyGenerator::createGalaxy(simulation, 120);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        simulation.update(0.003);
        sf::RectangleShape fade(
                sf::Vector2f(800, 600)
        );
        fade.setFillColor(sf::Color(0, 0, 0, 20));
        window.draw(fade);
        renderer.draw(window, simulation);
        window.display();
    }
    return 0;
}