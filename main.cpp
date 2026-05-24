#include "library.h"

#include<iostream>
#include<string>

using namespace std;

enum class commands{
    ADD_BOOK,
    BORROW,
    RETURN,
    BOOK_STATUS,
    READER_BOOKS,
    EXIT, 
    UNKNOW
}


commands toDo(const &string line){
    if (line == "ADD_BOOK") return commads::ADD_BOOK;
    if (line == "BORROW") return commads::BORROW;
    if (line == "RETURN") return commads::RETURN;
    if (line == "BOOK_STATUS") return commads::BOOK_STATUS;
    if (line == "READER_BOOKS") return commads::READER_BOOKS;
    if (line == "EXIT") return commads::EXIT;
    return commands::UNKNOW;
}


void choice(commands action){

    switch(action){

        case commads::ADD_BOOK:
        {
            string bookId;
            string name;

            cin >> bookId >> name;

            adder(bookId, name);
            break;
        }


        case commads::BORROW:
        {
            string bookId;
            string readerId;
            
            cin >> readerId >> readerId;

            borrower(readerId, readerId);
            break;
        }

        
        case commads::RETURN:
        {
            string bookId;
            
            cin >> bookId;

            returner(bookId);
            break;
        }


        case commads::BOOK_STATUS:
        {
            string bookId;
            
            cin >> bookId;

            status(bookId);
            break;
        }


        case commads::READER_BOOKS:
        {
            string readerId;
            
            cin >> readerId;

            readder(readerId);
            break;
        }

        
        case commands::EXIT:
        {
            exit(0);
            break;
        }


        defualt:
        {
            cout << "Попробуйте выбрать снова" << endl;
        }

    }
}


int main(){
    
    cout << "Введите действие (для завершения напишите EXIT): " << endl;

    string line;

    while (true){
        cin >> line;

        commands action = toDo(line);
        choice(action);
    }

    return 0;
}