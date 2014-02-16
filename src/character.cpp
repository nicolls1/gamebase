#include "character.h"
#include <iostream>

#define MIN_POSITION 0
#define MAX_POSITION 3

#define RUNNING_FRAMES 14
#define MELEE_FRAMES 20

Character::Character(std::string name) : name_(name), runningFrame_(0), meleeFrame_(0),
    meleeAttack_(false), position_(0) {
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
    
    std::vector<sf::Texture> meleeing;
    for(int j = 1; j <= MELEE_FRAMES; ++j) {
      std::string meleeing_path("assets/PlayerFrames/");
      meleeing_path.append(std::to_string(i));
      meleeing_path.append("/Melee/Melee00");

      if(j < 10) {
        meleeing_path.append("0");
      }
      meleeing_path.append(std::to_string(j));
      meleeing_path.append(".png");


      sf::Texture t;
      if(!t.loadFromFile(meleeing_path))
        std::cout << "Failed to load Melee frame " << j << std::endl;

      meleeing.push_back(t);
    }

    meleeImages_.push_back(meleeing);
  }
}

Character::Character(Json::Value json) { }

void Character::moveLeft() {
  if(meleeAttack_) {
    return;
  }

  if(position_ != MIN_POSITION) {
    --position_;
  }
}

void Character::moveRight() {
  if(meleeAttack_) {
    return;
  }

  if(position_ != MAX_POSITION) {
    ++position_;
  }
}

void Character::meleeAttack() {
  meleeAttack_ = true;
}

void Character::draw(sf::RenderWindow* w) {
  //sf::Sprite idle(idleImages_[position_]);
  //w->draw(idle);
  
  if(meleeAttack_) {
    sf::Sprite meleeing(meleeImages_[position_][meleeFrame_]);
    w->draw(meleeing);

    if(meleeFrame_ == MELEE_FRAMES-1) {
      meleeAttack_ = false;
      meleeFrame_ = 0;
      return;
    }

    ++meleeFrame_;
    return;
  }

  sf::Sprite running(runningImages_[position_][runningFrame_]);
  w->draw(running);

  runningFrame_ = (runningFrame_+1) % (RUNNING_FRAMES - 2);
}
