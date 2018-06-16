#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(800, 600), "Sountrack");

	//va a tener el archivo del sonido
	SoundBuffer buffer;
	Sound sonido;
	//cargando buffer
	if (buffer.loadFromFile("soundtrack.wav")) {
		cout << "no se pudo cargar efecto" << endl;
	}
	//ya tenemos la variable sonudo para reproduvir y trabajar con ella
	sonido.setBuffer(buffer);

	Music Cancion;
	if (!Cancion.openFromFile("soundtrack anime.ogg")) {
		cout << "No se pudo cargar la musica" << endl;
	}
	Cancion.setVolume(80);
	Cancion.setPitch(1.2);
	Cancion.setLoop(true);

	while (window.isOpen()) {
		Event evento;
		while (window.pollEvent(evento)) {
			//cerrar ventana
			if (evento.type == Event::Closed) {
				window.close();
			}
			//si presiona un boton del mouse
			if (evento.type == Event::MouseButtonPressed) {
				//si el boton del mouse es el izquierdo
				if (evento.mouseButton.button == Mouse::Button::Left) {
					sonido.setVolume(60);
					sonido.setPitch(1.2);
					cout << "SOnido se reproduce" << endl;
					sonido.play();
				}
				if (evento.mouseButton.button == Mouse::Button::Right) {
					cout << "cancion" << endl;
					Cancion.play();
				}
			}
		}
		window.clear();
		window.display();
	}
	
	return 0;
}