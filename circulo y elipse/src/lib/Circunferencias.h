#pragma once
class Circunferencias
{
public:
	Circunferencias();
	void pintarPixel(float* color, int x, int y, int pixelSize);
	void circulo(int* datos, float red, float green, float blue);
	void elipse(int* datos, float red, float green, float blue);
	void octales(float x, float y, int a, int b);
	void cuadrantes(float x, float y, int a, int b);
	int calcularRadio(int centroX, int centroY, int rX, int rY);

	void set_a(int a);
	void set_b(int b);
	void set_r(int r);
	void set_r1(int r1);
	void set_r2(int r2);
private:
	int a = 0, b = 0, r = 0, r1 = 0, r2 = 0;
};

