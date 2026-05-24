#include "library.h"

#include <iostream>
#include <string>

using namespace std;

enum class Commands{
    ADD_BOOK,
    BORROW,
    RETURN,
    BOOK_STATUS,
    READER_BOOKS,
    EXIT,
    UNKNOWN
};

Commands toDo(const string& line){

    if (line == "ADD_BOOK") return Commands::ADD_BOOK;
    if (line == "BORROW") return Commands::BORROW;
    if (line == "RETURN") return Commands::RETURN;
    if (line == "BOOK_STATUS") return Commands::BOOK_STATUS;
    if (line == "READER_BOOKS") return Commands::READER_BOOKS;
    if (line == "EXIT") return Commands::EXIT;

    return Commands::UNKNOWN;
}

void choice(Commands action, Library& library){

    switch(action){

        case Commands::ADD_BOOK:
        {
            string bookId;
            string name;

            cin >> bookId >> name;

            adder(library, bookId, name);

            break;
        }

        case Commands::BORROW:
        {
            string bookId;
            string readerId;

            cin >> bookId >> readerId;

            borrower(library, bookId, readerId);

            break;
        }

        case Commands::RETURN:
        {
            string bookId;

            cin >> bookId;

            returner(library, bookId);

            break;
        }

        case Commands::BOOK_STATUS:
        {
            string bookId;

            cin >> bookId;

            status(library, bookId);

            break;
        }

        case Commands::READER_BOOKS:
        {
            string readerId;

            cin >> readerId;

            reader(library, readerId);

            break;
        }

        case Commands::EXIT:
        {
            exit(0);
        }

        default:
        {
            cout << "Попробуйте выбрать снова" << endl;
        }
    }
}

int main(){

    Library library;

    cout << "Введите действие (для завершения напишите EXIT): " << endl;

    string line;

    while (true){

        cin >> line;

        Commands action = toDo(line);

        choice(action, library);
    }

    return 0;
}