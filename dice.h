#ifndef DICE_H_
#define DICE_H_

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Dice {
  public:
    Dice(int sides);
    int roll(); //retruns a dice roll in the range

  private:
    int m_sides;
};

#endif //DICE_H_
