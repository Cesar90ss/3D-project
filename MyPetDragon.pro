TEMPLATE = app
TARGET   = cg3D
CONFIG  += qt opengl warn_on debug
QT *= xml opengl 

HEADERS  = *.h
SOURCES  = *.cpp

macx:LIBS *= -framework Glut
linux-g++*:LIBS *= -lglut

QGL=-lQGLViewer

LIBS *= $${QGL}
