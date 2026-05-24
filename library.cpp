#include "library.h"

#include <iostream>
#include <cctype>

using namespace std;


//ВАЛИДНОСТЬ ID КНИГИ
bool isOkBook(string bookId){

    if (bookId.size() < 2 || bookId[0] != 'B'){
        return false;
    }

    for (int i = 1; i < bookId.size(); ++i){
        if (!isdigit(bookId[i])){
            return false;
        }
    }
    return true;
}


//ВАЛИДНОСТЬ ID ЧИТАТЕЛЯ
bool isOkReader(string readerId){

    if (readerId.size() < 2 || readerId[0] != 'R'){
        return false;
    }

    for (int i = 1; i < readerId.size(); ++i){
        if (!isdigit(readerId[i])){
            return false;
        }
    }
    return true;
}


//ДОБАВИТЬ КНИГУ В БИБЛИОТЕКУ
void adder(Library& library, string bookId, string name){

    if (!isOkBook(bookId)){
        cout << "Ошибка: Неверный идентификатор (пример: B111)" << endl;
        return;
    }

    if (library.books.count(bookId)){
        cout << "Ошибка: Книга с идентификатором " << bookId << " уже существует" << endl;
        return;
    }

    Book book;

    book.id = bookId;
    book.name = name;

    library.books[bookId] = book;

    cout << "Книга " << bookId << " " << name << " добавлена" << endl;
}


//ВЫДАТЬ КНИГУ ЧИТАТЕЛЮ
void borrower(Library& library, string bookId, string readerId){

    if (!isOkBook(bookId)){
        cout << "Ошибка: Неверный идентификатор (пример: B111)" << endl;
        return;
    }

    if (!isOkReader(readerId)){
        cout << "Ошибка: Неверный идентификатор (пример: R111)" << endl;
        return;
    }

    if (!library.books.count(bookId)){
        cout << "Ошибка: Книги с идентификатором " << bookId << " не существует" << endl;
        return;
    }

    Book& book = library.books[bookId];

    if (book.status){
        cout << "Ошибка: Книга уже находится у читателя" << endl;
        return;
    }

    Reader& reader = library.readers[readerId];

    reader.id = readerId;

    if (reader.books.size() >= 2){
        cout << "Ошибка: Книгу нельзя выдать читателю " << readerId << ", поскольку у него превышен лимит" << endl;
        return;
    }

    reader.books.push_back(bookId);

    book.status = true;
    book.readerId = readerId;

    cout << "Книга " << bookId << " выдана читателю " << readerId << endl;
}


//ВЕРНУТЬ КНИГУ В БИБЛИОТЕКУ
void returner(Library& library, string bookId){

    if (!isOkBook(bookId)){
        cout << "Ошибка: Неверный идентификатор (пример: B111)" << endl;
        return;
    }

    if (!library.books.count(bookId)){
        cout << "Ошибка: Книги с идентификатором " << bookId << " не существует" << endl;
        return;
    }

    Book& book = library.books[bookId];

    if (!book.status){
        cout << "Ошибка: Книга уже находится в библиотеке" << endl;
        return;
    }

    Reader& reader = library.readers[book.readerId];

    vector<string> newBooks;

    for (string id : reader.books){
        if (id != bookId){
            newBooks.push_back(id);
        }
    }

    reader.books = newBooks;

    book.status = 0;
    book.readerId = "";

    cout << "Книга " << bookId << " возвращена в библиотеку" << endl;
}


//ГДЕ КНИГА
void status(Library& library, string bookId){

    if (!isOkBook(bookId)){
        cout << "Ошибка: Неверный идентификатор (пример: B111)" << endl;
        return;
    }

    if (!library.books.count(bookId)){
        cout << "Ошибка: Книги с идентификатором " << bookId << " не существует" << endl;
        return;
    }

    Book& book = library.books[bookId];

    if (!book.status){
        cout << "Книга " << bookId << " находится в библиотеке" << endl;
    }
    else{
        cout << "Книга " << bookId << " находится у читателя " << book.readerId << endl;
    }
}


//ИНФОРМАЦИЯ О ЧИТАТЕЛЕ
void reader(Library& library, string readerId){

    if (!isOkReader(readerId)){
        cout << "Ошибка: Неверный идентификатор (пример: R111)" << endl;
        return;
    }

    if (!library.readers.count(readerId) || library.readers[readerId].books.empty()){
        cout << "Читатель " << readerId << " имеет книги: -" << endl;
        return;
    }

    Reader& reader = library.readers[readerId];


    cout << "Читатель " << readerId << " имеет книги: ";

    for (int i = 0; i < reader.books.size(); ++i){
        cout << reader.books[i] << " ";
    }
    cout << endl;
}