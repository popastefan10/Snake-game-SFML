#ifndef HARTA_H
#define HARTA_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../Headers/functii.h"

using namespace std;


class harta : public sf::Drawable {
  private:
    bool wall[100][100];

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  public:
    harta();
    harta(string);

    int width, length;
    bool isWall(int, int) const;
};

#endif // HARTA_H
