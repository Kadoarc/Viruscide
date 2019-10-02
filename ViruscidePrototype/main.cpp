#include <iostream>
#include <conio.h>

#include "Application.h"


int main(int argc, char**argv)
{
	/* Instantiate our application (game) */
	Application application("Viruscide", Globals::windowSize.x, Globals::windowSize.y);

	/* Run it */
	application();

	_getch();
	return 0;
}