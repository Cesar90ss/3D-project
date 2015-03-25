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
	void DrawCylinder(float height , float xbase , float ybase,float zbase,float radius1 , float radius2);

    //void drawElements();
    //void drawArrays();
};

#endif

