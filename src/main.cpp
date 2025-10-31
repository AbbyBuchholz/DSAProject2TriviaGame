#include "question.h"
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include <queue>
using namespace std;

using namespace bridges;
// hi sophia and adam!! hope y'all are well :)
// we got this

int main() {
    Bridges bridges(1, "s-pappous", "1078662839858");
    bridges.setTitle("Accessing Necessary Data");
    DataSource ds (&bridges);

    int count = 0;

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
            cout << "IMDB Data:" << endl
                << "\tActor: " << currActor << endl
                << "\tMovie: " << currMovie << endl;
            count++;
        }
    }

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
                cout << "IMDB Data:" << endl
                << "\tActor: " << currActor << endl
                << "\tMovie: " << currMovie << endl
                << "\tGenre: " << currGenres << endl;
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
