#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Flecha{
public:
  Flecha();
  void actualizarF(float tiemp);
  Sprite get_sprite2(){return *spr_flecha;}
  int angulo;
private:
  Sprite *spr_flecha;
  Texture *txt_flecha;
  friend class Juego;
};
Flecha::Flecha(){
  txt_flecha = new Texture;
<<<<<<< HEAD
  txt_flecha->loadFromFile("flecha.png");
=======
  txt_flecha->loadFromFile("Sprites/flecha.png");
>>>>>>> c6da2b0449bab8cce108d17cb26b612fde5ed6b1
  spr_flecha = new Sprite(*txt_flecha);
  spr_flecha->setPosition(150,340);
  angulo=0;
}
void Flecha::actualizarF(float tiemp){
  if(tiemp < 0.5 ) spr_flecha->rotate(10);
  /*tiemp/=10;
  spr_flecha->setPosition(spr_personaje->getPosition().x /2.f, (spr_personaje->getPosition().y /2.f)+10);
  spr_flecha->setOrigin((float)(spr_flecha->gettexture()->getSize().x), (float)(spr_flecha->gettexture()->getSize().y));
  if(){//escribir la condicion del mouse
      //ang=;
      spr_flecha->setRotation(spr_flecha->getRotation+ang);
  }*/
}
