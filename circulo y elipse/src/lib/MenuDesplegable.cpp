#include "MenuDesplegable.h"
#include <GL/glut.h>

void MenuDesplegable::generarMenu(void (*funcion)(int a), int button)
{
	glutCreateMenu(funcion);
	glutAddMenuEntry("circulo", 1);
	glutAddMenuEntry("Elipse", 2);
	glutAddMenuEntry("Graficar", 3);
	glutAttachMenu(button);
}
