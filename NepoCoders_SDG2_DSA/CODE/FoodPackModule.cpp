#include "FoodPackModule.h"
#include <iostream>
using namespace std;

vector<pair<string, int>> FoodPacks;

void AddFoodPack() {
    string foodName;
    int qty;
    cout << "\nEnter Food Pack name: ";
    cin >> foodName;
    cout << "How many units are you adding? ";
    cin >> qty;

    bool found = false;
    for (auto &f : FoodPacks) {
        if (f.first == foodName) {
            f.second += qty;
            found = true;
            cout << "Updated " << foodName << " quantity: " << f.second << endl;
            break;
        }
    }

    if (!found) {
        FoodPacks.push_back({foodName, qty});
        cout << "Added " << foodName << " with quantity: " << qty << endl;
    }
}

void DisplayFood() {
    cout << "\nFOOD INVENTORY:\n";
    if (FoodPacks.empty()) { cout << "No food packs left.\n"; return; }

    for (auto &f : FoodPacks) {
        cout << "- " << f.first << " = " << f.second << endl;
    }
}







