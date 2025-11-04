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
// im gonna explode

int main() {
    Bridges bridges(1, "s-pappous", "1078662839858");
    bridges.setTitle("Accessing Necessary Data");
    DataSource ds (&bridges);

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    // cout << "IMDB1 Data:" << endl;
    vector<ActorMovieIMDB> actor_list1 = ds.getActorMovieIMDBData();
    for (int i = 0; i < actor_list1.size(); i++)
    {
        string currActor = actor_list1[i].getActor();
        replace(currActor.begin(), currActor.end(), '_', ' ');
        string currMovie = actor_list1[i].getMovie();
        replace(currMovie.begin(), currMovie.end(), '_', ' ');
        if(currMovie.find('#') != string::npos || currMovie.find('{') != string::npos || currMovie.find("(TV)") != string::npos)
        {
            actor_list1.erase(actor_list1.begin());
            i--;
        }
        else
        {
            // cout
            //     << "\tActor: " << currActor << endl
            //     << "\tMovie: " << currMovie << "\n" << endl;
            count1++;
        }
    }

    cout << "IMDB2 Data:" << endl;
    vector<ActorMovieIMDB> actor_list2 = ds.getActorMovieIMDBData2();
    for (int j = 0; j < actor_list2.size(); j++)
    {
        string currActor = actor_list2[j].getActor();
        replace(currActor.begin(), currActor.end(), '_', ' ');
        string currMovie = actor_list2[j].getMovie();
        replace(currMovie.begin(), currMovie.end(), '_', ' ');

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
                // cout << "\tActor: " << currActor << endl
                // << "\tMovie: " << currMovie << endl
                // << "\tGenre: " << currGenres << "\n" << endl;
                count2++;
            }
        }
    }

    cout << "Song Data:" << endl;
    vector<Song> song_list = ds.getSongData();
    for (int i = 0; i < song_list.size(); i++)
    {
        string currArtist = song_list[i].getArtist();
        string currTitle = song_list[i].getSongTitle();
        string currDate = song_list[i].getReleaseDate();
        string currAlbum = song_list[i].getAlbumTitle();
        cout
                << "\tArtist: " << currArtist << endl
                << "\tSong: " << currTitle << endl
                << "\tDate: " << currDate << endl
                << "\tAlbum: " << currAlbum << "\n" << endl;
        count3++;
    }

    cout << "Book Data:" << endl;
    vector<GutenbergBook> books_list;
    for (int i = 1; i < 40; i++) {
        books_list.push_back(ds.getGutenbergBookMetaData(i));
    }
    cout << "book size: " << books_list.size() << endl;
    for (int k = 0; k < books_list.size(); k++)
    {
        vector<string> allAuthors = books_list[k].getAuthors();
        string currAuthors = "";
        for(string item : allAuthors)
        {
            currAuthors += item + ", ";
        }
        string currTitle = books_list[k].getTitle();

        cout << "\tAuthor: " << currAuthors << endl;
        cout << "\tTitle: " << currTitle << endl;
        count4++;
    }

    cout << "U.S. City Data: " << endl;
    unordered_map<string, string> city_params{
        {"min_pop", "600000"}
    };
    vector<City> cities_list = ds.getUSCities(city_params);
    for (int i = 0; i < cities_list.size(); i++)
    {
        string currCity = cities_list[i].getCity();
        string currState = cities_list[i].getState();
        int currPop = cities_list[i].getPopulation();
        int currEle = cities_list[i].getElevation();
        string currTime = cities_list[i].getTimeZone();
        cout
                << "City: " << currCity << endl
                << "\tState: " << currState << endl
                << "\tPopulation: " << currPop << endl
                << "\tElevation: " << currEle << " meters" << endl
                << "\tTime Zone: " << currTime << "\n" << endl;
        count5++;
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
