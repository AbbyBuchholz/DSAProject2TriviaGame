// //
// // Created by pokem on 10/25/2025.
// //
#include <iostream>
#include <string>
#pragma once
// #include <vector>
// using namespace std;
//
//
//
// class Question {
//     public:
//         string question;
//         string answer;
//         string guess;
//         string category;
//         string subcategory;
//         vector<string> details;
//         string getGuess();
//         bool checkGuess();
//     private:
//
// };
//
// class Books: public Question {
//     public:
//         Books() {
//             category = "Books";
//         }
//         string author;
//         string title;
//         string authorBirth;
//         string authorDeath;
//         string genre;
//         string subject;
//         Books(string a, string t, string ab, string ad, string g, string s);
//         void createQuestion();
// };
//
// class Cities: public Question {
//     public:
//         Cities() {
//             category = "Cities";
//         }
//         string name;
//         string state;
//         string population;
//         Cities(string n, string s, string p);
//         string decideSubCategory();
//         void createQuestion();
// };
//
// class Movies: public Question {
//     public:
//         Movies() {
//             category = "Movies";
//         }
//         string actor;
//         string title;
//         string genre;
//         Movies(string a, string t, string g);
//         string decideSubCategory();
//         void createQuestion();
// };
//
// class Songs: public Question {
//     public:
//         Songs() {
//             category = "Songs";
//         }
//         string title;
//         string album;
//         string releaseDate;
//         string artist;
//         Songs(string t, string al, string r, string ar);
//         string decideSubCategory();
//         void createQuestion();
// };
//
//
// Books::Books(string a, string t, string ab, string ad, string g, string s) {
//     category = "Books";
//     author = a;
//     title = t;
//     authorBirth = ab;
//     authorDeath = ad;
//     genre = g;
//     subject = s;
//     subcategory = "author";
//     details.push_back(author);
//     details.push_back(title);
//     details.push_back(authorBirth);
//     details.push_back(authorDeath);
//     details.push_back(genre);
//     details.push_back(subject);
//     createQuestion();
// }
//
// void Books::createQuestion() {
//     question = "The " + genre + ", " + title + "was written by what author who was born on " + authorBirth + " and died on " + authorDeath + "? (First and last name required)";
//     answer = author;
// }
//
//
// Cities::Cities(string n, string s, string p) {
//     category = "Cities";
//     name = n;
//     state = s;
//     population = p;
//     subcategory = "state";
//     details.push_back(name);
//     details.push_back(state);
//     details.push_back(population);
//     createQuestion();
// }
//
// void Cities::createQuestion() {
//     question = "What state contains the city of " + name + " with a population of " + population + " people?";
//     answer = name;
// }
//
// Movies::Movies(string a, string t, string g) {
//     category = "Movies";
//     actor = a;
//     title = t;
//     genre = g;
//     subcategory = decideSubCategory();
//     details.push_back(actor);
//     details.push_back(title);
//     details.push_back(genre);
// }
//
// string Movies::decideSubCategory() {
//     return "title";
// }
//
// Songs::Songs(string t, string al, string r, string ar) {
//     category = "Songs";
//     title = t;
//     album = al;
//     releaseDate = r;
//     artist = ar;
//     subcategory = decideSubCategory();
//     details.push_back(title);
//     details.push_back(album);
//     details.push_back(releaseDate);
//     details.push_back(artist);
// }
//
// string Songs::decideSubCategory() {
//     int random = rand() % 3;
//     if (random == 0) {
//         return "title";
//     } else if (random == 1) {
//         return "album";
//     } else if (random == 2) {
//         return "artist";
//     }
// }

std::string helloString = "hello world";