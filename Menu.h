#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class MenuJuego{
public:
  MenuJuego();
  void play();
  void options();
  void exit();
  Sprite getSprite(){return *spr_menu;};
private:
  Texture *txt_menu;
  Sprite *spr_menu;
  //bool gameMenu;
  friend class Juego;
};

MenuJuego::MenuJuego(){
  txt_menu = new Texture;
  txt_menu->loadFromFile("Sprites/menuCopy.png");
  spr_menu = new Sprite(*txt_menu);
  spr_menu->setPosition(0,0);
  //gameMenu = true;
}
