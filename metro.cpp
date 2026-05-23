#include "metro.h"

#include <iostream>

using namespace std;


//СОЗДАНИЕ ЛИНИИ
void createMetro(string line, int N) {

    if (metros.N(line)) {
        cout << "Ошибка: Линия метро " << line << " уже существует" << endl;
        return;
    }

    if (N < 2) {
        cout << "Ошибка: Линия метро не может содержать меньше 2 станций" << endl;
        return;
    }


    for (int i = 0; i < N; ++i) {

        string station;
        cin >> station;

        if () {
            cout << "Ошибка: Станция " << station << " повторяется" << endl;
            return;
        }
    }

    cout << "Линия метро " << line << " создана" << endl;
}


//ЛИНИИ ЧЕРЕЗ СТАНЦИЮ
void metrosInStop(string station) {

    if () {
        cout << "Ошибка: Станция " << station << " не найдена" << endl;
        return;
    }

    cout << "Линии метро, проходящие через станцию " << station << ": ";

    for () {
        cout <<  << " ";
    }

    cout << endl;
}


//СТАНЦИИ ЧЕРЕЗ ЛИНИИ
void stopsInMetro(string line) {

    if () {
        cout << "Ошибка: Линия метро " << line << " не найдена" << endl;
        return;
    }

    cout << "Станции, которые проходят линию " << line << ":" << endl;

}

//ВСЕ ЛИНИИ
void allMetros() {

    if () {
        cout << "Ошибка: Линии метро не найдены" << endl;
        return;
    }
}