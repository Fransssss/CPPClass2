// Fransiskus Agapa

#ifndef CPPCLASS2_BOOK_H
#define CPPCLASS2_BOOK_H

#include "string"
using std::string;

class Book
{
private:
    string _title;
    string _author;
    int _year;
public:
    Book();
    Book(const string& theTitle, const string& theAuthor, const int& theYear);
    string GetTitle() const;
    string GetAuthor() const;
    int GetYear() const;
    string lineJson() const;
};


#endif //CPPCLASS2_BOOK_H
