#ifndef criminals_h
#define criminals_h

#include <string>
#include <iostream>
using namespace std;

class Criminal {
private:
  string name;
  int power;

public:
  Criminal(const string & criminalName=0, int criminalPower=0)
      : name(criminalName), power(criminalPower) {}

  string getName() const { return name; }

  int getPower() const { return power; }
};

bool compareCriminalPower(const Criminal& criminal1, const Criminal& criminal2) {
  return criminal1.getPower() < criminal2.getPower();
}

void fightCriminal(int detectivePower, int criminalPower) {
  if (detectivePower > criminalPower) {
    cout << "Congratulations! You defeated the criminal!" << std::endl;
  } else if (detectivePower < criminalPower) {
    cout << "Oh no! The criminal was too powerful. Better luck next time!" << endl;
  } else {
    cout << "It's a tie! You couldn't defeat the criminal. Better luck next time!" <<endl;
  }
}

#endif