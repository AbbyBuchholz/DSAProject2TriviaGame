#include "question.h"
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include <queue>
#include <list>
using namespace std;

using namespace bridges;
// hi sophia and adam!! hope y'all are well :)
// we got this

int main() {
    Bridges bridges(1, "s-pappous", "1078662839858");
    bridges.setTitle("Accessing Necessary Data");
    DataSource ds (&bridges);

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    vector<Question> questions;

    cout << "IMDB1 Data:" << endl;
    vector<ActorMovieIMDB> actor_list1 = ds.getActorMovieIMDBData();
    for (int i = 0; i < actor_list1.size(); i++)
    {
        // Actor Data
        string currActor = actor_list1[i].getActor();
        int sPos = currActor.find('(');
        int ePos = currActor.find(')');
        if(sPos != string::npos && ePos != string::npos)
            currActor.erase(sPos, ePos);
        replace(currActor.begin(), currActor.end(), '_', ' ');

        // Movie Title Data
        string currMovie = actor_list1[i].getMovie();
        replace(currMovie.begin(), currMovie.end(), '_', ' ');
        if(currMovie.find('#') != string::npos || currMovie.find('{') != string::npos || currMovie.find("(TV)") != string::npos)
        {
            actor_list1.erase(actor_list1.begin());
            i--;
        }
        else
        {
            int startPos = currMovie.find('(');
            int endPos = currMovie.find(')');

            // Year Data
            string currYear = currMovie.substr(startPos + 1, endPos - startPos - 1);

            // Movie Title Data
            currMovie.erase(startPos, endPos);
            if(currMovie.find(", The") != string::npos)
            {
                int stPos = currMovie.find(", The");
                int phraseLen = 5;
                string currPhrase = currMovie.substr(stPos + 2, phraseLen - 2) + " ";
                currMovie.erase(stPos, phraseLen);
                currMovie.insert(0, currPhrase);
            }
            else if(currMovie.find(", A") != string::npos)
            {
                int stPos = currMovie.find(", A");
                int phraseLen = 3;
                string currPhrase = currMovie.substr(stPos + 2, phraseLen - 2) + " ";
                currMovie.erase(stPos, phraseLen);
                currMovie.insert(0, currPhrase);
            }
            else if(currMovie.find(", An") != string::npos)
            {
                int stPos = currMovie.find(", An");
                int phraseLen = 4;
                string currPhrase = currMovie.substr(stPos + 2, phraseLen - 2) + " ";
                currMovie.erase(stPos, phraseLen);
                currMovie.insert(0, currPhrase);
            }
            else if(currMovie.find(", La") != string::npos)
            {
                int stPos = currMovie.find(", La");
                int phraseLen = 4;
                string currPhrase = currMovie.substr(stPos + 2, phraseLen - 2) + " ";
                currMovie.erase(stPos, phraseLen);
                currMovie.insert(0, currPhrase);
            }
            cout
                << "Movie: " << currMovie << endl
                << "\tActor: " << currActor << endl
                << "\tYear: " << currYear << "\n" << endl;
            count1 += 3;
        }
    }

    cout << "IMDB2 Data:" << endl;
    vector<ActorMovieIMDB> actor_list2 = ds.getActorMovieIMDBData2();
    for (int j = 0; j < actor_list2.size(); j++)
    {
        string currActor = actor_list2[j].getActor();

        int sPos = currActor.find('(');
        int ePos = currActor.find(')');
        if(sPos != string::npos && ePos != string::npos)
            currActor.erase(sPos, ePos);

        replace(currActor.begin(), currActor.end(), '_', ' ');
        if(currActor.find(",") != string::npos)
        {
            int stPos = currActor.find(",");
            string currPhrase = currActor.substr(stPos + 2) + " ";
            currActor.erase(stPos, currPhrase.length() + 1);
            currActor.insert(0, currPhrase);
        }

        string currMovie = actor_list2[j].getMovie();
        replace(currMovie.begin(), currMovie.end(), '_', ' ');
        int currRating = actor_list2[j].getMovieRating();

        if(currMovie.find('#') != string::npos || currMovie.find('{') != string::npos || currMovie.find("(TV)") != string::npos)
        {
            actor_list2.erase(actor_list2.begin());
            j--;
        }
        else
        {
            vector<string> allGenres = actor_list2[j].getGenres();
            string currGenres = "";
            for(string item : allGenres)
            {
                currGenres += item + ", ";
            }
            if(currGenres.find("Documentary") != string::npos || currGenres.find("Sport") != string::npos || currGenres.find("News") != string::npos || currGenres.find("Short") != string::npos || currGenres.find("Talk-Show") != string::npos || currGenres.find("Biography") != string::npos || currGenres.find("Music") != string::npos || currGenres.find("Reality-TV") != string::npos || currGenres.find("Game-Show") != string::npos)
            {
                actor_list2.erase(actor_list2.begin());
                j--;
            }
            else
            {
                int startPos = currMovie.find('(');
                int endPos = currMovie.find(')');
                string currYear = currMovie.substr(startPos + 1, endPos - startPos - 1);
                currMovie.erase(startPos, endPos);
                cout
                << "Movie: " << currMovie << endl
                << "\tActor: " << currActor << endl
                << "\tGenre: " << currGenres << endl
                << "\tYear: " << currYear << endl
                << "\tRating: " << currRating << "/10\n" << endl;
                count2 += 4 + allGenres.size();
            }
        }
    }

    cout << "Song Data:" << endl;
    vector<Song> song_list = ds.getSongData();
    for (int i = 0; i < song_list.size(); i++)
    {
        string currTitle = song_list[i].getSongTitle();
        string currArtist = song_list[i].getArtist();
        string currDate = song_list[i].getReleaseDate();
        string currAlbum = song_list[i].getAlbumTitle();
        cout
                << "Song: " << currTitle << endl
                << "\tArtist: " << currArtist << endl
                << "\tDate: " << currDate << endl
                << "\tAlbum: " << currAlbum << "\n" << endl;
        count3 += 4;
    }

    cout << "Book Data:" << endl;
    vector<GutenbergBook> books_list;
    for (int i = 1; i < 40; i++) {
        books_list.push_back(ds.getGutenbergBookMetaData(i));
    }
    for (int k = 0; k < books_list.size(); k++)
    {
        string currTitle = books_list[k].getTitle();

        vector<string> allAuthors = books_list[k].getAuthors();
        string currAuthors = "";
        for(string item : allAuthors)
        {
            currAuthors += item + ", ";
        }
        string currLang = books_list[k].getLang();
        vector<string> allGenres = books_list[k].getGenres();
        string currGenres = "";
        for(string item : allGenres)
        {
            currGenres += item + ", ";
        }
        cout
                << "Title: " << currTitle << endl
                << "\tAuthor: " << currAuthors << endl
                << "\tLanguage: " << currLang << endl
                << "\tGenres: " << currGenres << "\n" << endl;
        count4 += 2 + allAuthors.size() + allGenres.size();
    }

    cout << "U.S. City Data: " << endl;
    unordered_map<string, string> city_params{
        {"min_pop", "100000"}
    };
    vector<City> cities_list = ds.getUSCities(city_params);
    for (int i = 0; i < cities_list.size(); i++)
    {
        string currCity = cities_list[i].getCity();
        string currState = cities_list[i].getState();
        string currCountry = cities_list[i].getCountry();
        int currPop = cities_list[i].getPopulation();
        int currEle = cities_list[i].getElevation();
        string currTime = cities_list[i].getTimeZone();
        int currLat = cities_list[i].getLatitude();
        int currLong = cities_list[i].getLongitude();
        cout
                << "City: " << currCity << endl
                << "\tState: " << currState << endl
                << "\tCountry: " << currCountry << endl
                << "\tPopulation: " << currPop << endl
                << "\tElevation: " << currEle << " meters" << endl
                << "\tTime Zone: " << currTime << endl
                << "\tLatitude: " << currLat << endl
                << "\tLongitude: " << currLong << "\n" << endl;
        count5 += 8;
    }

    cout << "IMDB 1 Count: " << count1 << endl;
    cout << "IMDB 2 Count: " << count2 << endl;
    cout << "Song Count: " << count3 << endl;
    cout << "Book Count: " << count4 << endl;
    cout << "U.S. City Count: " << count5 << endl;

    int total = count1 + count2 + count3 + count4 + count5;
    cout << "Total Count: " << total << endl;

    return 0;
}
