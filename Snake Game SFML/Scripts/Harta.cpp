#include "../Headers/Harta.h"

harta::harta() {
  //ctor
}

harta::harta(string fileName) {
  ifstream in(fileName);
  in >> width >> length;

  for(int i = 0; i < width; i++) { /// indexez de la 0 ca sa fie pozitiile ok cu cele din snake
    for(int j = 0; j < length; j++){
      char crtCh;
      in >> crtCh;
      if(crtCh == '#')
        wall[i][j] = true;
      else
        wall[i][j] = false;
    }
  }
}

bool harta::isWall(int x, int y) const {
  return wall[y][x];
}

void harta::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for(int i = 0; i < length; i++)
    for(int j = 0; j < width; j++)
      if(isWall(i, j)) {
        sf::RectangleShape wallBlock(sf::Vector2f((float)PIXEL, (float)PIXEL));
        wallBlock.setPosition((float)i * PIXEL, (float)j * PIXEL);
        wallBlock.setFillColor(sf::Color::Green);

        target.draw(wallBlock);
      }
}
