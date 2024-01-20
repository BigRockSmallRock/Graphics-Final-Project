#include "Building.hpp"

#include "Shape.hpp"
#include "Camera.hpp"
#include <stdio.h>


Building::Building() {
	//depth				//width 			//height
	vertex[0][0] = -10; vertex[0][1] = -10; vertex[0][2] = 0;
	vertex[1][0] = -10; vertex[1][1] = 10;  vertex[1][2] = 0;
	vertex[2][0] = 10;  vertex[2][1] = 10;  vertex[2][2] = 0;
	vertex[3][0] = 10;  vertex[3][1] = -10; vertex[3][2] = 0;
	vertex[4][0] = -10; vertex[4][1] = -10; vertex[4][2] = 20;
	vertex[5][0] = -10; vertex[5][1] = 10;  vertex[5][2] = 20;
	vertex[6][0] = 10;  vertex[6][1] = 10;  vertex[6][2] = 20;
	vertex[7][0] = 10;  vertex[7][1] = -10; vertex[7][2] = 20;

	face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
	face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
	face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
	face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
	face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
	face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;



	for (int i = 0 ; i<6; i++) {
		Vector V1 = Vector(vertex[face[i][1]][0]-vertex[face[i][0]][0], vertex[face[i][1]][1]-vertex[face[i][0]][1], vertex[face[i][1]][2]-vertex[face[i][0]][2]);
		Vector V2 = Vector(vertex[face[i][2]][0]-vertex[face[i][1]][0], vertex[face[i][2]][1]-vertex[face[i][1]][1], vertex[face[i][2]][2]-vertex[face[i][1]][2]);
		Vector V3 =  V1.cross(V2);
		V3.normalize();
		faceNormal[i][0] = V3.x;
		faceNormal[i][1] = V3.y;
		faceNormal[i][2] = V3.z;
	}

	r = 1;
	g = 1;
	b = 1;
}
Building::Building(int width, int height, int depth) {
    //depth                //width             //height
    vertex[0][0] = -width; vertex[0][1] = -depth; vertex[0][2] = 0;
    vertex[1][0] = -width; vertex[1][1] = depth;  vertex[1][2] = 0;
    vertex[2][0] = width;  vertex[2][1] = depth;  vertex[2][2] = 0;
    vertex[3][0] = width;  vertex[3][1] = -depth; vertex[3][2] = 0;
    vertex[4][0] = -width; vertex[4][1] = -depth; vertex[4][2] = height;
    vertex[5][0] = -width; vertex[5][1] = depth;  vertex[5][2] = height;
    vertex[6][0] = width;  vertex[6][1] = depth;  vertex[6][2] = height;
    vertex[7][0] = width;  vertex[7][1] = -depth; vertex[7][2] = height;

    face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
    face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
    face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
    face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
    face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
    face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;

    for (int i = 0 ; i<6; i++) {
        Vector V1 = Vector(vertex[face[i][1]][0]-vertex[face[i][0]][0], vertex[face[i][1]][1]-vertex[face[i][0]][1], vertex[face[i][1]][2]-vertex[face[i][0]][2]);
        Vector V2 = Vector(vertex[face[i][2]][0]-vertex[face[i][1]][0], vertex[face[i][2]][1]-vertex[face[i][1]][1], vertex[face[i][2]][2]-vertex[face[i][1]][2]);
        Vector V3 =  V1.cross(V2);

        V3.normalize();

        faceNormal[i][0] = V3.x;
        faceNormal[i][1] = V3.y;
        faceNormal[i][2] = V3.z;
    }

    r = 1;
    g = 1;
    b = 1;
};


void Building::drawFace(int i) {
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);

	if(getId() == 11 || getId() == 14){
	        glBindTexture(GL_TEXTURE_2D,7);
	    }
	    else if(getId() == 12 || getId() == 17) {
	        glBindTexture(GL_TEXTURE_2D, 8);
	    }
	    else if (getId() == 15 || getId() == 13) {
	        glBindTexture(GL_TEXTURE_2D, 9);
	    }
	    else {
	        glBindTexture(GL_TEXTURE_2D, 6);
	    }

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3fv(&vertex[face[i][0]][0]);
	glTexCoord2f(1.0, 0.0); glVertex3fv(&vertex[face[i][1]][0]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(&vertex[face[i][2]][0]);
	glTexCoord2f(0.0, 1.0); glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Building::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	for (int i = 0; i < 6; i++) {
			drawFace(i);
	}

	glPopMatrix();
}

bool Building::isFrontface(int faceindex, Camera camera) {
	GLfloat v[4];
	v[0] = faceNormal[faceindex][0];
	v[1] = faceNormal[faceindex][1];
	v[2] = faceNormal[faceindex][2];
	v[3] = 0.0;
	mc.multiplyVector(v);

	if (pmc != NULL) {
		pmc->multiplyVector(v);
		return (pmc->mat[0][3] - camera.eye.x) * v[0] + (pmc->mat[1][3] - camera.eye.y) * v[1] + (pmc->mat[2][3] - camera.eye.z) * v[2] < 0;
	} else {
		return (mc.mat[0][3] - camera.eye.x) * v[0] + (mc.mat[1][3] - camera.eye.y) * v[1] + (mc.mat[2][3] - camera.eye.z) * v[2] < 0;
	}
}
