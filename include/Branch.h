#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>



class Branch
{
public :
  Branch();
  float Ratio();
  float setRatio();
  int Colour();
  std::string setColour();
  float widthDecrease() const;
  void createBranch(float m_w, float m_length);
  void drawRecurse(int,int);

private :

float m_length;
int m_ratio;
std::string m_colour;
float m_w;



};

#endif // BRANCH_H
