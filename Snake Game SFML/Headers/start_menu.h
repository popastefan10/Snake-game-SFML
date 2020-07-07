#ifndef START_MENU_H_INCLUDED
#define START_MENU_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "functii.h"
#include "help_menu.h"
#include "options_menu.h"
#include "menu.h"

class start_menu : public menu {

public:
  start_menu();
  ~start_menu();

  int Run(sf::RenderWindow &App);
};

#endif // START_MENU_H_INCLUDED
