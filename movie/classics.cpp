// -------------------------------- classics.cpp ------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/08/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a classic movie. It will contain all
// information related to the Movie and allow for comparisons to other Drama
// objects.
// ----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int)

#include "classics.h"


// ------------------------------- Classics -----------------------------------
// Constructor
// Takes a string containing the movie info as parameter
// Constructs a Classics object and populates the genre, title, director,
// majorActor, releaseMonth, and releaseYear field
// Used to create a partial object for compareTo
// ----------------------------------------------------------------------------
Classics::Classics(string info) {
    istringstream line(info);
    
    //get genre
    getline(line, genre, ',');
    
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
    
    string firstName, lastName;
    getline(line, firstName, ' ');
    getline(line, firstName, ' ');
    getline(line, lastName, ' ');
    
    majorActor = firstName + " " + lastName;
    
    string month;
    getline(line, month, ' ');
    releaseMonth = stoi(month);
    
    string year;
    getline(line, year, ' ');
    releaseYear = stoi(year);
    
    format = "D";
}


// ------------------------------- Classics -----------------------------------
// Constructor
// Takes release month and year ints, and an actor name string as parameters
// Constructs a Classics object and populates the release month and year, and
// main actor fields
// Used to create a partial object for compareTo
// ----------------------------------------------------------------------------

Classics::Classics(int month, int year, string actor) {
    releaseMonth = month;
    releaseYear = year;
    majorActor = actor;
    genre = "C";
}


// ----------------------------- getMajorActor --------------------------------
// Takes no parameters
// Returns the major actor
// -----------------------------------------

string Classics::getMajorActor() {
    return majorActor;
}


// ----------------------------- getReleaseMonth ------------------------------
// Takes no parameters
// Returns the release month
// ---------------------------------------

int Classics::getReleaseMonth() {
    return releaseYear;
}


// ------------------------------ compareTo -----------------------------------
// Takes a Classics object as parameter, and compares it to the current object
// based on their release dates and major actors
// Returns -1 smaller, 0 is equal, 1 if greater
// ----------------------------------------------------------------------------

int Classics::compareTo(Movie* otherClassic) {
    if (otherClassic != nullptr && otherClassic->getGenre() != "C") {
        return -2;
    }
    Classics* other = dynamic_cast<Classics*>(otherClassic);
    if (releaseYear > other->releaseYear) {
        return 1;
    } else if (releaseYear < other->releaseYear) {
        return -1;
    }
    if (releaseMonth > other->releaseMonth) {
        return 1;
    } else if (releaseMonth < other->releaseMonth) {
        return -1;
    }
    if (majorActor > other->majorActor) {
        return 1;
    } else if (majorActor < other->majorActor) {
        return -1;
    }
    return 0;
}


// ------------------------------ operator<< ----------------------------------
// Displays a Classic in the following format:
// Genre, Stock, Director, Title, Major actor, Release date
// ---------------------------------------------------------------------------- 

// C, Stock, Director, Title, Major actor Release date
void Classics::print(ostream& output) const {
    output
    << "Genre: " << genre
    << " Stock: " << stockInStore
    << " Director: " << director
    << " Title: " << title
    << " Major Actor: " << majorActor
    << " Release date: " << releaseMonth << " " << releaseYear
    << endl;
}

