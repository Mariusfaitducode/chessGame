#ifndef VECTOR2_H
#define VECTOR2_H


class Vector2
{
public:
    Vector2() = delete;
    Vector2(int x, int y);

    void setVector(int x, int y);

    int getX();
    int getY();

private:
    int _x;
    int _y;
};

#endif // VECTOR2_H
