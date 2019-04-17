#include <GL/glut.h>
#include <iostream>


// window size
#define lenX 800
#define lenY 600

// colors
#define white 1.0, 1.0, 1.0
#define blue 0.35, 0.35, 0.58
#define black 0.0, 0.0, 0.0
#define red 0.9, 0.15, 0.15
#define yellow 0.85, 0.75, 0.0
#define green 0.0, 0.75, 0.1

// variables
float prop;
const double eps = 1e-9;

// prototypes
void ilumination();
void drawColoredCircle(GLdouble, GLdouble, GLint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
void drawShapes();
void reshape(int, int);
void observer();


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(lenX, lenY);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-lenX)/2, (glutGet(GLUT_SCREEN_HEIGHT)-lenY)/2);
    glutCreateWindow("L5");

    glutDisplayFunc(drawShapes);
    glutReshapeFunc(reshape);

    glutMainLoop();
}


void drawColoredCircle(GLdouble iR, GLdouble oR, GLint sides, GLint rings, GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    glColor4f(r, g, b, a);
	glutSolidTorus(iR, oR, sides, rings);
}


void drawShapes() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ilumination();
    
	//Circles
	glPushMatrix();
        glTranslated(-36.0, 0.0, 0.0);
        drawColoredCircle(1.8, 15.0, 30, 60, blue, 1.0);
    glPopMatrix();

	drawColoredCircle(1.8, 15.0, 30, 60, black, 1.0);

    glPushMatrix();
		glTranslated(36.0, 0.0, 0.0);
		drawColoredCircle(1.8, 15.0, 30, 60, red, 1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-18.0, -15.0, 1.5);
        drawColoredCircle(1.8, 15.0, 30, 60, yellow, 1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslated(18.0, -15.0, 1.5f);
		drawColoredCircle(1.8, 15.0, 30, 60, green, 1.0);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int x, int y) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(white,1.0);

    glEnable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

    prop = (float)x/(float)y;
    //std::cout << "glut screen width(DEFUALT): " << x << std::endl;
    //std::cout << "glut screen height(DEFAULT): " << y << std::endl;
    //std::cout << prop << std::endl;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 30, prop, 0.2, 600 );
    glViewport(0, 0, x, y);
    observer();
}

void observer() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    ilumination();

    gluLookAt(
        0,45,150,
        0,0,0,
        0,120,0
	);
}

void ilumination()
{

    GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0};
	GLfloat luzAmbiente[4] = {0.2, 0.2 ,0.2, 1.0};
	GLfloat luzDifusa[4] = {0.6, 0.6, 0.6, 1.0};
	GLfloat luzPos[4] = {0.0, 60.0, 90.0, 1.0};

	GLint especMaterial = 60;
	GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};

	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, luzPos);
}