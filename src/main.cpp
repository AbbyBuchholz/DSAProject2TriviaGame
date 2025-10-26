#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "bridges-cxx-3.4.1-x86_64-linux-gnu/include/Bridges.h"
#include "bridges-cxx-3.4.1-x86_64-linux-gnu/include/Datasource.h"
#include "bridges-cxx-3.4.1-x86_64-linux-gnu/include/data_src/ActorMovieIMDB.h"
#include "bridges-cxx-3.4.1-x86_64-linux-gnu/include/data_src/Book.h"
#include "bridges-cxx-3.4.1-x86_64-linux-gnu/include/data_src/City.h"
#include "bridges-cxx-3.4.1-x86_64-linux-gnu/include/data_src/Song.h"

using namespace bridges;
// hi sophia and adam!! hope y'all are well :)

int main() {
    Bridges bridges(1, "s-pappous", "1078662839858");
    bridges.setTitle("Accessing Necessary Data");
    DataSource ds (&bridges);

    vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1814);
    return 0;
}
