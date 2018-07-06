

#include "Soundtrack.h"


SoundTrack::SoundTrack(){
  buffer.loadFromFile("SOUND/Explosion.wav");
  sonido.setBuffer(buffer);
  Cancion.openFromFile("SOUND/After Dark.ogg");

  Cancion.setVolume(60);
  //Cancion.setPitch(1.2);
  Cancion.setLoop(true);
}
void SoundTrack::suenaSonido(){
  sonido.play();
}
void SoundTrack::suenaCancion(){
  Cancion.play();
}
