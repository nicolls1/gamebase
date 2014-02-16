#include "background.h"
#include <iostream>
#include <string>

#define BACKGROUND_IMAGES 30

Background::Background() : currentImage_(0), velocity_(100), position_(0) {

  for(int i = 1; i < BACKGROUND_IMAGES; ++i) {
    sf::Texture bg;
    std::string path("assets/Background/Tunnel00");
    if(i < 10) {
      path.append("0");
    }
    path.append(std::to_string(i));
    path.append(".jpg");

    if(!bg.loadFromFile(path))
      std::cout << "Error loading background" << std::endl;
    bgTexture_.push_back(bg);
  }
  
}

void Background::setVelocity(int v) { velocity_ = v; }

void Background::draw(sf::RenderWindow* w) {
  sf::Sprite background(bgTexture_[currentImage_]);
  w->draw(background);
  position_ += velocity_;
  if(position_ > 100) {
    position_ = 0;
    currentImage_ = (currentImage_ + 1) % (BACKGROUND_IMAGES - 1);
  }
}


