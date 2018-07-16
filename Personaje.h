#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Personaje{
public:
  Personaje(int a,int b,int x,int y);

  void actualizar(float tiemp);
  Sprite getSprite(){return *spr_personaje;}
  RectangleShape getShape(){return *cajavida;}
  void izquierda();
  void derecha();
  void arriba();
  void abajo();
  void set_frame(Sprite &spr_p,Vector2i numero_frame);
  void frame_loop();
  float getpositionX();
  float getpositionY();
  void freno();
  void restavida();
  void colorvida();
private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Vector2f velocidad;
  Vector2f aceleracion;
  Vector2i division_sprites;
  Vector2i frame_actual;
  RectangleShape *cajavida;
  int vida;
  int voltear;
  friend class Juego;
  friend class Flecha;
};
