/*
 *  Road project
 *  Author: Jamal and Shaun
 *  Version: 2023-12-05
 */
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "time.h"
#include <windows.h>
#include <mmsystem.h>

extern GLint csType;
extern GLint transType, xbegin;
extern World myWorld;
extern Camera myCamera;

extern GLint direction[];
GLint speed = 8;
GLint NpcId = 1;
Point newRef;
Point newCam;

void menu() {
	GLint VCTransMenu = glutCreateMenu(VCSTransMenu);
	glutAddMenuEntry("Rotate x", 1);
	glutAddMenuEntry("Rotate y", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x", 4);
	glutAddMenuEntry("Translate y", 5);
	glutAddMenuEntry("Translate z", 6);

	GLint MovementSpeed = glutCreateMenu(speedChange);
	glutAddMenuEntry("1", 1);
	glutAddMenuEntry("2", 2);
	glutAddMenuEntry("3", 3);
	glutAddMenuEntry("4", 4);

	GLint SpectateMenu = glutCreateMenu(SpecMenu);
	glutAddMenuEntry("NPC 1", 0);
	glutAddMenuEntry("NPC 2", 1);
	glutAddMenuEntry("NPC 3", 2);
	glutAddMenuEntry("NPC 4", 3);
	glutAddMenuEntry("Car 1", 4);
	glutAddMenuEntry("Car 2", 5);

	GLint CameraLocation = glutCreateMenu(CamLoc);
	glutAddMenuEntry("Corner 1", 0);
	glutAddMenuEntry("Corner 2", 1);
	glutAddMenuEntry("Corner 3", 2);
	glutAddMenuEntry("Corner 4", 3);
	glutAddMenuEntry("Original", 4);


	glutCreateMenu(mainMenu);
	glutAddSubMenu("Camera Controls", VCTransMenu);
	glutAddSubMenu("Movement Speed", MovementSpeed);
	glutAddSubMenu("Spectate NPC", SpectateMenu);
	glutAddSubMenu("Camera Location", CameraLocation);
	glutAddMenuEntry("Start Scene", 1);
	glutAddMenuEntry("Stop Scene", 2);
	glutAddMenuEntry("Quit", 3);
}

void mainMenu(GLint option) {
	switch (option){
		case 1:
			animateMenu(option);
			break;
		case 2:
			animateMenu(option);
			break;
		case 3:
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void VCSTransMenu(GLint transOption) {
	csType = 3;
	transType = transOption;
	glutPostRedisplay();
}


void animateSpectate(void) {
    GLfloat npcX = myWorld.searchById(NpcId)->getMC().mat[0][3];
    GLfloat npcY = myWorld.searchById(NpcId)->getMC().mat[1][3];
    GLfloat npcZ = myWorld.searchById(NpcId)->getMC().mat[2][3];
    newRef.set(npcX, npcY, npcZ);
    myCamera.set(myCamera.eye, newRef, myCamera.viewup);
	glutPostRedisplay();

}

void SpecMenu(GLint ID) {
	NpcId = ID;
	animateSpectate();
}

void CamLoc(GLint Corner) {
    GLfloat camX = 0;
    GLfloat camY = 0;
    GLfloat camZ = 0;

	switch (Corner){
		case 0:
			camX = 10;
			camY = 30;
		    newCam.set(camX, camY, camZ);
		    myCamera.set(newCam, myCamera.ref, myCamera.viewup);
			break;
		case 1:
			camX = 10;
			camY = -30;
		    newCam.set(camX, camY, camZ);
		    myCamera.set(newCam, myCamera.ref, myCamera.viewup);
			break;
		case 2:
			camX = -10;
			camY = 30;
		    newCam.set(camX, camY, camZ);
		    myCamera.set(newCam, myCamera.ref, myCamera.viewup);
			break;
		case 3:
			camX = -10;
			camY = -30;
		    newCam.set(camX, camY, camZ);
		    myCamera.set(newCam, myCamera.ref, myCamera.viewup);
			break;
		case 4:
			camX = -10;
			camY = -20;
			camZ = -20;
			newCam.set(camX, camY, camZ);
			myCamera.set(newCam, myCamera.ref, myCamera.viewup);
			break;
	}
	glutPostRedisplay();
}


void VCSTransform(GLint x){
	GLfloat theta = (xbegin - x > 0) ? 1 : -1;
	if (transType == 1) {  //eye rotate x
		myCamera.rotate(1.0, 0.0, 0.0, theta*0.5);
	}
	else if (transType == 2) { // eye rotate y
		myCamera.rotate(0.0, 1.0, 0.0, theta*0.5);
	}
	else if(transType == 3){ //eye rotate z
		myCamera.rotate(0.0, 0.0, 1.0, theta*0.5);
	}
	else if (transType == 4) { //eye translate x
		myCamera.translate(theta* 0.02, 0.0, 0.0);
	}
	else if(transType == 5){   // eye translate y
		myCamera.translate(0.0, theta* 0.02, 0.0);
	}
	else if(transType == 6){ // eye translate z
		myCamera.translate(0.0, 0.0, theta* 0.02);
	}
	else if(transType == 7){  // change dnear
		myCamera.dnear += theta * .1;
	}
	else if(transType == 8){  // change dfar
		myCamera.dfar += theta *.1;
	}
}

void speedChange(GLint set) {
	switch(set){
	case 1:
		speed = 8;
	break;
	case 2:
		speed = 6;
	break;
	case 3:
		speed = 4;
	break;
	case 4:
		speed = 2;
	break;
	}


}

void animateWalking(void) {
	for (int i = 0; i < 6; i++) {
		if(i<4){
		if (myWorld.searchById(i)->getMC().mat[1][3] < -30) {
			direction[i] *= -1;

		} else if (myWorld.searchById(i)->getMC().mat[1][3] > 30) {
			direction[i] *= -1;
		}

		}else{
			if (myWorld.searchById(i)->getMC().mat[1][3] < -27) {
				direction[i] *= -1;

			} else if (myWorld.searchById(i)->getMC().mat[1][3] > 27) {
				direction[i] *= -1;
			}
		}
		if(i<4){
		myWorld.searchById(i)->translate(0, 0.1 * direction[i] / speed, 0);
		}else{
			myWorld.searchById(i)->translate(0, 0.3 * direction[i] / speed, 0);
		}
		glutPostRedisplay();

	}
}


void animate(void) {
	animateWalking();
	animateSpectate();
}


void animateMenu(GLint option ) {
    switch (option){
        case 1:
            glutIdleFunc(animate);
            PlaySound((LPCSTR) "Music.wav", NULL, SND_FILENAME | SND_ASYNC);
            break;
        case 2:
            glutIdleFunc(NULL);
            PlaySound(NULL, NULL, NULL);
            break;
    }
    glutPostRedisplay();
}



