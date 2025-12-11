#include "FoodPackModule.h"
#include <iostream>
using namespace std;

vector<pair<string, int>> FoodPacks;

void InsertionSortFoodPacks(vector<pair<string,int>> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        auto key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].first > key.first) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
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
    InsertionSortFoodPacks(FoodPacks);
}

void DisplayFood() {
    cout << "\nFOOD INVENTORY:\n";
    if (FoodPacks.empty()) { cout << "No food packs left.\n"; return; }

    for (auto &f : FoodPacks) {
        cout << "- " << f.first << " = " << f.second << endl;
    }
}








