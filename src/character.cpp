#include "character.h"
#include <iostream>

#define MIN_POSITION 0
#define MAX_POSITION 3

#define RUNNING_FRAMES 14

Character::Character(std::string name) : name_(name), position_(0)
{
  for(int i = 0; i <= MAX_POSITION; ++i) {
    std::string idle_path("assets/PlayerFrames/");
    idle_path.append(std::to_string(i));
    idle_path.append("/Idle/Idle1.png");

    sf::Texture t;
    if(!t.loadFromFile(idle_path))
      std::cout << "Failed to load idle image " << i << std::endl;
    idleImages_.push_back(t);

    std::vector<sf::Texture> running;
    for(int j = 2; j <= RUNNING_FRAMES; ++j) {
      std::string running_path("assets/PlayerFrames/");
      running_path.append(std::to_string(i));
      running_path.append("/Run/Run00");

      if(j < 10) {
        running_path.append("0");
      }
      running_path.append(std::to_string(j));
      running_path.append(".png");


      sf::Texture t;
      if(!t.loadFromFile(running_path))
        std::cout << "Failed to load Running frame " << j << std::endl;

      running.push_back(t);
    }

    runningImages_.push_back(running);
    
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
  //sf::Sprite idle(idleImages_[position_]);
  //w->draw(idle);

  sf::Sprite running(runningImages_[position_][runningFrame_]);
  w->draw(running);

  runningFrame_ = (runningFrame_+1) % (RUNNING_FRAMES - 2);
}
