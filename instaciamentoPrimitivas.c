#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14

void desenhaCubo(int tamanho){
	double i;
	
	glPushMatrix();//frente do cubo
	glColor3d(1, 0, 0);
	glBegin(GL_LINES);
		for(i=0; i<=tamanho; i+=0.01){
			glVertex3d(0, i, 0);
			glVertex3d(tamanho, i , 0);
		}	
	glEnd();
	glPopMatrix();

	glPushMatrix();//lateral direita do cubo
	//glRotated(90, 0, 1, 0);
	glColor3d(0, 0, 1);
	glBegin(GL_LINES);
		for(i=0; i<=tamanho; i+=0.01){
			glVertex3d(tamanho, 0, i);
			glVertex3d(tamanho, tamanho, i);
		}	
	glEnd();
	glPopMatrix();

	glPushMatrix();//trás do curso
	glTranslated(0, 0, tamanho);
	glColor3d(0, 1, 0);
	glBegin(GL_LINES);
		for(i=0; i<=tamanho; i+=0.01){
			glVertex3d(0, i, 0);
			glVertex3d(tamanho, i , 0);
		}	
	glEnd();
	glPopMatrix();

	glPushMatrix();//lateral esquerda do cubo
	//glRotated(90, 0, 1, 0);
	glTranslated(-tamanho, 0, 0);
	glColor3d(1, 1, 0);
	glBegin(GL_LINES);
		for(i=0; i<=tamanho; i+=0.01){
			glVertex3d(tamanho, 0, i);
			glVertex3d(tamanho, tamanho, i);
		}	
	glEnd();
	glPopMatrix();

	glPushMatrix();//parte de baixo do cubo
	//glRotated(90, 1, 0, 0);
	//glTranslated(-tamanho, 0, 0);
	glColor3d(1, 0, 1);
	glBegin(GL_LINES);
		for(i=0; i<=tamanho; i+=0.01){
			glVertex3d(0, 0, i);
			glVertex3d(tamanho, 0, i);
		}	
	glEnd();
	glPopMatrix();

	glPushMatrix();//parte de cima do cubo
	glTranslated(0, tamanho, 0);
	//glRotated(90, 1, 0, 0);
	glColor3d(0, 1, 1);
	glBegin(GL_LINES);
		for(i=0; i<=tamanho; i+=0.01){
			glVertex3d(0, 0, i);
			glVertex3d(tamanho, 0, i);
		}	
	glEnd();
	glPopMatrix();
}

void desenhaCircunferencia(int raio){
	double i, j;
	glBegin(GL_LINES);
	for(i=0; i<=180; i++){
		glRotated(i, 1, 0, 0);
		for(j=0; j<=2*PI; j+=0.001){
			glVertex3d(0, 0, 0);
			glVertex3d(raio*cos(j), raio*sin(j), 0);
		}		
	}

	glEnd();
}

void display(){

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);	


	//glRotated(40, 1, 0, 0);
	//glRotated(40, 0, 1, 0);	

	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-50.0, 50.0, -50.0, 50.0, 0.1, 50);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -20);

	//glColor3d(1, 0, 0);
	//desenhaCircunferencia(8);

	//glTranslated(10, 0, 0);
	desenhaCubo(10);

	glFlush();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Instancia");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}