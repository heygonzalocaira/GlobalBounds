#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Personaje{
public:
  Personaje();

  void actualizar(float);
  Sprite get_sprite(){return *spr_personaje;};

private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};
