#include "vector2.h"

Vector2::Vector2(int x, int y) : _x(x), _y(y)
{
}

void Vector2:: setVector(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

int Vector2:: getX()
{
    return this->_x;
}

int Vector2:: getY()
{
    return this->_y;
}
