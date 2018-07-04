
#include "Proyectil.h"



Proyectil::Proyectil(){
  txt_proyectil = new Texture;

  txt_proyectil->loadFromFile("Sprites/granada.png");

  spr_proyectil = new Sprite(*txt_proyectil);
  spr_proyectil->setPosition(120,320);

  velocidad.x=50;
  velocidad.y=-50;

  aceleracion.x=0;
  aceleracion.y=9.8;

}
void Proyectil::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  spr_proyectil->setPosition(spr_proyectil->getPosition().x+velocidad.x*tiemp,spr_proyectil->getPosition().y+velocidad.y*tiemp);
  // borrar este IF para que solo se dibuje una vez

  /*if(spr_proyectil->getPosition().x> 500 && spr_proyectil-> getPosition().y >400 ){

    velocidad.x=50;
    velocidad.y=-50;
    aceleracion.x=0;
    aceleracion.y=9.8;
    spr_proyectil->setPosition(120,320);
  }
*/
}
