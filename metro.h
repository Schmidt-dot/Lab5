#pragma once 

#include<vector>
#include<string>
#include<map>

using namespace std;

//ИНФОРМАЦИЯ О МЕТРО
extern map<string, vector<string>> metros;


//ФУНКЦИИ
void createMetro(line, N);

void metrosInStop(station);

void stopsInMetro(line);

void allMetros();