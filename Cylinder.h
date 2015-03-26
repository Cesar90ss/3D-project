#ifndef _CYLINDER_
#define _CYLINDER_

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Cylinder : public Renderable
{
public:
   void init(Viewer &);
	void draw();

private:
	void CirclePoints();
	void drawHull(float z1, float r1, float z2, float r2);
	  void drawFan1(float z, float r) ;
	  void drawFan2(float z, float r) ;
	  void drawCylinder(float z1, float r1, float z2, float r2) ;
	    void drawWing(float angle, bool left);

    //void drawElements();
    //void drawArrays();
};

#endif

