

#include "Personaje.h"


Personaje::Personaje(){
  txt_personaje = new Texture;

  txt_personaje->loadFromFile("Sprites/frames.png");
  spr_personaje = new Sprite(*txt_personaje);
  spr_personaje->setPosition(100,250);
  velocidad.x=0;
  velocidad.y=0;

  aceleracion.x=0;
  aceleracion.y=9.8;
  vida=100;
  division_sprites.x=4;
  division_sprites.y=2;
  frame_actual.x=0;
  frame_actual.y=0;
  set_frame(*spr_personaje,{0,0});
}
void Personaje::freno(){
  aceleracion.y=0;
  velocidad.y=0;
  //cout<<aceleracion.y<<endl;
}
void Personaje::set_frame(Sprite &spr_p,Vector2i numero_frame){
  IntRect posicion(numero_frame.x*spr_personaje->getTexture()->getSize().x/division_sprites.x,numero_frame.y*spr_personaje->getTexture()->getSize().y/division_sprites.y,spr_personaje->getTexture()->getSize().x/division_sprites.x,spr_personaje->getTexture()->getSize().y/division_sprites.y);
  spr_personaje->setTextureRect(posicion);
}
void Personaje::frame_loop(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  else
    frame_actual.x =0;
}
void Personaje::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  spr_personaje->setPosition(spr_personaje->getPosition().x+velocidad.x*tiemp,spr_personaje->getPosition().y+velocidad.y*tiemp);
}

void Personaje::izquierda(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  set_frame(*spr_personaje,frame_actual);
  spr_personaje->setPosition(spr_personaje->getPosition().x-5,spr_personaje->getPosition().y);
}
void Personaje::derecha(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  set_frame(*spr_personaje,frame_actual);
  spr_personaje->setPosition(spr_personaje->getPosition().x+5,spr_personaje->getPosition().y);
}
void Personaje::arriba(){
  //velocidad.x+=30;
  spr_personaje->setPosition(spr_personaje->getPosition().x,spr_personaje->getPosition().y-5);
}
void Personaje::abajo(){
  //velocidad.y+=30;
  spr_personaje->setPosition(spr_personaje->getPosition().x,spr_personaje->getPosition().y+5);
}
float Personaje::getpositionX(){
  return spr_personaje->getPosition().x;
}
float Personaje::getpositionY(){
  return spr_personaje->getPosition().y;
}

void Personaje::restavida(){
  vida-=10;
  cout<<vida<<endl;
}
