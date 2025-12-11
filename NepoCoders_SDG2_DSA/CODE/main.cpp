#include "FamilyModule.h"
#include "FoodPackModule.h"
#include "QueueModule.h"
#include "DistributionModule.h"
#include "SearchingModule.h"
#include "ReportModule.h"
#include "UtilityModule.h"
#include <iostream>
using namespace std;

int main() {
    LoadSampleData(); 
    int choice;
    do {
        cout << "\n===== DISTRICT AID SYSTEM =====\n";
        cout << "1. Register Family\n";
        cout << "2. Add Food Packs\n";
        cout << "3. Distribution of Food Pack\n";
        cout << "4. Search Family\n";
        cout << "5. Show Families\n";
        cout << "6. Show Food Packs\n";
        cout << "7. Show Queue\n";
        cout << "8. Exit\n";
        cout << "9. Show Summary Report\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: RegisterFamily(); break;
            case 2: AddFoodPack(); break;
            case 3: Distribute(); break;
            case 4: SearchFamily(); break;
            case 5: DisplayFamilies(); break;
            case 6: DisplayFood(); break;
            case 7: DisplayQueue(); break;
            case 8: cout << "Thank you for helping our society <3.\n"; break;
            case 9: DisplayReport(); break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    return 0;
}



