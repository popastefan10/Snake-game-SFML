#ifndef START_MENU_H_INCLUDED
#define START_MENU_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "functii.h"
#include "help_menu.h"
#include "options_menu.h"
#include "cScreen.h"
#include "button.h"

class start_menu : public cScreen {

private:
  int selected;                /// the index of the button selected, ranges from 0 to Buttons.size() - 1
  std::vector<button> Buttons; /// the buttons that make up the menu
  sf::Font font;               /// the font of the buttons' text

public:
  start_menu();
  ~start_menu();

  void setSelected(int);
  int getSelected();

  void setFont(sf::Font);
  sf::Font getFont();

  int getNumberOfButtons();

  /// posX and posY are the coordinates of the button relative to the upper left corner (0, 0)
  /// screenIndex is the index of the screen that will be displayed when the button is pressed
  void add_button(std::string buttonText = "Press", float posX = 0, float posY = 0, int screenIndex = -1);

  int Run(sf::RenderWindow &App);
};

#endif // START_MENU_H_INCLUDED
