//// include the GLUT header file so we can access all the GLUT calls
//#include <glut.h>
//bool FullScreen = false;
//int window1ID;
//// Create a method to hold all our drawing calls
//// This function must be declared before the MAIN call so that MAIN knows it exists
//// NOTE: read the contents of MAIN first, before reading the DISPLAY method. It will make more sense that way !
//void display(void)
//{
//	
//	// glClear sets the colour of the window to the colour previously define by
//	// glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum
//	glClear(GL_COLOR_BUFFER_BIT);
//	// et the colour of any future objects we create
//	// This colour will remain the active draw colour until we change it
//	glColor3f(1.0, 0.0, 0.0);
//	///////////////////////////////////////////////////
//	//draw a line - START
//	///////////////////////////////////////////////////
//	//Start to crete a line primitive
//	glBegin(GL_LINES);
//	// Now add in the vertices of the line
//	glVertex2i(10, 10);
//	glVertex2i(200, 200);
//	glEnd(); //declare that the line is now finished primitive
//			 ///////////////////////////////////////////////////
//			 //draw a line - END
//			 ///////////////////////////////////////////////////
//			 // Now process all the OpenGL commands as quickly as possible
//	glFlush();
//}
//    
//
//// Create windows application
////Use keyboards ASCII code
//void keyboard(unsigned char key, int a, int b) {
//	switch (key) {
//	case 49://1 Change Title
//		glutSetWindowTitle("The New Title");
//		break;
//
//	case 50://2 Reposition Window
//		glutPositionWindow(400, 600);
//		break;
//
//	case 51://3 Full Screen Change
//		if(FullScreen==false) {
//		glutFullScreen();
//		}
//
//		else if (FullScreen == true) {
//			glutReshapeWindow(400, 400);
//			glutPositionWindow(200, 200);
//		}
//
//		FullScreen = !FullScreen;
//		break;
//
//	case 52://4 Iconify and title change
//		glutIconifyWindow();
//
//		glutSetIconTitle("Hidden");
//
//		break;
//	case 101://e Push
//		glutPushWindow();
//
//		break;
//	case 102://f Pop
//		glutPopWindow();
//
//		break;
//	case 103://g DESTROY
//		glutDestroyWindow(window1ID);
//		break;
//	case 104://h
//
//		break;
//	case 105://i
//
//		break;
//
//	}
//}
//void main(int argc, char *argv[])
//{
//	//Start the GLUT windowing system
//	glutInit(&argc, argv);
//	// Define settings for the display
//	// GLUT_SINGLE = use a single rerfesh buffer
//	// GLUT_RGB = use the RGB colour space
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	// Set the dimensions of all future windows.
//	glutInitWindowSize(500, 500);
//	// Set the position of the window. Origin is top left of screen
//	glutInitWindowPosition(100, 100);
//	// Create a window with a title
//	glutCreateWindow("My Line");
//	// Set the background colour of the window to white (red, green, blue, alpha)
//	// RGB values in range of 0 to 1
//	// Alpha channel used to blend two overlapping objects
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	// OpenGL assumes you are working with 3D graphcis by default
//	// If we want to work in just 2D we have to tell OpenGL that we want to do this
//	// We therefore tell OpenGL to 'project' the image onto a 2D plane.
//	glMatrixMode(GL_PROJECTION);
//	glutKeyboardFunc(keyboard);
//	// Now setup the coordinate system for the projected image
//	// (x min, x max, y min, y max)
//	// Bottom left = (0,0) top right = (250,250)
//	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
//	// Process the 'display' method and pass the results to DisplayFunc
//	// which will pass the results to the display window, ready to be displayed.
//	glutDisplayFunc(display);
//	// The contents of the display window are not drawn immediately.
//	// The following function displays the content.
//	// This must be the last function in the program
//	glutMainLoop();
//}
