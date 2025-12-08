#include "QueueModule.h"
#include "FamilyModule.h"
#include <iostream>
#include <iomanip>

void DisplayQueue() {
    if (AidQueue.empty()) {
        std::cout << "\nQueue is empty.\n";
        return;
    }

    std::cout << "\nCURRENT AID QUEUE:\n";
    std::cout << std::left
         << std::setw(6) << "ID"
         << std::setw(20) << "Name"
         << std::setw(10) << "Members"
         << std::setw(10) << "Type"
         << std::setw(10) << "Priority" << std::endl;

    std::cout << std::string(56, '-') << std::endl;

    std::queue<Family> TempQueue = AidQueue;
    while (!TempQueue.empty()) {
        Family f = TempQueue.front();
        TempQueue.pop();

        std::cout << std::left
         << std::setw(6) << f.Id
         << std::setw(20) << f.Name
         << std::setw(10) << f.Members
         << std::setw(10) << f.Type
         << std::setw(10) << (IsPriority(f.Type) ? "PRIORITY" : "NORMAL") << std::endl;
    }

    std::cout << "\nTotal families in queue: " << AidQueue.size() << std::endl;
}
