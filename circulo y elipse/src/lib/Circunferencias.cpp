#include "Circunferencias.h"
#include "Colores.h"
#include <math.h>
#include <iostream>
#include <GL/glut.h>
Colores colorCir;

Circunferencias::Circunferencias()
{
}

void Circunferencias::circulo(int a, int b, int r)
{
	float x0 = 0, y0 = 0;
	glBegin(GL_POINTS);
	glColor3fv(colorCir.RGBToFloat(238, 108, 77));
	glPointSize(10);
	while (x0 <= y0) {
		y0 = sqrt(pow(r, 2) - pow(x0, 2));
		octales(x0, y0, a, b);
		x0++;
	}
	glEnd();
	glFlush();
}

void Circunferencias::octales(float x, float y, int a, int b)
{
	int xP = x + a; //xPositiva
	int xN = -x + a; //xNegativa
	int yP = y + b; //xNegativa
	int yN = -y + b; //xNegativa
	glVertex2d(xP, yP);
	glVertex2d(xN, yP);
	glVertex2d(xP, yN);
	glVertex2d(xN, yN);
	xP = x + b; //xPositiva
	xN = -x + b; //xNegativa
	yP = y + a; //xNegativa
	yN = -y + a; //xNegativa
	glVertex2d(yP, xP);
	glVertex2d(yN, xP);
	glVertex2d(yP, xN);
	glVertex2d(yN, xN);
}
