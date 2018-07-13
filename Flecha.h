#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Flecha{
public:
  Flecha();
  void rotarPositivo();
  void rotarNegativo();
  Sprite get_sprite2(){return *spr_flecha;}
  int angulo;
private:
  Sprite *spr_flecha;
  Texture *txt_flecha;
  friend class Juego;
};
