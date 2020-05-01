// ----------------------------- moviefactory.cpp -----------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/06/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements a factory that is responsible for determining
// what type of Movie object should be instantiated based on provided
// input. Allows for dynamic binding of Movie objects.
// ----------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of
//    associated Movie genre

#include "moviefactory.h"
#include <string>


// ------------------------------ createMovie ---------------------------------
// Takes a genre character and a movie info string as parameters
// Instantiates the appropriate type of movie based on the given genre
// ----------------------------------------------------------------------------

Movie* MovieFactory::createMovie(char genre, string info) {
    switch (genre) {
        case 'F':
            return new Comedy(info);
        case 'D':
            return new Drama(info);
        case 'C':
            return new Classics(info);
        default:
            cout << "ERROR: " << genre << " is not a valid movie genre. ";
            return nullptr;
    }
}

