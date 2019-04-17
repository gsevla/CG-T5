#include <GL/glut.h>
#include <stdlib.h>

void Lighting( void )
{

    GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat luzAmbiente[4] = { 0.2, 0.2 ,0.2, 1.0 };
	GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat luzPos[4] = { 0.0, 80.0, 100.0, 1.2 };


	GLint especMaterial = 60;
	GLfloat especularidade[4] = { 1.0, 1.0, 1.0, 1.0 };


	glMaterialfv( GL_FRONT, GL_SPECULAR, especularidade );
	glMateriali( GL_FRONT, GL_SHININESS, especMaterial );


	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, luzAmbiente );


	glLightfv( GL_LIGHT0, GL_AMBIENT, luzAmbiente );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv( GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv( GL_LIGHT0, GL_POSITION, luzPos );
}



void Draw(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	Lighting();

	//Circles

	//Gy
	glPushMatrix();
		glTranslated( -40.0f, 0.0f, 0.0f );
		glColor3f( 0.35, 0.35, 0.58 );
		glutSolidTorus( 2.0, 17.0, 20, 40 );
	glPopMatrix();

	// B
	glColor3f( 0.0f, 0.0f, 0.0f );
	glutSolidTorus( 2.0, 17.0, 20, 40 );

    // R
    glPushMatrix();
		glTranslated( 40.0f, 0.0f, 0.0f );
		glColor3f(0.90f, 0.15f, 0.15f);
		glutSolidTorus(2.0, 17.0, 20, 40);
	glPopMatrix();

	// Y
	glPushMatrix();
		glTranslated( -20.0f, -17.0f, 1.5f );
		glColor3f(0.85f, 0.80f, 0.00f);
		glutSolidTorus(2.0, 17.0, 20, 40);
	glPopMatrix();

	// G
	glPushMatrix();
		glTranslated( 20.0f, -17.0f, 1.5f );
		glColor3f(0.00f, 0.99f, 0.10f);
		glutSolidTorus(2.0, 17.0, 20, 40);
	glPopMatrix();

	glutSwapBuffers();
}


void Observer(void)
{

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	Lighting();

    gluLookAt(
        0,45,200,
        0,0,0,
        0,1,0
	);
}

void Teclado( unsigned char tecla, int x, int y )
{
	if( tecla == 27 ) // 27 = esc
	{
		exit( 0 );
	}
}


void Inicializa( void )
{
	// White background
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

	glEnable( GL_COLOR_MATERIAL );

	glEnable( GL_LIGHTING );

	glEnable( GL_LIGHT0 );

	glEnable( GL_DEPTH_TEST );

	glShadeModel( GL_SMOOTH );

	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();

	gluPerspective( 50, 1.0, 0.5, 500 );

	glViewport( 0, 0, 500, 500 );

	Observer();
}

int main( int argc, char **argv )
{
	glutInit( &argc, argv );

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

	glutInitWindowPosition( 5, 5 );

	glutInitWindowSize( 500,500);

	glutCreateWindow("Olimpiadas");

	glutDisplayFunc(Draw);

	glutKeyboardFunc (Teclado);

	Inicializa();

	glutMainLoop();

	return 0;
}
