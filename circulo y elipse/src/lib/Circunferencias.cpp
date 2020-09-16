#include "Circunferencias.h"
#include "Colores.h"
#include <math.h>
#include <iostream>
#include <GL/glut.h>
Colores colorCir;

Circunferencias::Circunferencias()
{
}

void Circunferencias::pintarPixel(float* color, int x, int y, int pixelSize)
{
	glColor3fv(color);
	glPointSize(pixelSize);
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
	glFlush();
}

void Circunferencias::circulo(int* datos, float red, float green, float blue)
{
	set_a(*datos);
	set_b(*(datos + 1));
	set_r(*(datos + 2));

	float x0 = 0, y0 = 0;
	glPointSize(3);
	glColor3fv(colorCir.RGBToFloat(red, green, blue));
	glBegin(GL_POINTS);
	while (x0 <= y0) {
		y0 = sqrt(pow(r, 2) - pow(x0, 2));
		octales(x0, y0, a, b);
		x0++;
	}
	glEnd();
	glFlush();
}

void Circunferencias::elipse(int* datos, float red, float green, float blue)
{
	set_a(*datos);
	set_b(*(datos + 1));
	set_r1(*(datos + 2));
	set_r2(*(datos + 3));

	float x0 = 1, y0 = 0;
	glPointSize(3);
	glColor3fv(colorCir.RGBToFloat(red, green, blue));
	glBegin(GL_POINTS);
	while (x0 <= r1)
	{
		y0 = sqrt((1 - pow(x0, 2) / pow(r1, 2)) * pow(r2, 2));
		cuadrantes(x0, y0, a, b);
		x0 += .01;
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

int Circunferencias::calcularRadio(int centroX, int centroY, int rX, int rY)
{
	int dx = abs(centroX - rX);
	int dy = abs(centroY - rY);
	int radio = sqrt(pow(dx,2)+ pow(dy,2));
	return radio;
}

void Circunferencias::set_a(int a)
{
	this->a = a;
}

void Circunferencias::set_b(int b)
{
	this->b = b;
}

void Circunferencias::set_r(int r)
{
	this->r = r;
}

void Circunferencias::set_r1(int r1)
{
	this->r1 = r1;
}

void Circunferencias::set_r2(int r2)
{
	this->r2 = r2;
}


