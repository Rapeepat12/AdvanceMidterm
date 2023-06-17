#include "criminals.h"
#include "snack.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(Criminal *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j].getPower() > arr[j + 1].getPower()) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  const int totalSnacks = 6;
  const int totalCriminals = 3;

  string criminals[totalCriminals];
  int powers[totalCriminals];

cout<<"Welcome to Snack Detective the Game"<<endl<<endl;
cout<<"Premise: You play as a detective that starts with 10 power and have to eat snack to gain more powers to fight against the criminals!"<<endl<<endl;

  cout << "First, enter the details of " << totalCriminals << " criminals:" << endl;
  for (int i = 0; i < totalCriminals; i++) {
    cout << "Enter the name of criminal " << i + 1 << ": ";
    cin >> criminals[i];

    cout << "Enter the power of criminal " << i + 1 << ": ";
    cin >> powers[i];
  }

  

  bubbleSort(criminalList, totalCriminals);
  //sort(criminalList, criminalList + NUM_CRIMINALS, compareCriminalPower); //sorting

  Snack *snacks[totalSnacks];

  snacks[0] = nullptr;  // Placeholder for 0

  snacks[1] = new Snack("M&M", "Sweet but not good for health", 10);
  snacks[2] = new Snack("Nutrition Bar", "Healthy and sweet", 15);
  snacks[3] = new Snack("Apple slices", "Good for health but little flavour", 8);
  snacks[4] = new Snack("Cookie", "Just sweet", 12);
  snacks[5] = new Snack("Potato Chips", "Salty and full with air", 6);

  cout << "\nSnacks:\n";
  for (int i = 1; i < totalSnacks; i++) {
    cout << i << ". Name: " << snacks[i]->getName() << endl
         << "   Description: " << snacks[i]->getDescription() <<endl;
  }

  int chooseSnack;
  cout << "\nEnter the number of the snacks you want to eat (1-"
       << totalSnacks - 1 << "): ";
  cin >> chooseSnack;

  if (chooseSnack >= 1 && chooseSnack < totalSnacks) {
    int detectivePower = 10; // Starting power of the detective
    detectivePower += snacks[chooseSnack]->getPowerBoost();
    cout << "You eat the " << snacks[chooseSnack]->getName()
         << " snack. Your power is boosted."<<endl;
    cout << "Your power: " << detectivePower << "\n";

    bool defeatedAllCriminals = false;

    while (!defeatedAllCriminals) {
      cout << "\nSorted Criminals based on Power:\n";
      for (int i = 0; i < totalCriminals; i++) {
        cout << i + 1 << ". Name: " << criminalList[i].getName()
             << ", Power: " << criminalList[i].getPower() <<endl;
      }

      int chooseCriminal;
      cout << "\nEnter number of the criminal you want to fight (1-"
           << totalCriminals << ") or enter 0 to exit: ";
      cin >> chooseCriminal;

      if (chooseCriminal >= 1 &&
          chooseCriminal <= totalCriminals) {
        int criminalPower = criminalList[chooseCriminal - 1].getPower();
        cout << "\nYou are fighting against criminal "
             << criminalList[chooseCriminal - 1].getName()
             << " with power " << criminalPower << "." << endl;

        // Fight the criminal
        fightCriminal(detectivePower, criminalPower);

        // Check if detective won the fight
        if (detectivePower > criminalPower) {
          cout << "Congratulations! You defeated the criminal!" << endl;

          int chooseSnack;
          cout << "Enter the number of the snacks you want to eat (1-"
 << totalSnacks - 1 << ") or enter 0 to exit: ";
          cin >> chooseSnack;

          if (chooseSnack >= 1 && chooseSnack < totalSnacks) {
            detectivePower += snacks[chooseSnack]->getPowerBoost();
            cout << "You eat the " << snacks[chooseSnack]->getName()
                 << " snack. Your power is boosted." << endl;
                cout << "Your power: " << detectivePower <<endl;
          } else if (chooseSnack == 0) {
            defeatedAllCriminals = true;
            cout << "Exiting..." << endl;
          } else {
            defeatedAllCriminals = true;
            cout << "Invalid snack number. No snack has been eaten. Exiting..."
                 << endl;
          }
        } else if (detectivePower < criminalPower) {
          cout << "Oh no! The criminal was too powerful. Better luck next time!"
               << endl;
          defeatedAllCriminals = true;
        } else {
          cout << "It's a tie! You couldn't defeat the criminal. Better luck "
                  "next time!"
               << endl;
          defeatedAllCriminals = true;
        }
      } else if (chooseCriminal == 0) {
        defeatedAllCriminals = true;
        cout << "Exiting..." << endl;
      } else {
        defeatedAllCriminals = true;
        cout << "Invalid criminal number. No fight initiated. Exiting..."
             << endl;
      }
    }

    // Cleaning up allocated memory
    for (int i = 1; i < totalSnacks; i++) {
      delete snacks[i];
    }

    delete[] criminalList;

    return 0;
  }
}