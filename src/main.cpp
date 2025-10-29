#include <iostream>
#include <string>
#include <vector>
#include "question.h"

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include <queue>
using namespace std;
using namespace bridges;

using namespace bridges;
// hi sophia and adam!! hope y'all are well :)
// we got this

int main() {
    Bridges bridges(1, "s-pappous", "1078662839858");
    bridges.setTitle("Accessing Necessary Data");
    DataSource ds (&bridges);

    vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData();
    std::cout << actor_list.size() << std::endl;
    std::cout << helloString;
    return 0;
}
