#include "Person.hpp"
#include "Shape.hpp"
#include <stdio.h>

Person::Person() {
	body = new Body();
	arms = new Body();
	arms->translate(-0.7, 0, -0.47);
	arms->rotate(0, 1, 0, 90);
	arms->setScale(0.8);
	head = new Head();
	head->translate(0, 0, 1.2);
}

Person::~Person() {
	delete body;
	delete head;
	delete arms;
}

void Person::draw() {


	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	body->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	arms->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	head->draw();
	glPopMatrix();
}
