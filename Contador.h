
#include <SFML/Graphics.hpp>

using namespace sf;

class Contador{
public:
  Contador();
  Sprite getContador(){return *spr_contador;}
  void set_frame(Sprite &spr_p,Vector2i numero_frame);
  void frame_loop();
  void iniciar();
private:
  Sprite *spr_contador;
  Texture *txt_contador;
  Vector2i division_sprites;
  Vector2i frame_actual;
};
Contador::Contador(){
  txt_contador = new Texture;
  txt_contador -> loadFromFile("Sprites/contador1.png");
  spr_contador = new Sprite(*txt_contador);
  spr_contador->setPosition(350,50);
  division_sprites.x=16;
  division_sprites.y=1;
  frame_actual.x=0;
  frame_actual.y=0;
  set_frame(*spr_contador,{0,0});
}
void Contador::set_frame(Sprite &spr_p,Vector2i numero_frame){
  IntRect posicion(numero_frame.x*spr_contador->getTexture()->getSize().x/division_sprites.x,numero_frame.y*spr_contador->getTexture()->getSize().y/division_sprites.y,spr_contador->getTexture()->getSize().x/division_sprites.x,spr_contador->getTexture()->getSize().y/division_sprites.y);
  spr_contador->setTextureRect(posicion);
}
void Contador::frame_loop(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  else
    frame_actual.x =0;
  iniciar();
}
void Contador::iniciar(){
  if(frame_actual.x<division_sprites.x-1)
    frame_actual.x++;
  set_frame(*spr_contador,frame_actual);
}
