#ifndef HARTA_H
#define HARTA_H
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../Headers/functii.h"

using namespace std;


class Harta : public sf::Drawable
{
    public:
        Harta();
        Harta(string);

        void displayHarta();
        int width, length;
        bool estePerete(int, int) const;

    private:
        int n, m;
        bool perete[100][100];

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HARTA_H
