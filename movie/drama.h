// ---------------------------------- drama.h ---------------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 02/23/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class defines a drama movie. It will contain all information
// related to the Movie and allow for comparisons to other Drama objects.
// ----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int)


#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

using namespace std;

class Drama: public Movie {
    
    // Overloaded << : prints a movie
    //friend ostream& operator<<(ostream&, const Movie&);
    
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates a Drama object and populates the genre, title,
        // director, and releaseYear fields
        Drama(string);
    
        // Constructor: Creates a Drama object and populates the title
        // and release year fields
        Drama(string, string);
    
        // Compares this object to other Drama objects
        virtual int compareTo(Movie*);
    
    protected:
        virtual void print(ostream &) const;
};

#endif
