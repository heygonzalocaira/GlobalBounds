#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Menu{
public:
  Menu();
  void play();
  void options();
  void exit();
private:
  Texture *txt_menu;
  sprite *spr_menu;
  bool gameMenu;
};

Menu::Menu(){
  txt_menu = new Texture;
  txt_menu->loadFromFile("menu.png");
  spr_menu = new Sprite(*txt_menu);
  spr_menu->setPosition(0,0);
}
