#ifndef FOODPACKMODULE_H
#define FOODPACKMODULE_H

#include <string>
#include <vector>

extern std::vector<std::pair<std::string, int>> FoodPacks;

void AddFoodPack();
void DisplayFood();
void InsertionSortFoodPacks(std::vector<std::pair<std::string, int>> &arr);
#endif

