/*
 *  Road project
 *  Author: Jamal and Shaun
 *  Version: 2023-12-05
 */
#ifndef AREA_H
#define AREA_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class Area: public Shape {

protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceNormal[6][3];
	GLfloat faceColor[6][3];
	GLfloat vertexColor[8][3];
	GLfloat vertexNormal[8][3];
	GLfloat r, g, b;

public:
	Area();
	void draw();
	void drawFace(int);

	bool isFrontface(int faceindex, Camera camera);
};

#endif
