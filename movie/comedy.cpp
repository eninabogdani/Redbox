// --------------------------------- comedy.cpp -------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/08/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a comedy movie. It will contain all
// information related to the Movie and allow for comparisons to other Drama
// objects.
// ----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int)


#include "comedy.h"


// -------------------------------- Comedy ------------------------------------
// Constructor
// Takes a string containing the movie info as parameter
// Constructs a Comedy object and populates the genre, title, director, and
// releaseYear fields
// ----------------------------------------------------------------------------

Comedy::Comedy(string info) {
    istringstream line(info);
    
    //get genre
    getline(line, genre, ',');
    ltrim(genre);

    //get stock
    string stock;
    getline(line, stock, ',');
    stockInStore = stoi(stock);

    //get director
    getline(line, director, ',');
    ltrim(director);

    //get title
    getline(line, title, ',');
    ltrim(title);
    
    string year;
    getline(line, year, ' ');
    getline(line, year, ' ');
    releaseYear = stoi(year);
    
    format = "D";
}


// -------------------------------- Comedy ------------------------------------
// Constructor
// Takes a title string and a release year int as parameters
// Constructs a Comedy object and populates the title and release year fields
// Used to create a partial object for compareTo
// ----------------------------------------------------------------------------

Comedy::Comedy(string title, int year) {
    this->title = title;
    releaseYear = year;
    genre = "F";
}


// ------------------------------ compareTo -----------------------------------
// Takes a Comedy object as parameter, and compares it to the current object
// based on their directors and titles
// Returns -1 smaller, 0 is equal, 1 if greater
// ----------------------------------------------------------------------------

int Comedy::compareTo(Movie* otherComedy) {
    if (otherComedy != nullptr && otherComedy->getGenre() != "F") {
        return -2;
    }
    Comedy* other = dynamic_cast<Comedy*>(otherComedy);
    if (title > other->title) {
        return 1;
    } else if (title < other->title) {
        return -1;
    }
    if (releaseYear > other->releaseYear) {
        return 1;
    } else if (releaseYear < other->releaseYear) {
        return -1;
    }
    return 0;
}


// ------------------------------ operator<< ----------------------------------
// Displays a Comedy in the following format:
// Genre, Stock, Director, Title, Release year
// ----------------------------------------------------------------------------


// F, Stock, Director, Title, Year it released
void Comedy::print(ostream& output) const {
    output
    << "Genre: " << genre
    << " Stock: " << stockInStore
    << " Director: " << director
    << " Title: " << title
    << " Release Year: " << releaseYear
    << endl;
}

