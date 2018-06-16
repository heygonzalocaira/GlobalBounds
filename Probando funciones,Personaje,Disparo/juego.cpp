#include "juego.h"
#include <iostream>
using namespace std;

Juego::Juego(int resolucion_x, int resolucion_y, std::string titulo) {
	fps = 60;
	tiempo2 = 0;
	ventana = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);
	ventana->setFramerateLimit(fps);
	textura = new Texture;
	textura->loadFromFile("verde.png");
	textura2.loadFromFile("heroe.png");
	sprite = new Sprite(*textura);
	sprite2 = new Sprite(textura2);
	sprite3 = new Sprite(textura2);
	//sprite->setScale((float)ventana->getSize().x,(float) ventana->getSize().y);
	sprite2->setPosition(200, 200);
	sprite3->setColor(Color::Blue);
	sprite3->setPosition((float)ventana->getSize().x / 2,(float) ventana->getSize().y / 2);
	evento = new Event;

	caja1 = new RectangleShape({ 64,64 });
	caja1->setFillColor(Color::Green);
	caja1->setPosition(400, 100);

	textura3 = new Texture;
	textura3->loadFromFile("caja.png");
	caja1->setTexture(textura3);

	circulo = new CircleShape(16);
	circulo->setFillColor(Color::Black);
	circulo->setPosition(250,200);

	gameLoop();
}
void Juego::dibujar() {

	ventana->clear();
	ventana->draw(*sprite);
	ventana->draw(*sprite2);		
	//ventana->draw(*sprite3);
	//ventana->draw(*caja1);
	ventana->draw(*circulo);
	ventana->display();
}
void Juego::gameLoop() {
	while (ventana->isOpen()) {
		tiempo = reloj.getElapsedTime();
		if (tiempo.asSeconds() > 1 / fps) {
			tiempo2 += 0.5;
			if (tiempo2 > 5) {
				caja1->rotate(10);
				tiempo2 = 0;
			}
			else
			{
				cout << tiempo2 << endl;
			}
			procesarColisiones();
			procesarMouse();
			procesarEvento();
			dibujar();
		}
	}
}
void Juego::procesarEvento() {
	while (ventana->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana->close();
			exit(1);
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				sprite2->setPosition(sprite2->getPosition().x, sprite2->getPosition().y - 5);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down)) {
				sprite2->setPosition(sprite2->getPosition().x, sprite2->getPosition().y + 5);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				sprite2->setPosition(sprite2->getPosition().x - 5, sprite2->getPosition().y);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				sprite2->setPosition(sprite2->getPosition().x + 5, sprite2->getPosition().y);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					circulo->setPosition(circulo->getPosition().x + 5, circulo->getPosition().y);
					if (circulo->getPosition().x > 590)
						circulo->setPosition(250, 200);
			}
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				sprite2->setPosition(Vector2f(posicion_mouse));
			}
		}
	}
}

void Juego::procesarMouse() {
	posicion_mouse = Mouse::getPosition(*ventana);
	posicion_mouse = (Vector2i)ventana->mapPixelToCoords(posicion_mouse);
}

void Juego::procesarColisiones() {
	FloatRect posicion_del_mouse(Vector2f(posicion_mouse), { 32,32 });
	if (sprite2->getGlobalBounds().intersects(posicion_del_mouse)) {
		sprite2->setPosition(Vector2f(posicion_mouse));
	}

	//Colision personaje con el azul :V
	if (sprite2->getGlobalBounds().intersects(sprite3->getGlobalBounds())) {
		sprite3->rotate(3);
	}
}
