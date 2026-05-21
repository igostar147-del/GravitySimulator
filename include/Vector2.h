#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    double x;
    double y;
    Vector2();
    Vector2(double x, double y);
    Vector2 add(const Vector2& other) const;
    Vector2 subtract(const Vector2& other) const;
    Vector2 multiply(double value) const;
    double length() const;
};

#endif