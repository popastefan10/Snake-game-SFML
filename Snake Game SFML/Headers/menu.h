#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <vector>
#include "cScreen.h"
#include "button.h"

class menu : public cScreen {

protected:
  int selected;                  /// the index of the button selected, ranges from 0 to Buttons.size() - 1
  std::vector<button> Buttons; /// the buttons that make up the menu
  sf::Font font;                 /// the font of the buttons' text

protected:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  menu();
  ~menu();

  void setSelected(int);
  int getSelected();

  void setFont(sf::Font);
  sf::Font getFont();

  int getNumberOfButtons();

  /// posX and posY are the coordinates of the button relative to the upper left corner (0, 0)
  /// screenIndex is the index of the screen that will be displayed when the button is pressed
  void add_button(std::string buttonText = "Press", float posX = 0, float posY = 0, int screenIndex = -1);
  void add_button(button &);
  void add_button(button *);
};

#endif // MENU_H_INCLUDED
