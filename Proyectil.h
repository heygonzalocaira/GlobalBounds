#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Proyectil{
public:
  Proyectil(Vector2f pos,Vector2f vel);
  ~Proyectil()= default;
  void actualizar(float tiemp);
  void actualizar2(float tiemp);
  void restaurar();
  Sprite get_sprite1(){return *spr_proyectil;}
  Sprite get_sprite2(){return *spr_proyectil2;}
private:
  Sprite *spr_proyectil;
  Texture *txt_proyectil;
  Sprite *spr_proyectil2;
  Texture *txt_proyectil2;
  Vector2f velocidad;
  Vector2f aceleracion;
  Vector2f copia;
  friend class Juego;
};

/*Proyectil::Proyectil(){
  txt_proyectil = new Texture;
  txt_proyectil->loadFromFile("granada.png");
  spr_proyectil = new Sprite(*txt_proyectil);
  spr_proyectil->setPosition(120,320);

  velocidad.x=50;
  velocidad.y=-50;

  aceleracion.x=0;
  aceleracion.y=9.8;
  if(spr_proyectil->getPosition().x> 500 && spr_proyectil-> getPosition().y >400){
    spr_proyectil->setPosition(120,320);
  }
}
void Proyectil::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  spr_proyectil->setPosition(spr_proyectil->getPosition().x+velocidad.x*tiemp,spr_proyectil->getPosition().y+velocidad.y*tiemp);
  //acomodando posicion
  //spr_proyectil->setPosition((spr_proyectil->getPosition().x /2.f)+velocidad.x*tiemp,(spr_proyectil->getPosition().y /2.f)+velocidad.y*tiemp);

  //acomodando origen de la imagen a su centro
  //spr_proyectil->setOrigin((float)(spr_proyectil->gettexture()->getSize().x /2.f), (float)(spr_proyectil->gettexture()->getSize().y /2.f));
  //rotar proyectil
  //spr_proyectil->setRotation(spr_proyectil->getRotation+10);

  // borrar este IF para que solo se dibuje una vez
/*  if(spr_proyectil->getPosition().x> 500 && spr_proyectil-> getPosition().y >400 ){

    velocidad.x=50;
    velocidad.y=-50;
    aceleracion.x=0;
    aceleracion.y=9.8;
    spr_proyectil->setPosition(120,320);
  }
*/
//}
