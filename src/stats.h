#ifndef STATS_H
#define STATS_H

class Stats {
  public:
    Stats();
    Stats(int strength, int range, int magic, int defense, int health);

    int getStrength();
    int getRange();
    int getMagic();
    int getDefense();
    int getHealth();

  private:
    int strength_;
    int range_;
    int magic_;
    int defense_;
    int health_;
};

#endif
