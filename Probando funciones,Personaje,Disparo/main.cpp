#include <SFML/Graphics.hpp>
#include <iostream>
#include "juego.h"

using namespace sf;
using namespace std;

int main() {
	Juego *partida;
	partida = new Juego(900, 600, "hola :D");
	return 0;
}