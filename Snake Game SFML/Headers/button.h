#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class button : public sf::Drawable {

private:
  sf::Font font;          /// the font of the text displayed on the button
  std::string buttonText; /// the text which will be displayed on the button
  float posX, posY;       /// the button's position on the screen relative to the upper-left corner
  int linkedScreenIndex;  /// the index of the screen that will be displayed when the button is pressed
  bool selected;          /// true if the button is selected (the btn will be coloured red), false otherwise

protected:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  button(std::string btnText = "Button", float X = 0, float Y = 0, int scrIdx = -1);
  ~button();

  void setFont(sf::Font);
  sf::Font getFont();

  void setButtonText(std::string);
  std::string getButtonText();

  void setX(float);
  float getX();

  void setY(float);
  float getY();

  void setLinkedScreenIndex(int);
  int getLinkedScreenIndex();

  void select();
  void unselect();
  bool getSelected();
};

#endif // BUTTON_H_INCLUDED
