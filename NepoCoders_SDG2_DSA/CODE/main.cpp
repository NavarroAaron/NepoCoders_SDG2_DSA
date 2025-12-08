#include <iostream>
#include "FamilyModule.h"
#include "FoodPackModule.h"
#include "QueueModule.h"
#include "DistributionModule.h"
#include "SearchModule.h"

int main() {
    LoadSampleData(); 

    int choice;
    do {
        std::cout << "\n===== DISTRICT AID SYSTEM =====\n";
        std::cout << "1. Register Family\n";
        std::cout << "2. Add Food Packs\n";
        std::cout << "3. Distribution of Food Pack\n";
        std::cout << "4. Search Family\n";
        std::cout << "5. Show Families\n";
        std::cout << "6. Show Food Packs\n";
        std::cout << "7. Show Queue\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: RegisterFamily(); break;
            case 2: AddFoodPack(); break;
            case 3: Distribute(); break;
            case 4: SearchFamily(); break;
            case 5: DisplayFamilies(); break;
            case 6: DisplayFood(); break;
            case 7: DisplayQueue(); break;
            case 8: std::cout << "Thank you for helping our society <3.\n"; break;
            default: std::cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    return 0;
}
