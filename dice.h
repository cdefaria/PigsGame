/*
 * Author Michael Taylor
 * Date Sep. 14th 2015
 * Description: This class is the random dice roller for the game
 */

#ifndef DICE_H_
#define DICE_H_

#include<random>
#include<chrono>

using namespace std;

class Dice {
  public:
    Dice(unsigned int, unsigned int);
    unsigned int roll(); //retruns a dice roll in the range

  private:
  default_random_distribution generator;
  uniform_int_distribution<unsigned int>
};

#endif //DICE_H_
