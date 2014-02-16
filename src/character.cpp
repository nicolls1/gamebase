#include "character.h"
#include <iostream>

#define MIN_POSITION 0
#define MAX_POSITION 3

Character::Character(std::string name) : name_(name), position_(0)
{
  for(int i = 0; i <= MAX_POSITION; ++i) {
    std::string path("assets/PlayerFrames/");
    path.append(std::to_string(i));
    path.append("/Idle/Idle1.png");

    sf::Texture t;
    if(!t.loadFromFile(path))
      std::cout << "Failed to load idle image " << i << std::endl;
    idleImages_.push_back(t);
  }
}

Character::Character(Json::Value json) { }

void Character::moveLeft() {
  if(position_ != MIN_POSITION) {
    --position_;
  }
}

void Character::moveRight() {
  if(position_ != MAX_POSITION) {
    ++position_;
  }
}

void Character::draw(sf::RenderWindow* w) {
  sf::Sprite idle(idleImages_[position_]);
  w->draw(idle);
}
