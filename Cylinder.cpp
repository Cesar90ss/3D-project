#include <iostream>
using namespace std;
#include "Cylinder.h"
#include "math.h"

float saved_valuesx1 [361];
float saved_valuesy1 [361];




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
    glPushMatrix();
    {
         glTranslatef(0,0,0);
         glRotatef(0, 0, 0, 0);
         DrawCylinder(3,0,0,0,2.2);


    } 
     glPushMatrix();
    {
         glTranslatef(0,0,2.7);
         glRotatef(10, 0, 1, 0);
         DrawCylinder(2.8,0,0,0,2.1);
    }  
    glPopMatrix();

      glPushMatrix();
    {
         glTranslatef(0.3,0,5.2);
         glRotatef(20, 0, 1, 0);
         DrawCylinder(3.2,0,0,0,1.8);
    }  
    glPopMatrix();

	glPushMatrix();
    {
         glTranslatef(1.1,0,7.9);
         glRotatef(35, 0, 1, 0);
         DrawCylinder(3.5,0,0,0,1.5);
    }  
    glPopMatrix();

    glPushMatrix();
    {
         glTranslatef(3.2,0,10.6);
         glRotatef(43, 0, 1, 0);
         DrawCylinder(3.8,0,0,0,1.2);
    }  
    glPopMatrix();

    glPushMatrix();
    {
         glTranslatef(5.8,0,13.1);
         glRotatef(52, 0, 1, 0);
         DrawCylinder(2,0,0,0,0.9);
    }  
    glPopMatrix();

      glPushMatrix();
    {
         glTranslatef(7,0,14);
         glRotatef(59, 0, 1, 0);
         DrawCylinder(2.5,0,0,0,0.5);
    }  
    glPopMatrix();


    // glPushMatrix();
    // {
    //      glTranslatef(0.4,0,2.7);
    //      glRotatef(35, 0, 1, 0);
    //      DrawCylinder(3,0,0,0,1.8);
    // }  
    // glPopMatrix();

    // glPushMatrix();
    // {
    //      glTranslatef(0.4,0,3.7);
    //      glRotatef(30, 0, 1, 0);
    //      DrawCylinder(3,0,0,0,1.8);
    // }  
    // glPopMatrix();


    //    glPushMatrix();
    // {
    //      glTranslatef(0,0,4.7);
    //      glRotatef(30, 0, 1, 0);
    //      DrawCylinder(4,0,0,0,1.5);
    // }  
    // glPopMatrix();

    //   glPushMatrix();
    // {
    //      glTranslatef(0,0,4.7);
    //      glRotatef(30, 0, 1, 0);
    //      DrawCylinder(6,0,0,0,1.2);
    // }  
    // glPopMatrix();
  
  
    
	

}


//==================== 1. Immediate method ===================================
// immediate definition of individual vertex properties

void Cylinder::DrawCylinder(float height , float xbase , float ybase,float zbase,float radius)
{

            

             //Bottom circle
             glBegin(GL_TRIANGLE_FAN);
             glNormal3f(0.0, 0.0, -1);
             glVertex3f ( xbase, ybase, zbase);
             int i ;
                for ( i =0 ; i<= 360 ; i++)
            {
            
            float theta = 2.0f * 3.1415926f * float(i) / float(360);//get the current angle
            float tempx = radius * cosf(theta);//calculate the x component
            float tempy = radius * sinf(theta);//calculate the y component
            saved_valuesx1[i]=tempx+xbase;
            saved_valuesy1[i]=tempy+ybase;
            glVertex3f(tempx+xbase, tempy +ybase,zbase);       
            }
            glVertex3f(saved_valuesx1[0],saved_valuesy1[0], zbase);  
            glEnd();
            //Top Circle
            glBegin(GL_TRIANGLE_FAN);
            glNormal3f(0.0, 0.0, 1);
            glVertex3f ( xbase, ybase, zbase+height);
                for ( i =0 ; i<= 360 ; i++)
            {
            float theta = 2.0f * 3.1415926f * float(i) / float(360);//get the current angle
            float tempx = radius * cosf(theta);//calculate the x component
            float tempy = radius * sinf(theta);//calculate the y component
            glVertex3f(tempx+xbase, tempy +ybase,zbase+height);//output vertex        
            }
            glVertex3f(saved_valuesx1[0],saved_valuesy1[0], zbase+height);
            glEnd();
                    
            //Draw the rectangeles
             glBegin(GL_QUADS);                      // Draw A Quad
             for (i=0;i<356;i++)
             {
            glNormal3f(saved_valuesx1[i],saved_valuesy1[i], zbase);          
            glVertex3f(saved_valuesx1[i],saved_valuesy1[i], zbase);  
                    // Top Left
            glNormal3f(saved_valuesx1[i+5],saved_valuesy1[i+5], zbase);
            glVertex3f(saved_valuesx1[i+5],saved_valuesy1[i+5], zbase);  
                   // Top Right
            glNormal3f(saved_valuesx1[i+5],saved_valuesy1[i+5], zbase+height);
            glVertex3f(saved_valuesx1[i+5],saved_valuesy1[i+5], zbase+height);

            glNormal3f(saved_valuesx1[i],saved_valuesy1[i], zbase+height);    
            glVertex3f(saved_valuesx1[i],saved_valuesy1[i], zbase+height);    
            }
            glEnd(); 
    
}


