#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
<<<<<<< HEAD


=======

//clase abstracta Juego
class Juego{
public:
    virtual actualizar(float){}
    virtual Sprite* get_sprite(){}
};
>>>>>>> 8b7a140f1b8c6616f88c3e77d3864f3a6590f288

class Personaje{
public:
  Personaje();
<<<<<<< HEAD
  void actualizar(float tiemp);
  Sprite get_sprite(){return *spr_personaje;};
  void procesarEvento();
=======
  void actualizar(float);
  //Sprite get_sprite(){return *spr_personaje;};
  Sprite* get_sprite(){return spr_personaje;}
>>>>>>> 8b7a140f1b8c6616f88c3e77d3864f3a6590f288
private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Vector2f velocidad;
  Vector2f aceleracion;
  friend class Juego;
};
