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
    Book();                                                                                     // user defined default constructor
    Book(const string& theTitle, const string& theAuthor, const int& theYear);                  // user defined constructor
    string GetTitle() const;
    string GetAuthor() const;
    int GetYear() const;
    string lineJson() const;
};


#endif //CPPCLASS2_BOOK_H
