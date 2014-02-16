#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <vector>

class Background {
  public:
    Background();

    void setVelocity(int v);
    void draw(sf::RenderWindow* w);

  private:
    int currentImage_;
    int velocity_;
    int position_;
    std::vector<sf::Texture> bgTexture_;

};

#endif
