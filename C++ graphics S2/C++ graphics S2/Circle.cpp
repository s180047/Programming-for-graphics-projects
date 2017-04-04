#include <windows.h>
#include <math.h>
#include <glut.h>

#define PI 3.1415926535897932384626433832795

#define WIDTH 640
#define HEIGHT 480

void init();
void reshape(int, int);
void display();

//Specifies the radius of the circle
static int radius = 2;

int main(int argc, char **argv)
{
	glutInit(&amp; argc, argv);
	glutInitDisplayMode(GLUT _ DOUBLE | GLUT _ RGBA | GLUT _ DEPTH);
	glutInitWindowSize WIDTH, HEIGHT);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("OpenGL Draw Circle");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}

void init()
{
	glEnable(GL _ DEPTH _ TEST); // draws object in correct order rather than on in front of other.
	glCullFace(GL _ BACK); // OpenGL would not draw back face
	glEnable(GL _ CULL _ FACE);

	glMatrixMode(GL _ PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
	glMatrixMode(GL _ MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 0.0); // assigns colour to the screen RGB

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	glMatrixMode(GL _ PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
	glMatrixMode(GL _ MODELVIEW);
	glLoadIdentity();

}

void display()
{
	glClear(GL _ COLOR _ BUFFER _ BIT | GL _ DEPTH _ BUFFER _ BIT);

	glPushMatrix();

		gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);// tells the camera where to: position x,y,z, focal point x,y,z, orintation x,y,z

		glPushMatrix();
			glColor3f(0.2, 0.3, 0.5) A shade of blue

			glBegin(GL _ POLYGON); // to begin drawing the circle. 
				for (double i = 0; i < 2 * PI; i += PI / 6) //Any step smaller than 6 would not be a circle. Possibly decagon or other polygon.
					glVertex3f(cos(i)* radius, sin(i)* radius, 0.0);

				glEnd();

			// Draw the circle

			glPopMatrix();
			glPopMatrix();
glFlush();
glutSwapBuffers();

}

