

#ifndef CAR_HPP_
#define CAR_HPP_

#include <GL/glut.h>
#include "CarTop.hpp"
#include "Wheel.hpp"
#include "Person.hpp"

class Car: public Shape {
protected:
	CarTop* car;
	Person* person;
	Wheel* wheel;
	Wheel* wheel2;
	Wheel* wheel3;
	Wheel* wheel4;

public:
	~Car();
	Car();
	void draw();
};

#endif
