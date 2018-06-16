#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Proyectil{
public:
  Proyectil();
  void actualizar(float tiemp);
  Sprite get_sprite1(){return *spr_proyectil;}
private:
  Sprite *spr_proyectil;
  Texture *txt_proyectil;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};
