#include <iostream>
using namespace std;
#include "Cylinder.h"
#include "math.h"

float cpx [361];
float cpy [361];




/*
          Z
          | 
    7 +-------+ 6
     /|      /|
    / |     / |   ---> Y
 4 +-------+5 |
   | 3+----|--+ 2
   | /     | /
   |/      |/
 0 +-------+ 1
      /
     X         
*/

const float DEG2RAD = 3.14159/180;
void Cylinder::init(Viewer &)
{}

void Cylinder::draw()
{
			CirclePoints();

			 glPushMatrix();
        {
           // glTranslatef(0, sin_t * (float)(-1/ (2 + speed)), 1);

            // Torso & tail
            glPushMatrix();
            {
                // Torso:
                {  
                    //z1,r1,z2,r2
                    // cone before the neck
                    drawHull(0.5f, 0.5f, -0.5f, 1.0f);
                    glTranslatef(0, 0, -0.5f);

                    // cone before the tail
                    drawHull(0, 1, -2, 0.5f);
                    glTranslatef(0, 0, -2);
                }

                // Tail:
                {
                    // tail element 1
                    glRotatef(-10, 0, 1, 0);
                    drawHull(0, 0.5f, -1, 0.3f);
                    glTranslatef(0, 0, -1);

                    // tail element 2
                    glRotatef(15, 1, 0, 0);
                    drawHull(0.07f, 0.3f, -0.93f, 0.2f);
                    glTranslatef(0, 0, -0.86f);

                    // tail element 3
                    glRotatef(35, 1, 0, 0);
                    drawHull(0.1f, 0.2f, -0.7f, 0.1f);
                    drawFan2(-0.7f, 0.1f);
                }
            }
            glPopMatrix();

            // Head:
            glPushMatrix();
            {
                // neck
                glTranslatef(0, 0, 0.7f);
                drawHull(0.2f, 0.4f, -0.2f, 0.5f);

                // head
                glRotatef(20, 1, 0, 0);
                drawCylinder(1, 0.2f, 0, 0.55f);
            }
            glPopMatrix();

            // Wings:
            // float angle = sin_t * 30 + 7;

             drawWing(20, true);
             drawWing(10, false);
        }
        glPopMatrix();


	

}


//==================== 1. Immediate method ===================================
// immediate definition of individual vertex properties
// you specify the height   ,x , y , z coorinates and the radius of the bottom circle and up circle
void Cylinder::CirclePoints()
{


            
             int i ;
                for ( i =0 ; i<= 360 ; i++)
            {
            
            float theta = 2.0f * 3.1415926f * float(i) / float(360);//get the current angle
            float tempx =  cosf(theta);//calculate the x component
            float tempy =  sinf(theta);//calculate the y component
            cpx[i]=tempx;
            cpy[i]=tempy;
    	    }
 
}

void Cylinder::drawHull(float z1, float r1, float z2, float r2) {
       
        glBegin(GL_QUAD_STRIP);
        {
        	int i;
            for ( i = 0 ; i <= 361; ++i) {
                glNormal3f(cpx[i], cpy[i], 0);
                glVertex3f(cpx[i] * r1, cpy[i] * r1, z1);
                glVertex3f(cpx[i] * r2, cpy[i] * r2, z2);
            }
        }
        glEnd();

    }


     void Cylinder::drawFan1(float z, float r) {
    
        glBegin(GL_TRIANGLE_FAN);
        {
            glNormal3f(0, 0, z);
            glVertex3f(0, 0, z);
            int i;
            for ( i = 0;i <= 361; ++i) {
                glVertex3f(cpx[i] * r, cpy[i] * r, z);
            }
        }
        glEnd();
    }

     void Cylinder::drawFan2(float z, float r) {
   
        glBegin(GL_TRIANGLE_FAN);
        {
            glNormal3f(0, 0, z);
            glVertex3f(0, 0, z);
            int i;
            for ( i = 361; i >= 0; --i) {
                glVertex3f(cpx[i] * r, cpy[i] * r, z);
            }
        }
        glEnd();
    }


    void Cylinder::drawCylinder(float z1, float r1, float z2, float r2) 
    {
        drawHull(z1, r1, z2, r2);
        drawFan1(z1, r1);
        drawFan2(z2, r2);
    }


    void Cylinder::drawWing(float angle, bool left) {
        float v = left ? 1  : -1;
        glPushMatrix();
        {
            glRotatef(angle * v, 0, 0, 1);
            glScalef(v, 1, 1);

            // top of the wing
            glBegin(GL_TRIANGLE_FAN);
            {
                glNormal3f(0, 1, 0);
                glVertex3f(2, 0.5f, 1);

                glVertex3f(0, 0, 0);
                glVertex3f(0, 0, -1);
                glVertex3f(1.5f, 0.2f, -1);
                glVertex3f(3, 1, -2);
                glVertex3f(6, 0.7f, -1);
            }
            glEnd();

            // bottom of the wing
            glBegin(GL_TRIANGLE_FAN);
            {
                glNormal3f(0, 1, 0);
                glVertex3f(2, 0.5f, 1);

                glVertex3f(6, 0.7f, -1);
                glVertex3f(3, 1, -2);
                glVertex3f(1.5f, 0.2f, -1);
                glVertex3f(0, 0, -1);
                glVertex3f(0, 0, 0);
            }
            glEnd();
        }
        glPopMatrix();

    }

