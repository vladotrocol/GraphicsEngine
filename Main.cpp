#include <windows.h>
#include <GLTools.h>
#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif
const int screenWidth = 800;
const int screenHeight = 600;
GLdouble A;
GLdouble B;
GLdouble C;
GLdouble D;


void gs_init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	A = screenWidth / 4.0;
	B = 0.0;
	D = screenHeight / 2.0;
	C = D;
};

GLdouble j = 0.0;
bool reverse=true;

void gs_change(){
	if(j<300&&reverse){
		j+=0.005;
	}else{
		reverse = false;
	}
	if(!reverse&&j>0){
		j-=0.005;	
	}else{
			reverse=true;
	}
};

void gs_render(){
	glClear(GL_COLOR_BUFFER_BIT);
	gs_change();
	glBegin(GL_POINTS);
		for(GLdouble x = 0; x<4.0; x+=0.005){
			GLdouble func = exp(-fabs(x))*cos(50*3.14159265*x);
			glVertex2d(A*x*sin(x) + j, C*func*cos(x*x)+D);
		}
	glEnd();
	glFlush();
};

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Graphics Engine");
	glutIdleFunc(gs_render);
	glutDisplayFunc(gs_render);
	gs_init();
	glutMainLoop();
};