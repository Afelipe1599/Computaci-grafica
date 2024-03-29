/*

 * To change this license header, choose License Headers in Project Properties.

 * To change this template file, choose Tools | Templates

 * and open the template in the editor.

 */



/* 

 * File:   main.cpp

 * Author: javargas

 *

 * Created on February 12, 2017, 11:49 AM

 */



#include <stdio.h>

#include <stdlib.h>

#include "GL/freeglut.h"

#include "GL/gl.h"





using namespace std;



void display(void) {

    glClearColor(1.0, 1.0, 1.0, 0.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0,0.0,0.0);

    glutWireTorus(0.25,0.75, 28, 28);

    glColor3f(0.0,0.0,1.0) ;

    glutWireCube(.60) ;

    glutSwapBuffers();

}



void reshape(int width, int height) {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}



void keyboard(unsigned char key, int x, int y) {

    switch (key) {

    case 'h':

        printf("help\n\n");

        printf("c - Toggle culling\n");

        printf("q/escape - Quit\n\n");

        break;

    case 'c':

        if (glIsEnabled(GL_CULL_FACE))

           glDisable(GL_CULL_FACE);

        else

            glEnable(GL_CULL_FACE);

        break;

    case '1':

        glRotatef(1.0,1.,0.,0.);

        break;

    case '2':

        glRotatef(1.0,0.,1.,0.);

        break;

    case 'q':

    case 27:

        exit(0);

        break;

    }

    glutPostRedisplay();

}



int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(512, 512);

    glutInitWindowPosition(20, 20);

    glutCreateWindow("tecnunLogo");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    

    return 0;

}


