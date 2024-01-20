#include "Car.hpp"

#include <stdio.h>

Car::Car() {
	car = new CarTop();
	car->rotate(0, 1, 0, 90);
	car->translate(-2, 0, 0.5);

	person = new Person();
	person->translate(0.6, -2, -0.3);
	person->rotate(1, 0, 0, 270);
	person->scaleChange(0.5);

	wheel = new Wheel();
	wheel->translate(0, -1, -2);
	wheel->rotate(0, 1, 0, 90);

	wheel2 = new Wheel();
	wheel2->translate(-4, -1, -2);
	wheel2->rotate(0, 1, 0, 90);

	wheel3 = new Wheel();
	wheel3->translate(0, -1, 1);
	wheel3->rotate(0, 1, 0, 90);

	wheel4 = new Wheel();
	wheel4->translate(-4, -1, 1);
	wheel4->rotate(0, 1, 0, 90);
}

Car::~Car() {
	delete car;
	delete wheel;
	delete wheel2;
	delete wheel3;
	delete wheel4;
	delete person;
}

void Car::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	car->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	person->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	wheel->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	wheel2->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	wheel3->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	wheel4->draw();
	glPopMatrix();
}


