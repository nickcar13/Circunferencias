#include <iostream>
#include <GL/glut.h>

#include "lib/Ventana.h"
#include "lib/Colores.h"
#include "lib/Circunferencias.h"

int ANCHO = 1000, ALTO = 600;
Colores colormain;

void display() {}

void ejes() {

	//funcion para vista plano carteciano con 4 secciones 
	glOrtho(-ANCHO / 2, ANCHO / 2, -ALTO / 2, ALTO / 2, -1, 1);

	glBegin(GL_LINES);
	glColor3fv(colormain.RGBToFloat(41, 50, 65));
	glVertex2d(-ANCHO, 0);
	glVertex2d(ANCHO, 0);
	glVertex2d(0, ALTO);
	glVertex2d(0, -ALTO);
	glEnd();
	glFlush();
}

int main(int arg, char* argv[]) {
	Ventana ventana1(arg, *argv);
	Circunferencias c1;

	ventana1.bufferSimple("Hello", display, ANCHO, ALTO);
	ventana1.configVentana(61, 90, 128);

	ejes();
	//c1.circulo(0, 0, 200); // a , b, r
	c1.elipse(0, 200, 300, 100); //a , b , r1, r2


	ventana1.ciclo();
	return 0;
}