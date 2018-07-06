#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class SoundTrack{
private:
  SoundBuffer buffer;
  Sound sonido;
  Music Cancion;
public:
  SoundTrack();
  void suenaSonido();
  void suenaCancion();
};
