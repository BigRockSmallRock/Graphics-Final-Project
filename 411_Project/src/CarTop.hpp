#ifndef CARTOP_H
#define CARTOP_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class CarTop: public Shape {

protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceColor[6][3];
	GLfloat faceNormal[6][3];
	GLfloat vertexColor[8][3];
	GLfloat vertexNormal[8][3];
	GLfloat r, g, b;

public:
	CarTop();
	void draw();
	void drawFace(int);
	bool isFrontface(int faceindex, Camera camera);
};

#endif
