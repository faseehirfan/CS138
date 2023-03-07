/*
 * CS138, W23, Assignment 1, Problem 3
 * Main Function
 *
 * main function is a special function,
 * which serves as the entry point for the program.
 *
 * Try to keep it as simple as possible
 * and implement the logic of your program
 * in a1q3.cpp, so that you can write unit tests
 * for them and make sure of their expected behavior.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// no argc+argv because we aren't using them in A1

int main()
{
    // TODO: Solve the problem!

    int N;
    string token;
    string line;
    vector<string> para;
    cin >> N;
    if (N <= 0)
    {
        cerr << "Error, line length must be positive." << endl;
        return 1;
    }

    while (cin >> token)
    {

        if (line.length() + token.length() + 1 > N){
            para.push_back(line);
            line = "";
        } 

        else if (token.length() > N){
            token = token.substr(0, N);
            para.push_back(token);
        }

        line += (line.length() == 0 ? "" : " ") + token;

        if (line.size() > N){
            line = line.substr(0, N);
        }
    }

    if (line.size() != 0){
        para.push_back(line);
    }

    for (auto j : para){
        if (j.size() != 0)cout << j << endl;
    }
}