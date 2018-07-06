
#include "linker.h"
// Aun falta implementar esta clase
class Mira;


class Juego{
public:
  Juego(Vector2f resolucion,String titulo);
  void gameLoop();
  void dibujar();
  void dibujarMenu();
  void procesarEvento();
private:
  RenderWindow *ventana;

  Clock *reloj1;
  Time *tiempo1;
  float tiempo2;

  bool gameMenu=true;
  bool gameOver=false;
  float fps;
  int x0,y0;

  Event *evento;

  //Texture *txt_juegoP;
  //Sprite *spr_juegoP;
  Texture *txt_background;
  Sprite *spr_brackground;

  Personaje *jugador1;
  IzquierdaCommand *left;
  DerechaCommand *right;
  Manejador *interruptor;
  Proyectil *granada;
  Flecha *puntero;
  SoundTrack *musica;
  MenuJuego *menu;
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

  /*txt_juegoP = new Texture;
  txt_juegoP->loadFromFile("Sprites/heroe.png");
  spr_juegoP = new Sprite(*txt_juegoP);
  spr_juegoP->setPosition(600,320);*/

  reloj1 = new Clock();
  tiempo1 = new Time();

  jugador1=new Personaje();
  left= new IzquierdaCommand(*jugador1);
  right= new DerechaCommand(*jugador1);
  interruptor = new Manejador(left,right);
  granada=new Proyectil();
  puntero = new Flecha();
  musica= new SoundTrack();
  menu = new MenuJuego();
  tiempo2 = 0.f;
  evento = new Event;

  musica->suenaCancion();
  gameLoop();
}
void Juego::dibujarMenu(){
  ventana->draw(menu->getMenu());
}
void Juego::dibujar(){
  ventana->clear();
  dibujarMenu();
  if(gameMenu == false){
    ventana->clear();
    jugador1->frame_loop();
    jugador1->actualizar(tiempo2);
    granada->actualizar(tiempo2);
    puntero->actualizarF(tiempo2);
    ventana->draw(*spr_brackground);
    ventana->draw(jugador1->get_sprite());
    ventana->draw(granada->get_sprite1());
    ventana->draw(puntero->get_sprite2());
    ventana->display();
  }
  //ventana->draw(*spr_juegoP);
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

  x0=jugador1->getpositionX();
  y0=jugador1->getpositionY();
  while(ventana->pollEvent(*evento)){
    switch (evento->type) {
     case Event::Closed:
        ventana->close();
        exit(1);
        break;
     case Event::KeyPressed:
     if(Keyboard::isKeyPressed(Keyboard::Z))gameMenu=false;
      if(Keyboard::isKeyPressed(Keyboard::Up)){
        int h=4;
        if(h>=y0) break;
        else jugador1->arriba();
      }
      else if(Keyboard::isKeyPressed(Keyboard::Down)){
        int h1=500;
        if(h1<=y0)break;
        else jugador1->abajo();
    }
      else if(Keyboard::isKeyPressed(Keyboard::Left)){
        int h1=5;
        if(h1>=x0)break;
        else
        //spr_juegoP->setPosition(spr_juegoP->getPosition().x-5,spr_juegoP->getPosition().y);
        //jugador1->izquierda();
        interruptor->accion1();

      }
      else if(Keyboard::isKeyPressed(Keyboard::Right)){
        int h2=760;
        if(h2<=x0)break;
        else
        //spr_juegoP->setPosition(spr_juegoP->getPosition().x+5,spr_juegoP->getPosition().y);
        //jugador1->derecha();
        interruptor->accion2();
    }

    if(Keyboard::isKeyPressed(Keyboard::X))musica->suenaSonido();
    if(Keyboard::isKeyPressed(Keyboard::C))gameOver=true;
    }
  }
}



int main(int argc, char const *argv[]) {
  Juego partida({800,600},"Disparos");
  return 0;
}
