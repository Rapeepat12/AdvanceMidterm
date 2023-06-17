#ifndef snack_h
#define snack_h

#include <string>
#include "criminals.h"
using namespace std;

class Snack {
private:
  string name;
  string description;
  int powerBoost;

public:
  Snack(const string& snackName, const string& snackDescription, int boost)
      : name(snackName), description(snackDescription), powerBoost(boost) {}

  string getName() const { return name; }

  string getDescription() const { return description; }

  int getPowerBoost() const { return powerBoost; }
};

#endif
