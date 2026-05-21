#include "../include/GalaxyGenerator.h"

#include <cmath>
#include <cstdlib>

void GalaxyGenerator::createGalaxy(Simulation& simulation, int count)
{
    Body cen(
            Vector2(400, 300),
            Vector2(0, 0),
            5000,
            16,
            sf::Color::Yellow
    );
    simulation.addBody(cen);
    for (int i = 0; i < count; i++)
    {
        double ang = (double)rand() / RAND_MAX * 2 * 3.1415926535;
        double dist = 60 + (double)rand() / RAND_MAX * 250;
        double x = 400 + cos(ang) * dist;
        double y = 300 + sin(ang) * dist;
        Vector2 pos(x, y);
        double speed = 65 / sqrt(dist / 80);
        Vector2 directionFromCenter(cos(ang), sin(ang));
        Vector2 vel(
                -directionFromCenter.y * speed,
                directionFromCenter.x * speed
        );
        double m = 1;
        double rad = 2 + (double)rand() / RAND_MAX * 2;
        sf::Color col(
                100 + rand() % 156,
                100 + rand() % 156,
                255
        );
        Body star(pos, vel, m, rad, col);
        simulation.addBody(star);
    }
}