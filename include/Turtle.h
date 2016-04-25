#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include "Lsystems.h"

class Turtle
{
public:
    Turtle();
    void Draw(const LSystems &l, float _w, float _length);
    void rotateLeft();
    void rotateRight();
    void pitchUp();
    void pitchDown();
    void rollLeft();
    void rollRight();
    void push();
    void pop();
    void setAngle(float _angle);
    void createBranch();
    float m_depth;
    float m_angle;

private:
     float m_width;
     float m_length;

};

#endif // TURTLE_H
