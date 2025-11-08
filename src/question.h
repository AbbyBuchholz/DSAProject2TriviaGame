// //
// // Created by pokem on 10/25/2025.
// //
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#pragma once

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
        string authorFirstName;
        string authorLastName;
        string title;
        string language;
        vector<string> genre;
        Books(string aFN, string aLN, string t, string l, vector<string> g, int v);
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
        string actorFirstName;
        string actorLastName;
        string title;
        string year;
        Movies1(string aFN, string aLN, string t, string y, int v);
        string decideSubCategory();
        void createQuestion();
};

class Movies2: public Question {
    public:
        Movies2() {
            category = "Movies";
        }
        string actorFirstName;
        string actorLastName;
        string title;
        vector<string> genre;
        string year;
        string rating;
        Movies2(string aFN, string aLN, string t, vector<string> g, string y, string r, int v);
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