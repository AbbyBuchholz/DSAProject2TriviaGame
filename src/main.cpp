#include "question.h"
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include "sort.cpp"
#include <queue>
#include <list>
#include <fstream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

const string filename = "questions.txt";

using namespace std;

using namespace bridges;
// hi sophia and adam!! hope y'all are well :)
// we got this




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