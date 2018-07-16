#include <SFML/Graphics.hpp>
#include "Dibujo.h"
#include <iostream>

using namespace sf;
using namespace std;

class Flecha:public Dibujo{
public:
  Flecha(Vector2f pos);
  void rotarPositivo();
  void rotarNegativo();
  void setPosition(Vector2f pos);
  float angulo(){return spr_flecha->getRotation();}
  Vector2f getPosition();
  Sprite getSprite(){return *spr_flecha;}
  //int angulo;
private:
  Sprite *spr_flecha;
  Texture *txt_flecha;
  friend class Juego;
};
