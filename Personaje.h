#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//clase abstracta Juego
class Juego{
public:
    virtual actualizar(float){}
    virtual Sprite* get_sprite(){}
};

class Personaje{
public:
  Personaje();
  void actualizar(float);
  //Sprite get_sprite(){return *spr_personaje;};
  Sprite* get_sprite(){return spr_personaje;}
private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};

Personaje::Personaje(){
  txt_personaje = new Texture;
  txt_personaje->loadFromFile("heroe.png");
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
