#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include <math.h>
#include "Lsystems.h"
#include "Branch.h"


class Turtle
{
public:
    Turtle();
    void Draw(const LSystems &l, float m_w, float m_length);
    void rotateLeft();
    void rotateRight();
    void pitchUp();
    void pitchDown();
    void rollLeft();
    void rollRight();
    void push();
    void pop();
    void setAngle(float _angle);
    float m_depth;
    float m_angle;
    float m_width;



private:










};

#endif // TURTLE_H
