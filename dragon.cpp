#include <iostream>
#include "dragon.h"
#include <math.h>
#include <QGLViewer/vec.h>

using namespace std;



void Dragon::clear(){
    vector<Shapes *>::iterator it;
    for(it = tailparts.begin(); it != tailparts.end(); ++it){
        delete(*it);
    }

    tailparts.clear();
}

void Dragon::init(Viewer &viewer){
    clear();

    tail();

    body();

    //wings();

    //joint();

    chest();

    neck();

    atlas();
}

void Dragon::tail(){
    //add a fixed tail part

    qglviewer::Vec pos0 = qglviewer::Vec(0.0,0.0,0.0);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = 0.0;
    float angvel0 = 0.0;
    tailparts.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 0.5,0.4,0.2,0.0));

    qglviewer::Vec pos1 = qglviewer::Vec(0.45,0.,0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek1 = 0.0;
    float angvel1 = 1.0;
    tailparts.push_back(new Shapes(pos1, vel1, hoek1, angvel1, 0.6,0.2,0.15,0.0));

    qglviewer::Vec pos2 = qglviewer::Vec(0.55,0.0,0.0);
    qglviewer::Vec vel2 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek2 = 0.0;
    float angvel2 = 1.2;
    tailparts.push_back(new Shapes(pos2, vel2, hoek2, angvel2, 0.6,0.15,0.12,0.0));

    qglviewer::Vec pos3 = qglviewer::Vec(0.55,0.0,0.0);
    qglviewer::Vec vel3 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek3 = 0.0;
    float angvel3 = 1.4;
    tailparts.push_back(new Shapes(pos3, vel3, hoek3, angvel3, 0.5,0.12,0.1,0.0));

    qglviewer::Vec pos4 = qglviewer::Vec(0.45,0.0,0.0);
    qglviewer::Vec vel4 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek4 = 0.0;
    float angvel4 = 1.6;
    tailparts.push_back(new Shapes(pos4, vel4, hoek4, angvel4, 0.4,0.1,0.09,0.0));

    qglviewer::Vec pos5 = qglviewer::Vec(0.38,0.0,0.0);
    qglviewer::Vec vel5 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek5 = 0.0;
    float angvel5 = 1.8;
    tailend.push_back(new Shapes(pos5, vel5, hoek5, angvel5, 0.5,0.091,0.0,0.0));

}

void Dragon::body(){
    qglviewer::Vec pos0 = qglviewer::Vec(0.0,0.0,0.0);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = 0.0;
    float angvel0 = 0.0;
    bodyparts.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 0.7,0.45,0.4,0.0));

    qglviewer::Vec pos1 = qglviewer::Vec(-0.7,0.0,0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek1 = 0.0;
    float angvel1 = 0.0;
    bodyparts.push_back(new Shapes(pos1, vel1, hoek1, angvel1, 0.7,0.45,0.45,0.0));

    qglviewer::Vec pos2 = qglviewer::Vec(-0.19,0.01,0.0);
    qglviewer::Vec vel2 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek2 = -2.0;
    float angvel2 = 0.0;
    bodyparts.push_back(new Shapes(pos2, vel2, hoek2, angvel2, 0.2,0.4,0.45,0.0));
}

void Dragon::chest(){
    qglviewer::Vec pos0 = qglviewer::Vec(-0.8,0.0,0.0);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = 0.0;
    float angvel0 = 0.0;
    chestparts.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 0.9,0.45,0.4,0.42));
}

void Dragon::neck(){

    qglviewer::Vec pos0 = qglviewer::Vec(0.2,0.2,0.0);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = -80.0;
    float angvel0 = 0.0;
    neckparts.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 0.1,0.22,0.25,0.0));

    qglviewer::Vec pos1 = qglviewer::Vec(-0.1,0.01,0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek1 = -5.0;
    float angvel1 = 0.0;
    neckparts.push_back(new Shapes(pos1, vel1, hoek1, angvel1, 0.2,0.21,0.22,0.0));

    qglviewer::Vec pos2 = qglviewer::Vec(-0.18,0.015,0.0);
    qglviewer::Vec vel2 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek2 =  -5.0;
    float angvel2 = 0.0;
    neckparts.push_back(new Shapes(pos2, vel2, hoek2, angvel2, 0.2,0.19,0.21,0.0));

    qglviewer::Vec pos3 = qglviewer::Vec(-0.20,0.045,0.0);
    qglviewer::Vec vel3 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek3 =  -10.0;
    float angvel3 = 0.0;
    neckparts.push_back(new Shapes(pos3, vel3, hoek3, angvel3, 0.25,0.17,0.19,0.0));

    qglviewer::Vec pos4 = qglviewer::Vec(-0.4,0.05,0.0);
    qglviewer::Vec vel4 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek4 =  -5.0;
    float angvel4 = 0.0;
    neckparts.push_back(new Shapes(pos4, vel4, hoek4, angvel4, 0.5,0.15,0.17,0.0));

    qglviewer::Vec pos5 = qglviewer::Vec(-0.4,0.01,0.0);
    qglviewer::Vec vel5 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek5 =  -1.0;
    float angvel5 = 0.0;
    neckparts.push_back(new Shapes(pos5, vel5, hoek5, angvel5, 0.4,0.12,0.15,0.0));
}

void Dragon::atlas(){
    qglviewer::Vec pos0 = qglviewer::Vec(-0.8,0.0,0.0);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = 0.0;
    float angvel0 = 0.0;
    atlasparts.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 0.9,0.45,0.4,0.12));
}

/*
void Dragon::wings(){
    qglviewer::Vec pos0 = qglviewer::Vec(-0.7,0.3,0.4);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = 0.0;
    float angvel0 = 0.0;
    wingparts.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 1.7,0.055,0.02,0.0));

    qglviewer::Vec pos1 = qglviewer::Vec(0.0,0.0,0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek1 = 0.0;
    float angvel1 = 0.0;
    wingparts.push_back(new Shapes(pos1, vel1, hoek1, angvel1, 1.7,0.055,0.02,0.0));

    qglviewer::Vec pos2 = qglviewer::Vec(0.0,0.0,0.0);
    qglviewer::Vec vel2 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek2 = 0.0;
    float angvel2 = 0.0;
    wingparts.push_back(new Shapes(pos2, vel2, hoek2, angvel2, 1.7,0.02,0.0,0.0));

}


void Dragon::joint(){
    qglviewer::Vec pos0 = qglviewer::Vec(1.7,0.0,0.0);
    qglviewer::Vec vel0 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek0 = 0.0;
    float angvel0 = 0.0;
    joints.push_back(new Shapes(pos0, vel0, hoek0, angvel0, 0.0,0.0,0.0,0.021));

    qglviewer::Vec pos1= qglviewer::Vec(-1.75,0.0,0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0,0.0,0.0);
    float hoek1 = 0.0;
    float angvel1 = 0.0;
    joints.push_back(new Shapes(pos1, vel1, hoek1, angvel1, 0.0,0.0,0.0,0.1));
}
*/

void Dragon::draw()
{
    vector<Shapes *>::iterator it;

    //body

    glPushMatrix();

    for(it = bodyparts.begin(); it != bodyparts.end(); ++it){
        (*it)->drawCylConeNotCentered();
    }

    glPopMatrix();

    //tail

    glPushMatrix();

    glTranslatef(0.7,0.0,0.0);

    for(it = tailparts.begin(); it != tailparts.end(); ++it){
        (*it)->drawCylConeNotCentered();
    }

    for(it = tailend.begin(); it != tailend.end(); ++it){
        (*it)->drawConeNotCentered();
    }

    glPopMatrix();

    //chest

    glPushMatrix();

    for(it = chestparts.begin(); it != chestparts.end(); ++it){
        (*it)->drawSphere();
    }

    glPopMatrix();

    //neck

    glPushMatrix();
    glTranslatef(-1.18,0.00,0.0);

    for(it = neckparts.begin(); it != neckparts.end(); ++it){
        (*it)->drawCylConeNotCentered();
    }

    glPopMatrix();

    //atlas

    glPushMatrix();
    glTranslatef(0.08,1.45,0.0);

    for(it = atlasparts.begin(); it != atlasparts.end(); ++it){
        (*it)->drawSphere();
    }

    glPopMatrix();

/*    //wings left

    glPushMatrix();

    //glTranslated(-0.7,0.3,0.4);
    //glRotatef(-90, 0.0,1.0,0.0);
    //glRotatef(30,0.0,0.0,1.0);

    for(it = wingparts.begin(); it != wingparts.end(); ++it){
        (*it)->drawCylConeNotCentered();
    }

    for(it = joints.begin(); it != joints.end(); ++it){
        (*it)->drawSphere();
    }

    glPopMatrix();

    //wings right

    glPushMatrix();
    glTranslated(-0.7,0.3,-0.4);
    glRotatef(90, 0.0,1.0,0.0);
    glRotatef(30,0.0,0.0,1.0);

    for(it = wingparts.begin(); it != wingparts.end(); ++it){
        (*it)->drawCylConeNotCentered();
    }

    for(it = joints.begin(); it != joints.end(); ++it){
        (*it)->drawSphere();
    }

    glPopMatrix();

*/

}

void Dragon::animate(){

    vector<Shapes *>::iterator it;
    vector<Shapes *> allbodyparts;

    //Copy all parts to a vector

    for(unsigned int i=0; i<tailparts.size(); i++){
        allbodyparts.push_back(tailparts[i]);
    }

    for(unsigned int i=0; i<tailend.size(); i++){
        allbodyparts.push_back(tailend[i]);
    }

    //rotating

    for(it = allbodyparts.begin(); it != allbodyparts.end(); ++it){
        Shapes *s = *it;

        if(s->getAngle()< 20){
            s->setAngle(s->getAngle());
            s->incrAngle(0.1 * s->getAngluarVelocity());
        }

    }
}





