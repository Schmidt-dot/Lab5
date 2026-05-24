#pragma once 

#include<vector>
#include<string>
#include<map>

using namespace std;

//ИНФОРМАЦИЯ О МЕТРО
extern map<string, vector<string>> metros;


//ФУНКЦИИ
void createMetro(string line, int N);

void metrosInStop(string station);

void stopsInMetro(string line);

void allMetros();