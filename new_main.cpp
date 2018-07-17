
#include "linker.h"

class Juego{
public:
  Juego(Vector2f resolucion,String titulo);
  void gameLoop();
  void dibujar();
  void dibujarMenu();
  void bombas();
  void procesarEvento();
  void procesarColision();
  float gradosaradianes(float grados){return grados*3.14 /180;}
  float radianesagrados(float radianes){return radianes *180 /3.14;}
private:
  RenderWindow *ventana;

  Clock *reloj1;
  Time *tiempo1;
  float tiempo2;

  bool gameMenu=true;
  bool gameOver=false;
  float fps;
  int x0,y0;
  int turno;

  Event *evento;

  //Texture *txt_juegoP;
  //Sprite *spr_juegoP;
  Texture *txt_background;
  Sprite *spr_brackground;

  Boos *zapdos;
  Ground *piso;
  Personaje *jugador1;
  Personaje *jugador2;
  IzquierdaCommand *left;
  DerechaCommand *right;
  Manejador *interruptor;
  Proyectil *granada;
  Proyectil *tnt;
  Flecha *puntero;
  Contador *contador;
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



  reloj1 = new Clock();
  tiempo1 = new Time();

  piso = new Ground();
  jugador1=new Personaje(100,150,50,50);
  jugador2=new Personaje(600,150,600,50);

  left= new IzquierdaCommand(*jugador1);
  right= new DerechaCommand(*jugador1);
  interruptor = new Manejador(left,right);
  zapdos = new Boos();
  //granada=new Proyectil({jugador1->get_sprite().getPosition()},{60,-40});
  granada=new Proyectil({700,350},{-60,-40});
  tnt=new Proyectil({150,350},{60,-40});
  puntero = new Flecha({jugador1->getSprite().getPosition()});
  musica= new SoundTrack();
  menu = new MenuJuego();
  contador = new Contador();
  tiempo2 = 0.f;
  evento = new Event;
  turno=0;
  musica->suenaCancion();
  gameLoop();
}
void Juego::bombas(){
    zapdos->colocar();
    ventana->draw(zapdos->getShape());
}
void Juego::dibujarMenu(){
  ventana->draw(menu->getSprite());
}
void Juego::dibujar(){
  ventana->clear();
  dibujarMenu();
  if(gameMenu == false){
    ventana->clear();
    jugador1->frame_loop();
    jugador1->actualizar(tiempo2);
    jugador2->actualizar(tiempo2);
    ventana->draw(*spr_brackground);
    ventana->draw(piso->getSprite());
    ventana->draw(jugador1->getSprite());
    ventana->draw(jugador2->getSprite());
    ventana->draw(jugador1->getShape());
    ventana->draw(jugador2->getShape());

    if(granada!=NULL && tnt!=NULL){
      ventana->draw(granada->get_sprite1());
      ventana->draw(tnt->get_sprite2());
      granada->actualizar(tiempo2);
      tnt->actualizar2(tiempo2);
    }
    ventana->draw(puntero->getSprite());
    ventana->draw(zapdos->getSprite());
    ventana->draw(contador->getSprite());

    //bombas();
    contador->frame_loop();
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

      //Vector2f pos = puntero->getPosition().x + movec
      //puntero->setPosition(pos);
      dibujar();
    }
    procesarColision();
    procesarEvento();
  }
}
void Juego::procesarColision(){
  if(jugador1->getSprite().getGlobalBounds().intersects(piso->getSprite().getGlobalBounds())){
    jugador1->freno();
  }else{
    jugador1->aceleracion.y=7;
  }
  if(jugador1->getSprite().getGlobalBounds().intersects(granada->get_sprite1().getGlobalBounds())){
    jugador1->restavida();
  }
  if(jugador2->getSprite().getGlobalBounds().intersects(piso->getSprite().getGlobalBounds())){
    jugador2->freno();
  }else{
    jugador2->aceleracion.y=9.8;
  }
  if(jugador1->getSprite().getGlobalBounds().intersects(granada->get_sprite1().getGlobalBounds())){
    jugador2->restavida();
  }
}
void Juego::procesarEvento(){

  x0=jugador1->getpositionX();
  y0=jugador1->getpositionY();
  int h=4;int h1=500;int h2=5;int h3=760;
  while(ventana->pollEvent(*evento)){
    switch (evento->type) {
     case Event::Closed:
        ventana->close();
        exit(1);
        break;
     case Event::KeyPressed:
     if(Keyboard::isKeyPressed(Keyboard::Z))gameMenu=false;
      if(Keyboard::isKeyPressed(Keyboard::Up)){
        if(h>=y0) break;
        else {
          if(turno==0)jugador1->arriba();
          if(turno==1)jugador2->arriba();
        }
      }
    /*else if(Keyboard::isKeyPressed(Keyboard::Down)){

        if(h1<=y0)break;
        else {
          if(turno==0)jugador1->abajo();
          if(turno==1)jugador2->abajo();
        }//jugador1->abajo();
    }*/
      else if(Keyboard::isKeyPressed(Keyboard::Left)){
        if(h2>=x0)break;
        else{
          if(turno==0)interruptor->accion1();
          if(turno==1)jugador2->izquierda();
        }
        //interruptor->accion1();

      }
      else if(Keyboard::isKeyPressed(Keyboard::Right)){

        if(h3<=x0)break;
        else{
          if(turno==0)interruptor->accion2();
          if(turno==1)jugador2->derecha();
        }
    }
    if(Keyboard::isKeyPressed(Keyboard::Space)){
      float potencia_disparo=70;
      float angulo_mira = puntero->angulo();
      //cout<<angulo_mira<<endl;
      cout<<granada->velocidad.x<<" "<<granada->velocidad.y<<endl;
      musica->suenaSonido();
      if(turno==1){
        granada=new Proyectil({jugador2->getpositionX(),jugador2->getpositionY()},{potencia_disparo * cos(gradosaradianes(angulo_mira)),potencia_disparo*sin(gradosaradianes(angulo_mira))});
        //granada->restaurar();
      }
      if(turno==0){
        tnt=new Proyectil({jugador1->getpositionX(),jugador1->getpositionY()},{potencia_disparo * cos(gradosaradianes(angulo_mira)),potencia_disparo*sin(gradosaradianes(angulo_mira))});
        //tnt->restaurar();
      }
    }
    if(Keyboard::isKeyPressed(Keyboard::Q))puntero->rotarNegativo();
    if(Keyboard::isKeyPressed(Keyboard::E))puntero->rotarPositivo();
    //if(Keyboard::isKeyPressed(Keyboard::X))musica->suenaSonido();
    if(Keyboard::isKeyPressed(Keyboard::C))gameOver=true;
    if(Keyboard::isKeyPressed(Keyboard::V))turno=1;
    if(Keyboard::isKeyPressed(Keyboard::B))turno=0;
    }
  }
}



int main(int argc, char const *argv[]) {
  Juego partida({800,500},"Disparos");
  return 0;
}
