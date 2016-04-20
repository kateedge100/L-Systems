#include "branch.h"
#include "turtle.h"





Branch::Branch()
{


}


void Branch::drawRecurse(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) return;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    GLUquadricObj*qobj = gluNewQuadric();


    glPushMatrix();
    glRotatef(90.0f,1.0f, 0.0f, 0.0f);
    gluCylinder(qobj,
                0.01,
                0.012,
                0.5,
                50,
                50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f,0.5f,0.0f);
    drawRecurse(currentDepth+1,maxDepth);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-10.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f,0.5f,0.0f);
    drawRecurse(currentDepth+1,maxDepth);
    glPopMatrix();


    glPopMatrix();
}

void Branch::createBranch(float m_w,float m_length)
{




std::cout << "Branch::createBranch()\n";
    //glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glTranslatef(0.0f,m_length,0.0f);


    glPushMatrix();
    GLUquadricObj*qobj = gluNewQuadric();
    //glTranslatef(0.0f,-0.4f,0.0f);
    //glRotatef(90,0.0f,1.0f,0.0f);
    glRotatef(90,1.0f,0.0f,0.0f);


    gluCylinder(qobj,
                m_w,
                m_w,
                m_length,
                50,
                50);




    gluDeleteQuadric(qobj);
    glPopMatrix();






    //moves cylinder up each time drawn by length










/*
    glPushMatrix();
    GLUquadricObj*qobj = gluNewQuadric();
    glTranslated(-0.2,0,-0.4);
    glRotatef(90,0.0f,1.0f,0.0f);
    glRotatef(90,1.0f,0.0f,0.0f);
    gluCylinder(qobj,
                0.01,
                0.012,
                0.5,
                50,
                50);
    //gluDeleteQuadric(qobj);
    //glTranslated(0,0.75,0);
    glPopMatrix();

    */

    std::cout<<"branch drawn\n";



}


