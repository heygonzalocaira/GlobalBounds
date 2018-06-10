#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Juego;

class Personaje{
public:
  Personaje();
  void actualizar(float tiemp);
  Sprite get_sprite(){return *spr_personaje;};
private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};

Personaje::Personaje(){
  txt_personaje = new Texture;
  txt_personaje->loadFromFile("heroe.png");
  spr_personaje = new Sprite(*txt_personaje);
  spr_personaje->setPosition(100,320);
  velocidad.x=0;
  velocidad.y=0;

  aceleracion.x=0;
  aceleracion.y=0;
}
void Personaje::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  spr_personaje->setPosition(spr_personaje->getPosition().x+velocidad.x*tiemp,spr_personaje->getPosition().y+velocidad.y*tiemp);
}


class Proyectil{
public:
  Proyectil();
  void actualizar(float tiemp);
  Sprite get_sprite1(){return *spr_proyectil;};
private:
  Sprite *spr_proyectil;
  Texture *txt_proyectil;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};
Proyectil::Proyectil(){
  txt_proyectil = new Texture;
  txt_proyectil->loadFromFile("granada.png");
  spr_proyectil = new Sprite(*txt_proyectil);
  spr_proyectil->setPosition(120,320);

  velocidad.x=50;
  velocidad.y=-50;

  aceleracion.x=0;
  aceleracion.y=9.8;
  if(spr_proyectil->getPosition().x> 500 && spr_proyectil-> getPosition().y >400){
    spr_proyectil->setPosition(120,320);
  }
}
void Proyectil::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  spr_proyectil->setPosition(spr_proyectil->getPosition().x+velocidad.x*tiemp,spr_proyectil->getPosition().y+velocidad.y*tiemp);
  // borrar este IF para que solo se dibuje una vez

  if(spr_proyectil->getPosition().x> 500 && spr_proyectil-> getPosition().y >400 ){

    velocidad.x=50;
    velocidad.y=-50;
    aceleracion.x=0;
    aceleracion.y=9.8;
    spr_proyectil->setPosition(120,320);
  }

}
/*lass Mira:public Juego{

};*/

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

  txt_background = new Texture;
  txt_background->loadFromFile("background.png");
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
      case Event::KeyPressed:
      if(Keyboard::isKeyPressed(Keyboard::Up)){
        (jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x,(jugador1->get_sprite()).getPosition().y-5);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Down)){
        (jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x,(jugador1->get_sprite()).getPosition().y+5);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Left)){
        (jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x-5,(jugador1->get_sprite()).getPosition().y);
      }
      else if(Keyboard::isKeyPressed(Keyboard::Right)){
        (jugador1->get_sprite()).setPosition((jugador1->get_sprite()).getPosition().x+5,(jugador1->get_sprite()).getPosition().y);
      }
    }
  }
}



int main(int argc, char const *argv[]) {
  Juego partida({800,600},"Disparos");
  return 0;
}
