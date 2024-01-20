#include "World.hpp"
#include "Area.hpp"
#include "Building.hpp"
#include "Person.hpp"
#include "Car.hpp"
#include "CarTop.hpp"

using namespace std;

GLint direction[6];

World::World() {
	Shape *obj = NULL;

	obj = new Area();
	obj->setId(999);
	obj->scaleChange(30);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(0);
	obj->scaleChange(0.5);
	obj->translate(6, 13, -31);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(1);
	obj->scaleChange(0.5);
	obj->translate(9, 8, -31);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(2);
	obj->scaleChange(0.5);
	obj->translate(-12, 6, -31);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(3);
	obj->scaleChange(0.5);
	obj->translate(-15, 4, -31);
	objlist.push_back(obj);

	obj = new Car();
	obj->setId(4);
	obj->scaleChange(-0.1);
	obj->rotate(1, 0, 0, 90);
	obj->translate(1, 20, -29.6);
	objlist.push_back(obj);

	obj = new Car();
	obj->setId(5);
	obj->scaleChange(-0.2);
	obj->rotate(1, 0, 0, 90);
	obj->rotate(0, 0, 1, 180);
	obj->translate(-7, 0, -29.6);
	objlist.push_back(obj);

	direction[0] = 1;
	direction[1] = -1;
	direction[2] = 1;
	direction[3] = -1;
	direction[4] = 1;
	direction[5] = -1;

	obj = new Building();
	obj->setId(10);
	obj->scaleChange(-0.2);
	obj->rotate(0, 0, 1, 90);
	obj->translate(20, 20, -30);
	objlist.push_back(obj);

	obj = new Building();
	obj->setId(11);
	obj->scaleChange(-0.3);
	obj->rotate(0, 0, 1, 90);
	obj->translate(20, 5, -31);
	objlist.push_back(obj);

	obj = new Building(10, 20, 10);
	obj->setId(12);
	obj->scaleChange(-0.1);
	obj->rotate(0, 0, 1, 90);
	obj->translate(20, -10, -31);
	objlist.push_back(obj);

	obj = new Building(10, 18, 8);
	obj->setId(13);
	obj->scaleChange(-0.1);
	obj->rotate(0, 0, 1, 90);
	obj->translate(20, -25, -31);
	objlist.push_back(obj);

	obj = new Building(10, 20, 10); //here 1st
	obj->setId(14);
	obj->scaleChange(-0.1);
	obj->rotate(0, 0, 1, 90);
	obj->translate(-27, 19, -31); //depth width height
	objlist.push_back(obj);

	obj = new Building(10, 23, 14); //here 2nd //width depth height
	obj->setId(15);
	obj->scaleChange(-0.1);
	obj->rotate(0, 0, 1, 90);
	obj->translate(-29, 10, -31); //depth width height
	objlist.push_back(obj);

	obj = new Building(10, 13, 10); //here 3rd, width depth height
	obj->setId(16);
	obj->scaleChange(-0.1);
	obj->rotate(0, 0, 1, 90);
	obj->translate(-26, -5, -31); //depth width height
	objlist.push_back(obj);

	obj = new Building(10, 18, 8); //here 4th
	obj->setId(17);
	obj->scaleChange(-0.1);
	obj->rotate(0, 0, 1, 90);
	obj->translate(-26, -23, -31); //depth width height
	objlist.push_back(obj);

}

World::~World() {
	Shape *obj;
	while (!objlist.empty()) {
		obj = objlist.front();
		objlist.pop_front();
		free(obj);
	}
}

void lineSegment(float x1, float y1, float z1, float x2, float y2, float z2) {
	glBegin(GL_LINES);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glEnd();
}

void World::draw() {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it != objlist.end(); ++it) {
		(*it)->draw();
	}
}

void World::reset() {
	Shape *obj = NULL;

	obj = this->searchById(1);
	obj->reset();
	obj->setScale(0.5);
	obj->translate(2.5, 0, 0);

	obj = this->searchById(2);
	obj->reset();
	obj->setScale(0.5);
	obj->translate(4, 0, 0);

	obj = this->searchById(3);
	obj->reset();
	obj->setScale(0.5);
}

Shape* World::searchById(GLint i) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it != objlist.end(); ++it) {
		if ((*it)->getId() == i)
			return *it;
	}
	return NULL;
}

