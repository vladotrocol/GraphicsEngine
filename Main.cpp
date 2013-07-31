#include <windows.h>
#include <GLTools.h>
#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif
#include <vector>
#include <time.h> 
using namespace std;
const float pi = 3.14159265348979;

typedef struct Pointe{
	GLfloat x;
	GLfloat y;
}Point;

vector<Point> Points;
Point p;
int size = 30;
float r;
float g;
float b;

void gs_init(){
	srand (time(NULL));
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);

	for(int i = 1; i <= size; i++){
		p.x = 280*cos(pi/size*2*i) + 300;
		p.y = 280*sin(pi/size*2*i) + 300;
		Points.push_back(p);
	}
};

float random(){
	return (float)rand()/(float)RAND_MAX;
};

void gs_render(){
	glClear(GL_COLOR_BUFFER_BIT);
	for(unsigned int i= 0; i<Points.size();i++){
		r = random();
		g = random();
		b = random();
		glColor3f(r,g,b);
		for(unsigned int j= 0; j<Points.size();j++){
			if(i!=j){
				glBegin(GL_LINES);
				glVertex2f(Points[i].x, Points[i].y);
				glVertex2f(Points[j].x, Points[j].y);
				glEnd();
			}
		}
	}
	glBegin(GL_POINTS);
		glVertex2f(300.0f, 300.0f);
	glEnd();
	glutSwapBuffers();
};

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Graphics Engine");
	glutIdleFunc(gs_render);
	glutDisplayFunc(gs_render);	
	gs_init();
	glutMainLoop();
};