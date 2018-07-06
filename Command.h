
/*#include <SFML/Graphics.hpp>
#include "Personaje.h"

using namespace sf;

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
