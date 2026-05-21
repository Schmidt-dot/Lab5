#include "warehouse.h"

#include<iostream>
#include<string>

using namespace std;

//КЛАСС КОМАНД
enum class commands {
    ADD, //добавить
    REMOVE, //удалить
    INFO, //информация
    EXIT,//завершить
    UNKNOW
};

//СТОРКА В КОМАНДУ
commands toDo(const string& line){
    if (line == "ADD") return commands::ADD;
    if (line == "REMOVE") return commands::REMOVE;
    if (line == "INFO") return commands::INFO;
    if (line == "EXIT") return commands::EXIT;
    return commands::UNKNOW;
}

//ВЫБОР ДЕЙСТВИЯ
void choice(commands action) {

    switch (action){
        case commands::ADD:
        {
            string product; //наименование товара
            int amt; //количество
            string address; //адрес ячейки

            cin >> product >> amt >> address;

            adder(product, amt, address);

            break;
        }
    
        case commands::REMOVE:
        {
            string product; //наименование товара
            int amt; //количество
            string address; //адрес ячейки

            cin >> product >> amt >> address;

            remover(product, amt, address);

            break;
        }
    
        case commands::INFO:
        {
            info();
            break;
        }

        case commands::EXIT:
            exit(0);
            break;
    
        default:
            cout << "Попробуйте выбрать снова" << endl;
    }
}



int main(){

    init();
    
    cout << "Введите действие (для завершения напишите EXIT): " << endl;

    string line;

    while (true){
        cin >> line;

        commands action = toDo(line);
        choice(action);
    }

    return 0;
}