///
///  @file Turtle.cpp
///  @brief takes the rule produced in Lsystems.cpp and uses it to create a tree

#include "Turtle.h"
#include "Lsystems.h"
#include <iostream>
#include <fstream>
#include "GL/gl.h"
#include "GL/glu.h"


//----------------------------------------------------------------------------------------------------------------------


Turtle::Turtle()
{
  m_angle=30;
}


//----------------------------------------------------------------------------------------------------------------------


void Turtle::createBranch()
{
  glMatrixMode(GL_MODELVIEW);
  glTranslatef(0.0f,m_length,0.0f);

  glPushMatrix();
  GLUquadricObj*qobj = gluNewQuadric();
  glRotatef(90,1.0f,0.0f,0.0f);
  gluCylinder(qobj,
              m_width,
              m_width,
              m_length,
              50,
              50);
  gluDeleteQuadric(qobj);
  glPopMatrix();
}


//----------------------------------------------------------------------------------------------------------------------


void Turtle::setAngle(const float _angle)
{
  m_angle=_angle;

  std::cout<<"Angle assigned is "<<m_angle<<"\n";
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::rotateLeft()
{
  glRotatef(m_angle,0.0f,0.0f,1.0f);
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::rotateRight()
{
   glRotatef(-m_angle,0.0f,0.0f,1.0f);
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::rollLeft()
{
  glRotatef(m_angle,0,1,0);
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::rollRight()
{
  glRotatef(-m_angle,0,1,0);
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::pitchUp()
{
  glRotatef(m_angle,1.0f,0.0f,0.0f);
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::pitchDown()
{
  glRotatef(-m_angle,1.0f,0.0f,0.0f);
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::push()
{
  glPushMatrix();
  // so width cant be less then 0.008
  if(m_width>= 0.008)
 {
   m_width-=0.008;
 }

}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::pop()
{
  glPopMatrix();

  // so width cant be less then 0
  if(m_width<0.03)
  {
    m_width+=0.008;
  }
}

//----------------------------------------------------------------------------------------------------------------------


void Turtle::Draw(const LSystems &l, const float _w, const float _length)
{
  m_width=_w;
  m_length=_length;

  //Sets drawingRule equil to final iteraltion of m_str
  const std::string& drawingRule = l.getDrawingRule();
  std::string currentChar = "";

  std::cout<<"Drawing Rule\n"<<drawingRule<<"\n";

  // begins comparing at beginning of string at each iteraion
  unsigned long i =0;

  //Go through each character until last character
  for(i =0; i<drawingRule.length();i++)
  {
    currentChar=drawingRule.at(i);
    std::cout<<drawingRule<<"\n";

    //Go through each character until last character
    while(i!= drawingRule.length())
    {
      currentChar=drawingRule.at(i);

      if(currentChar.compare("F") == 0)
      {
        // create branch and set width
        createBranch();
        // jumps to next character
        i=i+1;
      }
      else if(currentChar.compare("+")== 0)
      {
        rotateRight();
        i=i+1;
      }
      else if(currentChar.compare("-")==0)
      {
        rotateLeft();
        i=i+1;
      }
      else if(currentChar.compare("&")==0)
      {
      pitchDown();
      i=i+1;
      }
      else if(currentChar.compare("^")==0)
      {
        pitchUp();
        i=i+1;
      }
      else if(currentChar.compare("\ ") ==0)
      {
        rollLeft();
        i=i+1;
      }
      else if(currentChar.compare("/") ==0)
      {
        rollRight();
        i=i+1;
      }
      else if(currentChar.compare("[")==0)
      {
        push();
        i=i+1;
      }
      else if(currentChar.compare("]")==0)
      {
        pop();
        i=i+1;
      }
      else
      {
        // if non action character move to next character
        i=i+1;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------


