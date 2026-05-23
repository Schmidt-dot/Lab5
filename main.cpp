#include <iostream>
#include <string>

using namespace std;

//КОМАНДЫ
enum class commands {
    CREATE_METRO, //Создать линию и станции
    METROS_IN_STOP, //Какие линии проходят через станцию
    STOPS_IN_METRO, //Какие станции проходят через линию
    METROS, //Отобразить все линии с указанием станций
    EXIT, //Выход
    UNKNOWN
};

// СТРОКА В КОМАНДУ
commands toDo(const string& line) {
    if (line == "CREATE_METRO") return commands::CREATE_METRO;
    if (line == "METROS_IN_STOP") return commands::METROS_IN_STOP;
    if (line == "STOPS_IN_METRO") return commands::STOPS_IN_METRO;
    if (line == "METROS") return commands::METROS;
    if (line == "EXIT") return commands::EXIT;
    return commands::UNKNOWN;
}

// ВЫБОР ДЕЙСТВИЯ
void choice(commands action) {

    switch (action) {

        case commands::CREATE_METRO:
        {
            string line;
            int N;

            cin >> line >> N;

            createMetro(line, N);

            break;
        }

        case commands::METROS_IN_STOP:
        {
            string station;

            cin >> station;

            metrosInStop(station);

            break;
        }

        case commands::STOPS_IN_METRO:
        {
            string line;

            cin >> line;

            stopsInMetro(line);

            break;
        }

        case commands::METROS:
        {
            allMetros();

            break;
        }

        case commands::EXIT:
        {
            exit(0);
        }

        default:
        {
            cout << "Ошибка: Неизвестная команда" << endl;
        }
    }
}

int main() {

    cout << "Введите команду: " << endl;

    string line;

    while (true) {

        cin >> line;

        commands action = toDo(line);

        choice(action);
    }

    return 0;
}