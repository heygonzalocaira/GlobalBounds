#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Personaje.h"
#include "Proyectil.h"
#include "Flecha.h"

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

  Texture *txt_juegoP;
  Sprite *spr_juegoP;
  Texture *txt_background;
  Sprite *spr_brackground;

  SoundBuffer buffer;
  Sound sonido;
  Music Cancion;

  Personaje *jugador1;
  Proyectil *granada;
  Flecha *puntero;
};

Juego::Juego(Vector2f resolucion,String titulo){
  ventana = new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
  ventana->setFramerateLimit(60);

  fps = 1/60.f;

  //la textura carga el recurso que seria la imagen
  txt_background = new Texture;
  txt_background->loadFromFile("Sprites/background.png");
  //el sprite puede ser modificado, se le puede dar angulo, posicion, rotacion, etc.
  spr_brackground = new Sprite(*txt_background);
  spr_brackground->setPosition(0,0);

  txt_juegoP = new Texture;
  txt_juegoP->loadFromFile("Sprites/heroe.png");
  spr_juegoP = new Sprite(*txt_juegoP);
  spr_juegoP->setPosition(600,320);

  buffer.loadFromFile("SOUND/soundtrack.wav");
  sonido.setBuffer(buffer);
  Cancion.openFromFile("SOUND/soundtrack anime.ogg");
  Cancion.setVolume(80);
  Cancion.setPitch(1.2);
  Cancion.setLoop(true);

  reloj1 = new Clock();
  tiempo1 = new Time();

  jugador1=new Personaje();
  granada=new Proyectil();
  puntero = new Flecha();
  tiempo2 = 0.f;
  evento = new Event;


  gameLoop();
}
void Juego::dibujar(){
  ventana->clear();
  granada->actualizar(tiempo2);
  puntero->actualizarF(tiempo2);
  ventana->draw(*spr_brackground);
  ventana->draw(jugador1->get_sprite());
  ventana->draw(granada->get_sprite1());
  ventana->draw(puntero->get_sprite2());
  ventana->draw(*spr_juegoP);
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

  int x0=spr_juegoP->getPosition().x, y0=spr_juegoP->getPosition().y;
  while(ventana->pollEvent(*evento)){
    switch (evento->type) {
     case Event::Closed:
        ventana->close();
        exit(1);
        //break;
        break;
     case Event::KeyPressed:
      if(Keyboard::isKeyPressed(Keyboard::Up)){

        int h=4;
        if(h>=y0)
        {
          break;
        }
        else{
        spr_juegoP->setPosition(spr_juegoP->getPosition().x,spr_juegoP->getPosition().y-5);
      }
      }
      else if(Keyboard::isKeyPressed(Keyboard::Down)){
        int h1=580;
        if(h1<=y0)
        {
          break;
        }
        else{
        spr_juegoP->setPosition(spr_juegoP->getPosition().x,spr_juegoP->getPosition().y+5);

      }
    }
      else if(Keyboard::isKeyPressed(Keyboard::Left)){

        int h1=5;
        if(h1>=x0)
        {
          break;
        }
        else{
        spr_juegoP->setPosition(spr_juegoP->getPosition().x-5,spr_juegoP->getPosition().y);
      }
      }
      else if(Keyboard::isKeyPressed(Keyboard::Right)){
        int h2=760;
        if(h2<=x0)
        {
          break;
        }
        else{
        spr_juegoP->setPosition(spr_juegoP->getPosition().x+5,spr_juegoP->getPosition().y);
      }

    }
    if(Keyboard::isKeyPressed(Keyboard::A)){
      sonido.play();
    }
    if(Keyboard::isKeyPressed(Keyboard::D)){
      Cancion.play();
    }
    }
  }
}



int main(int argc, char const *argv[]) {
  Juego partida({800,600},"Disparos");
  return 0;
}
