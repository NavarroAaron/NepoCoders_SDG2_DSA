#include "DistributionModule.h"
#include "FamilyModule.h"
#include "FoodPackModule.h"
#include <iostream>
using namespace std;

extern int TotalServed;
void RemoveFamilyFromList(string name) {
    for (int i = 0; i < Families.size(); i++) {
        if (Families[i].Name == name) {
            Families.erase(Families.begin() + i);
            break;
        }
    }
}

void Distribute() {
    if (AidQueue.empty()) {
        cout << "\nDistribution Stopped: The queue is empty.\n";
        return;
    }

    bool outOfStock = false;
    for (auto &f : FoodPacks) {
        if (f.second <= 0) {
            outOfStock = true;
            break;
        }
    }
    if (outOfStock) {
        cout << "\nDistribution Stopped: One or more food packs are empty.\n";
        return;
    }

    cout << "\n--- STARTING DISTRIBUTION ---\n";

    while (!AidQueue.empty()) {
        bool anyEmpty = false;
        for (auto &f : FoodPacks) {
            if (f.second <= 0) { anyEmpty = true; break; }
        }
        if (anyEmpty) break;

        Family CurrentFamily = AidQueue.front();
        AidQueue.pop();

        cout << "Served 1 of each food to: " << CurrentFamily.Name << endl;

     
        RemoveFamilyFromList(CurrentFamily.Name);

        for (auto &f : FoodPacks) {
            f.second--;
        }
    }

    cout << "--- DISTRIBUTION FINISHED ---\n";
}
