#ifndef WHEEL_HPP_
#define WHEEL_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class Wheel: public Shape {

protected:
	GLfloat radius;
	GLfloat height;
	GLfloat pi;

public:
	Wheel();
	void draw();
};

#endif
