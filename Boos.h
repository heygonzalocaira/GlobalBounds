

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Boos:public Dibujo{
public:
  Boos();
  Sprite getSprite(){return *spr_boos;}
  CircleShape getShape(){return *bombas;}
  void colocar();
  void actualizar(float tiemp);
private:
  Texture *txt_boos;
  Sprite *spr_boos;
  CircleShape *bombas;
  Vector2f velocidad;
  Vector2f aceleracion;
};
Boos::Boos(){
  txt_boos = new Texture();
  txt_boos->loadFromFile("Sprites/pokemon.png");
  spr_boos = new Sprite(*txt_boos);
  spr_boos->setOrigin(spr_boos->getTexture()->getSize().x/2.f,spr_boos->getTexture()->getSize().y/2.f);
  spr_boos -> setPosition(400,100);
  bombas = new CircleShape(14);
  bombas->setFillColor(Color::Yellow);
  velocidad.x=0;
  velocidad.y=0;
  aceleracion.x=0;
  aceleracion.y=9.8;
}
void Boos::colocar(){
  /*for(int i = 50;i<800;i+=100){
    bombas->setPosition(i,100);
  }*/
  bombas->setPosition(200,100);
}
void Boos::actualizar(float tiemp){
  tiemp/=10;
  velocidad.x+=aceleracion.x *tiemp;
  velocidad.y+=aceleracion.y *tiemp;
  bombas->setPosition(bombas->getPosition().x+velocidad.x*tiemp,bombas->getPosition().y+velocidad.y*tiemp);

}
