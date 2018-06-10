#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;



class Juego{
public:
  Juego(Vector2f resolucion,String titulo);
  void gameLoop();
private:
  RenderWindow *ventana;

  Clock *reloj1;
  Time *tiempo1;
  float tiempo2;

  bool gameOver=false;
  float fps;
};
Juego::Juego(Vector2f resolucion,String titulo){
  ventana = new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
  ventana->setFramerateLimit(60);

  fps= 1/60.f;

  reloj1= new Clock();
  tiempo1= new Time();
  tiempo2= 0.f;

  gameLoop();
}
void Juego::gameLoop(){
  while(!gameOver){
    *tiempo1= reloj1->getElapsedTime();
    if(tiempo1->asSeconds()>tiempo2 +fps){
      tiempo2 = tiempo1->asSeconds();
      ventana->clear();
      ventana->display();
    }
  }
}
