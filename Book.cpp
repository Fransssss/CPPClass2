// Fransiskus Agapa

#include "Book.h"
#include "sstream"

using std::stringstream;

// default constructor
Book::Book()
{
    this->_title = "NoTitle";
    this->_author = "NoAuthor";
    this->_year = -1;
}

Book::Book(const string &theTitle, const string &theAuthor, const int &theYear)
{
    this->_title = theTitle;
    this->_author = theAuthor;
    this->_year = theYear;
}

string Book::GetTitle() const
{
    return _title;
}

string Book::GetAuthor() const
{
    return _author;
}

int Book::GetYear() const
{
    return _year;
}

string Book::lineJson() const
{
    stringstream asJson;
    asJson << "{\"Title\":\"" << _title << "\", \"Author\":\"" << _author << "\", \"Year\":" << _year << "}";
    return asJson.str();
}
