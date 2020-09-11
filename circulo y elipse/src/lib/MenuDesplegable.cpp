#include "MenuDesplegable.h"

int* MenuDesplegable::entradaDatos(figuras name)
{
	if (name == figuras::circulo) {
		datos[0] = 0;
		datos[1] = 0;
		datos[2] = 80;
	}
	else if (name == figuras::elipse) {
		datos[0] = 0;
		datos[1] = 0;
		datos[2] = 100;
		datos[3] = 20;
	}

	return (datos);
}
