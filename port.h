#pragma once

#include <string>
#include <vector>
#include <stack>

using namespace std;

//КОНТЕЙНЕР
struct Container {
    string id; //идентификатор
    int weight; //вес
};


//СЕКЦИЯ
struct Section {
    int totalWeight = 0; //вес в секции
    vector<string> containers; //id контейнеров
};


//ОБЪЯВЛЕНИЕ Ф-ИЙ
void init(int maxWeight, int sectionCount);

bool isId(string id);

bool isPossible(int weight);

void arrive(string id, int weight);

void load();