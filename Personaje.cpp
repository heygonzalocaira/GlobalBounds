

#include "Personaje.h"


Personaje::Personaje(int a,int b,int x,int y){
  txt_personaje = new Texture;

  txt_personaje->loadFromFile("Sprites/frames.png");
  spr_personaje = new Sprite(*txt_personaje);
  spr_personaje->setPosition(a,b);
  velocidad.x=0;
  velocidad.y=0;
  cajavida = new RectangleShape({128,16});
  cajavida->setFillColor(Color::Green);
  cajavida->setPosition(x,y);
  aceleracion.x=0;
  aceleracion.y=9.8;
  vida=100;
  division_sprites.x=4;
  division_sprites.y=2;
  frame_actual.x=0;
  frame_actual.y=0;
  voltear =1;
  set_frame(*spr_personaje,{0,0});
}
void Personaje::freno(){
  aceleracion.y=0;
  velocidad.y=0;
  //cout<<aceleracion.y<<endl;
}
void Personaje::set_frame(Sprite &spr_p,Vector2i numero_frame){
  IntRect posicion(numero_frame.x*spr_personaje->getTexture()->getSize().x/division_sprites.x,numero_frame.y*spr_personaje->getTexture()->getSize().y/division_sprites.y,spr_personaje->getTexture()->getSize().x/division_sprites.x*voltear,spr_personaje->getTexture()->getSize().y/division_sprites.y);
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
  velocidad.x=aceleracion.x *tiemp;
  velocidad.y=aceleracion.y;
  spr_personaje->setPosition(spr_personaje->getPosition().x+velocidad.x*tiemp,spr_personaje->getPosition().y+velocidad.y*tiemp);
}

void Personaje::izquierda(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  voltear=-1;
  set_frame(*spr_personaje,frame_actual);
  spr_personaje->setPosition(spr_personaje->getPosition().x-5,spr_personaje->getPosition().y);
}
void Personaje::derecha(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  voltear=1;
  set_frame(*spr_personaje,frame_actual);
  spr_personaje->setPosition(spr_personaje->getPosition().x+5,spr_personaje->getPosition().y);
}
void Personaje::arriba(){
  velocidad.y=-10;
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
  colorvida();
}
void Personaje::colorvida(){
  if(vida<80 && vida >=50)
    cajavida->setFillColor(Color::Yellow);
  else if(vida<50 && vida >30)
    cajavida->setFillColor(Color::Red);
}
