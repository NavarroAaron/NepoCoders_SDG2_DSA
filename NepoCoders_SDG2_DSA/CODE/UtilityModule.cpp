#include <iostream>
#include <cstdlib>
using namespace std;

void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void PressEnterToContinue() {
    cout << "\nPress Enter to continue.....";
    cin.ignore();
    cin.get();
}
