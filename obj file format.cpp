
#include <iostream>
#include <glut.h>
#include <IL/ilut.h>
#include <string>






void Cube()
{
	glColor3f(1.5, 0, 0.5);
	glPushMatrix();
	glRotatef(angle3, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.5, 0, -6);
	glutSolidCube(0.5); // Easy cube
	glPopMatrix();


	//primitive function 
	Cube();


	glutMainLoop();
	return;

}