//
//  Header.h
//  Redbox
//
//  Created by Josiah Zacharias on 3/16/20.
//  Copyright © 2020 Josiah Zacharias. All rights reserved.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <algorithm>
#include <cctype>
#include <locale>

// trim string from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

#endif /* STRINGUTILS_H */
