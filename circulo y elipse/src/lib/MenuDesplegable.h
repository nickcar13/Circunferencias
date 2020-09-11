#pragma once
class MenuDesplegable
{
public:
	enum figuras {
		circulo,
		elipse
	};
	int* entradaDatos(figuras name);
private:
	int datos[4];
};

