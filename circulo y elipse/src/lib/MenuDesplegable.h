#pragma once
class MenuDesplegable
{
public:
	void generarMenu(void (*funcion)(int a), int button);
private:
	int datos[4];
};

