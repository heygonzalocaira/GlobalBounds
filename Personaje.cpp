

#include "Personaje.h"


Personaje::Personaje(){
  txt_personaje = new Texture;
  txt_personaje->loadFromFile("elcarlo.png");
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
void Personaje::izquierda(){
  spr_personaje->setPosition(spr_personaje->getPosition().x-5,spr_personaje->getPosition().y);
}
void Personaje::derecha(){
  spr_personaje->setPosition(spr_personaje->getPosition().x+5,spr_personaje->getPosition().y);
}
void Personaje::arriba(){
  spr_personaje->setPosition(spr_personaje->getPosition().x,spr_personaje->getPosition().y-5);
}
void Personaje::abajo(){
  spr_personaje->setPosition(spr_personaje->getPosition().x,spr_personaje->getPosition().y+5);
}
