// -------------------------------- classics.h ---------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 02/25/20
// -----------------------------------------------------------------------------
// Purpose: This class defines a classic movie. It will contain all information
// related to the Movie and allow for comparisons to other Classics objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string)
//     majorActor(string) releaseMonth(int) releaseYear(int)

#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

using namespace std;

class Classics : public Movie {
    
    // Overloaded << : prints a movie
    friend ostream& operator<<(ostream& output, const Movie& outputMovie);
    
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates a Classics object and populates the genre,
        // title, director, majorActor, releaseMonth, and releaseYear fields
        Classics(string);
    
        Classics(int, int, string);
    
        // Returns the major actor
        string getMajorActor();
        // Returns the movie release month
        int getReleaseMonth();
        // Compares this object to other Classics objects
        virtual int compareTo(Movie*);
    
    private:
    
    protected:
        virtual void print(ostream &) const;
};

#endif
