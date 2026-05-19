#include<iostream>
#include<string>

using namespace std;

//
enum class commands {
    ADD, //добавить
    REMOVE, //удалить
    INFO, //информация
    EXIT//завершить
};

//
commands toDo(const string& line){
    if (line == "ADD") return commands::ADD;
    if (line == "REMOVE") return commands::REMOVE;
    if (line == "INFO") return commands::INFO;
    if (line == "EXIT") return commands::EXIT;
}

//ВЫБОР ДЕЙСТВИЯ
void choice() {

    switch (line){
        case commands::ADD:
            string product; //наименование товара
            int quantity; //количество
            string address; //адрес ячейки
            cin << product << quantity << address;
            break;
    
        case commands::REMOVE:
            string product; //наименование товара
            int quantity; //количество
            string address; //адрес ячейки
            cin << product << quantity << address;
            break;
    
        case commands::INFO:
            /* code */
            break;
    
        case commands::EXIT:
            exit(0);
            break;
    
        default:
            cout << "Try again" << endl;
    }
}



int main(){
    string line;

    while (true){
        cin >> line;

        commands action = toDo(line);
        choice();
    }

    return 0;
}