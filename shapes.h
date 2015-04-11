#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glut.h>
#include <QGLViewer/vec.h>
#include <iostream>


using namespace std;

class Shapes
{
public:
    Shapes(qglviewer::Vec pos, qglviewer::Vec vel, float hoek, float angvel, float l, float bh, float th, float rad);
    void drawCylinder();
    void drawConeNotCentered();
    void drawCylCone();
    void drawCylConeNotCentered();
    void drawSphere();

    void setAngle(const float &hoek);
    void setPosition(const qglviewer::Vec &pos);
    void setVelocity(const qglviewer::Vec &vel);
    void setAngularVelocity(const float &angvel);

    const float & getAngle() const;
    const qglviewer::Vec & getPosition() const;
    const qglviewer::Vec & getVelocity() const;
    const float & getAngluarVelocity() const;

    void incrAngle(const float &hoek);
    void decrAngle(const float &hoek);
    void incrAngluarVelocity(const float &angvel);
    void incrPosition(const qglviewer::Vec &pos);
    void incrVelocity(const qglviewer::Vec &vel);

private:
    qglviewer::Vec position;
    qglviewer::Vec velocity;
    float angle;
    float angularvelocity;

    float length;
    float baseheight;
    float topheight;
    float radius;
};

#endif // SHAPES_H
