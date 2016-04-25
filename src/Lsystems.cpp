#include "Lsystems.h"
#include "Turtle.h"
#include "Branch.h"
#include <iostream>
#include <fstream>


#include <SDL/SDL.h>

#include <stdio.h>
#include <stdlib.h>



LSystems::LSystems()
{
    m_treeOption=1;
    m_iterations=0;
    m_maxIterations=3;


}



void LSystems::createLeaf()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2,0);
    glBegin(GL_TRIANGLES);

                glVertex3f(0, 0, 0);
                glVertex3f(0.2, 0, 0.3);
                glVertex3f(0, 1, 0);
                glVertex3f(0, 0, 0);
                glVertex3f(-0.2, 0, -0.3);
                glVertex3f(0, 1, 0);
                glEnd();
                glPopMatrix();


}

LSystems::~LSystems()
{

    m_str.clear();

}

void LSystems::selectTree(int option)
{
    m_treeOption=option;

}

void LSystems::setAxiom()
{
    if(m_treeOption==1)
    {

    std::ifstream inputAxiom("Axiom1.txt");

    std::getline(inputAxiom,m_axiom);
    }

    else if(m_treeOption==2)
    {

    std::ifstream inputAxiom("Axiom2.txt");

    std::getline(inputAxiom,m_axiom);
    }


    std::cout<<"axiom assigned is "<<m_axiom<<"\n";

}

void LSystems::setAlphabet()
{
    if(m_treeOption==1)
    {

    std::ifstream inputAlphabet("Alphabet1.txt");

    std::getline(inputAlphabet,m_alphabet);
    }

    else if(m_treeOption==2)
    {

    std::ifstream inputAlphabet("Alphabet2.txt");

    std::getline(inputAlphabet,m_alphabet);
    }



    std::cout<<"alphabet assigned is "<<m_alphabet<<"\n";

}



void LSystems::setRule()
{
    if (m_treeOption == 1)
    {
    std::ifstream inputRule("Rule1.txt");
    std::getline(inputRule,m_axiomRule);
    }

    else if (m_treeOption == 2)
    {
    std::ifstream inputRule("Rule2.txt");
    std::getline(inputRule,m_axiomRule);
    }

    std::cout<<"Rule assigned is "<<m_axiomRule<<"\n";

}

void LSystems::setAlphabetRule()
{
    if (m_treeOption == 1)
    {

    std::ifstream inputAlphabetRule("AlphabetRule1.txt");

    std::getline(inputAlphabetRule,m_alphabetRule);
    }


    else if (m_treeOption == 2)
    {

    std::ifstream inputAlphabetRule("AlphabetRule2.txt");

    std::getline(inputAlphabetRule,m_alphabetRule);
    }


    std::cout<<"Alphabet assigned is "<<m_alphabetRule<<"\n";
}


void LSystems::productions(int m_iterations)
{

    //m_axiom = "X";
    // assignes string axiom will be replaced with
    //m_axiomRule = "F-[[X]+X]+F[+FX";

    //m_alphabet = "B";
    //m_alphabetRule = "F[-X]B";

    int axRuleLength= m_axiomRule.length();
    int alRuleLength = m_alphabetRule.length();



    //creates string to store rule
    m_str = "F";
    // creates string to access each character in str
    std::string m_ch = "";
    // inserts axiom into rule
    m_str.insert(1,m_axiom);

    //prints axiom
    std::cout<<"axiom\n"<<m_str<< "\n";

     // add timer that increases iteration from 0 to selected number every 2 second to create appearence of growing

  // reference https://github.com/paluka/L-Systems-OpenGL/blob/master/src/Paluka-L-System.cpp

  // iteration rule to number of iterations
  for(int n=1;n<=m_iterations;n++)
  {

    std::cout<<"iteration "<<n<<""<<std::endl;
    // begins comparing at beginning of string at each iteraion
    unsigned long i =0;

    //Go through each character until last character
    while(i!= m_str.length())
    {
      m_ch=m_str.at(i);

      if(m_ch.compare(m_axiom) == 0)
      {   // if current character is axiom replaces with axiomRule
      m_str.replace(i,1,m_axiomRule);
      // jumps to character after replaced section to compare
      i=i+axRuleLength;
      }
      else if(m_ch.compare(m_alphabet)== 0)
      {
        m_str.replace(i,1,m_alphabetRule);
        i=i+alRuleLength;
      }
      else
      {
          i=i+1;
      }



    }

    // prints updated string
    std::cout << m_str << "\n";



  }

}
