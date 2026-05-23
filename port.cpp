#include "port.h"

#include <iostream>
#include <cctype>

using namespace std;

int maxStackWeight; //максимальный вес
int amtSections; //кол-во секций

vector<stack<Container>> stacks; //вектор, внутри со стеком, хранящим структуру контейнера
vector<int> curStackWeights; //массив веса стеков

//ЗАДАНИЕ ПАРАМЕТРОВ 
void init(int maxWeight, int sectionCount) {
    maxStackWeight = maxWeight;
    amtSections = sectionCount;
}


//ПРОВЕРКА НА КОРРЕКТНОСТЬ ИДЕНТИФИКАТОРА 
bool isId(string id) {
    if (id.size() != 4) { //длина 4
        return false;
    }

    if (id[0] != 'C') { //начинается с C
        return false;
    }

    for (int i = 1; i < 4; i++) { //после С все цифры

        if (!isdigit(id[i])) {
            return false;
        }
    }
    return true;
}


//ПОДХОДИТ ЛИ ВООБЩЕ
bool isPossible(int weight) {
    if (weight > maxStackWeight) { //введёный вес должен быть меньше макс стек
        return false;
    }
    return true;
}


//ПРОВЕРКА СВОБОДНЫЙ ЛИ СТЕК
bool allStacksEmpty() {
    for (const auto& stack : stacks) {

        if (!stack.empty()) {
            return false;
        }
    }
    return true;
}


//ПОИСК САМОЙ НЕЗАГРУЖЕННОЙ СЕКЦИИ
int lightestSection(vector<Section>& sections) { //вектор, со структурой секции
    int index = 0; //если одинаково - меньший порядковый номер

    for (int i = 1; i < amtSections; i++) { 

        if (sections[i].totalWeight < sections[index].totalWeight) { 

            index = i;
        }
    }
    return index;
}


//ЗАГРУЗКА
void arrive(string id, int weight) {    

    //Блок ошибок
    if (!isId(id)) {

        cout << "Ошибка: неверный идентификатор контейнера" << endl;

        return;
    }

    if (!isPossible(weight)) {

        cout << "Ошибка: контейнер слишком тяжелый для любого стека (макимальный размер " << maxStackWeight <<  ")" << endl;

        return;
    }


    Container container = {id, weight}; //создание контейнера 

    //Загрузка
    for (size_t i = 0; i < stacks.size(); i++) {

        if (curStackWeights[i] + weight <= maxStackWeight) { //помещается

            stacks[i].push(container); //добавить в начало

            curStackWeights[i] += weight;

            cout << "Контейнер " << id << " размещен в стек " << i + 1 << endl;

            return;
        }
    }

    //Если места в существующих стеках не хватает
    stack<Container> newStack; //создать новый

    newStack.push(container); //добавить контейнер

    stacks.push_back(newStack); //добавить новый стек в список к существующим

    curStackWeights.push_back(weight);

    cout << "Контейнер " << id << " размещен в стек " << stacks.size() << endl;
}


//ВЫГРУЗКА
void load() {
    
    }
}