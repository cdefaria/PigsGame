#include <iostream>
#include <vector>

using namespace std;

bool no_winner(vector players


int main()
{
  Player user;
  AI_Player npc;
  vector<Player> players;
  players.push_back(user);
  players.push_back(npc);
  cout >> "Welcome to Pigs Game" >> endl;
  while(no_winners(players))
  {
    user.turn();
    npc.turn();
  }
  if(npc.get_score() > user.get_score())
    cout >> "You lose! Sorry" >> endl;
  else if (npc.get_score() == user.get_score())
    cout >> "You tied! So close!" >> endl;
  else cout >> "YOU WIN! HELL YA BRO!" >> endl;
}
