#include <math.h>
#include "shapes.h"

Shapes::Shapes(qglviewer::Vec pos,qglviewer::Vec vel,float hoek, float angvel, float l, float bh, float th, float rad):
    position(pos),velocity(vel),angle(hoek), angularvelocity(angvel), length(l), baseheight(bh), topheight(th), radius(rad){

}


void Shapes::drawCylinder()
{
    glBegin(GL_TRIANGLE_FAN);
    float angle =  2 * M_PI/360;


    for(int i=0; i<360; i++){
        glNormal3f(0.0,0.0,1.0);
        glVertex3f(0.0,0.0,length/2);
        glVertex3f(baseheight*sin(i*angle),baseheight*cos(i*angle),length/2);
        glVertex3f(baseheight*sin((i+1)*angle),baseheight*cos((i+1)*angle),length/2);
    }


    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    for(int i=0; i<360; i++){
        glNormal3f(0.0,0.0,-1.0);
        glVertex3f(0.0,0.0,-length/2);
        glVertex3f(baseheight*sin(i*angle),baseheight*cos(i*angle),-length/2);
        glVertex3f(baseheight*sin((i+1)*angle),baseheight*cos((i+1)*angle),-length/2);
    }

    glEnd();

    glBegin(GL_QUADS);
    for(int i=0; i<360; i++){
        glNormal3f(sin(i*angle),cos(i*angle),0.0);
        glVertex3f(baseheight*sin(i*angle),baseheight*cos(i*angle),length/2);
        glVertex3f(baseheight*sin(i*angle),baseheight*cos(i*angle),-length/2);
        glVertex3f(baseheight*sin(angle),baseheight*cos(angle),-length/2);
        glVertex3f(baseheight*sin(angle),baseheight*cos(angle),length/2);
    }

    glEnd();


}

void Shapes::drawConeNotCentered(){

    glTranslatef(position.x, position.y,position.z);
    glRotatef(angle,0.0,0.0,1.0);

    glBegin(GL_TRIANGLE_FAN);
    float angle =  2 * M_PI/360;


    for(int i=0; i<360; i++){
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,baseheight*sin(i*angle),baseheight*cos(i*angle));
        glVertex3f(0.0,baseheight*sin((i+1)*angle),baseheight*cos((i+1)*angle));
    }

    glEnd();

    glBegin(GL_TRIANGLES);

    for(int i=0; i<360; i++){
        glNormal3f(tan(baseheight/length),sin(i*angle),cos(i*angle));
        glVertex3f(0.0,baseheight*sin(i*angle),baseheight*cos(i*angle));
        glVertex3f(0.0,baseheight*sin((i+1)*angle),baseheight*cos((i+1)*angle));
        glVertex3f(length, 0.0,0.0);
    }
    glEnd();

}

void Shapes::drawCylConeNotCentered(){

    glTranslatef(position.x, position.y,position.z);
    glRotatef(angle,0.0,0.0,1.0);

    glBegin(GL_TRIANGLE_FAN);
    float angle = 2 * M_PI/360;

    for(int i=0; i<360; i++){
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,baseheight*sin(i*angle),baseheight*cos(i*angle));
        glVertex3f(0.0,baseheight*sin((i+1)*angle),baseheight*cos((i+1)*angle));
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    for(int i=0; i<360; i++){
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(length,0.0,0.0);
        glVertex3f(length,topheight*sin(i*angle),topheight*cos(i*angle));
        glVertex3f(length,topheight*sin((i+1)*angle),topheight*cos((i+1)*angle));
    }

    glEnd();

    glBegin(GL_QUADS);

    for(int i=0; i<360; i++){
        glNormal3f(0.0,sin(i*angle),cos(i*angle));
        glVertex3f(0.0, baseheight*sin(i*angle),baseheight*cos(i*angle));
        glVertex3f(length,topheight*sin(i*angle),topheight*cos(i*angle));
        glVertex3f(length,topheight*sin(angle),topheight*cos(angle));
        glVertex3f(0.0,baseheight*sin(angle),baseheight*cos(angle));
    }

    glEnd();


}

void Shapes::drawCylCone(){

    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle, 0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    float angle =  2 * M_PI/360;


    for(int i=0; i<360; i++){
        glNormal3f(-1.0,0.0,0.0);
        glVertex3f(-length/2,0.0,0.0);
        glVertex3f(-length/2,baseheight*sin(i*angle),baseheight*cos(i*angle));
        glVertex3f(-length/2,baseheight*sin((i+1)*angle),baseheight*cos((i+1)*angle));
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    for(int i=0; i<360; i++){
        glNormal3f(1.0,0.0,0.0);
        glVertex3f(length/2,0.0,0.0);
        glVertex3f(length/2,topheight*sin(i*angle),topheight*cos(i*angle));
        glVertex3f(length/2,topheight*sin((i+1)*angle),topheight*cos((i+1)*angle));
    }

    glEnd();

    glBegin(GL_QUADS);

    for(int i=0; i<360; i++){
        glNormal3f(0.0,sin(i*angle),cos(i*angle));
        glVertex3f(-length/2, baseheight*sin(i*angle),baseheight*cos(i*angle));
        glVertex3f(length/2,topheight*sin(i*angle),topheight*cos(i*angle));
        glVertex3f(length/2,topheight*sin(angle),topheight*cos(angle));
        glVertex3f(-length/2,baseheight*sin(angle),baseheight*cos(angle));
    }

    glEnd();

    glPopMatrix();

}

void Shapes::drawSphere(){

    glTranslatef(position.x, position.y, position.z);

    glutSolidSphere(radius,12,12);
}

void Shapes::setAngle(const float &hoek){
    angle = hoek;
}

const float & Shapes::getAngle() const{
    return angle;
}

void Shapes::incrAngle(const float &hoek){
    angle += hoek;
}

void Shapes::decrAngle(const float &hoek){
    angle -= hoek;
}

void Shapes::incrPosition(const qglviewer::Vec &pos){
    position +=pos;
}

void Shapes::incrVelocity(const qglviewer::Vec &vel){
    velocity +=vel;
}

void Shapes::setVelocity(const qglviewer::Vec &vel){
    velocity = vel;
}

const qglviewer::Vec & Shapes::getVelocity() const{
    return velocity;
}

const float & Shapes::getAngluarVelocity() const{
    return angularvelocity;
}

void Shapes::setAngularVelocity(const float &angvel){
    angularvelocity = angvel;
}

const qglviewer::Vec & Shapes::getPosition() const{
    return position;
}

void Shapes::setPosition(const qglviewer::Vec &pos){
    position = pos;
}
