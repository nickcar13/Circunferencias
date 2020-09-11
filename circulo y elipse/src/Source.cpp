#include <iostream>
#include <GL/glut.h>

#include "lib/Ventana.h"
#include "lib/Colores.h"
#include "lib/Circunferencias.h"
#include "lib/MenuDesplegable.h"

int ANCHO = 1000, ALTO = 600;
Colores colormain;
Circunferencias c1;
MenuDesplegable menu;

int control = 0;


void display() {}

void ejes() {
	glBegin(GL_LINES);
	glColor3fv(colormain.RGBToFloat(41, 50, 65));
	glVertex2d(-ANCHO, 0);
	glVertex2d(ANCHO, 0);
	glVertex2d(0, ALTO);
	glVertex2d(0, -ALTO);
	glEnd();
	glFlush();
}

void opciones(int i) {
	glClear(GL_COLOR_BUFFER_BIT);
	ejes();
	if (i == 1) {
		control = 1;
	}
	else if (i == 2) {
		control = 2;
	}
	else if (i == 3) {
		if (control == 1)
		{
			int* datosC = menu.entradaDatos(menu.circulo);
			c1.circulo(datosC, 238, 108, 77);
		}
		else if (control == 2)
		{
			int* datosE = menu.entradaDatos(menu.elipse);
			c1.elipse(datosE, 238, 108, 77);
		}
	}
}

void generarMenu() {
	glutCreateMenu(opciones);
	glutAddMenuEntry("circulo", 1);
	glutAddMenuEntry("Elipse", 2);
	glutAddMenuEntry("Graficar", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void mouse(int btn, int state, int mx, int my)
{
	mx = mx - ANCHO / 2;
	my = (-1) * (my - ALTO / 2);
}

int main(int arg, char* argv[]) {
	Ventana ventana1(arg, *argv);

	ventana1.bufferSimple("Hello", display, ANCHO, ALTO);
	ventana1.configVentana(61, 90, 128);
	//funcion para vista plano carteciano con 4 secciones 
	glOrtho(-ANCHO / 2, ANCHO / 2, -ALTO / 2, ALTO / 2, -1, 1);

	ejes();
	generarMenu();
	glutMouseFunc(mouse);

	ventana1.ciclo();
	return 0;
}