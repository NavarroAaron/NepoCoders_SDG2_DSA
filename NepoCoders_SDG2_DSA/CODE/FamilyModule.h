#ifndef FAMILYMODULE_H
#define FAMILYMODULE_H
#ifndef FAMILYMODULE_H
#define FAMILYMODULE_H

#include <string>
#include <vector>
#include <queue>

struct Family {
    int Id;
    std::string Name;
    int Members;
    std::string Address;
    bool HasReceivedFood;
    char Type;
};

extern std::vector<Family> Families;
extern std::queue<Family> AidQueue;

bool IsDuplicate(std::string name);
bool IsPriority(char type);
void RegisterFamily();

#endif
