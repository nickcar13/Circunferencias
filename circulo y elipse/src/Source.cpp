#include <iostream>
#include <GL/glut.h>

#include "lib/Ventana.h"
#include "lib/Colores.h"

int ANCHO = 1000, ALTO = 600;

void display() {}

void ejes() {
	glBegin(GL_LINES);
	glVertex2d(-ANCHO,0);
	glVertex2d(ANCHO,0);
	glEnd();
	glFlush();
}

int main(int arg, char* argv[]) {
	Colores colormain;
	Ventana ventana1(arg, *argv);

	ventana1.bufferSimple("Hello",display,ANCHO,ALTO);
	ventana1.configVentana(246, 189, 96);

	//funcion para vista plano carteciano con 4 secciones 
	glOrtho(-ANCHO / 2, ANCHO / 2, -ALTO / 2, ALTO / 2, -1 , 1);
	ejes();

	ventana1.ciclo();
	return 0;
}