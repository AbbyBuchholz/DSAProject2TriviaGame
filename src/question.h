// //
// // Created by pokem on 10/25/2025.
// //
#include <iostream>
#include <string>
#pragma once
#include <vector>
#include <cctype>
using namespace std;

class Question {
    public:
        string question;
        string answer;
        string guess;
        string category;
        string subcategory;
        int variation;
        vector<string> details;
        string getGuess();
        bool checkGuess();
};

class Books: public Question {
    public:
        Books() {
            category = "Books";
        }
        string author;
        string title;
        string language;
        string genre;
        Books(string a, string t, string l, string g, int v);
        void createQuestion();
};

class Cities: public Question {
    public:
        Cities() {
            category = "Cities";
        }
        string name;
        string state;
        string country;
        string population;
        string elevation;
        string timeZone;
        string latitude;
        string longitude;
        Cities(string n, string s, string c, string p, string e, string tz, string la, string lo, int v);
        string decideSubCategory();
        void createQuestion();
};

class Movies1: public Question {
    public:
        Movies1() {
            category = "Movies";
        }
        string actor;
        string title;
        string year;
        Movies1(string a, string t, string y, int v);
        string decideSubCategory();
        void createQuestion();
};

class Movies2: public Question {
    public:
        Movies2() {
            category = "Movies";
        }
        string actor;
        string title;
        string genre;
        string year;
        string rating;
        Movies2(string a, string t, string g, string y, string r, int v);
        string decideSubCategory();
        void createQuestion();
};


class Songs: public Question {
    public:
        Songs() {
            category = "Songs";
        }
        string title;
        string album;
        string releaseDate;
        string artist;
        Songs(string t, string al, string r, string ar, int v);
        string decideSubCategory();
        void createQuestion();
};


Books::Books(string a, string t, string l, string g, int v) {
    category = "Books";
    author = a;
    title = t;
    language = l;
    genre = g;
    subcategory = "author";
    variation = v;
    details.push_back(author);
    details.push_back(title);
    details.push_back(language);
    details.push_back(genre);
    createQuestion();
}

void Books::createQuestion() {
    if (variation == 1) {
        question = "";
        answer = "";
    } else if (variation == 2) {
        question = "";
        answer = "";
    } else if (variation == 3) {
        question = "";
        answer = "";
    } else if (variation == 4) {
        question = "";
        answer = "";
    } else if (variation == 5) {
        question = "";
        answer = "";
    } else if (variation == 6) {
        question = "";
        answer = "";
    } else if (variation == 7) {
        question = "";
        answer = "";
    } else if (variation == 8) {
        question = "";
        answer = "";
    } else if (variation == 9) {
        question = "";
        answer = "";
    } else if (variation == 10) {
        question = "";
        answer = "";
    }
}


Cities::Cities(string n, string s, string c, string p, string e, string tz, string la, string lo, int v) {
    category = "Cities";
    name = n;
    state = s;
    country = c;
    population = p;
    elevation = e;
    timeZone = tz;
    latitude = la;
    longitude = lo;
    subcategory = "state";
    variation = v;
    details.push_back(name);
    details.push_back(state);
    details.push_back(country);
    details.push_back(population);
    details.push_back(elevation);
    details.push_back(timeZone);
    details.push_back(latitude);
    details.push_back(longitude);
    createQuestion();
}

void Cities::createQuestion() {
    if (variation == 1) {
        question = "";
        answer = "";
    } else if (variation == 2) {
        question = "";
        answer = "";
    } else if (variation == 3) {
        question = "";
        answer = "";
    } else if (variation == 4) {
        question = "";
        answer = "";
    } else if (variation == 5) {
        question = "";
        answer = "";
    } else if (variation == 6) {
        question = "";
        answer = "";
    } else if (variation == 7) {
        question = "";
        answer = "";
    } else if (variation == 8) {
        question = "";
        answer = "";
    } else if (variation == 9) {
        question = "";
        answer = "";
    } else if (variation == 10) {
        question = "";
        answer = "";
    }
}

Movies1::Movies1(string a, string t, string y, int v) {
    category = "Movies";
    actor = a;
    title = t;
    year = y;
    variation = v;
    subcategory = decideSubCategory();
    details.push_back(actor);
    details.push_back(title);
    details.push_back(year);
}

string Movies1::decideSubCategory() {
    return "title";
}

void Movies1::createQuestion() {
    if (variation == 1) {
        question = "";
        answer = "";
    } else if (variation == 2) {
        question = "";
        answer = "";
    } else if (variation == 3) {
        question = "";
        answer = "";
    } else if (variation == 4) {
        question = "";
        answer = "";
    } else if (variation == 5) {
        question = "";
        answer = "";
    } else if (variation == 6) {
        question = "";
        answer = "";
    } else if (variation == 7) {
        question = "";
        answer = "";
    } else if (variation == 8) {
        question = "";
        answer = "";
    } else if (variation == 9) {
        question = "";
        answer = "";
    } else if (variation == 10) {
        question = "";
        answer = "";
    }
}

Movies2::Movies2(string a, string t, string g, string y, string r, int v) {
    category = "Movies";
    actor = a;
    title = t;
    genre = g;
    year = y;
    rating = r;
    variation = v;
    subcategory = decideSubCategory();
    details.push_back(actor);
    details.push_back(title);
    details.push_back(genre);
    details.push_back(year);
    details.push_back(rating);
}

string Movies2::decideSubCategory() {
    return "title";
}

void Movies2::createQuestion() {
    if (variation == 1) {
        question = "";
        answer = "";
    } else if (variation == 2) {
        question = "";
        answer = "";
    } else if (variation == 3) {
        question = "";
        answer = "";
    } else if (variation == 4) {
        question = "";
        answer = "";
    } else if (variation == 5) {
        question = "";
        answer = "";
    } else if (variation == 6) {
        question = "";
        answer = "";
    } else if (variation == 7) {
        question = "";
        answer = "";
    } else if (variation == 8) {
        question = "";
        answer = "";
    } else if (variation == 9) {
        question = "";
        answer = "";
    } else if (variation == 10) {
        question = "";
        answer = "";
    }
}

Songs::Songs(string t, string al, string r, string ar, int v) {
    category = "Songs";
    title = t;
    album = al;
    releaseDate = r;
    artist = ar;
    variation = v;
    subcategory = decideSubCategory();
    details.push_back(title);
    details.push_back(album);
    details.push_back(releaseDate);
    details.push_back(artist);
}

string Songs::decideSubCategory() {
    int random = rand() % 2;
    if (random == 0) {
        return "album";
    } else if (random == 1) {
        return "artist";
    }
    return "";
}

void Songs::createQuestion() {
    if (variation == 1) {
        question = "";
        answer = "";
    } else if (variation == 2) {
        question = "";
        answer = "";
    } else if (variation == 3) {
        question = "";
        answer = "";
    } else if (variation == 4) {
        question = "";
        answer = "";
    } else if (variation == 5) {
        question = "";
        answer = "";
    } else if (variation == 6) {
        question = "";
        answer = "";
    } else if (variation == 7) {
        question = "";
        answer = "";
    } else if (variation == 8) {
        question = "";
        answer = "";
    } else if (variation == 9) {
        question = "";
        answer = "";
    } else if (variation == 10) {
        question = "";
        answer = "";
    }
}

bool Question::checkGuess() {
    string lowerCaseAnswer = "";
    string lowerCaseGuess = "";
    for (int i = 0; i < answer.length(); i++) {
        if (isalpha(answer[i])) {
            lowerCaseAnswer += tolower(answer[i]);
        } else {
            lowerCaseAnswer += answer[i];
        }
    }
    for (int j = 0; j < guess.length(); j++) {
        if (isalpha(guess[j])) {
            lowerCaseGuess += tolower(guess[j]);
        } else {
            lowerCaseGuess += guess[j];
        }
    }
    return lowerCaseAnswer == lowerCaseGuess;
}


std::string helloString = "hello world";