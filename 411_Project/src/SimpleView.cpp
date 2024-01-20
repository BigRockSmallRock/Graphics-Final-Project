/*
 *  Road project
 *  Author: Jamal and Shaun
 *  Version: 2023-12-05
 */

#include <GL/glew.h>
#include "pixmap/RGBpixmap.h"
#include "Camera.hpp"
#include "time.h"
#include <windows.h>
#include <mmsystem.h>

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Menu.hpp"
#include "World.hpp"


GLint winWidth = 1280, winHeight = 720;
GLint isInMove = 0,
	  xbegin = 0,
	  csType = 1,    /* coordinate system type: 1 for MCS, 2 for WCS, 3 for VCS */
	  transType = 4;  /* depends on csType  */

CullMode cullMode = BACKFACE;      /* culling option */
RenderMode renderMode = TEXTURE; //  WIRE;  /* shade option  */

World myWorld;
Camera myCamera;
Shape *selectObj = NULL;  // pointer to select object
GLint displayOption = 0;   /* 0: world, 1: solar system, 2: control points, 3: curve, 4: rotation surface.  */

RGBpixmap pix[8];

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	selectObj = myWorld.searchById(3);

	/* load six texture bitmap */
	pix[0].readBMPFile("Textures/road1.bmp");
	pix[0].setTexture(0);

	pix[1].readBMPFile("Textures/space.bmp");
	pix[1].setTexture(1);

	pix[2].readBMPFile("Textures/background1.bmp");
	pix[2].setTexture(2);

	pix[3].readBMPFile("Textures/background.bmp");
	pix[3].setTexture(3);

	pix[4].readBMPFile("Textures/background.bmp");
	pix[4].setTexture(4);

	pix[5].readBMPFile("Textures/background.bmp");
	pix[5].setTexture(5);

	pix[6].readBMPFile("Textures/building1.bmp");
	pix[6].setTexture(6);

    pix[7].readBMPFile("Textures/building2.bmp");
    pix[7].setTexture(7);

    pix[8].readBMPFile("Textures/building3.bmp");
    pix[8].setTexture(8);

    pix[9].readBMPFile("Textures/building4.bmp");
    pix[9].setTexture(9);

	glEnable(GL_DEPTH_TEST);

}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myCamera.setProjectionMatrix();
	myWorld.draw();

	glFlush();
	glutSwapBuffers();
}


void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseActionFcn(int button, int state, int xMouse, int yMouse) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		isInMove = 1;
		xbegin = xMouse;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		isInMove = 0;
	}
}

void mouseMotionFcn(GLint xMouse, GLint yMouse) {
	if (isInMove) {
		if(csType == 3){
			VCSTransform(xMouse);
		}
		glutPostRedisplay();
	}
}


int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CP411 Road Project by Jamal and Shaun");

	menu();
	init();
	glutDisplayFunc(display);
	glutMotionFunc(mouseMotionFcn);
	glutMouseFunc(mouseActionFcn);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
