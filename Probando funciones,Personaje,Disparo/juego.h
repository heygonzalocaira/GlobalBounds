#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Juego {
public:
	Juego(int resolucion_x, int resolucion_y, std::string titulo);
	void dibujar();
	void gameLoop();
	void procesarEvento();
	void procesarMouse();
	void procesarColisiones();
	void disparo();

private:
	RenderWindow * ventana;
	int fps;
	Texture *textura;
	Texture textura2;
	Texture *textura3;
	Sprite *sprite;
	Sprite *sprite2;
	Sprite *sprite3;
	Event *evento;
	Vector2i posicion_mouse;
	RectangleShape *caja1;
	CircleShape *circulo;

	Clock reloj;
	Time tiempo;
	float tiempo2;

};