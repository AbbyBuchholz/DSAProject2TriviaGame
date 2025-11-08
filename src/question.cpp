//
// Created by pokem on 11/8/2025.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "question.h"

using namespace std;

Books::Books(string aFN, string aLN, string t, string l, vector<string> g, int v) {
    category = "Books";
    authorFirstName = aFN;
    authorLastName = aLN;
    title = t;
    language = l;
    genre = g;
    subcategory = "author";
    variation = v;
    // details.push_back(author);
    // details.push_back(title);
    // details.push_back(language);
    // details.push_back(genre);
    createQuestion();
}

void Books::createQuestion() {
    if (variation == 1) {
        // question = "This" + author + " wrote the " + language + " language book " + title + ". What genre is it in?";
        // answer = genre;
    } else if (variation == 2) {
        question = "Who wrote " + title + "?";
        answer = authorFirstName + authorLastName;
    } else if (variation == 3) {
        question = "What language is " + title + " by " + authorFirstName + authorLastName + "in?";
        answer = language;
    } else if (variation == 4) {
        question = "What book did " + authorFirstName + authorLastName + " write?";
        answer = title;
    } else if (variation == 5) {
        question = title + ",  a seminal work in the" + genre[0] + " genre, was written by which author?";
        answer = authorFirstName + authorLastName;
    } else if (variation == 6) {
        question = "Who wrote the " + genre[0] + title + "?";
        answer = authorFirstName + authorLastName;
    } else if (variation == 7) {
        question = "What famous " + genre[0] + " was written by " + authorFirstName + authorLastName; + "?";
        answer = title;
    } else if (variation == 8) {
        question = title + " was written by whom?";
        answer = authorFirstName + authorLastName;
    } else if (variation == 9) {
        // question = "What genre is " + title + "?";
        // answer = genre;
    } else if (variation == 10) {
        question = "What eloquent orator wrote the masterpiece " + title + "?";
        answer = authorFirstName + authorLastName;
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
        question = "What city is at the latitude of " + latitude + " and the longitude of " + longitude + "?";
        answer = name;
    } else if (variation == 2) {
        question = "What city in " + state + " has a population of " + population + "?";
        answer = name;
    } else if (variation == 3) {
        question = "What state has the city of " + name + " and a population of " + population + "?";
        answer = state;
    } else if (variation == 4) {
        question = "What country features the city " + name + "?";
        answer = country;
    } else if (variation == 5) {
        question = "What time zone is " + name + " in?";
        answer = timeZone;
    } else if (variation == 6) {
        question = "What city in " + state + " has a population of " + population + " and is in the " + timeZone + " time zone?";
        answer = name;
    } else if (variation == 7) {
        question = "What city is at the latitude of " + latitude + " and the longitude of " + longitude + " and at an elevation of " + elevation + "?";
        answer = name;
    } else if (variation == 8) {
        question = "What city in " + state + " and is at the latitude of " + latitude + " and the longitude of " + longitude + " and at an elevation of " + elevation + "?";
        answer = name;
    } else if (variation == 9) {
        question = "What state is at the latitude of " + latitude + " and the longitude of " + longitude + " and at an elevation of " + elevation + " and has the city " + name + "?";
        answer = state;
    } else if (variation == 10) {
        question = "If " + name + " is at longitude " + longitude + ", what time zone is it in?";
        answer = timeZone;
    }
}

Movies1::Movies1(string aFN, string aLN, string t, string y, int v) {
    category = "Movies";
    actorFirstName = aFN;
    actorLastName = aLN;
    title = t;
    year = y;
    variation = v;
    subcategory = decideSubCategory();
    // details.push_back(actor);
    // details.push_back(title);
    // details.push_back(year);
}

string Movies1::decideSubCategory() {
    return "title";
}

void Movies1::createQuestion() {
    if (variation == 1) {
        question = "What year did " + title + "starring " + actorFirstName + actorLastName + "come out?";
        answer = year;
    } else if (variation == 2) {
        question = "What movie did " + actorFirstName + actorLastName + " star in " + year + "?";
        answer = title;
    } else if (variation == 3) {
        question = "What year did " + title + " release?";
        answer = year;
    } else if (variation == 4) {
        question = "What film did " + actorFirstName + actorLastName + " perform in " + year + "?";
        answer = title;
    } else if (variation == 5) {
        question = "In " + year + ", what movie did " + actorFirstName + actorLastName + "appear in?";
        answer = title;
    } else if (variation == 6) {
        question = "In " + title + " (" + year + "), which actor has a notable appearance?";
        answer = actorFirstName + actorLastName;
    } else if (variation == 7) {
        question = actorFirstName + actorLastName + " notably appears in what movie from " + year + "?";
        answer = title;
    } else if (variation == 8) {
        question = actorFirstName + actorLastName + " appears in " + title + " in which year?";
        answer = year;
    } else if (variation == 9) {
        question = "You’re a time traveler in the year" + year + "and just got invited to the movie starring" + actorFirstName + actorLastName + ". Which movie are you seeing?";
        answer = title;
    } else if (variation == 10) {
        question = "You’re a time traveler who doesn’t know what year it is and just got invited to the movie" + title + "starring" + actorFirstName + actorLastName + ". What year are you in?";
        answer = year;
    }
}

Movies2::Movies2(string aFN, string aLN, string t, vector<string> g, string y, string r, int v) {
    category = "Movies";
    actorFirstName = aFN;
    actorLastName = aLN;
    title = t;
    genre = g;
    year = y;
    rating = r;
    variation = v;
    subcategory = decideSubCategory();
    // details.push_back(actor);
    // details.push_back(title);
    // details.push_back(genre);
    // details.push_back(year);
    // details.push_back(rating);
}

string Movies2::decideSubCategory() {
    return "title";
}

void Movies2::createQuestion() {
    if (variation == 1) {
        question = "What year did " + title + "starring " + actorFirstName + actorLastName + "come out?";
        answer = year;
    } else if (variation == 2) {
        question = "What movie did " + actorFirstName + actorLastName + " star in " + year + "?";
        answer = title;
    } else if (variation == 3) {
        question = "What year did " + title + " release?";
        answer = year;
    } else if (variation == 4) {
        question = "What film did " + actorFirstName + actorLastName + " perform in " + year + "?";
        answer = title;
    } else if (variation == 5) {
        question = "What " + rating + " movie from the year" + year + " did " + actorFirstName + actorLastName + "star in?";
        answer = actorFirstName + actorLastName;
    } else if (variation == 6) {
        question = "What rating does " + title + "have?";
        answer = rating;
    } else if (variation == 7) {
        // question = "What genre is" + title + "starring " + actor + "?";
        // answer = genre;
    } else if (variation == 8) {
        question = "What movie stars " + actorFirstName + actorLastName + ", is a " + genre[0] + ", came out in " + year + ", and has a rating of " + rating + "?";
        answer = title;
    } else if (variation == 9) {
        question = "In " + year + ", what movie did " + actorFirstName + actorLastName + "appear in?";
        answer = year;
    } else if (variation == 10) {
        question = "What movie starring " + actorFirstName + actorLastName + " released in " + year + "?";
        answer = title;
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
        question = "What year was " + album + " by " + artist + " released?";
        answer = releaseDate;
    } else if (variation == 2) {
        question = "Which album is " + title + " on?";
        answer = album;
    } else if (variation == 3) {
        question = "Which artist released the album " + album + "?";
        answer = artist;
    } else if (variation == 4) {
        question = "What year was " + album + "released?";
        answer = releaseDate;
    } else if (variation == 5) {
        question = "Which artist released" + album + "in " + releaseDate + "?";
        answer = artist;
    } else if (variation == 6) {
        question = title + "on the album" + album + "was by which artist?";
        answer = artist;
    } else if (variation == 7) {
        question = releaseDate + "‘s " + album + " was released by which artist?";
        answer = artist;
    } else if (variation == 8) {
        question = "What album did " + artist + " drop in " + releaseDate + "?";
        answer = album;
    } else if (variation == 9) {
        question = "What year did " + artist + " drop the song " + title + "?";
        answer = releaseDate;
    } else if (variation == 10) {
        question = "What year did " + artist + " drop the album " + album + "?";
        answer = releaseDate;
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