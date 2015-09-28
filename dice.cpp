#include"dice.h"

Dice::Dice(int sides)
{
  /* initialize random seed: */
  srand (time(NULL));
  m_sides = sides;
}

int Dice::roll()
{
  return (rand() % m_sides) + 1; //generate secret number between 1 and sides
}
