// include the GLUT header file so we can access all the GLUT calls
#include <glut.h>  


//GLint giXRes = 800;
//GLint giYRes = 800;


// This function must be declared before the MAIN call so that MAIN knows it exists

{

// glClear sets the colour of the window to the colour previously defined by
// glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum
glClear(GL_COLOR_BUFFER_BIT);
// This colour will remain the active draw colour until we change it
glColor3f(1.0, 0.0, 0.0);
///////////////////////////////////////////////////
//draw a line - START
///////////////////////////////////////////////////
//Start to create a line primitive
glBegin(GL_LINES);
// Now add in the vertices of the line
glVertex2i(10, 10);
glVertex2i(200, 200);
glEnd(); //declare that the line is now finished primitive
///////////////////////////////////////////////////
//draw a line - END

void drawCube() {
glBegin(GL_QUADS);

// Define vertices in counter-clockwise (CCW) order with normal pointing out
glColor3f(0.0f, 1.0f, 0.0f);		// Green
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glEnd();


// Bottom face (y = -1.0f)
glColor3f(1.0f, 0.5f, 0.0f);		// Orange
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glEnd();

// Front face  (z = 1.0f)
glColor3f(1.0f, 0.0f, 0.0f);		// Red
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glEnd();

// Back face (z = -1.0f)
glColor3f(1.0f, 1.0f, 0.0f);		// Yellow
glVertex3f(1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, -1.0f);
glEnd();

// Left face (x = -1.0f)
glColor3f(0.0f, 0.0f, 1.0f);		// Blue
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glEnd();

// Right face (x = 1.0f)
glColor3f(1.0f, 0.0f, 1.0f);		// Magenta
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glEnd();

}
///////////////////////////////////////////////////
// Now process all the OpenGL commands as quickly as possible
glFlush();
}
// Create our windows applciation
void main(int argc, char *argv[])
{
//Start the GLUT windowing system
glutInit(&argc, argv);
// Define settings for the display
// GLUT_SINGLE = use a single rerfesh buffer
// GLUT_RGB = use the RGB colour space
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Set the dimensions of all future windows.
glutInitWindowSize(800, 800);
// Set the position of the window. Origin is top left of screen
glutInitWindowPosition(100, 100);
// Create a window with a title
glutCreateWindow("My Cube");
// Set the background colour of the window to white (red, green, blue, alpha)
// RGB values in range of 0 to 1
// Alpha channel used to blend two overlapping objects
glClearColor(1.0, 1.0, 1.0, 0.0);
// OpenGL assumes you are working with 3D graphcis by default
// If we want to work in just 2D we have to tell OpenGL that we want to do this
// We therefore tell OpenGL to 'project' the image onto a 2D plane.
glMatrixMode(GL_PROJECTION);
// Now setup the coordinate system for the projected image
// (x min, x max, y min, y max)
// Bottom left = (0,0) top right = (250,250)
gluOrtho2D(0.0, 250.0, 0.0, 250.0);
// Process the 'display' method and pass the results to DisplayFunc
// which will pass the results to the display window, ready to be displayed.
glutDisplayFunc(display);
// The contents of the display window are not drawn immediately.
// The following function displays the content.
// This must be the last function in the program
glutMainLoop();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Add perspective view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 9.0);

	// moving the camera and target the same relative distance, creates a pan
	gluLookAt(0.0, 6.0, 0.0, 0.0, 0.0, -7.0, 0, 1, 0);

	// Switch back to Model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0.0f, 0.0f, -7.0f);

	drawCube();

	glutSwapBuffers();

	glutPostRedisplay();
}

void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// Re-size event. Called back when the window first appears and
// whenever the window is re-sized with its new width and height 
void reshape(GLsizei width, GLsizei height) {		// GLsizei must be non-negative integer

													// Compute aspect ratio of the new window
	if (height == 0) height = 1;					// To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // Enable the Projection matrix
	glLoadIdentity();             // Reset

								  // Enable perspective projection with fovy, aspect, zNear and zFar

}


// Main function: GLUT runs as a console application starting at main() 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(giXRes, giYRes);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Rotating Clipped Cube");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutMainLoop();
	Timer(0);
	return 0;
}