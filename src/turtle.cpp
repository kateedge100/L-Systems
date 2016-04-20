#include "turtle.h"
#include "branch.h"
#include "lsystems.h"
#include <GLFunctions.h>
#include <iostream>
#include <fstream>

Turtle::Turtle()
{

}

void Turtle::setAngle()
{
    std::string angle;

    std::ifstream inputAngle("Angle1.txt");

    std::getline(inputAngle,angle);

    m_angle= std::stod(angle);




    std::cout<<"Angle assigned is "<<m_angle<<"\n";
}



void Turtle::rotateLeft()
{

    glRotatef(30,0.0f,0.0f,1.0f);

}


void Turtle::rotateRight()
{

   glRotatef(-30,0.0f,0.0f,1.0f);

}


void Turtle::rollLeft()
{
    glRotatef(30,0,1,0);

}

void Turtle::rollRight()
{
    glRotatef(-30,0,1,0);
}

void Turtle::pitchUp()
{
    glRotatef(-30,1.0f,0.0f,0.0f);

}

void Turtle::pitchDown()
{
    glRotatef(30,1.0f,0.0f,0.0f);

}


void Turtle::push(float m_w)
{
   glPushMatrix();

    if(m_depth>0.8)
   {
     m_depth-=0.1;
   }

}

void Turtle::pop(float m_w)
{
   glPopMatrix();

   if(m_depth< 1.3)
   {
     m_depth+=0.1;
  }

}





void Turtle::Draw(const LSystems &l, float m_w, float m_length)
{


   m_depth=1;


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

                Branch b;
                // creat branch and set width
                b.createBranch(m_w*m_depth,m_length);



               // std::cout<<"F Read\n";


            // jumps to next character
            i=i+1;
            }
            else if(currentChar.compare("+")== 0)
            {

                rotateRight();


                //std::cout<<"rotate right\n";

                i=i+1;
            }
            else if(currentChar.compare("-")==0)
            {
                rotateLeft();

               // std::cout<<"rotate left\n";

                i=i+1;
            }
            else if(currentChar.compare("&")==0)
            {
                pitchDown();

               // std::cout<<"rotate left\n";

                i=i+1;
            }
            else if(currentChar.compare("^")==0)
            {
                pitchUp();

               // std::cout<<"rotate left\n";

                i=i+1;
            }
            else if(currentChar.compare("\ ") ==0)
            {
                rollLeft();

                //std::cout<<"rotate left\n";

                i=i+1;
            }
            else if(currentChar.compare("/") ==0)
            {
                rollRight();

                //std::cout<<"rotate left\n";

                i=i+1;
            }

            else if(currentChar.compare("[")==0)
            {
                push(m_w);
               // std::cout<<"push\n";
                i=i+1;
            }
            else if(currentChar.compare("]")==0)
            {
                pop(m_w);
               // std::cout<<"pop\n";
                i=i+1;
            }

            else
            {  // if non action character move to next character
                i=i+1;
            }

          }


        }


}

