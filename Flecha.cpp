#include "Flecha.h"

Flecha::Flecha(){
  txt_flecha = new Texture;

  txt_flecha->loadFromFile("Sprites/flecha.png");

  spr_flecha = new Sprite(*txt_flecha);
  //spr_personaje->getPosition().x+32;
  spr_flecha->setPosition(150,50);
  spr_flecha->setOrigin(spr_flecha->getTexture()->getSize().x/2.f,spr_flecha->getTexture()->getSize().y/2.f);
  angulo=0;
}
void Flecha::rotarNegativo(){
  spr_flecha->rotate(-10);
}
void Flecha::rotarPositivo(){
  spr_flecha->rotate(10);
}
