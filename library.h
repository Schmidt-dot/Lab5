#pragma once

#include<string>
#include<vector>
#include<map>

//ХРАНИЛИЩЕ
struct Book {
    std::string id;
    std::string name;
    bool status = 0; //0 - library, 1 - reader
    std::string readerId;
};

struct Reader {
    std::string id;
    std::vector<std::string> books;
};

struct Library {
    std::map<std::string, Book> books;
    std::map<std::string, Reader> readers;
};


//Ф-ИИ
void adder(std::string bookId, std::string name);

void borrower(std::string bookId, std::string readerId);

void returner(std::string bookId);

void status(std::string bookId);

void readder(std::string readerId);
