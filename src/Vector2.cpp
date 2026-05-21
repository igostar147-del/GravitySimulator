#include "../include/Vector2.h"

#include <cmath>

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(double xVal, double yVal)
{
    x = xVal;
    y = yVal;
}

Vector2 Vector2::add(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::subtract(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::multiply(double val) const
{
    return Vector2(x * val, y * val);
}

double Vector2::length() const
{
    return std::sqrt(x * x + y * y);
}