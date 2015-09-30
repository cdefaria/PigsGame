#include"dice.h"

Dice::Dice()
{
  /* initialize random seed: */
  srand (time(NULL));
}

int Dice::roll()
{
  return (rand() % m_sides) + 1; //generate secret number between 1 and sides
}

void Dice::set_sides(int sides)
{
  m_sides = sides;
}
