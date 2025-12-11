#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "ReportModule.h"
#include "FamilyModule.h"
#include "FoodPackModule.h"
#include "QueueModule.h"

using namespace std;

extern int TotalServed;
extern vector<Family> Families;
extern queue<Family> AidQueue;
extern vector<pair<string,int>> FoodPacks;

void DisplayReport() {
    cout << "\n===== DISTRIBUTION SUMMARY REPORT =====\n";

    cout << "Total Families Served: " << TotalServed << endl;
    cout << "Families Remaining in Queue: " << AidQueue.size() << endl;
    cout << "Families Remaining in Registered List: " << Families.size() << endl; 
    
    cout << "\nRemaining Inventory:\n";
    if (FoodPacks.empty()) {
        cout << "No food packs remaining.\n";
    }else {
        for(auto &f : FoodPacks) {
           cout << "- " << f.first << ": " << f.second << endl;
        }
    }

    cout << "===================================\n";
}
