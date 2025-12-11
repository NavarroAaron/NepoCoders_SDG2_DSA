#include "SearchingModule.h"
#include "FamilyModule.h"
#include "FoodPackModule.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void DisplayFamilies() {
    cout << "\nREGISTERED FAMILIES:\n";
    if (Families.empty()) {
        cout << "No families left.\n";
        return;
    }

    cout << left 
         << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Members"
         << setw(25) << "Address"
         << setw(10) << "Type" << endl;

    cout << string(71, '-') << endl;

    for (auto &f : Families) {
        cout << left
             << setw(6) << f.Id
             << setw(20) << f.Name
             << setw(10) << f.Members
             << setw(25) << f.Address
             << setw(10) << f.Type << endl;
    }
    cout << "\nTotal Families: " << Families.size() << endl;
}

void SearchFamily() {
    string name;
    cin.ignore();
    cout << "\nEnter family name to search: ";
    getline(cin, name);
    bool found = false;
    for (auto &f : Families) {
        if (f.Name == name) { found = true; break; }
    }
    cout << (found ? "Family is REGISTERED.\n" : "Family NOT FOUND.\n");
}

void LoadSampleData() {
    vector<Family> Sample = {
        {101, "Navarro Family", 4, "123 Main St", false, 'V'},
        {102, "Garcia Family", 3, "456 Oak Ave", false, 'N'},
        {103, "Reyes Family", 5, "789 Pine Rd", false, 'V'},
        {104, "Cruz Family", 6, "321 Maple St", false, 'V'},
        {105, "Santos Family", 4, "654 Elm St", false, 'N'}
    };

    for (auto f : Sample) Families.push_back(f);

    sort(Families.begin(), Families.end(),
         [](Family a, Family b) { return a.Name < b.Name; });

    queue<Family> PriorityQueue, NormalQueue;
    for (auto f : Families) {
        if (IsPriority(f.Type)) PriorityQueue.push(f);
        else NormalQueue.push(f);
    }
    while (!PriorityQueue.empty()) {
        AidQueue.push(PriorityQueue.front());
        PriorityQueue.pop();
    }
    while (!NormalQueue.empty()) {
        AidQueue.push(NormalQueue.front());
        NormalQueue.pop();
    }

    FoodPacks = { {"Rice", 10}, {"Noodles", 10}, {"CannedGoods", 10} };
    InsertionSortFoodPacks(FoodPacks);
}
