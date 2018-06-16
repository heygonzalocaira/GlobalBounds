#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Personaje{
public:
  Personaje();
  void actualizar(float tiemp);
  Sprite get_sprite(){return *spr_personaje;};
  Sprite get_sprite2(){return *spr_flecha;};
  Sprite get_sprite3(){return *spr_granada;};
private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Sprite *spr_flecha;
  Texture *txt_flecha;
  Sprite *spr_granada;
  Texture *txt_granada;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};
Personaje::Personaje(){
  txt_personaje=new Texture;
  txt_personaje->loadFromFile("okabe.png");
  spr_personaje = new Sprite(*txt_personaje);
  spr_personaje->setPosition(0,280);

  txt_flecha=new Texture;
  txt_flecha->loadFromFile("flecha.png");
  spr_flecha = new Sprite(*txt_flecha);
  spr_flecha->setPosition(150,400);

  txt_granada=new Texture;
  txt_granada->loadFromFile("granada.png");
  spr_granada=new Sprite(*txt_granada);
  spr_granada->setPosition(200,300);

  velocidad.x=50;
  velocidad.y=-50;

  aceleracion.x=0;
  aceleracion.y=9.8;
}
void Personaje::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x * tiemp;
  velocidad.y+=aceleracion.y * tiemp;

  //distancia = velocidad * tiempo;
  //spr_personaje->setPosition(spr_personaje->getPosition().x+velocidad.x*tiemp,spr_personaje->getPosition().y+velocidad.y*tiemp);
  spr_flecha->setPosition(spr_flecha->getPosition().x+velocidad.x*tiemp,spr_flecha->getPosition().y+velocidad.y*tiemp);
}

class Juego{
public:
  Juego(Vector2f resolucion,String titulo);
  void gameLoop();
  void procesarEvento();
  friend class Personaje;
private:
  RenderWindow *ventana;

  Clock *reloj1;
  Time *tiempo1;
  float tiempo2;

  bool gameOver=false;
  float fps;
  Event *evento;
  CircleShape *bala;
  RectangleShape *mira;
  Personaje *jugador1;
  Personaje *linea;
  Personaje *bola;
};
Juego::Juego(Vector2f resolucion,String titulo){
  ventana = new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
  ventana->setFramerateLimit(60);

  fps= 1/60.f;

  reloj1= new Clock();
  tiempo1= new Time();
  jugador1 = new Personaje();
  tiempo2= 0.f;
  evento = new Event;
  bala = new CircleShape(10);
  bala->setFillColor(Color::Red);
	bala->setPosition(100,250);
  mira = new RectangleShape({20,64});
  mira->setFillColor(Color::Green);
	mira->setPosition(300,400);
  linea = new Personaje();
  bola=new Personaje();
  gameLoop();
}
void Juego::gameLoop(){
  while(!gameOver){
    *tiempo1= reloj1->getElapsedTime();
    if(tiempo1->asSeconds()>tiempo2 +fps){
      tiempo2 = tiempo1->asSeconds();
      ventana->clear();
      linea->actualizar(tiempo2);
      ventana->draw(jugador1->get_sprite());
      //ventana->draw(*bala);
      //ventana->draw(*mira);
      ventana->draw(linea->get_sprite2());
      //ventana->draw(bola->get_sprite3());
      ventana->display();
      //procesarEvento();
    }
  }
}
/*void Juego::procesarEvento(){
  while (ventana->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana->close();
			exit(1);
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				linea->setPosition(linea->getPosition().x-5,linea->getPosition().y);
			}else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				linea->setPosition(linea->getPosition().x+5,linea->getPosition().y);
			}
		}
	}
}
*/

int main(int argc, char const *argv[]) {
  Juego partida({800,600},"Disparos");
  return 0;
}
