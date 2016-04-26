#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include "Lsystems.h"

/// \author Kate Edge
/// \version 1.0
/// \date 26/4/2016
/// \class Turtle
/// \brief Stores infomation needed to draw tree

class Turtle
{
public:
    float m_angle;
    Turtle();
    void Draw(const LSystems &l, const float _w, const float _length);
    void rotateLeft();
    void rotateRight();
    void pitchUp();
    void pitchDown();
    void rollLeft();
    void rollRight();
    void push();
    void pop();
    void setAngle(const float _angle);
    void createBranch();
    void setAngle();


private:
     float m_width;
     float m_length;
};

#endif // TURTLE_H
