// Author: Fransiskus Agapa
// 9/3/22
// Practices make improvement - Have Fun !!!
// :)

// =======================
// simple program for user to access
// most popular children books and its authors AND
// user can speficy a certain data to display based on its index / number in database
// =======================

#include <iostream>
#include "fstream"
#include "Book.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::stoi;

int main()
{
    string choice;                                                 // user choice
    Book* theBook = nullptr;                                       // class pointer to new allocated memory
    bool hasChoseOptOne = false;                                   // make sure user has chosen number one first
    ifstream inFS;                                                 // input file stream
    cout << endl << "== Famous Children Book Database ==" << endl;
    cout << "1. Display database" << endl;
    cout << "e. Exit" << endl;
    cout << "choice: ";
    cin >> choice;
    cout << endl;

    while(choice != "e" and choice != "E")
    {
        if (choice == "1")
        {
            int numberingLine = 1;                                               // numbering line
            cout << endl << "= Famous Children Book =" << endl << endl;
            inFS.open("../DatabaseChildrenBooks");                               // open file
            if (inFS.is_open())                                                  // check if file is open
            {
                string line;                                                     // get each line one at a time
                getline(inFS, line);                                             // skip subject(title, author, yera)
                while (getline(inFS, line))
                {
                    int stQuotePos = 0;                                           // pos of first quote
                    int ndQuotePos = 0;                                           // pos of second quote
                    int commaPos = 0;                                             // pos of comma
                    stQuotePos = line.find('"');
                    ndQuotePos = line.find('"',stQuotePos + 1);                  // start search from / after the position of first quote
                    commaPos = line.find(',', ndQuotePos + 1);                   // plus one to start from space after second quotes

                    // title
                    string title;
                    title = line.substr(stQuotePos, (ndQuotePos - stQuotePos) + 1);
                    // author
                    string author;
                    author = line.substr(ndQuotePos + 1, (commaPos - ndQuotePos) - 1);
                    // year
                    string strYear;
                    int year;
                    strYear = line.substr(commaPos + 1, line.size() - commaPos);
                    year = stoi(strYear);

                    theBook = new Book(title, author, year);
                    cout << numberingLine << ". Title: " << theBook->GetTitle() << endl;
                    cout << "   Author: " << theBook->GetAuthor() << endl;
                    cout << "   Year: " << theBook->GetYear() << endl << endl;
                    numberingLine++;
                }
                hasChoseOptOne = true;                                             // indicate user has seen database at least once
                inFS.close();                                                      // close after reading
            }
            else                                                                   // if file cannot be opened
            {
                cout << endl << "[ Fila Cannot be Opened ]" << endl;
            }
        }
        else if (choice == "2")
        {
            if (!hasChoseOptOne)                                                   // user has to see data at least once
            {
                cout << endl << "[ Invalid choice ]" << endl;
            }
            else
            {
                int numberPicked;                                                  // number of line user wants to pick / see / be displayed
                int numberLineToGet = 0;                                           // number of line to get from file
                string line;                                                       // line / data to display / the one that user request
                cout << endl << "Input the number of line: ";
                cin >> numberPicked;
                inFS.open("../DatabaseChildrenBooks");                            // open file
                if (inFS.is_open()) {
                    while (getline(inFS, line))
                    {
                        if (numberLineToGet == numberPicked)
                        {
                            int stQuotePos = 0;                                   // pos of first quote
                            int ndQuotePos = 0;                                   // pos of second quote
                            int commaPos = 0;                                     // pos of comma
                            stQuotePos = line.find('"');
                            ndQuotePos = line.find('"', stQuotePos + 1);          // start search from / after the position of first quote
                            commaPos = line.find(',', ndQuotePos + 1);            // plus one to start from space after second quotes

                            // title
                            string title;
                            title = line.substr(stQuotePos, (ndQuotePos - stQuotePos) + 1);

                            // author
                            string author;
                            author = line.substr(ndQuotePos + 1, (commaPos - ndQuotePos) - 1);

                            // year
                            string strYear;
                            int year;
                            strYear = line.substr(commaPos + 1, line.size() - commaPos);
                            year = stoi(strYear);

                            theBook = new Book(title, author, year);
                            cout << endl << numberPicked << ". Title: " << theBook->GetTitle() << endl;
                            cout << "   Author: " << theBook->GetAuthor() << endl;
                            cout << "   Year: " << theBook->GetYear() << endl << endl;
                        }
                        numberLineToGet++;
                    }
                    if (numberPicked > numberLineToGet)                            // line cannot be found
                    {
                        cout << endl << "[ Data cannot be found ]" << endl;
                    }
                    inFS.close();                                                  // close file
                }
            }
        }
        else
        {
            cout << endl << "[ Invalid choice ]" << endl;
        }

        if(hasChoseOptOne)                                                         // indicate user has seen database at least once
        {
            cout << endl << "== Famous Children Book Database ==" << endl;
            cout << "1. Display database" << endl;
            cout << "2. Display a specific book " << endl;
            cout << "e. Exit" << endl;
            cout << "choice: ";
            cin >> choice;
            cout << endl;
        }
        else
        {
            cout << endl << "== Famous Children Book Database ==" << endl;
            cout << "1. Display database" << endl;
            cout << "e. Exit" << endl;
            cout << "choice: ";
            cin >> choice;
            cout << endl;
        }
    }


    if(choice == "e" or choice == "E")
    {
        cout << endl << "== Exit Program ==" << endl;
    }

    return 0;
}
