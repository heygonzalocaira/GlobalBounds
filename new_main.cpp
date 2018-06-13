#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personaje.h"
#include "Proyectil.h"
using namespace sf;
using namespace std;

// Aun falta implementar esta clase
class Mira;


class Juego{
public:
  Juego(Vector2f resolucion,String titulo);
  void gameLoop();
  void dibujar();
  void procesarEvento();
private:
  RenderWindow *ventana;

  Clock *reloj1;
  Time *tiempo1;
  float tiempo2;

  bool gameOver=false;
  float fps;

  Event *evento;

  Texture *txt_background;
  Sprite *spr_brackground;
  Personaje *jugador1;
  Proyectil *granada;
};

Juego::Juego(Vector2f resolucion,String titulo){
  ventana = new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
  ventana->setFramerateLimit(60);

  fps = 1/60.f;

  //la textura carga el recurso que seria la imagen
  txt_background = new Texture;
  txt_background->loadFromFile("background.png");
  //el sprite puede ser modificado, se le puede dar angulo, posicion, rotacion, etc.
  spr_brackground = new Sprite(*txt_background);
  spr_brackground->setPosition(0,0);

  reloj1 = new Clock();
  tiempo1 = new Time();

  jugador1=new Personaje();
  granada=new Proyectil();

  tiempo2 = 0.f;
  evento = new Event;


  gameLoop();
}
void Juego::dibujar(){
  ventana->clear();
  granada->actualizar(tiempo2);
  ventana->draw(*spr_brackground);
  ventana->draw(jugador1->get_sprite());
  ventana->draw(granada->get_sprite1());
  ventana->display();
}
void Juego::gameLoop(){
  while(!gameOver){
    *tiempo1 = reloj1->getElapsedTime();
    if(tiempo1->asSeconds()>tiempo2+fps){
      tiempo2 = tiempo1->asSeconds();
      dibujar();
    }
   procesarEvento();
  }
}

void Juego::procesarEvento(){

  while(ventana->pollEvent(*evento)){
    switch (evento->type) {
     case Event::Closed:
        ventana->close();
        exit(1);
        //break;
        break;
     case Event::KeyPressed:
      if(Keyboard::isKeyPressed(Keyboard::Up)){
        //(jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x,(jugador1->get_sprite()).getPosition().y-5);
        (jugador1->get_sprite())->setPosition((jugador1->get_sprite())->getPosition().x,(jugador1->get_sprite())->getPosition().y-5);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Down)){
        //(jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x,(jugador1->get_sprite()).getPosition().y+5);
        (jugador1->get_sprite())->setPosition((jugador1->get_sprite())->getPosition().x,(jugador1->get_sprite())->getPosition().y+5);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Left)){
        //(jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x-5,(jugador1->get_sprite()).getPosition().y);
        (jugador1->get_sprite())->setPosition((jugador1->get_sprite())->getPosition().x-5,(jugador1->get_sprite())->getPosition().y);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Right)){
        //(jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x+5,(jugador1->get_sprite()).getPosition().y);
        (jugador1->get_sprite())->setPosition((jugador1->get_sprite())->getPosition().x+5,(jugador1->get_sprite())->getPosition().y);
      }
    break;
    }
  }
}



int main(int argc, char const *argv[]) {
  Juego partida({800,600},"Disparos");
  return 0;
}
