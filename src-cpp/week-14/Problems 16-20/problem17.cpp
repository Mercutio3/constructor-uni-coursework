#include <iostream>

class Book {
    private:
        char * title;
        int pages;
    public:
        Book(const Book&);
        Book(const char * t, int p);
        Book();
};

Book::Book(const Book& b){
    title = new char[30];
    strcpy(title, b.title);
    pages = b.pages;
}
//Without strcpy, the defualt copy constructor will not copy the title info
//correctly, as it will still point to the same location.