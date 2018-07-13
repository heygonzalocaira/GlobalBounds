
#include "Proyectil.h"



Proyectil::Proyectil(Vector2f pos,Vector2f vel){
  txt_proyectil = new Texture;

  txt_proyectil->loadFromFile("Sprites/bomba.png");

  spr_proyectil = new Sprite(*txt_proyectil);
  spr_proyectil->setPosition(pos);
  spr_proyectil->setOrigin(spr_proyectil->getTexture()->getSize().x/2.f,spr_proyectil->getTexture()->getSize().y/2.f);

  velocidad=vel;

  aceleracion.x=0;
  aceleracion.y=9.8;

}
void Proyectil::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  spr_proyectil->setPosition(spr_proyectil->getPosition().x+velocidad.x*tiemp,spr_proyectil->getPosition().y+velocidad.y*tiemp);
  spr_proyectil->rotate(5);
  // borrar este IF para que solo se dibuje una vez

  /*if(spr_proyectil->getPosition().x> 500 && spr_proyectil-> getPosition().y >400 ){

    velocidad.x=50;
    velocidad.y=-50;
    aceleracion.x=0;
    aceleracion.y=9.8;
    spr_proyectil->setPosition(120,320);
  }*/

}
