#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Flecha{
public:
  Flecha(Vector2f pos);
  void rotarPositivo();
  void rotarNegativo();
  void setPosition(Vector2f pos);
  float angulo(){return spr_flecha->getRotation();}
  Vector2f getPosition();
  Sprite get_sprite2(){return *spr_flecha;}
  //int angulo;
private:
  Sprite *spr_flecha;
  Texture *txt_flecha;
  friend class Juego;
};
