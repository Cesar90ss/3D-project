#include <iostream>
using namespace std;
#include "Cylinder.h"
#include "math.h"

float saved_valuesx1 [361];
float saved_valuesy1 [361];
float saved_valuesx2 [361];
float saved_valuesy2 [361];




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
                    //z1,r1,z2,r2
                    // cone before the neck
         		  DrawCylinder(10,0,0,0,0.5,4);
                  //  drawHull(0.5f, 0.5f, -0.5f, 1f);
                    glTranslatef(0, 0, -0.5f);

                    // cone before the tail
                  // //  drawHull(0, 1, -2, 0.5f);
                    //   DrawCylinder(1,0,0,0,1,0.5);
                    // glTranslatef(0, 0, -2);
                }

                 glPopMatrix();

    // glPushMatrix();
    // {
    //      glTranslatef(0,0,10);
    //      glRotatef(90, 0, 0, 1);
    //      DrawCylinder(10,0,0,0,2);


    // } 
    


    //   glPushMatrix();
    // {
    //      glTranslatef(0,0,0);
    //      glRotatef(0, 0, 0, 0);
    //      DrawCylinder(6,0,0,0,0.5);


    // } 
    //   glPushMatrix();
    // {
    //      glTranslatef(0.3,0,5.2);
    //      glRotatef(20, 0, 1, 0);
    //      DrawCylinder(3.2,0,0,0,1.8);
    // }  
    // glPopMatrix();

  
    
	

}


//==================== 1. Immediate method ===================================
// immediate definition of individual vertex properties
// you specify the height   ,x , y , z coorinates and the radius of the bottom circle and up circle
void Cylinder::DrawCylinder(float height , float xbase , float ybase,float zbase,float radius1,float radius2)
{

            

             //Bottom circle
             glBegin(GL_TRIANGLE_FAN);
             glNormal3f(0.0, 0.0, -1);
             glVertex3f ( xbase, ybase, zbase);
             int i ;
                for ( i =0 ; i<= 360 ; i++)
            {
            
            float theta = 2.0f * 3.1415926f * float(i) / float(360);//get the current angle
            float tempx = radius1 * cosf(theta);//calculate the x component
            float tempy = radius1 * sinf(theta);//calculate the y component
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
            float tempx = radius2 * cosf(theta);//calculate the x component
            float tempy = radius2 * sinf(theta);//calculate the y component
            saved_valuesx2[i]=tempx+xbase;
            saved_valuesy2[i]=tempy+ybase;
            glVertex3f(tempx+xbase, tempy +ybase,zbase+height);//output vertex        
            }
            glVertex3f(saved_valuesx2[0],saved_valuesy2[0], zbase+height);
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
            glNormal3f(saved_valuesx2[i+5],saved_valuesy2[i+5], zbase+height);
            glVertex3f(saved_valuesx2[i+5],saved_valuesy2[i+5], zbase+height);

            glNormal3f(saved_valuesx2[i],saved_valuesy2[i], zbase+height);    
            glVertex3f(saved_valuesx2[i],saved_valuesy2[i], zbase+height);    
            }
            glEnd(); 
    
}


