#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "Body.h"

class Simulation
{
public:
    std::vector<Body> bodies;
    double G;
    Simulation();
    void addBody(Body body);
    void update(double dt);
    void computeGravity();
    void mergeCollisions();
};

#endif