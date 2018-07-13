#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Personaje{
public:
  Personaje();

  void actualizar(float tiemp);
  Sprite get_sprite(){return *spr_personaje;};
  void izquierda();
  void derecha();
  void arriba();
  void abajo();
  void set_frame(Sprite &spr_p,Vector2i numero_frame);
  void frame_loop();
  double getpositionX();
  double getpositionY();
private:
  Sprite *spr_personaje;
  Texture *txt_personaje;
  Vector2f velocidad;
  Vector2f aceleracion;
  Vector2i division_sprites;
  Vector2i frame_actual;
  friend class Juego;
  friend class Flecha;
};

/*
class Command{
public:
  virtual void execute()=0;
};

class DerechaCommand:public Command{
public:
  DerechaCommand(Personaje &character):thecharacter(character){}
  virtual void execute(){
    thecharacter.derecha();
  }
private:
  Personaje &thecharacter;
};
class IzquierdaCommand:public Command{
public:
  IzquierdaCommand(Personaje &character):thecharacter(character){}
  virtual void execute(){
    thecharacter.izquierda();
  }
private:
  Personaje &thecharacter;
};

class Manejador{
private:
  Command &accion1Command;
  Command &accion2Command;
public:
  Manejador(Command *izqCmd,Command *derCmd):accion1Command(*izqCmd),accion2Command(*derCmd){}
  void accion1(){
    accion1Command.execute();
  }
  void accion2(){
    accion2Command.execute();
  }
};*/
