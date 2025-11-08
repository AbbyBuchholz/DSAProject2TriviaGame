#include "question.h"
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include <queue>
#include <list>
#include <fstream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const string filename = "questions.txt";

using namespace std;

using namespace bridges;
// hi sophia and adam!! hope y'all are well :)
// we got this

// the merge functions that merge the split vectors (does the actual sorting)
void mergeM1(vector<Movies1>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Movies1> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].actorLastName <= rightVector[j].actorLastName)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeM2(vector<Movies2>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Movies2> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].actorLastName <= rightVector[j].actorLastName)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeSongs(vector<Songs>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Songs> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].artist <= rightVector[j].artist)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeBooks(vector<Books>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Books> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].authorLastName <= rightVector[j].authorLastName)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeCities(vector<Cities>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Cities> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].state < rightVector[j].state)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].state > rightVector[j].state)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].name <= rightVector[j].name)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}

// The original mergesort functions that keep splitting up the vectors
void mergeSortM1(vector<Movies1>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortM1(qVector, left, mid);
        mergeSortM1(qVector, mid + 1, right);
        mergeM1(qVector, left, mid, right);
    }
}
void mergeSortM2(vector<Movies2>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortM2(qVector, left, mid);
        mergeSortM2(qVector, mid + 1, right);
        mergeM2(qVector, left, mid, right);
    }
}
void mergeSortSongs(vector<Songs>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortSongs(qVector, left, mid);
        mergeSortSongs(qVector, mid + 1, right);
        mergeSongs(qVector, left, mid, right);
    }
}
void mergeSortBooks(vector<Books>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortBooks(qVector, left, mid);
        mergeSortBooks(qVector, mid + 1, right);
        mergeBooks(qVector, left, mid, right);
    }
}
void mergeSortCities(vector<Cities>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortCities(qVector, left, mid);
        mergeSortCities(qVector, mid + 1, right);
        mergeCities(qVector, left, mid, right);
    }
}

// These functions are used to compare ideal data, and if they're equal, they go to secondary data to compare & sort.
bool compareQuickSortM1(Movies1& ele, Movies1& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.actorLastName < pivot.actorLastName;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortM2(Movies2& ele, Movies2& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.actorLastName < pivot.actorLastName;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortSongs(Songs& ele, Songs& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.artist < pivot.artist;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortBooks(Books& ele, Books& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.authorLastName < pivot.authorLastName;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortCities(Cities& ele, Cities& pivot)
{
    if(ele.state == pivot.state)
    {
        return ele.name < pivot.name;
    }
    return ele.state < pivot.state;
}

// The original quickSort functions using the middle element as a partition
void quickSortM1(vector<Movies1>& qVector, int low, int high)
{
    Movies1 pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortM1(qVector[up], pivot))
            up++;
        while(compareQuickSortM1(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortM1(qVector, low, down);
    }
    if(up < high)
    {
        quickSortM1(qVector, up, high);
    }
}
void quickSortM2(vector<Movies2>& qVector, int low, int high)
{
    Movies2 pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortM2(qVector[up], pivot))
            up++;
        while(compareQuickSortM2(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortM2(qVector, low, down);
    }
    if(up < high)
    {
        quickSortM2(qVector, up, high);
    }
}
void quickSortSongs(vector<Songs>& qVector, int low, int high)
{
    Songs pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortSongs(qVector[up], pivot))
            up++;
        while(compareQuickSortSongs(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortSongs(qVector, low, down);
    }
    if(up < high)
    {
        quickSortSongs(qVector, up, high);
    }
}
void quickSortBooks(vector<Books>& qVector, int low, int high)
{
    Books pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortBooks(qVector[up], pivot))
            up++;
        while(compareQuickSortBooks(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortBooks(qVector, low, down);
    }
    if(up < high)
    {
        quickSortBooks(qVector, up, high);
    }
}
void quickSortCities(vector<Cities>& qVector, int low, int high)
{
    Cities pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortCities(qVector[up], pivot))
            up++;
        while(compareQuickSortCities(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortCities(qVector, low, down);
    }
    if(up < high)
    {
        quickSortCities(qVector, up, high);
    }
}

vector<Question> createData(bool isMergeSort, bool isQuickSort) {
    Bridges bridges(1, "s-pappous", "1078662839858");
    bridges.setTitle("Accessing Necessary Data");
    DataSource ds (&bridges);

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    vector<Question> questions;
    vector<Movies1> qActor1;
    vector<Movies2> qActor2;
    vector<Songs> qSong;
    vector<Books> qBook;
    vector<Cities> qCity;

    cout << "IMDB1 Data:" << endl;
    vector<ActorMovieIMDB> actor_list1 = ds.getActorMovieIMDBData();
    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < actor_list1.size(); i++)
        {
            // Actor Data
            string currActor = actor_list1[i].getActor();
            string lastName = "";
            int sPos = currActor.find('(');
            int ePos = currActor.find(')');
            if(sPos != string::npos && ePos != string::npos)
                currActor.erase(sPos - 1, ePos + 1);
            replace(currActor.begin(), currActor.end(), '_', ' ');
            if(currActor.find(" ") != string::npos)
            {
                int stPos = currActor.find(" ");
                lastName = currActor.substr(stPos + 1);
                currActor.erase(stPos, lastName.length() + 1);
            }

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

                Movies1* m1 = new Movies1(currActor, lastName, currMovie, currYear, j);
                qActor1.push_back(*m1);

                cout
                    << "Movie: " << currMovie << endl
                    << "\tActor: " << currActor << " " << lastName << endl
                    << "\tYear: " << currYear << "\n" << endl;
                count1 += 3;
            }
        }
    }

    cout << "IMDB2 Data:" << endl;
    vector<ActorMovieIMDB> actor_list2 = ds.getActorMovieIMDBData2();
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j < actor_list2.size(); j++)
        {
            // Actor Name Data
            string currActor = actor_list2[j].getActor();
            string firstName = "";

            int sPos = currActor.find('(');
            int ePos = currActor.find(')');
            if(sPos != string::npos && ePos != string::npos)
                currActor.erase(sPos, ePos);

            replace(currActor.begin(), currActor.end(), '_', ' ');
            if(currActor.find(",") != string::npos)
            {
                int stPos = currActor.find(",");
                firstName = currActor.substr(stPos + 2);
                currActor.erase(stPos, firstName.length() + 1);
            }

            // Movie Title Data
            string currMovie = actor_list2[j].getMovie();
            replace(currMovie.begin(), currMovie.end(), '_', ' ');
            // Rating Data
            int currRating = actor_list2[j].getMovieRating();
            // Movie Title Data
            if(currMovie.find('#') != string::npos || currMovie.find('{') != string::npos || currMovie.find("(TV)") != string::npos)
            {
                actor_list2.erase(actor_list2.begin());
                j--;
            }
            else
            {
                // Genre Data
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
                    // Year Data
                    int startPos = currMovie.find('(');
                    int endPos = currMovie.find(')');
                    string currYear = currMovie.substr(startPos + 1, endPos - startPos - 1);
                    currMovie.erase(startPos, endPos);

                    Movies2* m2 = new Movies2(firstName, currActor, currMovie, allGenres, currYear, to_string(currRating), i);
                    qActor2.push_back(*m2);

                    cout
                    << "Movie: " << currMovie << endl
                    << "\tActor: " << firstName << " " << currActor << endl
                    << "\tGenre: " << currGenres << endl
                    << "\tYear: " << currYear << endl
                    << "\tRating: " << currRating << "/10\n" << endl;
                    count2 += 4 + allGenres.size();
                }
            }
        }
    }

    cout << "Song Data:" << endl;
    vector<Song> song_list = ds.getSongData();
    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < song_list.size(); i++)
        {
            string currTitle = song_list[i].getSongTitle();
            string currArtist = song_list[i].getArtist();
            string currDate = song_list[i].getReleaseDate();
            string currAlbum = song_list[i].getAlbumTitle();

            Songs* s = new Songs(currTitle, currAlbum, currDate, currArtist, j);
            qSong.push_back(*s);
            cout
                    << "Song: " << currTitle << endl
                    << "\tArtist: " << currArtist << endl
                    << "\tDate: " << currDate << endl
                    << "\tAlbum: " << currAlbum << "\n" << endl;
            count3 += 4;
        }
    }

    cout << "Book Data:" << endl;
    vector<GutenbergBook> books_list;
    for (int i = 1; i < 40; i++) {
        books_list.push_back(ds.getGutenbergBookMetaData(i));
    }
    for (int j = 1; j <= 10; j++) {
        for (int k = 0; k < books_list.size(); k++)
        {
            // Book Title Data
            string currTitle = books_list[k].getTitle();
            string firstName = "";
            string lastName = "";

            // Gets the main author and sets it as the author.
            vector<string> allAuthors = books_list[k].getAuthors();
            if(!allAuthors.empty())
            {
                lastName = allAuthors[0];
                if(lastName.find(",") != string::npos)
                {
                    int stPos = lastName.find(",");
                    firstName = lastName.substr(stPos + 2);
                    lastName.erase(stPos, firstName.length() + 1);
                }
            }

            // Language Data
            string currLang = books_list[k].getLang();
            // Book Genre Data
            vector<string> allGenres = books_list[k].getGenres();
            string currGenres = "";
            for(string item : allGenres)
            {
                currGenres += item + ", ";
            }

            Books* b = new Books(firstName, lastName, currTitle, currLang, allGenres, j);
            qBook.push_back(*b);

            cout
                    << "Title: " << currTitle << endl
                    << "\tAuthor: " << firstName << " " << lastName << endl
                    << "\tLanguage: " << currLang << endl
                    << "\tGenres: " << currGenres << "\n" << endl;
            count4 += 2 + allAuthors.size() + allGenres.size();
        }
    }

    cout << "U.S. City Data: " << endl;
    unordered_map<string, string> city_params{
        {"min_pop", "100000"}
    };
    vector<City> cities_list = ds.getUSCities(city_params);
    for (int j = 1; j <= 10; j++) {
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

            Cities* c = new Cities(currCity, currState, currCountry, to_string(currPop), to_string(currEle), currTime, to_string(currLat), to_string(currLong), j);
            qCity.push_back(*c);
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
    }

    // Decides whether to do mergeSort or quickSort based on what setting is on.

    if(isMergeSort)
    {
        mergeSortM1(qActor1, 0, qActor1.size() - 1);
        mergeSortM2(qActor2, 0, qActor2.size() - 1);
        mergeSortSongs(qSong, 0, qSong.size() - 1);
        mergeSortBooks(qBook, 0, qBook.size() - 1);
        mergeSortCities(qCity, 0, qCity.size() - 1);
    }
    if(isQuickSort)
    {
        quickSortM1(qActor1, 0, qActor1.size() - 1);
        quickSortM2(qActor2, 0, qActor2.size() - 1);
        quickSortSongs(qSong, 0, qSong.size() - 1);
        quickSortBooks(qBook, 0, qBook.size() - 1);
        quickSortCities(qCity, 0, qCity.size() - 1);
    }


    // Inserts all sorted questions into the question bank
    questions.insert(questions.end(), qActor1.begin(), qActor1.end());
    questions.insert(questions.end(), qActor2.begin(), qActor2.end());
    questions.insert(questions.end(), qSong.begin(), qSong.end());
    questions.insert(questions.end(), qBook.begin(), qBook.end());
    questions.insert(questions.end(), qCity.begin(), qCity.end());

    cout << "IMDB 1 Count: " << count1 << endl;
    cout << "IMDB 2 Count: " << count2 << endl;
    cout << "Song Count: " << count3 << endl;
    cout << "Book Count: " << count4 << endl;
    cout << "U.S. City Count: " << count5 << endl;

    int total = count1 + count2 + count3 + count4 + count5;
    cout << "Total Count: " << total << endl;
    cout << "Vector: " << questions.size() << endl;
    return questions;
}

//code to transfer the data to the frontend!
//It also utilizes a .txt to prevent loading 100,000 data points every time
int main(int argc, char** argv) {
    ifstream infile(filename);
    string userInput;
    if (argc > 1) {
        userInput = argv[1];
    } else {
        userInput = "";
    }
    std::random_device rd;
    std::mt19937 g(rd());

    if (!infile.good() || (userInput == "randomize")) { //randomize the data
        ofstream outfile(filename, ios::trunc);
        vector<Question> questions = createData(false, false);
        shuffle(questions.begin(), questions.end(), g);
        for (int i = 0; i < questions.size(); i++) {
            outfile << questions[i].question << "|" << questions[i].answer << "|" << questions[i].category <<endl;
        }
        cout << "Successfully created questions!";
        outfile.close();
    }
    if (userInput == "mergeSort") {
        ofstream outfile(filename, ios::trunc);
        vector<Question> questions = createData(true, false);
        shuffle(questions.begin(), questions.end(), g);
        for (int i = 0; i < questions.size(); i++) {
            outfile << questions[i].question << "|" << questions[i].answer << "|" << questions[i].category << endl;
        }
        cout << "Successfully created questions!";
        outfile.close();
    }
    if (userInput == "quickSort") {
        ofstream outfile(filename, ios::trunc);
        vector<Question> questions = createData(false, true);
        for (int i = 0; i < questions.size(); i++) {
            outfile << questions[i].question << "|" << questions[i].answer << "|" << questions[i].category << endl;
        }
        cout << "Successfully created questions!";
        outfile.close();
    }
    if (userInput == "next") {
        struct QuestionStruct {
            string question;
            string answer;
            string category;
        };
        vector<QuestionStruct> questions;
        string line;

        while (getline(infile, line)) {
            size_t firstDelimiter = line.find("|");
            size_t secondDelimiter = line.find("|", firstDelimiter + 1);

            if (firstDelimiter != string::npos && secondDelimiter != string::npos) {
                string question = line.substr(0, firstDelimiter);
                string answer = line.substr(firstDelimiter + 1, secondDelimiter - firstDelimiter - 1);
                string category = line.substr(secondDelimiter + 1);
                if (!question.empty() && !answer.empty() && !category.empty()) {
                    questions.push_back({question,answer,category});
                }
            }

        }
        infile.close();

        srand(static_cast<unsigned int>(time(nullptr)));
        int idx = rand() % questions.size();

        QuestionStruct selected = questions[idx];
        cout << selected.question << "|" << selected.answer << "|" << selected.category << endl;
        return 0;
    }

    return 0;
}