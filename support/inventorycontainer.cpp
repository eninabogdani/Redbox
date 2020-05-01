// ---------------------------- inventorycontainer.cpp ------------------------
// Enina Bogdani, Josiah Zacharias
// Created: 03/14/20
// Modified: 03/16/20
// ----------------------------------------------------------------------------
// Purpose: This class implements an inventory container used to perform the
// actions required by the Inventory class: inserting, retrieving, and
// displaying the movies contained in an inventory.
// ----------------------------------------------------------------------------

#include "inventorycontainer.h"

// --------------------------- InventoryContainer -----------------------------
// Default constructor
// Takes no parameters
// Constructs an empty InventoryContainer
// ----------------------------------------------------------------------------

InventoryContainer::InventoryContainer() {
    data = new BinTree*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data[i] = new BinTree();
    }
}


// --------------------------- InventoryContainer -----------------------------
// Dstructor
// Takes no parameters
// Deletes the current InventoryContainer
// ----------------------------------------------------------------------------

InventoryContainer::~InventoryContainer() {
    for (int i = 0; i < SIZE; i++) {
        if (data[i] != nullptr) {
            delete data[i];
            data[i] = nullptr;
        }
    }
    
    delete[] data;
    data = nullptr;
}


// ------------------------------ insertMovie ---------------------------------
// Takes a pointer to a Movie object as parameter, and inserts that movie into
// the current Inventory object
// ----------------------------------------------------------------------------

void InventoryContainer::insertMovie(Movie* movie) {
    // Index 0 = Comedies
    // Index 1 = Dramas
    // Index 2: Classics
    string genre = movie->getGenre();
    if (genre == "F") {
        data[0]->insert(movie);
    } else if (genre == "D") {
        data[1]->insert(movie);
    } else {
        data[2]->insert(movie);
    }
}


// ----------------------------- retrieveMovie --------------------------------
// Takes a movie genre and info as parameters, and retrieves the matching
// movie from the current Inventory
// ----------------------------------------------------------------------------

Movie* InventoryContainer::retrieveMovie(string genre, string info) const {
    istringstream line(info);
    
    if (genre == "F") {
        string title;
        int year;
        getline(line, title, ',');
        ltrim(title);
        line >> year;
        Comedy dummyFunny = Comedy(title, year);
        Movie* returnMovie = nullptr;
        data[0]->retrieve(&dummyFunny, returnMovie);
        return returnMovie;
        
    } else if (genre == "D") {
        string director;
        string title;
        getline(line, director, ',');
        ltrim(director);
        getline(line, title, ',');
        ltrim(title);
        Drama dummyDrama = Drama(director, title);
        Movie* returnMovie = nullptr;
        data[1]->retrieve(&dummyDrama, returnMovie);
        return returnMovie;
        
    } else { // if genre == "C"
        string month;
        string year;
        string majorActor;
        getline(line, month, ' ');
        getline(line, year, ' ');
        int releaseMonth = stoi(month);
        int releaseYear = stoi(year);
        getline(line, majorActor);
        ltrim(majorActor);
        Classics dummyClassic = Classics(releaseMonth, releaseYear, majorActor);
        Movie* returnMovie = nullptr;
        data[2]->retrieve(&dummyClassic, returnMovie);
        return returnMovie;
    }
}


// ------------------------------ displayAll ----------------------------------
// Takes no parameters
// Displays all the movies in the current Inventory in the following order:
// Comedies, Dramas, Classics
// ----------------------------------------------------------------------------

void InventoryContainer::displayAll() {
    for (int i = 0; i < SIZE; i++) {
        cout << *data[i];
    }
}
