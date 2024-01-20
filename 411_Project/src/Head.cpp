#include "Head.hpp"
#include "Camera.hpp"
#include <stdio.h>

Head::Head() {
	radius = 0.4;
	splices = 50;
	stacks = 50;
	r = 0.8;
	g = 0.6;
	b = 0.4;
	quad = gluNewQuadric();
}

void Head::draw() {
	glPushMatrix();
	ctmMultiply();

	glColor3f(r, g, b);
	glutSolidSphere(radius,splices,stacks);

	glPopMatrix();
}


