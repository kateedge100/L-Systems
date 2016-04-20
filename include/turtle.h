#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include <math.h>
#include "lsystems.h"
#include "branch.h"


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
    void push(float m_w);
    void pop(float m_w);
    void setAngle();
    float m_depth;


private:
    float m_angle;







};

#endif // TURTLE_H
