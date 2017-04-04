//// CHANGEEEEEEEEE++++++++++++++++++
////An example of a shader program where the shaders are stored as seperate
//// text files which must be read into an array of characters before being 
//// passed to the shader program
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <glew.h>
//#include <glut.h>
//#include "textfile.h"	// Header file for code to read a textfile, used to read in the shader files
//
//GLint giXRes = 600;
//GLint giYRes = 600;
//GLint window1ID;
//GLuint sID;
//GLuint vbo = 0; // Used to store the vertex buffer object
//GLuint vao = 0; // Used to store the vertex array object
//
//// functions for the cube
////void display();
////void specialKeys();
//
//
////void LoadGLTextures();
////void InitTexture();
//				
////global variables for the cube
////double rotate_y = 0;
////double rotate_x = 0;
//
//float points[] = {		// three vertices used to draw a triagle
//	0.0f,  0.5f,  0.0f,
//	0.5f, -0.5f,  0.0f,
//	-0.5f, -0.5f,  0.0f
//};
//
//char *vs = NULL;	// Pointer to a Charcter array for the vertext shader
//char *fs = NULL;	// Pointer to a character array for the fragment shader
//
//float points[] = {
//						//This comand ensures we always have a clear screen to work with
//						//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//					
//						// Reset transformations of the cube
//						//glLoadIdentity();
//
//						// movement of the cube
//						//glRotatef(rotate_x, 1.0, 0.0, 0.0);
//						//glRotatef(rotate_y, 0.0, 1.0, 0.0);
//					
//								
//						// We begin to draw the cube side by side. Ensuring we assign th epolygones counter clockwise.
//						//Multi-coloured side - Front
//						glBegin(GL_POLYGON);
//					
//						glColor3f(1.0, 0.0, 0.0);	glVertex3f(0.5, -0.5, -0.5); // Polygon1 is red
//						glColor3f(0.0, 1.0, 0.0);	glVertex3f(0.5, 0.5, -0.5);  // Polygon2 is green
//						glColor3f(0.0, 0.0, 1.0);	glVertex3f(-0.5, 0.5, -0.5); // Polygon3 is blue
//						glColor3f(1.0, 0.0, 1.0);	glVertex3f(-0.5, -0.5, -0.5); // Polygon4 is purple
//					
//						glEnd();
//					
//						//Multicolour side - Back
//						glBegin(GL_POLYGON);
//					
//						
//					
//						glColor3f(1.0, 0.0, 0.0);   glVertex3f(0.5, -0.5, 0.5); //Polygon is red
//						glColor3f(0.0, 1.0, 1.0);   glVertex3f(0.5, 0.5, 0.5);  //Polygone is  green
//						glColor3f(1.0, 0.0, 1.0);   glVertex3f(-0.5, 0.5, 0.5);   //Polygone is purple
//						glColor3f(1.0, 1.0, 1.0);   glVertex3f(-0.5, -0.5, 0.5);  //Polygone is green
//					
//						glEnd();
//					
//						//Purple side - Right
//						glBegin(GL_POLYGON);
//					
//						glColor3f(1.0, 0.0, 1.0);
//					
//						glVertex3f(0.5, -0.5, -0.5);
//						glVertex3f(0.5, 0.5, -0.5);
//						glVertex3f(0.5, 0.5, 0.5);
//						glVertex3f(0.5, -0.5, 0.5);
//					
//						
//						};
//					
//						glEnd();
//					
//						//Green side - Left
//						glBegin(GL_POLYGON);
//					
//						glColor3f(0.0, 1.0, 0.0);
//					
//						glVertex3f(-0.5, -0.5, 0.5);
//						glVertex3f(-0.5, 0.5, 0.5);
//						glVertex3f(-0.5, 0.5, -0.5);
//						glVertex3f(-0.5, -0.5, -0.5);
//					
//						glEnd();
//					
//						//Blue side - Top
//						glBegin(GL_POLYGON);
//					
//						glColor3f(0.0, 0.0, 1.0);
//					
//						glVertex3f(0.5, 0.5, 0.5);
//						glVertex3f(0.5, 0.5, -0.5);
//						glVertex3f(-0.5, 0.5, -0.5);
//						glVertex3f(-0.5, 0.5, 0.5);
//					
//						glEnd();
//					
//						//Red side - Bottom
//						glBegin(GL_POLYGON);
//					
//						glColor3f(1.0, 0.0, 0.0);
//					
//						glVertex3f(0.5, -0.5, -0.5);
//						glVertex3f(0.5, -0.5, 0.5);
//						glVertex3f(-0.5, -0.5, 0.5);
//						glVertex3f(-0.5, -0.5, -0.5);
//					
//						glEnd();
//					
////						char *vs = NULL;	// Pointer to a Character array for the vertext shader
////						char *fs = NULL;	// Pointer to a character array for the fragment shader
//
////////////////////////////////////////////////////////////////////////////////
//// shaderCompilerCheck()
////
//// Function to check the shader has been compiled correctly
//// Outputs any compile errors in the shader to the command line window
////////////////////////////////////////////////////////////////////////////////
//
//void shaderCompilerCheck(GLuint ID) {
//	GLint comp;
//	glGetShaderiv(ID, GL_COMPILE_STATUS, &comp);  // Return the compile status from the shader
//
//	if (comp == GL_FALSE) {		// If shader failed to compile, print the error message
//		printf("Shader Compilation FAILED");
//		GLchar messages[256];
//		glGetShaderInfoLog(ID, sizeof(messages), 0, &messages[0]);
//		printf("message %s \n", messages);
//	}
//}
//
////////////////////////////////////////////////////////////////////////////////
//// shaderLinkCheck()
////
//// Function to check the shader has been linked to the main application correctly
//// Outputs any compile errors in the shader to the command line window
////////////////////////////////////////////////////////////////////////////////
//void shaderLinkCheck(GLuint ID) {
//	GLint linkStatus, validateStatus;
//	glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus); // Return the linker status from the shader
//
//	if (linkStatus == GL_FALSE) {	// If shader failed to link, print the error message
//		printf("Shader Linking FAILED\n");
//		GLchar messages[256];
//		glGetProgramInfoLog(ID, sizeof(messages), 0, &messages[0]);
//		printf("message %s \n", messages);
//	}
//
//	glValidateProgram(ID);	// Check to see if the application can be executed.
//
//	glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus); // Return the result of the validation process.
//
//	if (validateStatus == GL_FALSE) {	// If application failed to validate, print the error message
//		printf("Shader Validation FAILED\n");
//		GLchar messages[256];
//		glGetProgramInfoLog(ID, sizeof(messages), 0, &messages[0]);
//		printf("message %s \n", messages);
//	}
//}
//
////////////////////////////////////////////////////////////////////////////////
//// shaders()
////
//// Function to create the vertex and fragment shaders
////////////////////////////////////////////////////////////////////////////////
//void shaders()
//{
//
//	sID = glCreateProgram();	// Create the main program
//
//	GLuint vID = glCreateShader(GL_VERTEX_SHADER);	// Create an empty vertex shader program
//	GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);// Create an empty fragment shader program
//
//	vs = textFileRead("VertexShader.vert");		// Load the vertex shader program into a variable
//	fs = textFileRead("FragmentShader.frag");	// Load the fragment shader program into a variable
//
//	glShaderSource(vID, 1, &vs, NULL);	// Load the contents of the vertex shader text file variable into the empty vertex shader program
//	glShaderSource(fID, 1, &fs, NULL);	// Load the contents of the fragment shader text file variable into the empty vertex fragment program
//
//	glCompileShader(vID);	// Compile the vertex shader
//	glCompileShader(fID);	// Compile the fragment shader
//
//	shaderCompilerCheck(vID);	// Check for compile errors in the vertext shader
//	shaderCompilerCheck(fID);	// Check for compile errors in the fragment shader
//
//	glAttachShader(sID, vID);	// Attached the vertex shader to the main program
//	glAttachShader(sID, fID);	// Attached the fragment shader to the main program
//
//	glLinkProgram(sID);	// Send the vertex shader program to the GPU vertex processor, and the fragment shader program to the GPU fragment processor
//
//	shaderLinkCheck(sID);	// Check for Linker errors
//
//	
//}
//
//////Key controls to rotate cube
////
////void specialKeys(int key, int x, int y)
////{
////	// Rotate right by 5 degrees
////	if (key == GLUT_KEY_RIGHT)
////		rotate_y += 5;
////
////	//Rotate left by 5 degrees
////	else if (key == GLUT_KEY_LEFT)
////		rotate_y -= 5;
////
////	//Rotate upwards by 5 degrees
////	else if (key == GLUT_KEY_UP)
////	rotate_x += 5;
////
////	//Rotate downwards by 5 degrees
////	else if (key == GLUT_KEY_DOWN)
////	rotate_x -= 5;
////	
////	//Update display
////	glutPostRedisplay();
////
////}
//
//void initGL() {
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LEQUAL);
//	glMatrixMode(GL_PROJECTION);
//	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
//}
//
//void reshape(GLsizei width, GLsizei height) {
//	if (height == 0) height = 1;
//	GLfloat aspect = (GLfloat)width / (GLfloat)height;
//
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	gluPerspective(45.0, 1.0, 1.0, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(0.0, 6.0, 0.0, 0.0, 0.0, -7.0, 0, 1, 0);
//	glTranslatef(0.0f, 0.0f, -7.0f);
//
//	glClearColor(0.0, 1.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glUseProgram(sID);	// Use shader program which has already been setup in main()
//
//	glDrawArrays(GL_TRIANGLES, 1, 3);	// Use the first 3 vertices from position 0 to draw a triangle
//	glDrawArrays(GL_QUADS, 6, 4);
//
//										////////////////////////////////////////////////////////////////////
//										// Note the increase in memory usage when this section of code is 
//										// placed in display(). Move this code to the bottom of shaders()
//										// and note the change in memory usage.
//										////////////////////////////////////////////////////////////////////
//	
//	glGenBuffers(1, &vbo);				// Create a buffer object
//	glBindBuffer(GL_ARRAY_BUFFER, vbo); // Make the buffer object a vertex array
//	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);  //Set the size of the buffer, and insert the data
//	glGenVertexArrays(1, &vao);			// Generate a name for the vertex array
//	glBindVertexArray(vao);				// Bind the vertex arary object
//	glEnableVertexAttribArray(0);		// Now enable the vertex array
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); // Apply some properties to the vertices. Lookup this command in documentation for more details
//															  ////////////////////////////////////////////////////////////////////
//															  ////////////////////////////////////////////////////////////////////
//
//	glUseProgram(0);	//Unbind the shader program
//
//	glutSwapBuffers();
//	glutPostRedisplay();
//}
//
//
//int main(int argc, char **argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitDisplayMode(GLUT_DOUBLE);
//	glutInitWindowPosition(200, 50);
//	glutInitWindowSize(giXRes, giYRes);
//	glutCreateWindow("Second semester assignment");
//	glEnable(GL_DEPTH_TEST);
//	initGL();
//	glewInit();
//
//	//Callback functions for the cube
//	//glutDisplayFunc(display);
////	glutSpecialFunc(specialKeys);
//
//	// Check if OpenGL Shading Language is available
//	if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
//		printf("Ready for GLSL\n");
//	else
//	{
//		printf("No GLSL support\n");
//		exit(1);
//	}
//
//	shaders();	// Create the shader programs
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//
//	glutMainLoop();
//
//	return 0;
//}
//
//
//
//
///*
//glFlush();
//glutSwapBuffers();
//
//
//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//gluPerspective(45.0, 1.0, 1.0, 100.0);
//glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();
//
//gluLookAt(0.0, 6.0, 0.0, 0.0, 0.0, -7.0, 0, 1, 0);
//glTranslatef(0.0f, 0.0f, -7.0f);
//
//glClearColor(0.0, 1.0, 0.0, 0.0);
//glClear(GL_COLOR_BUFFER_BIT);
//
//glUseProgram(sID);	// Use shader program which has already been setup in main()
//
//glDrawArrays(GL_TRIANGLES, 0, 3);	// Use the first 3 vertices from position 0 to draw a triangle
//
//////////////////////////////////////////////////////////////////////
//// Note the increase in memory usage when this section of code is
//// placed in display(). Move this code to the bottom of shaders()
//// and note the change in memory usage.
//////////////////////////////////////////////////////////////////////
//
//glBindBuffer(GL_ARRAY_BUFFER, vbo); // Make the buffer object a vertex array
//glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);  //Set the size of the buffer, and insert the data
//glGenVertexArrays(1, &vao);			// Generate a name for the vertex array
//glBindVertexArray(vao);				// Bind the vertex arary object
//glEnableVertexAttribArray(0);		// Now enable the vertex array
//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); // Apply some properties to the vertices. Lookup this command in documentation for more details
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//glUseProgram(0);	//Unbind the shader program
//
//glutSwapBuffers();
//glutPostRedisplay();
//}
//
//
//
//*/
///*
//*********************************************************************************************************************
//********************************************************************************************************************
//
//*		This Code Was Created By Jeff Molofee 2000
//*		A HUGE Thanks To Fredric Echols For Cleaning Up
//*		And Optimizing The Base Code, Making It More Flexible!
//*		If You've Found This Code Useful, Please Let Me Know.
//*		Visit My Site At nehe.gamedev.net
//
//
////#include <windows.h>		// Header File For Windows
////#include <gl\gl.h>			// Header File For The OpenGL32 Library
////#include <gl\glu.h>			// Header File For The GLu32 Library
////#include <gl\glaux.h>		// Header File For The Glaux Library
//
//HDC			hDC = NULL;		// Private GDI Device Context
//HGLRC		hRC = NULL;		// Permanent Rendering Context
//HWND		hWnd = NULL;		// Holds Our Window Handle
//HINSTANCE	hInstance;		// Holds The Instance Of The Application
//
//bool	keys[256];			// Array Used For The Keyboard Routine
//bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
//bool	fullscreen = TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default
//
//GLfloat	rtri;				// Angle For The Triangle ( NEW )
//GLfloat	rquad;				// Angle For The Quad ( NEW )
//
//LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
//
//GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
//{
//	if (height == 0)										// Prevent A Divide By Zero By
//	{
//		height = 1;										// Making Height Equal One
//	}
//
//	glViewport(0, 0, width, height);						// Reset The Current Viewport
//
//	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
//	glLoadIdentity();									// Reset The Projection Matrix
//
//														// Calculate The Aspect Ratio Of The Window
//	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
//
//	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
//	glLoadIdentity();									// Reset The Modelview Matrix
//}
//
//int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
//{
//	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
//	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
//	glClearDepth(1.0f);									// Depth Buffer Setup
//	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
//	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
//	return TRUE;										// Initialization Went OK
//}
//
//int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
//	glLoadIdentity();									// Reset The Current Modelview Matrix
//	glTranslatef(-1.5f, 0.0f, -6.0f);						// Move Left 1.5 Units And Into The Screen 6.0
//	glRotatef(rtri, 0.0f, 1.0f, 0.0f);						// Rotate The Triangle On The Y axis ( NEW )
//	glBegin(GL_TRIANGLES);								// Start Drawing A Triangle
//	glColor3f(1.0f, 0.0f, 0.0f);						// Red
//	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Front)
//	glColor3f(0.0f, 1.0f, 0.0f);						// Green
//	glVertex3f(-1.0f, -1.0f, 1.0f);					// Left Of Triangle (Front)
//	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
//	glVertex3f(1.0f, -1.0f, 1.0f);					// Right Of Triangle (Front)
//	glColor3f(1.0f, 0.0f, 0.0f);						// Red
//	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Right)
//	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
//	glVertex3f(1.0f, -1.0f, 1.0f);					// Left Of Triangle (Right)
//	glColor3f(0.0f, 1.0f, 0.0f);						// Green
//	glVertex3f(1.0f, -1.0f, -1.0f);					// Right Of Triangle (Right)
//	glColor3f(1.0f, 0.0f, 0.0f);						// Red
//	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Back)
//	glColor3f(0.0f, 1.0f, 0.0f);						// Green
//	glVertex3f(1.0f, -1.0f, -1.0f);					// Left Of Triangle (Back)
//	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
//	glVertex3f(-1.0f, -1.0f, -1.0f);					// Right Of Triangle (Back)
//	glColor3f(1.0f, 0.0f, 0.0f);						// Red
//	glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of Triangle (Left)
//	glColor3f(0.0f, 0.0f, 1.0f);						// Blue
//	glVertex3f(-1.0f, -1.0f, -1.0f);					// Left Of Triangle (Left)
//	glColor3f(0.0f, 1.0f, 0.0f);						// Green
//	glVertex3f(-1.0f, -1.0f, 1.0f);					// Right Of Triangle (Left)
//	glEnd();											// Done Drawing The Pyramid
//
//	glLoadIdentity();									// Reset The Current Modelview Matrix
//	glTranslatef(1.5f, 0.0f, -7.0f);						// Move Right 1.5 Units And Into The Screen 7.0
//	glRotatef(rquad, 1.0f, 1.0f, 1.0f);					// Rotate The Quad On The X axis ( NEW )
//	glBegin(GL_QUADS);									// Draw A Quad
//	glColor3f(0.0f, 1.0f, 0.0f);						// Set The Color To Green
//	glVertex3f(1.0f, 1.0f, -1.0f);					// Top Right Of The Quad (Top)
//	glVertex3f(-1.0f, 1.0f, -1.0f);					// Top Left Of The Quad (Top)
//	glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom Left Of The Quad (Top)
//	glVertex3f(1.0f, 1.0f, 1.0f);					// Bottom Right Of The Quad (Top)
//	glColor3f(1.0f, 0.5f, 0.0f);						// Set The Color To Orange
//	glVertex3f(1.0f, -1.0f, 1.0f);					// Top Right Of The Quad (Bottom)
//	glVertex3f(-1.0f, -1.0f, 1.0f);					// Top Left Of The Quad (Bottom)
//	glVertex3f(-1.0f, -1.0f, -1.0f);					// Bottom Left Of The Quad (Bottom)
//	glVertex3f(1.0f, -1.0f, -1.0f);					// Bottom Right Of The Quad (Bottom)
//	glColor3f(1.0f, 0.0f, 0.0f);						// Set The Color To Red
//	glVertex3f(1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Front)
//	glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Front)
//	glVertex3f(-1.0f, -1.0f, 1.0f);					// Bottom Left Of The Quad (Front)
//	glVertex3f(1.0f, -1.0f, 1.0f);					// Bottom Right Of The Quad (Front)
//	glColor3f(1.0f, 1.0f, 0.0f);						// Set The Color To Yellow
//	glVertex3f(1.0f, -1.0f, -1.0f);					// Top Right Of The Quad (Back)
//	glVertex3f(-1.0f, -1.0f, -1.0f);					// Top Left Of The Quad (Back)
//	glVertex3f(-1.0f, 1.0f, -1.0f);					// Bottom Left Of The Quad (Back)
//	glVertex3f(1.0f, 1.0f, -1.0f);					// Bottom Right Of The Quad (Back)
//	glColor3f(0.0f, 0.0f, 1.0f);						// Set The Color To Blue
//	glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Left)
//	glVertex3f(-1.0f, 1.0f, -1.0f);					// Top Left Of The Quad (Left)
//	glVertex3f(-1.0f, -1.0f, -1.0f);					// Bottom Left Of The Quad (Left)
//	glVertex3f(-1.0f, -1.0f, 1.0f);					// Bottom Right Of The Quad (Left)
//	glColor3f(1.0f, 0.0f, 1.0f);						// Set The Color To Violet
//	glVertex3f(1.0f, 1.0f, -1.0f);					// Top Right Of The Quad (Right)
//	glVertex3f(1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Right)
//	glVertex3f(1.0f, -1.0f, 1.0f);					// Bottom Left Of The Quad (Right)
//	glVertex3f(1.0f, -1.0f, -1.0f);					// Bottom Right Of The Quad (Right)
//	glEnd();											// Done Drawing The Quad
//
//	rtri += 0.2f;											// Increase The Rotation Variable For The Triangle ( NEW )
//	rquad -= 0.15f;										// Decrease The Rotation Variable For The Quad ( NEW )
//	return TRUE;										// Keep Going
//}
//
//GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
//{
//	if (fullscreen)										// Are We In Fullscreen Mode?
//	{
//		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
//		ShowCursor(TRUE);								// Show Mouse Pointer
//	}
//
//	if (hRC)											// Do We Have A Rendering Context?
//	{
//		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
//		{
//			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//		}
//
//		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
//		{
//			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//		}
//		hRC = NULL;										// Set RC To NULL
//	}
//
//	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
//	{
//		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//		hDC = NULL;										// Set DC To NULL
//	}
//
//	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
//	{
//		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//		hWnd = NULL;										// Set hWnd To NULL
//	}
//
//	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
//	{
//		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//		hInstance = NULL;									// Set hInstance To NULL
//	}
//}
//
///*	This Code Creates Our OpenGL Window.  Parameters Are:					*
//*	title			- Title To Appear At The Top Of The Window				*
//*	width			- Width Of The GL Window Or Fullscreen Mode				*
//*	height			- Height Of The GL Window Or Fullscreen Mode			*
//*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
//*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*
//
//BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
//{
//	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
//	WNDCLASS	wc;						// Windows Class Structure
//	DWORD		dwExStyle;				// Window Extended Style
//	DWORD		dwStyle;				// Window Style
//	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
//	WindowRect.left = (long)0;			// Set Left Value To 0
//	WindowRect.right = (long)width;		// Set Right Value To Requested Width
//	WindowRect.top = (long)0;				// Set Top Value To 0
//	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height
//
//	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag
//
//	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
//	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
//	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
//	wc.cbClsExtra = 0;									// No Extra Window Data
//	wc.cbWndExtra = 0;									// No Extra Window Data
//	wc.hInstance = hInstance;							// Set The Instance
//	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
//	wc.hbrBackground = NULL;									// No Background Required For GL
//	wc.lpszMenuName = NULL;									// We Don't Want A Menu
//	wc.lpszClassName = "OpenGL";								// Set The Class Name
//
//	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
//	{
//		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;											// Return FALSE
//	}
//
//	if (fullscreen)												// Attempt Fullscreen Mode?
//	{
//		DEVMODE dmScreenSettings;								// Device Mode
//		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
//		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
//		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
//		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
//		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
//		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
//
//		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
//		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
//		{
//			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
//			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
//			{
//				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
//			}
//			else
//			{
//				// Pop Up A Message Box Letting User Know The Program Is Closing.
//				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
//				return FALSE;									// Return FALSE
//			}
//		}
//	}
//
//	if (fullscreen)												// Are We Still In Fullscreen Mode?
//	{
//		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
//		dwStyle = WS_POPUP;										// Windows Style
//		ShowCursor(FALSE);										// Hide Mouse Pointer
//	}
//	else
//	{
//		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
//		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
//	}
//
//	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size
//
//																	// Create The Window
//	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
//		"OpenGL",							// Class Name
//		title,								// Window Title
//		dwStyle |							// Defined Window Style
//		WS_CLIPSIBLINGS |					// Required Window Style
//		WS_CLIPCHILDREN,					// Required Window Style
//		0, 0,								// Window Position
//		WindowRect.right - WindowRect.left,	// Calculate Window Width
//		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
//		NULL,								// No Parent Window
//		NULL,								// No Menu
//		hInstance,							// Instance
//		NULL)))								// Dont Pass Anything To WM_CREATE
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
//	{
//		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
//		1,											// Version Number
//		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
//		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
//		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
//		PFD_TYPE_RGBA,								// Request An RGBA Format
//		bits,										// Select Our Color Depth
//		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
//		0,											// No Alpha Buffer
//		0,											// Shift Bit Ignored
//		0,											// No Accumulation Buffer
//		0, 0, 0, 0,									// Accumulation Bits Ignored
//		16,											// 16Bit Z-Buffer (Depth Buffer)  
//		0,											// No Stencil Buffer
//		0,											// No Auxiliary Buffer
//		PFD_MAIN_PLANE,								// Main Drawing Layer
//		0,											// Reserved
//		0, 0, 0										// Layer Masks Ignored
//	};
//
//	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	ShowWindow(hWnd, SW_SHOW);						// Show The Window
//	SetForegroundWindow(hWnd);						// Slightly Higher Priority
//	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
//	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen
//
//	if (!InitGL())									// Initialize Our Newly Created GL Window
//	{
//		KillGLWindow();								// Reset The Display
//		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
//		return FALSE;								// Return FALSE
//	}
//
//	return TRUE;									// Success
//}
//
//LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
//	UINT	uMsg,			// Message For This Window
//	WPARAM	wParam,			// Additional Message Information
//	LPARAM	lParam)			// Additional Message Information
//{
//	switch (uMsg)									// Check For Windows Messages
//	{
//	case WM_ACTIVATE:							// Watch For Window Activate Message
//	{
//		// LoWord Can Be WA_INACTIVE, WA_ACTIVE, WA_CLICKACTIVE,
//		// The High-Order Word Specifies The Minimized State Of The Window Being Activated Or Deactivated.
//		// A NonZero Value Indicates The Window Is Minimized.
//		if ((LOWORD(wParam) != WA_INACTIVE) && !((BOOL)HIWORD(wParam)))
//			active = TRUE;						// Program Is Active
//		else
//			active = FALSE;						// Program Is No Longer Active
//
//		return 0;								// Return To The Message Loop
//	}
//
//	case WM_SYSCOMMAND:							// Intercept System Commands
//	{
//		switch (wParam)							// Check System Calls
//		{
//		case SC_SCREENSAVE:					// Screensaver Trying To Start?
//		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
//			return 0;							// Prevent From Happening
//		}
//		break;									// Exit
//	}
//
//	case WM_CLOSE:								// Did We Receive A Close Message?
//	{
//		PostQuitMessage(0);						// Send A Quit Message
//		return 0;								// Jump Back
//	}
//
//	case WM_KEYDOWN:							// Is A Key Being Held Down?
//	{
//		keys[wParam] = TRUE;					// If So, Mark It As TRUE
//		return 0;								// Jump Back
//	}
//
//	case WM_KEYUP:								// Has A Key Been Released?
//	{
//		keys[wParam] = FALSE;					// If So, Mark It As FALSE
//		return 0;								// Jump Back
//	}
//
//	case WM_SIZE:								// Resize The OpenGL Window
//	{
//		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
//		return 0;								// Jump Back
//	}
//	}
//
//	// Pass All Unhandled Messages To DefWindowProc
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}
//
//int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
//	HINSTANCE	hPrevInstance,		// Previous Instance
//	LPSTR		lpCmdLine,			// Command Line Parameters
//	int			nCmdShow)			// Window Show State
//{
//	MSG		msg;									// Windows Message Structure
//	BOOL	done = FALSE;								// Bool Variable To Exit Loop
//
//														// Ask The User Which Screen Mode They Prefer
//	if (MessageBox(NULL, "Would You Like To Run In Fullscreen Mode?\n", "Start FullScreen?\n", MB_YESNO | MB_ICONQUESTION) == IDNO)
//	{
//		fullscreen = FALSE;							// Windowed Mode
//	}
//
//	// Create Our OpenGL Window
//	if (!CreateGLWindow("NeHe's Solid Object Tutorial", 640, 480, 16, fullscreen))
//	{
//		return 0;									// Quit If Window Was Not Created
//	}
//
//	while (!done)									// Loop That Runs While done=FALSE
//	{
//		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
//		{
//			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
//			{
//				done = TRUE;							// If So done=TRUE
//			}
//			else									// If Not, Deal With Window Messages
//			{
//				TranslateMessage(&msg);				// Translate The Message
//				DispatchMessage(&msg);				// Dispatch The Message
//			}
//		}
//		else										// If There Are No Messages
//		{
//			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
//			if ((active && !DrawGLScene()) || keys[VK_ESCAPE])	// Active?  Was There A Quit Received?
//			{
//				done = TRUE;							// ESC or DrawGLScene Signalled A Quit
//			}
//			else									// Not Time To Quit, Update Screen
//			{
//				SwapBuffers(hDC);					// Swap Buffers (Double Buffering)
//			}
//
//			if (keys[VK_F1])						// Is F1 Being Pressed?
//			{
//				keys[VK_F1] = FALSE;					// If So Make Key FALSE
//				KillGLWindow();						// Kill Our Current Window
//				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
//														// Recreate Our OpenGL Window
//				if (!CreateGLWindow("NeHe's Solid Object Tutorial", 640, 480, 16, fullscreen))
//				{
//					return 0;						// Quit If Window Was Not Created
//				}
//			}
//		}
//	}
//
//	// Shutdown
//	KillGLWindow();									// Kill The Window
//	return (msg.wParam);							// Exit The Program
//}
//*/
//
////+++++++++++++++++++++++++++++
////++++++++++++++++++++++++++++
//
//
////http://www.youtube.com/user/thecplusplusguy
////Thanks for the typed in code to Tapit85
////you need brick.bmp in format R5G6B5
//
////#include <stdio.h>
////#include <stdlib.h>
////#include <glew.h>
////#include <glut.h>
////#include "textfile.h"	// Header file for code to read a textfile, used to read in the shader files
//
////
////Gluint myImage;
////
////void drawCube(float size)
////{
////	float difamb[] = { 1.0,0.5,0.3,1.0 };
////	glBegin(GL_QUADS);
////	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);
////	// front face
////	glNormal3f(0.0, 0.0, 1.0);
////	//		glColor3f(1.0,0.0,0.0);
////	glVertex3f(size / 2, size / 2, size / 2);
////	glVertex3f(-size / 2, size / 2, size / 2);
////	glVertex3f(-size / 2, -size / 2, size / 2);
////	glVertex3f(size / 2, -size / 2, size / 2);
////	// left face
////	glNormal3f(-1.0, 0.0, 0.0);
////	//		glColor3f(0.0,1.0,0.0);
////	glVertex3f(-size / 2, size / 2, size / 2);
////	glVertex3f(-size / 2, -size / 2, size / 2);
////	glVertex3f(-size / 2, -size / 2, -size / 2);
////	glVertex3f(-size / 2, size / 2, -size / 2);
////	// back face
////	glNormal3f(0.0, 0.0, -1.0);
////	//		glColor3f(0.0,0.0,1.0);
////	glVertex3f(size / 2, size / 2, -size / 2);
////	glVertex3f(-size / 2, size / 2, -size / 2);
////	glVertex3f(-size / 2, -size / 2, -size / 2);
////	glVertex3f(size / 2, -size / 2, -size / 2);
////	// right face
////	glNormal3f(1.0, 0.0, 0.0);
////	//		glColor3f(1.0,1.0,0.0);
////	glVertex3f(size / 2, size / 2, size / 2);
////	glVertex3f(size / 2, -size / 2, size / 2);
////	glVertex3f(size / 2, -size / 2, -size / 2);
////	glVertex3f(size / 2, size / 2, -size / 2);
////	// top face
////	glNormal3f(0.0, 1.0, 0.0);
////	//		glColor3f(1.0,0.0,1.0);
////	glVertex3f(size / 2, size / 2, size / 2);
////	glVertex3f(-size / 2, size / 2, size / 2);
////	glVertex3f(-size / 2, size / 2, -size / 2);
////	glVertex3f(size / 2, size / 2, -size / 2);
////	// bottom face
////	glNormal3f(0.0, -1.0, 0.0);
////	//		glColor3f(0.0,1.0,1.0);
////	glVertex3f(size / 2, -size / 2, size / 2);
////	glVertex3f(-size / 2, -size / 2, size / 2);
////	glVertex3f(-size / 2, -size / 2, -size / 2);
////	glVertex3f(size / 2, -size / 2, -size / 2);
////	glEnd();
////}
////
////float angle = 0.0;
////const int triangle = 1;
////
////unsigned int loadTexture(const char* filename)
////{
////	//SDL_Surface* img = SDL_LoadBMP(filename);
////	myImage = ilutGLLoadImage(Flower1.bmp);
////	unsigned int id;
////	glGenTextures(1, &id);
////	glBindTexture(GL_TEXTURE_2D, id);
////	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////	//SDL_FreeSurface(img);
////	return id;
////}
////
////unsigned int tex;
////
////void init()
////{
////	glClearColor(0.0, 0.0, 0.0, 1.0);	//background color and alpha
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	gluPerspective(45, 640.0 / 480.0, 1.0, 500.0);
////	glMatrixMode(GL_MODELVIEW);
////	glEnable(GL_DEPTH_TEST);
////	glEnable(GL_TEXTURE_2D);
////	tex = loadTexture("brick.bmp");
////}
////
////void display()
////{
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	glLoadIdentity();
////	glTranslatef(0.0, 0.0, -5.0);
////	glRotatef(angle, 1.0, 1.0, 1.0);	// angle, x-axis, y-axis, z-axis
////	glBindTexture(GL_TEXTURE_2D, tex);
////	glBegin(GL_QUADS);
////	glTexCoord2f(0.0, 2.0);
////	glVertex3f(-2.0, 2.0, 0.0);
////	glTexCoord2f(0.0, 0.0);
////	glVertex3f(-2.0, -2.0, 0.0);
////	glTexCoord2f(2.0, 0.0);
////	glVertex3f(2.0, -2.0, 0.0);
////	glTexCoord2f(2.0, 2.0);
////	glVertex3f(2.0, 2.0, 0.0);
////	glEnd();
////}
////
////int main(int argc, char** argv)
////{
////	SDL_Init(SDL_INIT_EVERYTHING);
////	SDL_Surface *screen;
////	screen = SDL_SetVideoMode(1024, 768, 32, SDL_SWSURFACE | SDL_OPENGL | SDL_FULLSCREEN);
////	//	screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_FULLSCREEN);
////	bool running = true;
////	const int FPS = 30;
////	Uint32 start;
////	SDL_Event event;
////	init();
////	while (running) {
////		start = SDL_GetTicks();
////		while (SDL_PollEvent(&event)) {
////			switch (event.type) {
////			case SDL_QUIT:
////				running = false;
////				break;
////			case SDL_KEYDOWN:
////				switch (event.key.keysym.sym)
////				{
////				case SDLK_ESCAPE:
////					running = false;
////					break;
////				}
////				break;
////			}
////		}
////
////		display();
////		SDL_GL_SwapBuffers();
////		angle += 0.5;
////		if (angle > 360)
////			angle -= 360;
////		if (1000 / FPS > SDL_GetTicks() - start)
////			SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
////	}
////	SDL_Quit();
////	return 0;
////}
//
////#include <glut.h>   #include <IL/ilut.h> // Adds funstionality to load textures 
////
////GLint giXRes = 800; GLint giYRes = 800; GLfloat zRotate = 0;    GLfloat rotateSpeed = 0.1f;
////
////GLuint myImage; // Varaible to hole the name of the texture to load 
////
////void InitTextures(void) {  // Define wrapping behaviour for material  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
////
////						   // Define texture Filtering behaviour for material  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST); 
////
////	myImage = ilutGLLoadImage("Flower1.bmp"); // Load an image and apply it to the variable myImage 
////
////	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); // Define how material is sent further down the rendering pipeline                 // this will become redundant when we start to use shaders } 
////
////	void drawSquare() {
////
////		glEnable(GL_TEXTURE_2D);   // Switch on 2D texture mapping, this will overiride any glColor()  glBindTexture(GL_TEXTURE_2D, myImage);// Use the suplied 2D texture with any primitive shapes cfeated from this point onwards  glBegin(GL_POLYGON);   // Define clockwise   glTexCoord2f(0.0, 0.0);   // Assign a UV c-ordinate for the next vertex   glVertex3f(-1, -1, 1);  
////
////		glTexCoord2f(0.0, 1.0);   // Assign a UV c-ordinate for the next vertex   glVertex3f(-1, 1, 1);  
////
////		glTexCoord2f(1.0, 1.0);   // Assign a UV c-ordinate for the next vertex   glVertex3f(1, 1, 1); 
////
////		glTexCoord2f(1.0, 0.0);   // Assign a UV c-ordinate for the next vertex   glVertex3f(1, -1, 1); 
////
////		glEnd(); /*  glBegin(GL_POLYGON);   // Define anti-clockwise   glTexCoord2f(1.0, 0.0);    glVertex3f(-1.0f, 1.0f, 1.0f);
////
////				 glTexCoord2f(1.0, 1.0);   glVertex3f(-1.0f, 1.0f, -1.0f);
////
////				 glTexCoord2f(0.0, 1.0);   glVertex3f(-1.0f, -1.0f, -1.0f);
////
////				 glTexCoord2f(0.0, 0.0);   glVertex3f(-1.0f, -1.0f, 1.0f);   glEnd(); */  glDisable(GL_TEXTURE_2D);   // Swich off 2D texture mapping } 
////
////		void display() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   glMatrixMode(GL_PROJECTION);  glLoadIdentity();  gluPerspective(45.0, 1.0, 1.0, 100.0);  glMatrixMode(GL_MODELVIEW);  glLoadIdentity();  glClearColor(1.0, 1.0, 1.0, 0.0);  glClear(GL_COLOR_BUFFER_BIT);    glTranslatef(0.0f, 0.0f, -5.0f);  zRotate = zRotate + rotateSpeed;  glPushMatrix();   glRotatef(zRotate, 0.0, 1.0, 0.0);     drawSquare();  glPopMatrix();    glutSwapBuffers();    glutPostRedisplay(); }
////
////		void initGL() {
////			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  glClearDepth(1.0f);  glEnable(GL_DEPTH_TEST);
////			glDepthFunc(GL_LEQUAL);  glShadeModel(GL_SMOOTH);     glMatrixMode(GL_PROJECTION);     glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
////		}
////
////		int main(int argc, char** argv) {
////			glutInit(&argc, argv);              glutInitDisplayMode(GLUT_DOUBLE);   glutInitWindowSize(giXRes, giYRes);  glutInitWindowPosition(50, 50);   glutCreateWindow("Load a texture");              /////////////////////////////////////////////  // Functions to setup the OpenILUT  renderer  ilInit();  iluInit();  ilutRenderer(ILUT_OPENGL);   ///////////////////////////////////////////// 
////
////			glFrontFace(GL_CW);  // When defining primitives, the FRONT side is assumed to be created from vertices which are listed in a clockwise direction  glCullFace(GL_BACK); // Specify if front or back faces should be culled. only takes effect if glEnable(GL_CULL_FACE) is executed // glEnable(GL_CULL_FACE); // Uncomment this line to stop the back face of the QUAD being displayed  glEnable(GL_DEPTH_TEST);   InitTextures();   // Custom function to configure the textures 
////
////			initGL();  glutDisplayFunc(display);         glutMainLoop();   return 0;
////		}