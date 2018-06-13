#include <SFML/Graphics.hpp>
#include <math.h>
#include "personaje.h"

using namespace sf;
using namespace std;

class Flecha{
public:
  Flecha();
  void actualizar(float);
  Sprite* get_sprite(){return spr_flecha;}
  int angulo;
private:
  Sprite *spr_flecha;
  Texture *txt_flecha;
  friend class Juego;
};
Flecha::Flecha(){
  txt_flecha = new Texture;
  txt_flecha->loadFromFile("flecha.png");
  spr_flecha = new Sprite(*txt_flecha);
  spr_flecha->setPosition(100,320);
  angulo=0;
}
void Personaje::actualizar(float tiemp){
  tiemp/=10;
  spr_flecha->setPosition(spr_personaje->getPosition().x /2.f, (spr_personaje->getPosition().y /2.f)+10);
  spr_flecha->setOrigin((float)(spr_flecha->gettexture()->getSize().x), (float)(spr_flecha->gettexture()->getSize().y));
  if(){//escribir la condicion del mouse
      //ang=;
      spr_flecha->setRotation(spr_flecha->getRotation+ang);
  }
}
