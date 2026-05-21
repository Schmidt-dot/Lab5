#include<iostream>
#include<string>

using namespace std;
//A - 13*7*9
//B - 13*7*9

/*
vector<char> zone = {'A', 'B'};
int stack = 13; //кол-во стеллажей
int vertical = 7; //кол-во вертикальных
int shelf = 9; //кол-во полок
int size = 10; //начальная вместимость ячейки
*/
void skald(){}

bool isOkAddress(const string& address){

    if (address[0] != 'A' && address[0] != 'B') return false; 
    
    int stack, vertical, shelf;

    if (address.size() == 5) {
        stack = (address[1] - '0') * 10 + (address[2] - '0');
        vertical = address[3] - '0';
        shelf = address[4] - '0';
    } 

    else if (address.size() == 4){
        stack = address[1] - '0';
        vertical = address[2] - '0';
        shelf = address[3] - '0';
    } 

    else { 
        return false;
    }

    if (stack < 1 || stack > 13) return false;

    if (vertical < 1 || vertical > 7) return false;

    if (shelf < 1 || shelf > 9) return false;

    return true;
}


void add(string product, int quantity, string address){

    if (quantity > size){
        cout << "Ошибка: Превышена вместимость ячейки (максимум 10)" << endl;
        break;
    }

    if (!isOkAddress) {
        cout << "Ошибка: Неверный адрес ячейки" << endl
        break;
    }

    if () {
        cout << "Ошибка: Ячейка " << address << "занята товаром" << product;
    }


}


void remove(string product, int quantity, string address){
if (quantity > size){
        cout << "Недостаточно товаров для удаления" << endl;
        break;
    }

    if (!isOkAddress) {
        cout << "Ошибка: Неверный адрес ячейки" << endl
        break;
    }

    if () {
        cout << "Ошибка: Товар " << product << "не найден в ячейке" << address;
    }


}


void info(){

}