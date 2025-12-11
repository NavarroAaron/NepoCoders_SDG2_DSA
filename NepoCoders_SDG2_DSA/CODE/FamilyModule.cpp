#include "FamilyModule.h"
#include "UtilityModule.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
   
vector<Family> Families;
queue<Family> AidQueue;

bool IsDuplicate(string name) {
    for (auto &fam : Families) {
        if (fam.Name == name) return true;
    }
    return false;
}

bool IsPriority(char type) {
    return (type == 'V');
}

void RegisterFamily() {
    string name, address;
    int id, members;
    char type;

    cout << "\nEnter Family ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Family Name: ";
    getline(cin, name);
    if (IsDuplicate(name)) {
        cout << "Family already exists!\n";
        return;
    }

    cout << "Enter number of members: ";
    cin >> members;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Family type (V/N): ";
    cin >> type;

    Family NewFamily = {id, name, members, address, false, type};
    Families.push_back(NewFamily);

    sort(Families.begin(), Families.end(),
         [](Family a, Family b) { return a.Name < b.Name; });

    if (IsPriority(type)) {
        queue<Family> TempQueue;
        TempQueue.push(NewFamily);
        while (!AidQueue.empty()) {
            TempQueue.push(AidQueue.front());
            AidQueue.pop();
        }
        AidQueue = TempQueue;
    } else {
        AidQueue.push(NewFamily);
    }

    cout << "Family registered successfully!\n";
}



