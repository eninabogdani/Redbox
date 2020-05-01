// --------------------------------- drama.cpp --------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/08/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a drama movie. It will contain all
// information related to the Movie and allow for comparisons to other Drama
// objects.
// ----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int)

#include "drama.h"

// -------------------------------- Drama -------------------------------------
// Constructor
// Takes a string containing the movie info as parameter
// Constructs a Drama object and populates the genre, title, director, and
// releaseYear fields
// ----------------------------------------------------------------------------

Drama::Drama(string info) {
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


// -------------------------------- Drama -------------------------------------
// Constructor
// Takes a director name string and movie title string as parameters
// Constructs a Drama object and populates the director and title fields
// Used to create a partial object for compareTo
// ----------------------------------------------------------------------------

Drama::Drama(string director, string title) {
    this->director = director;
    this->title = title;
    genre = "D";
}


// ------------------------------ compareTo -----------------------------------
// Takes a Drama object as parameter, and compares it to the current object
// based on their titles and release years
// Returns -1 smaller, 0 is equal, 1 if greater
// ----------------------------------------------------------------------------

int Drama::compareTo(Movie* otherDrama) {
    if (otherDrama != nullptr && otherDrama->getGenre() != "D") {
        return -2;
    }
    Drama* other = dynamic_cast<Drama*>(otherDrama);
    if (director > other->director) {
        return 1;
    } else if (title < other->title) {
        return -1;
    }
    
    if (title > other->title) {
        return 1;
    } else if (releaseYear < other->releaseYear) {
        return -1;
    }
    
    return 0;
    
}


// ------------------------------ operator<< ----------------------------------
// Displays a Drama in the following format:
// Genre, Stock, Director, Title, Release year
// ----------------------------------------------------------------------------


// D, Stock, Director, Title, Year it released
void Drama::print(ostream& output) const {
    output
    << "Genre: " << genre
    << " Stock: " << stockInStore
    << " Director: " << director
    << " Title: " << title
    << " Release Year: " << releaseYear
    << endl;
}

