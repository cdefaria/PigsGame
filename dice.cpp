#include"dice.h"

Dice::Dice(unsigned int begin_range, unsigned int end_range)
{
  
  if(begin_range <= end_range)
    generator(begin_range, end_range);
  else
    generator(end_range, begin_range);
}
