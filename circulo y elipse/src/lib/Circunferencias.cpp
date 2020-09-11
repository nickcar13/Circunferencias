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
	glPointSize(3);
	glColor3fv(colorCir.RGBToFloat(238, 108, 77));
	glBegin(GL_POINTS);
	while (x0 <= y0) {
		y0 = sqrt(pow(r, 2) - pow(x0, 2));
		octales(x0, y0, a, b);
		x0++;
	}
	glEnd();
	glFlush();
}

void Circunferencias::elipse(int a, int b, int r1, int r2)
{
	float x0 = 1, y0 = 0;
	glPointSize(3);
	glColor3fv(colorCir.RGBToFloat(238, 108, 77));
	glBegin(GL_POINTS);
	while (x0 <= r1)
	{
		y0 = sqrt((1 - pow(x0, 2) / pow(r1, 2)) * pow(r2, 2));
		cuadrantes(x0, y0, a, b);
		x0+=.01;
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

void Circunferencias::cuadrantes(float x, float y, int a, int b)
{
	int xP = x + a; //xPositiva
	int xN = -x + a; //xNegativa
	int yP = y + b; //xNegativa
	int yN = -y + b; //xNegativa
	glVertex2d(xP, yP);
	glVertex2d(xN, yP);
	glVertex2d(xP, yN);
	glVertex2d(xN, yN);
}
