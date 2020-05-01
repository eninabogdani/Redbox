// --------------------------------- movie.cpp --------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/06/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a singular Movie object. The movie will
// contain information on the genre, director, title, release year, and current
// stock in the store. Depending on the type of movie object created, more
// information may also be stored. All Movie objects will be comparable to
// other Movies of the same genre.
// ----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string)
//       In addition, the following movie genre's input will also contain:
//         Comedy: releaseYear(int)
//         Drama: releaseYear(int)
//         Classics: majorActor(string) releaseMonth(int) releaseYear(int)
//  - Input data is correctly formatted.

#include "movie.h"

// -------------------------------- Movie -------------------------------------
// Default constructor
// Takes no parameters
// Constructs an empty Movie object
// ----------------------------------------------------------------------------

Movie::Movie() {
    genre = "";
    stockInStore = 0;
    director = "";
    title = "";
    releaseYear = 0;
    format = "";
}

// TODO: need?
Movie::~Movie() {
    
}


// ------------------------------- getGenre -----------------------------------
// Takes no parameters
// Returns the movie genre
// ----------------------------------------------------------------------------

string Movie::getGenre() {
    return genre;
}


// ------------------------------- getDirector --------------------------------
// Takes no parameters
// Returns the movie director
// ----------------------------------------------------------------------------

string Movie::getDirector() {
    return director;
}


// -------------------------------- getTitle ----------------------------------
// Takes no parameters
// Returns the movie title
// ----------------------------------------------------------------------------

string Movie::getTitle() {
    return title;
}


// ----------------------------- getReleaseYear -------------------------------
// Takes no parameters
// Returns the movie release year
// ----------------------------------------------------------------------------

int Movie::getReleaseYear() {
    return releaseYear;
}


// ----------------------------- getStockInStore ------------------------------
// Takes no parameters
// Returns the number of available copies of the movie
// ----------------------------------------------------------------------------

int Movie::getStockInStore() {
    return stockInStore;
}


// ----------------------------- increaseStock --------------------------------
// Takes no parameters
// Increases the stock by 1
// ----------------------------------------------------------------------------

void Movie::increaseStock() {
    stockInStore++;
}


// ----------------------------- decreaseStock --------------------------------
// Takes no parameters
// Increases the stock by 1
// ----------------------------------------------------------------------------

void Movie::decreaseStock() {
    stockInStore--;
}


ostream& operator<<(ostream& output, const Movie& outputMovie) {
    outputMovie.print(output);
    return output;
}
