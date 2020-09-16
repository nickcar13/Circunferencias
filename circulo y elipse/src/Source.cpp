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
int contadorPuntos = 0;
int centroX = 0, centroY = 0, r = 0, r1 = 0, r2 = 0;
bool grafico = false;

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
	contadorPuntos = 0;
	if (i == 1) {
		control = 1;
	}
	else if (i == 2) {
		control = 2;
	}
	else if (i == 3) {
		if (control == 1)
		{
			int datosC[3] = { centroX,centroY,r };
			c1.circulo(datosC, 238, 108, 77);
			c1.pintarPixel(colormain.RGBToFloat(0, 0, 0), centroX, centroY, 3);
			r != 0 ? grafico = true: grafico = false;
		}
		else if (control == 2)
		{
			int datosE[4] = { centroX, centroY, r1, r2 };
			c1.elipse(datosE, 238, 108, 77);
			grafico == true;
			r2 != 0 && r1 != 0 ? grafico = true : grafico = false;
		}
		if (!grafico) {
			grafico = false;
			glClear(GL_COLOR_BUFFER_BIT);
			ejes();
			glFlush();
			std::cout << "Faltan datos intente de nuevo";
		}
		centroX = 0;
		centroY = 0;
		r = 0;
		r1 = 0;
		r2 = 0;
	}
}

void mouse(int btn, int state, int mx, int my)
{
	mx = mx - ANCHO / 2;
	my = (-1) * (my - ALTO / 2);
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//indica la entrada del centro 
		if (control != 0 && contadorPuntos == 0)
		{
			std::cout << "El centro seleccionado es: " << mx << " , " << my << std::endl;
			contadorPuntos++;
			c1.pintarPixel(colormain.RGBToFloat(0, 0, 0), mx, my, 3);
			centroX = mx;
			centroY = my;
		}
		else if (control == 1 && contadorPuntos == 1)
		{
			contadorPuntos++;
			c1.pintarPixel(colormain.RGBToFloat(250, 250, 250), mx, my, 3);
			r = abs(c1.calcularRadio(centroX, centroY, mx, my));
			std::cout << "la distancia radial seleccionada es: " << r << std::endl;

		}
		else if (control == 2 && contadorPuntos < 3)
		{
			c1.pintarPixel(colormain.RGBToFloat(0, 0, 0), mx, my, 3);
			contadorPuntos == 1 ? r1 = abs(c1.calcularRadio(centroX, centroY, mx, my)) : r1 = r1;
			contadorPuntos == 2 ? r2 = abs(c1.calcularRadio(centroX, centroY, mx, my)) : r2 = r2;
			std::cout << "El radio seleccionado es: " << r1 << " , " << r2 << std::endl;
			contadorPuntos++;
		}
	}
}

int main(int arg, char* argv[]) {
	Ventana ventana1(arg, *argv);


	ventana1.bufferSimple("Hello", [] {}, ANCHO, ALTO);
	ventana1.configVentana(61, 90, 128);
	//funcion para vista plano carteciano con 4 secciones 
	glOrtho(-ANCHO / 2, ANCHO / 2, -ALTO / 2, ALTO / 2, -1, 1);
	//generar el menu (modificable a futuro)
	menu.generarMenu(opciones, GLUT_RIGHT_BUTTON);


	ejes();
	glutMouseFunc(mouse);

	ventana1.ciclo();
	return 0;
}