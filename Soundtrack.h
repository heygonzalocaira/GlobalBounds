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

SoundTrack::SoundTrack(){
  buffer.loadFromFile("SOUND/Explosion.wav");
  sonido.setBuffer(buffer);
  Cancion.openFromFile("SOUND/After Dark.ogg");

  Cancion.setVolume(80);
  //Cancion.setPitch(1.2);
  Cancion.setLoop(true);
}
void SoundTrack::suenaSonido(){
  sonido.play();
}
void SoundTrack::suenaCancion(){
  Cancion.play();
}
