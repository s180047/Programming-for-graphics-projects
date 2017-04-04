/*
Code for graphics for games Assignment 1 - Connor Wilby
Blog address: https://cjacecppgraphics.blogspot.co.uk/

#include <iostream>
#include <glut.h>
#include <IL/ilut.h>
#include <string>

Variables to control the "pulse" of the earth
GLfloat EarthRadius = 0.4;
bool Expanding = true;

Window size coordinates
int WindowX = 900;
int WindowY = 900;

Colour variables
GLfloat Green[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat Red[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat Blue[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat White[] = { 1.0, 1.0, 1.0, 1.0 };

Texture file variables
GLuint SunTexture, EarthTexture, MoonTexture;


Variables to hold the angles that the objects orbit with
float angle1, angle2, angle3 = 0.0f;

 Create a quadratic object for use with gluSphere
GLUquadricObj *qObj = gluNewQuadric();




void EarthExpand()//Function to make the earth "pulse" over time.
{
	float Max = 0.6;
	float Min = 0.4;


	if (Expanding == true)
	{
		EarthRadius += 0.007;
		if (EarthRadius >= Max)
		{
			Expanding = false;
		}
	}

	if (Expanding == false)
	{
		EarthRadius -= 0.007;
		if (EarthRadius <= Min)
		{
			Expanding = true;
		}
	}
}

void Sun()
{
	glEnable(GL_TEXTURE_2D);					//Enable texturing
	glPushMatrix();								//Push the identity matrix onto the stack
		glTranslatef(0.0, 0.0, -6);				//Move the sun
		glBindTexture(GL_TEXTURE_2D, SunTexture);//Bind the sun texture to the next object to be created
		glRotatef(angle3, 0.0f, -1.0f, 0.0f);	//Rotate the sun
		gluSphere(qObj, 0.3, 32, 32);			//Create the sun
	glPopMatrix();								//Pop the now edited matrix off the stack to restore the identity matrix
	glDisable(GL_TEXTURE_2D);					//Disable 2D texturing
}

void Moon()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	
	Move the Moon to the centre of the Earth
	glRotatef(angle1, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.5, 0, -6);

	Make the Moon orbit the Earth
	glRotatef(angle2, 0.0f, 0.0f, 1.0f);
	glTranslatef(1, 0, 0);

	glRotatef(90, 0.0f, 1.0f, 0.0f);	//Rotation to get the Moon to display side-on
	glBindTexture(GL_TEXTURE_2D, MoonTexture);//Bind the Moon texture
	gluSphere(qObj, 0.15, 24, 24);

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Earth()
{

	glEnable(GL_TEXTURE_2D);
	EarthExpand();							//Function to control the "pulse" of the earth
	glPushMatrix();
		glRotatef(angle1, 0.0f, 0.0f, 1.0f);//Rotate the earth by an angle so that when it is translated it ends up moved at a slight angle, creating the orbiting effect
		glTranslatef(1.5, 0, -6);
		glBindTexture(GL_TEXTURE_2D, EarthTexture);
		glRotatef(90, 0.0f, 1.0f, 0.0f);	//Rotation to get the earth to display side-on
		glRotatef(angle3, 0.0f, 0.0f, 1.0f);//Rotation to make the earth spin
		gluSphere(qObj, EarthRadius, 24, 24);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Mars()
{
	glColor3f(.8, 0, 0); //Set a colour for Mars
	glPushMatrix();
		glRotatef(angle2, 0.0f, 0.0f, 1.0f);
		glTranslatef(-1.5, 0, -6);
		glutSolidSphere(.25, 32, 32);		// A slightly different function to create a sphere, does not need a quadratic, but also cannot be textured
		glRotatef(angle3, 0.0f, 0.0f, 1.0f);// Because it is declared after the creation of Mars, it applies to the next primitivespawned, namely the tourus
		glutWireTorus(.15, 0.8, 32, 32);	// Create a torus at the last coordinates stored in the matrix, which is the location of Mars.
	glPopMatrix();
}

void Teapot()
{
	glColor3f(0, 0, 1);
	glPushMatrix();
		glRotatef(angle2, 0.0f, 0.0f, 1.0f);
		glTranslatef(2, 0, -6);
		glRotatef(angle3, 0.0f, 0.0f, 1.0f);//Rotate the teapot to show off the lighting
		glutSolidTeapot(0.25);// There's a function to create a Teapot?!?! Eh, why not... 
	glPopMatrix();
}

void Cube()
{
	glColor3f(1.5, 0, 0.5);
	glPushMatrix();
		glRotatef(angle3, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.5, 0, -6);
		glutSolidCube(0.5); // Easy cube
	glPopMatrix();
}

void Text(const char *text, int length, float x, float y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, WindowX, 0, WindowY, -5, 5);//set co-ordinate system for the placement of the text, automatically scales based on window size.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(x, y);//position
	for (int i = 0; i < length; i++)//loop through the characters to draw each letter to the screen, rasterPos moves the next letter across by the width of the previous letter
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void DrawPlanets()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Setting for the quadratics used in the textured spheres
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);

	Set up the light materials and shininess.
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 30.0);

	Load the identity matrix so it only has to be done once.
	glLoadIdentity();

	Enable colours to be used in lighting, this allows the lighting effects to be shown with the teapot, Mars and Torus.
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	Change the colour of the text used
	glColor3f(0, 0, 0);

	Create a string to hold my text
	std::string text = "Connor Wilby, S176047";

	Draw text at the top of the page
	Text(text.data(), text.size(), 0,880);

	Primitives functions
	Sun();
	Earth();
	Moon();
	Mars();
	Teapot();
	Cube();

	angle1 += 0.5f;
	if (angle1 > 360.0f)
		angle1 = 0.0f;

	angle2 += 0.75f;
	if (angle2 > 360.0f)
		angle2 = 0.0f;

	angle3 += 1.0f;
	if (angle3 > 360.0f)
		angle3 = 0.0f;

	glutSwapBuffers;
}

void Lighting()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);


	GLfloat AmbientLight[] = {0.2,0.2,0.2,1.0}; // Ambient lighting settings
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);   // Define ambient light behaviour

	GLfloat DiffuseLight[] = {0.8,0.8,0.8,1.0}; // Diffuse lighting settings
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);   // Define diffuse ambient light behaviour

	GLfloat SpecularLight[] = {1.0,1.0,1.0,1.0}; // Specular lighting settings
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight); // Define specular light behaviour

	GLfloat LightPos[] = { 0.0, 0, -6, 1.0 }; //Define light postion
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos); // Place light0



}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawPlanets();
	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
}

void Textures()
{
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);

	Texture wrapping for material
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 Define texture Filtering behaviour for material
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	Load images
	SunTexture = ilutGLLoadImage("SunTexture.bmp");
	EarthTexture = ilutGLLoadImage("EarthTexture.bmp");
	MoonTexture = ilutGLLoadImage("MoonTexture.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); // Define how material is sent further down the rendering pipeline

}

void main(int iArgc, char** Argv)
{
	glutInit(&iArgc, Argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WindowX, WindowY);
	glutCreateWindow("Solarium");
	glEnable(GL_DEPTH_TEST);

	glFrontFace(GL_CW);// define clockwise as the front face
	glCullFace(GL_BACK);// Cull the back of each primitive to cut down on memory use
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);//Enable a depth test to ensure that the primitives render properly
	Textures(); //function to configure the textures
	Lighting(); //Function to configure Lighting

	glutDisplayFunc(display);

	glutMainLoop();
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <glut.h>
#include <stdlib.h>
#include <IL/ilut.h>
#include <string>

static int left = 0, right = 0;

unsigned int loadTexture(const char* filename)
GLuint myImage;

void InitTextures(void)
{
	SDL_Surface* img = SDL_LoadBMP(Filename);
	unsigned int id;
	glGenTexures(3, &id);
	glBindTexure(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 
	img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// Ensures the image covers the sphere completely
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);// Shows the image as neat as possible
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(img);

	myImage = ilutGLLoadImage("SKY.jpg");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);// To define the rendering pipeline
}

void init(void)
{
	glClearColor(9.0, 9.0, 9.0, 0.0);
	glShadeModel(GL_FLAT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	Intensity of light

	GLfloat qaAmbientLight[]{ 0.4, 0.4, 0.4, 1.0 };
	GLfloat qaDiffuseLight[]{ 0.6, 0.6, 0.6, 1.0 };
	GLfloat qaSpecularLight[]{ 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	position for the light

	GLfloat qaLightPosition[] = { 0.5,0.5,0.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}

void display(void)// create the sphere 
{
	glEnable(GL_TEXTURE_2D);// Applies image in 2D
	glBindTexture(GL_TEXTURE_2D, myImage);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef((GLfloat)left, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)right, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);   //red,green,blue
	GLUquadricObj *qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);
	gluSphere(qObj, 2.0, 30, 36);    // double radious, slices, stacks
	glPopMatrix();
	glutSwapBuffers();

}
void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, w / (GLfloat)h, 3.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(2.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Observing position
}
void pushbutton(unsigned char button, int x, int y)
{
	switch (button) {
	case 'a': left = (left + 1) % 360; //moves the sphere towards left 
		glutPostRedisplay(); 			break;
	case 'd': right = (right - 1) % 360; //moves the sphere towards right
		glutPostRedisplay();			default: break;
	}
}
void myMouseFunc(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)

		if (xMouse < 400)
		{
			left = (left + 1) % 360; //moves the sphere towards left
			glutPostRedisplay();
		}
	if (xMouse > 400)
	{
		right = (right - 1) % 360; //moves the sphere towards right
		glutPostRedisplay();
	}

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Sphere");
	glEnable(GL_DEPTH_TEST);
	init();
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);
	InitTextures();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(pushbutton);
	glutMouseFunc(myMouseFunc);

	glutMainLoop();
	return 0;
}

*/

























//Assignment 1 - The Sphere -
//Heidi Falcon - S180047 -

/*

#include <iostream>
#include <glut.h>
#include <stdlib.h>
#include <IL/ilut.h>
#include <string>

static int left = 0, right = 0;

unsigned int loadTexture(const char* filename)
GLuint myImage;

void InitTextures(void)
{
	SDL_Surface* img = SDL_LoadBMP(Filename);
	unsigned int id;
	glGenTexures(3, &id);
	glBindTexure(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 
	img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// Ensures the image covers the sphere completely
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);// Shows the image as neat as possible
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(img);

	myImage = ilutGLLoadImage("EarthTexture1.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);// To define the rendering pipeline
}

void init(void)
{
	glClearColor(9.0, 9.0, 9.0, 0.0);
	glShadeModel(GL_FLAT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	Intensity of light

	GLfloat qaAmbientLight[]{ 0.4, 0.4, 0.4, 1.0 };
	GLfloat qaDiffuseLight[]{ 0.6, 0.6, 0.6, 1.0 };
	GLfloat qaSpecularLight[]{ 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	position for the light

	GLfloat qaLightPosition[] = { 0.5,0.5,0.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}

void display(void)// create the sphere 
{
	glEnable(GL_TEXTURE_2D);// Applies image in 2D
	glBindTexture(GL_TEXTURE_2D, myImage);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef((GLfloat)left, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)right, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);   //red,green,blue
	GLUquadricObj *qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);
	gluSphere(qObj, 2.0, 30, 36);    // double radious, slices, stacks
	glPopMatrix();
	glutSwapBuffers();

}
void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, w / (GLfloat)h, 3.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(2.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Observing position
}
void pushbutton(unsigned char button, int x, int y)
{
	switch (button) {
	case 'a': left = (left + 1) % 360; //moves the sphere towards left 
		glutPostRedisplay(); 			break;
	case 'd': right = (right - 1) % 360; //moves the sphere towards right
		glutPostRedisplay();			default: break;
	}
}
void myMouseFunc(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)

		if (xMouse < 400)
		{
			left = (left + 1) % 360; //moves the sphere towards left
			glutPostRedisplay();
		}
	if (xMouse > 400)
	{
		right = (right - 1) % 360; //moves the sphere towards right
		glutPostRedisplay();
	}

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Sphere            		              Please click on both sides of the sphere to rotate it");
	glEnable(GL_DEPTH_TEST);
	init();
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);
	InitTextures();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(pushbutton);
	glutMouseFunc(myMouseFunc);

		glutMainLoop();
		return 0;
}



*/