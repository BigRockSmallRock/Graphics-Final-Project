/*
 *  Road project
 *  Author: Jamal and Shaun
 *  Version: 2023-12-05
 */
#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>

void menu();
void mainMenu(GLint option);
void VCSTransMenu(GLint transOption);
void VCSTransform(GLint);

void speedChange(GLint set);
void SpecMenu(GLint spec);
void animateMenu(GLint option);
void CamLoc(GLint corner);

#endif
