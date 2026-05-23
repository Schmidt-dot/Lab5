#include "port.h"

#include <iostream>
#include <string>

using namespace std;


//КЛАСС КОМАНД
enum class commands {
    ARRIVE, //добавление в стек
    LOAD, //выгрузка на судно
    EXIT, //завершить
    UNKNOWN
};


//СТРОКА В КОМАНДУ
commands toDo(const string& line) {
    if (line == "ARRIVE") return commands::ARRIVE;
    if (line == "LOAD") return commands::LOAD;
    if (line == "EXIT") return commands::EXIT;
    return commands::UNKNOWN;
}


//ВЫБОР ДЕЙСТВИЯ
void choice(commands action) {

    switch (action) {

        case commands::ARRIVE:
        {
            string id; //идентификатор
            int weight; //вес

            cin >> id >> weight;

            arrive(id, weight);

            break;
        }

        case commands::LOAD:
        {
            load();

            break;
        }

        case commands::EXIT:
        {
            exit(0);

            break;
        }

        default:
        {
            cout << "Попробуйте выбрать снова" << endl;
        }
    }
}


int main() {

    int maxWeight;
    int sectionCount;

    cout << "Введите максимальный размер стека: ";
    cin >> maxWeight;

    cout << "Введите количество секций судна: ";
    cin >> sectionCount;

    init(maxWeight, sectionCount);

    cout << "Введите действие (ARRIVE / LOAD / EXIT): " << endl;

    string line;

    while (true) {
        cin >> line;

        commands action = toDo(line);

        choice(action);
    }
    return 0;
}