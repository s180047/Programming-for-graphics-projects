//Heidi Falcon S180047
//Programming for graphics Second Semester Assignment
//Creation of a cube with shaders. User can rotate cube using arrow keys.

#include <stdio.h>
#include <stdlib.h>
#include <glew.h>
#include <glut.h>
#include <stdarg.h>
#include <math.h>
#include <textfile.h> // Header file for code used to read the shader files

// functions
void display();
void specialKeys();


//global variables
double rotate_y = 0;
double rotate_x = 0;



void display()
{
	//This comand ensures we always have a clear screen to work with
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations of the cube
	glLoadIdentity();

	//Other transformations+++TEST LATER+++
	//glTranslatef (0.1, 0.0, 0.0);
	//glRotatef(180, 0.0, 1.0, 0.0);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	//Other Transformations  ++Test Later++
	//glScalef (2.0, 2.0, 0.0); 
	
	// We begin to draw the cube side by side. Ensuring we assign th epolygones counter clockwise.
	//Multi-coloured side - Front
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);	glVertex3f(0.5, -0.5, -0.5); // Polygon1 is red
	glColor3f(0.0, 1.0, 0.0);	glVertex3f(0.5, 0.5, -0.5);  // Polygon2 is green
	glColor3f(0.0, 0.0, 1.0);	glVertex3f(-0.5, 0.5, -0.5); // Polygon3 is blue
	glColor3f(1.0, 0.0, 1.0);	glVertex3f(-0.5, -0.5, -0.5); // Polygon4 is purple

	glEnd();

	//Multicolour side - Back
	glBegin(GL_POLYGON);

	

	glColor3f(1.0, 0.0, 0.0);   glVertex3f(0.5, -0.5, 0.5); //Polygon is red
	glColor3f(0.0, 1.0, 1.0);   glVertex3f(0.5, 0.5, 0.5);  //Polygone is  green
	glColor3f(1.0, 0.0, 1.0);   glVertex3f(-0.5, 0.5, 0.5);   //Polygone is purple
	glColor3f(1.0, 1.0, 1.0);   glVertex3f(-0.5, -0.5, 0.5);  //Polygone is green

	glEnd();

	//Purple side - Right
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 1.0);

	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	float points[] = {		// three vertices used to draw a triagle
		0.0f,  0.5f,  0.0f,
		0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	glEnd();

	//Green side - Left
	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glEnd();

	//Blue side - Top
	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 1.0);

	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glEnd();

	//Red side - Bottom
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);

	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glEnd();

	//char *vs = NULL;	// Pointer to a Character array for the vertext shader
	//char *fs = NULL;	// Pointer to a character array for the fragment shader
	glFlush();
	glutSwapBuffers();

}

//Key controls to rotate cube

void specialKeys(int key, int x, int y)
{
	// Rotate right by 5 degrees
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//Rotate left by 5 degrees
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	//Rotate upwards by 5 degrees
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	//Rotate downwards by 5 degrees
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	
	//Update display
	glutPostRedisplay();

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // Initialize the program using parameters given

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Create a window
	glutCreateWindow("CUBE");

	//Buffer depth test
	glEnable(GL_DEPTH_TEST);

	//Callback functions

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	

	//Create a loop
	glutMainLoop();

	return 0;

