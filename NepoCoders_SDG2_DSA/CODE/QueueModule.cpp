#include "QueueModule.h"
#include "FamilyModule.h"
#include <iostream>
#include <iomanip>
using namespace std;

void DisplayQueue() {
    if (AidQueue.empty()) {
        cout << "\nQueue is empty.\n";
        return;
    }

    cout << "\nCURRENT AID QUEUE:\n";
    cout << left
         << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Members"
         << setw(10) << "Type"
         << setw(10) << "Priority" << endl;

    cout << string(56, '-') << endl;

    queue<Family> TempQueue = AidQueue;
    while (!TempQueue.empty()) {
        Family f = TempQueue.front();
        TempQueue.pop();

        cout << left
             << setw(6) << f.Id
             << setw(20) << f.Name
             << setw(10) << f.Members
             << setw(10) << f.Type
             << setw(10) << (IsPriority(f.Type) ? "PRIORITY" : "NORMAL") << endl;
    }

    cout << "\nTotal families in queue: " << AidQueue.size() << endl;
}
