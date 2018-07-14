
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Ground{
public:
  Ground();
  Sprite getGround(){return *spr_ground;}
  int idGround(){return id;}
private:
  Texture *txt_ground;
  Sprite *spr_ground;
  int id;
};
Ground::Ground(){
  txt_ground = new Texture();
  txt_ground->loadFromFile("Sprites/piso.png");
  spr_ground = new Sprite(*txt_ground);
  spr_ground->setPosition(0,350);
  id = 1;
}
