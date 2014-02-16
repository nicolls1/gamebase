#include "item.h"

Item::Item() { }

Item::Item(std::string name, int itemType, int armorType, Stats stats) : 
    name_(name), itemType_(itemType), armorType_(armorType), stats_(stats)
{ }

std::string Item::getName() {
  return name_;
}

int Item::getType() {
  return itemType_;
}

int Item::getArmorType() {
  return armorType_;
}

Stats Item::getStats() {
  return stats_;
}
