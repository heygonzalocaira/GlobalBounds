#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Menu{
public:
  Menu();
  void play();
  void options();
  void exit();
  void gameLoop();
  void dibujar();
private:
  RenderWindow *menuWindow;

  Texture *txt_menu;
  Sprite *spr_menu;

  bool gameMenu;
  Event *eventoMenu;
};

Menu::Menu(){
  menuWindow = new RenderWindow(VideoMode(800,600));
  txt_menu = new Texture;
  txt_menu->loadFromFile("menu.png");
  spr_menu = new Sprite(*txt_menu);
  spr_menu->setPosition(0,0);

}
void Menu::gameLoop(){
  while(!gameMenu){
    dibujar();
  }
}
void Menu::dibujar(){
  menuWindow->clear();
  
}
