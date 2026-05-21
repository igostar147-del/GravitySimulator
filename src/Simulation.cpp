#include "../include/Simulation.h"
#include "../include/Simulation.h"
#include <cmath>


Simulation::Simulation()
{
    G = 100;
}
void Simulation::addBody(Body body)
{
    bodies.push_back(body);
}

void Simulation::update(double dt)
{
    computeGravity();
    for (int i = 0; i < bodies.size(); i++)
    {
        bodies[i].update(dt);
    }
    mergeCollisions();
}
void Simulation::computeGravity()
{
    for (int i = 0; i < bodies.size(); i++)
    {
        bodies[i].acc = Vector2(0, 0);
    }
    for (int i = 0; i < bodies.size(); i++)
    {
        for (int j = 0; j < bodies.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            Vector2 dir = bodies[j].pos.subtract(bodies[i].pos);
            double dist = dir.length();
            if (dist < 1)
            {
                dist = 1;
            }
            Vector2 n = dir.multiply(1.0 / dist);
            double accVal = G * bodies[j].m / (dist * dist);
            bodies[i].acc = bodies[i].acc.add(
                    n.multiply(accVal)
            );
        }
    }
}

void Simulation::mergeCollisions()
{
    for (int i = 0; i < bodies.size(); i++)
    {
        for (int j = i + 1; j < bodies.size(); j++)
        {
            Vector2 diff = bodies[j].pos.subtract(bodies[i].pos);
            double dist = diff.length();
            double minDist = bodies[i].rad + bodies[j].rad;
            if (dist < minDist)
            {
                double newM = bodies[i].m + bodies[j].m;
                Vector2 newPos = bodies[i].pos.multiply(bodies[i].m)
                        .add(bodies[j].pos.multiply(bodies[j].m))
                        .multiply(1.0 / newM);
                Vector2 newVel = bodies[i].vel.multiply(bodies[i].m)
                        .add(bodies[j].vel.multiply(bodies[j].m))
                        .multiply(1.0 / newM);
                double newRad = std::sqrt(
                        bodies[i].rad * bodies[i].rad +
                        bodies[j].rad * bodies[j].rad
                );
                bodies[i].m = newM;
                bodies[i].pos = newPos;
                bodies[i].vel = newVel;
                bodies[i].rad = newRad;
                bodies.erase(bodies.begin() + j);
                j--;
            }
        }
    }
}
