#include "Body.hpp"
#include "Camera.hpp"
#include "Shape.hpp"
#include <stdio.h>

Body::Body() {
	radius = 0.25;
	height = 1.2;
	pi = 3.14159265359;
}

void Body::draw() {
	GLfloat x;
	GLfloat y;
	GLfloat degree;

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	glColor3f(0.8, 0.4, 0.2);
	glBegin(GL_QUAD_STRIP);
	degree = 0.0;
	while (degree < 2 * pi) {
		x = radius * cos(degree);
		y = radius * sin(degree);
		degree = degree + 0.12;
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	degree = 0.0;
	while (degree < 2 * pi) {
		x = radius * cos(degree);
		y = radius * sin(degree);
		degree = degree + 0.12;
		glVertex3f(x, y, height);
	}
	glVertex3f(radius, 0.0, height);
	glEnd();
	glPopMatrix();

}

