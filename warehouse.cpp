#include "warehouse.h"

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

//A - 13*7*9
//B - 13*7*9
//ВХОДНЫЕ ДАННЫЕ О СКЛАДЕ
vector<char> zone = {'A', 'B'}; //кол-во зон
int stack = 13; //кол-во стеллажей
int vertical = 7; //кол-во вертикальных
int shelf = 9; //кол-во полок
int sizeCell = 10; //начальная вместимость ячейки

map<string, cells> sklad;

//СОЗДАНИЕ ЯЧЕЕК
void init(){
    for (char z : zone){
        for (int s = 1; s <= stack; ++s){
            for (int v = 1; v <= vertical; ++v){
                for (int h = 1; h <= shelf; ++h){
                    string address = string(1, z) + to_string(s) + to_string(v) + to_string(h);
                    sklad[address] = {"",0};
                }
            }
        }

    }
}

//ПРОВЕРКА НА ВАЛИДНОСТЬ АДРЕСА
bool isOkAddress(const string& address){

    if (address[0] != 'A' && address[0] != 'B') return false; 
    
    int curStack, curVertical, curShelf;

    if (address.size() == 5) {
        curStack = (address[1] - '0') * 10 + (address[2] - '0');
        curVertical = address[3] - '0';
        curShelf = address[4] - '0';
    } 

    else if (address.size() == 4){
        curStack = address[1] - '0';
        curVertical = address[2] - '0';
        curShelf = address[3] - '0';
    } 

    else { 
        return false;
    }

    if (curStack < 1 || curStack > 13) return false;

    if (curVertical < 1 || curVertical > 7) return false;

    if (curShelf < 1 || curShelf > 9) return false;

    return true;
}


//ДОБАВЛЕНИЕ ПРОДУКТА
void adder(string product, int amt, string address){

    if (!isOkAddress(address)) {
        cout << "Ошибка: Неверный адрес ячейки" << endl;
        return;
    }

    cells &cell = sklad[address]; //Обращение к адресу на складе

    //Блок ошибочного ввода
    if (amt > (sizeCell - cell.amt)){
        cout << "Ошибка: Превышена вместимость ячейки (максимум 10)" << endl;
        return;
    }

    if (cell.amt != 0 && product != cell.product) {
        cout << "Ошибка: Ячейка " << address << " занята товаром" << cell.product;
        return;
    }

    //Добавление
    cell.amt += amt;    
    cell.product = product;

    cout << "Добавлено " << amt << " " << product << " в ячейку " << address << endl; 
}


//УДАЛЕНИЕ ПРОДУКТА
void remover(string product, int amt, string address){

    if (!isOkAddress(address)) {
        cout << "Ошибка: Неверный адрес ячейки" << endl;
        return;
    }

    cells &cell = sklad[address]; //Обращение к адресу на складе

    //Блок ошибок
    if (amt > cell.amt){
        cout << "Недостаточно товаров для удаления" << endl;
        return;
    }

    if (product != cell.product) {
        cout << "Ошибка: Товар " << product << " не найден в ячейке " << address;
        return;
    }

    //Удаление
    cell.amt -= amt;
    if (cell.amt == 0){
        cell.product = "";
    }

    cout << "Удалено " << amt << " " << product << " (остаток: " << cell.amt << ")" << endl;
}


//ИНФОРМАЦИЯ О ЗАПОЛНЕННОСТИ 
void info(){
    int total = 16380;

    int used = 0;
    int usedA = 0;
    int usedB = 0;

    for (const auto &cell : sklad){
        used += cell.second.amt;

        if (cell.first[0] == 'A'){
            usedA += cell.second.amt;
        }

        if (cell.first[0] == 'B'){
            usedB += cell.second.amt;
        }

    }

    double loadAll = (double)used / total * 100; //Загруженность склада

    double zoneALoad = (double)usedA / (total / 2) * 100; //Закгружнность зоны А

    double zoneBLoad = (double)usedB / (total / 2) * 100; //Закгружнность зоны B

    cout << "Загруженность склада: " << loadAll << "%" << endl;
    cout << "Загруженность зоны А: " << zoneALoad << "%" << endl;
    cout << "Загруженность зоны B: " << zoneBLoad << "%" << endl;

    cout << "Заполненные ячейки: " << endl;
    for (const auto &cell : sklad){
        if (cell.second.amt != 0){
            cout << cell.first << cell.second.product << cell.second.amt << endl;
        }
    }

    cout << "Пустые ячейки:" << endl;
    for (const auto &cell : sklad){
        if (cell.second.amt == 0){
            cout << cell.first << " ";
        }
    }

    cout << endl;
}