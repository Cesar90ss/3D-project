#ifndef _TAIL_
#define _TAIL_

#include "renderable.h"
#include "shapes.h"
#include <GL/glut.h>

class Dragon : public Renderable
{
public:
    void init(Viewer &);
    void animate();
    void draw();

private:
    void tail();
    void body();
    void wings();
    void joint();
    void neck();
    void head();
    void chest();
    void atlas();
    void clear();
    std::vector<Shapes *> tailparts;
    std::vector<Shapes *> tailend;
    std::vector<Shapes *> bodyparts;
    std::vector<Shapes *> wingparts;
    std::vector<Shapes *> joints;
    std::vector<Shapes *> neckparts;
    std::vector<Shapes *> chestparts;
    std::vector<Shapes *> atlasparts;

};

#endif

