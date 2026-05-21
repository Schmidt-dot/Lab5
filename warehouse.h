#pragma once

#include<vector>
#include<string>

using namespace std;

//ЯЧЕЙКА
struct cells{
    string product = "";
    int amt = 0;
};


//ФУНКЦИИ
void init();

bool isOkAddress(const string& address);

void adder(string product, int amt, string address);

void remover(string product, int amt, string address);

void info();