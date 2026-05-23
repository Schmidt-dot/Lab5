#include "metro.h"

#include<iostream>
#include<set>

using namespace std;

map<string, vector<string>> metros; //линиям соответствует вектор станций

//СОЗДАНИЕ ЛИНИИ
void createMetro(string line, int N) {

    if (metros.count(line)) { //проверка существования линии
        cout << "Ошибка: Линия метро " << line << " уже существует" << endl;
        return;
    }

    if (N < 2) { //минимум 2 станции
        cout << "Ошибка: Линия метро не может содержать меньше 2 станций" << endl;
        return;
    }

    vector<string> stations; // станции линии
    set<string> single; // уникальные станции

    for (int i = 0; i < N; ++i) {

        string station;
        cin >> station;

        if (single.count(station)) { //проверка повторения станции
            cout << "Ошибка: Станция " << station << " повторяется" << endl;
            return;
        }

        single.insert(station); //добавление станции в set
        stations.push_back(station); //добавление станции в vector
    }

    metros[line] = stations; //сохранение линии

    cout << "Линия метро " << line << " создана" << endl;
}


//ЛИНИИ ЧЕРЕЗ СТАНЦИЮ
void metrosInStop(string station) {

    vector<string> cross; 

    for (const auto& metro : metros) { //перебор линий

        for (const auto& curStation: metro.second) { //перебор станций линии

            if (curStation == station) { //совпадение станции
                cross.push_back(metro.first); //добавление линии
            }
        }
    }

    if (cross.empty()) { //станция не найдена
        cout << "Ошибка: Станция " << station << " не найдена" << endl;
        return;
    }

    cout << "Линии метро, проходящие через станцию " << station << ": ";

    for (string line : cross) { 
        cout << line << " ";
    }

    cout << endl;
}


//СТАНЦИИ ЧЕРЕЗ ЛИНИИ
void stopsInMetro(string line) {

    if (!metros.count(line)) { //проверка существования линии
        cout << "Ошибка: Линия метро " << line << " не найдена" << endl;
        return;
    }

    cout << "Станции, которые проходит линия " << line << ":" << endl;

    for (auto station : metros[line]) { //перебор станций линии

        cout << station << ": ";

        bool anotherCross = false; //есть ли пересечения

        for (auto metro : metros) { //перебор линий

            if (metro.first == line)
                continue; //пропуск текущей линии

            for (auto curStation : metro.second) { //перебор станций другой линии

                if (curStation == station) { //совпадение станции
                    cout << metro.first << " ";
                    anotherCross = true;
                }
            }
        }

        if (!anotherCross) { //станций нет
            cout << " ";
        }
        cout << endl;
    }
}


//ВСЕ ЛИНИИ
void allMetros() {

    if (metros.empty()) { //проверка пустоты
        cout << "Ошибка: Линии метро не найдены" << endl;
        return;
    }

    for (const auto& metro : metros) { //перебор линий

        cout << "Линия " << metro.first << ": ";

        for (const auto& station : metro.second) { //вывод станций
            cout << station << " ";
        }
        cout << endl;
    }
}